#ifndef MINMAX_H
#define MINMAX_H

class minMax
{
private:
  int numElements;
  int* priority;
  int* time;
  int* names;

public:
  minMax();
  ~minMax();
  void insert(int newValue, int newTime);
  void firstHeap();
  void recursiveFirst(int index);
  void heapify();
  void recursiveHeapify(int index);
  void deleteMin();
  void deleteMax();
  int findMin();
  int findMax();
  void runSchedule();
  void levelOrder();
};
#endif
