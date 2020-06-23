using namespace std;
#ifndef MAXHEAP_H
#define MAXHEAP_H

class maxHeap
{
private:
  //keeps track of my number of elements
  int numElements;
  //my array of values
  int* arrA;

public:
  //constructor & destructor
  maxHeap();
  ~maxHeap();
  //insert function
  void insertA(int newValue);
  //heapifies the heap
  void heapifyA();
  void recursiveHeapifyA(int index);
  //Deletes the min and returns it
  int deleteMinA();
  //deletes the max and returns it
  int deleteMaxA();
  //finds the max
  int findMaxA();
  //finds the min
  int findMinA();
  //prints the levelorder
  void levelOrderA();
};
#endif
