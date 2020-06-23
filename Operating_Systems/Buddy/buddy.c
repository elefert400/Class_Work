/**
 * Buddy Allocator
 *
 * For the list library usage, see http://www.mcs.anl.gov/~kazutomo/list/
 */

/**************************************************************************
 * Conditional Compilation Options
 **************************************************************************/
#define USE_DEBUG 0

/**************************************************************************
 * Included Files
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "buddy.h"
#include "list.h"

/**************************************************************************
 * Public Definitions
 **************************************************************************/
#define MIN_ORDER 12
#define MAX_ORDER 20

#define PAGE_SIZE (1<<MIN_ORDER)
/* page index to address */
#define PAGE_TO_ADDR(page_idx) (void *)((page_idx*PAGE_SIZE) + g_memory)

/* address to page index */
#define ADDR_TO_PAGE(addr) ((unsigned long)((void *)addr - (void *)g_memory) / PAGE_SIZE)

/* find buddy address */
#define BUDDY_ADDR(addr, o) (void *)((((unsigned long)addr - (unsigned long)g_memory) ^ (1<<o)) \
									 + (unsigned long)g_memory)

#if USE_DEBUG == 1
#  define PDEBUG(fmt, ...) \
	fprintf(stderr, "%s(), %s:%d: " fmt,			\
		__func__, __FILE__, __LINE__, ##__VA_ARGS__)
#  define IFDEBUG(x) x
#else
#  define PDEBUG(fmt, ...)
#  define IFDEBUG(x)
#endif

/**************************************************************************
 * Public Types
 **************************************************************************/
typedef struct {

	struct list_head list;
	/* block order*/
	int block_order;
	/* Page index*/
	int index;
	/* Page address */
	char* block_add;
} page_t;

/**************************************************************************
 * Global Variables
 **************************************************************************/
/* free lists*/
struct list_head free_area[MAX_ORDER+1];

/* memory area */
char g_memory[1<<MAX_ORDER];

/* page structures */
page_t g_pages[(1<<MAX_ORDER)/PAGE_SIZE];

/**************************************************************************
 * Public Function Prototypes
 **************************************************************************/

/**************************************************************************
 * Local Functions
 **************************************************************************/

/**
 * Initialize the buddy system
 */
void buddy_init()
{
	int i;
	int n_pages = (1<<MAX_ORDER) / PAGE_SIZE;
	for (i = 0; i < n_pages; i++) {
		/* The list of pages initializing */
		INIT_LIST_HEAD(&g_pages[i].list);

		g_pages[i].index = i;
		g_pages[i].block_add = PAGE_TO_ADDR(i);
		g_pages[i].block_order = -1;
	}

	g_pages[0].block_order = MAX_ORDER;

	/* initialize freelist */
	for (i = MIN_ORDER; i <= MAX_ORDER; i++) {
		INIT_LIST_HEAD(&free_area[i]);
	}

	/* add the entire memory as a freeblock */
	list_add(&g_pages[0].list, &free_area[MAX_ORDER]);
}

/**
 * Allocate a memory block.
 *
 * On a memory request, the allocator returns the head of a free-list of the
 * matching size (i.e., smallest block that satisfies the request). If the
 * free-list of the matching block size is empty, then a larger block size will
 * be selected. The selected (large) block is then splitted into two smaller
 * blocks. Among the two blocks, left block will be used for allocation or be
 * further splitted while the right block will be added to the appropriate
 * free-list.
 *
 * @param size size in bytes
 * @return memory block address
 */
void *buddy_alloc(int size)
{
	/* TODO: IMPLEMENT THIS FUNCTION */

	//bound checking of the size
	if(size <= 0 || size > (1 << MAX_ORDER))
	{
		return NULL;
	}

	//calculating order
	int order = MIN_ORDER;
	while((1 << order) < size && order <= MAX_ORDER)
	{
		order++;
	}

	//interate over the lists looking for a place to allocate
	for(int i = order; i <= MAX_ORDER; i++)
	{
		//check that the list is not empty
		if(list_empty(&free_area[i]) == 0)
		{
			page_t *leftPage;
			page_t *rightPage;
			int pageIndex;
			void *pageAddress;

			//begin recursively splitting the blocks
			//and end recursion when the block is small enough for the request
			if(i == order)
			{
				leftPage = list_entry(free_area[i].next, page_t, list);
				list_del(&(leftPage->list));
			}
			//recursion step
			else
			{
				//grab the left most page in the breakdown
				leftPage = &g_pages[ADDR_TO_PAGE(buddy_alloc((1 << (order + 1))))];

				//calculate blocks index
				pageIndex = leftPage->index + (1 << order) / PAGE_SIZE;
				rightPage = &g_pages[pageIndex];

				//add the buddy to the free list
				list_add(&(rightPage->list), &free_area[order]);
			}

			//update left block
			leftPage->block_order = order;

			//calculate page address and return
			pageAddress = PAGE_TO_ADDR(leftPage->index);
			return pageAddress;
		}
		// else
		// {
		// 	//list is empty, return null
		// 	return NULL;
		// }
	}
	return NULL;
}

/**
 * Free an allocated memory block.
 *
 * Whenever a block is freed, the allocator checks its buddy. If the buddy is
 * free as well, then the two buddies are combined to form a bigger block. This
 * process continues until one of the buddies is not free.
 *
 * @param addr memory block address to be freed
 */
void buddy_free(void *addr)
{
	page_t *pageToFree = &g_pages[ADDR_TO_PAGE(addr)];
	/* holds the buddy to be checked */
	page_t *buddyToFree;
	/* blockOrderToFree holds the size of the memory to be freed */
	int blockOrderToFree = pageToFree->block_order;
	/* holds the list*/
	struct list_head *freeList;
	/* This loop checks the selected block size and the greater ones */
	for(int i = blockOrderToFree; i <= MAX_ORDER; i++){
		buddyToFree = NULL;

		list_for_each(freeList, &free_area[i]){
			/* gets the entry */
			buddyToFree = list_entry(freeList, page_t, list);
			/* assure that there is no other free buddy from the same size */
			if(buddyToFree == NULL)
				break;
			else if (buddyToFree->block_add == BUDDY_ADDR(addr, i)){
				break;
			}
		}
		/* if there is no matching buddy of the same size
		 * or if there is a matching size but not a buddy
		 */
		if(buddyToFree == NULL || buddyToFree->block_add != BUDDY_ADDR(addr, i)){
			g_pages[ADDR_TO_PAGE(addr)].block_order = -1;
			list_add(&g_pages[ADDR_TO_PAGE(addr)].list, &free_area[i]);
			return;
		}
		/* merege the two buddies */
		/* update address */
		if(((char *) addr) > (buddyToFree->block_add)){
			addr = buddyToFree->block_add;
		}
		/* remove the block from the free area */
		list_del(&(buddyToFree->list));
	}

}

/**
 * Print the buddy system status---order oriented
 *
 * print free pages in each order.
 */
void buddy_dump()
{
	int o;
	for (o = MIN_ORDER; o <= MAX_ORDER; o++) {
		struct list_head *pos;
		int cnt = 0;
		list_for_each(pos, &free_area[o]) {
			cnt++;
		}
		printf("%d:%dK ", cnt, (1<<o)/1024);
	}
	printf("\n");
}
