using namespace std;
#ifndef MINHEAP_H
#define MINHEAP_H

class minHeap
{
private:
  //keeps track of my number of elements
  int numElements;
  //my array of values
  int* arr;

public:
  //constructor & destructor
  minHeap();
  ~minHeap();
  //insert function
  void insert(int newValue);
  //heapifies the heap
  void heapify();
  void recursiveHeapify(int index);
  //Deletes the min and returns it
  int deleteMin();
  //deletes the max and returns it
  int deleteMax();
  //finds the max
  int findMax();
  //finds the min
  int findMin();
  //prints the levelorder
  void levelOrder();

};
#endif
