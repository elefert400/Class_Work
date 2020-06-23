#include "minHeap.h"
#include <fstream>
#include<iostream>
#include<cmath>
using namespace std;

minHeap::minHeap()
{
  int newData;
  int tracker = 0;
  numElements = 0;
  int myArray[500];
  arr = myArray;
  ifstream infile;
  infile.open("data.txt");
  if(infile.fail())
  {
    cout << "Error opening file" << endl;
  }
  else
  {
    while(infile>>newData)
    {
      arr[tracker] = newData;
      tracker++;
      numElements++;
    }
  }
  while(tracker < 499)
  {
    arr[tracker] = -1;
    tracker++;
  }
  //cout << "constructor" << endl;
  // for(int i = 0; i < numElements; i ++)
  // {
  //   cout << "array value at: " << i << " " << arr[i] << endl;;
  // }
  //levelOrder();
  heapify();
}

minHeap::~minHeap()
{
  delete(arr);
}

void minHeap::insert(int newValue)
{
  arr[numElements] = newValue;
  numElements++;
  heapify();
}

void minHeap::heapify()
{
  for(int i = 1; i < 10000; i++)
  {
    recursiveHeapify(0);
  }
  //levelOrder();
}

void minHeap::recursiveHeapify(int index)
{
  //cout << "In recursiveHeapify at index: " << index << endl;
  if(arr[index] == -1)
  {
    return;
  }
  //check all the children
  for(int i = 1; i < 5; i++)
  {
    int myChild = index * 5 + i;
    //cout << myChild << endl;
    if(arr[myChild] != -1)
    {
      recursiveHeapify(myChild);
    }
  }
  //cout << "Past recursive call" << endl;
  int minChild = 100000000;
  int minChildIndex;
  int child;
  int childIndex;
  //heapify on the parent level
  for(int j = 1; j < 6; j++)
  {
    childIndex = index * 5 + j;
    child = arr[childIndex];
    if(child == -1)
    {
      break;
    }
    if(child < minChild)
    {
      minChild = child;
      minChildIndex = childIndex;
    }
  }
  int current = arr[index];
  if(minChild < current)
  {
  //  cout << arr[index] << " is being swapped with " << minChild << endl;
    arr[index] = minChild;
    arr[minChildIndex] = current;

  }
}

int minHeap::deleteMin()
{
  int deletedValue = arr[0];
  int newIndex = numElements - 1;
  arr[0] = arr[newIndex];
  arr[numElements] = -1;
  numElements--;
  heapify();
  return deletedValue;
}

int minHeap::deleteMax()
{
  int maxValue = arr[0];
  int maxIndex = 0;
  for(int i = 0; i < numElements; i++)
  {
    if(maxValue < arr[i])
    {
      maxValue = arr[i];
      maxIndex = i;
    }
  }
  arr[maxIndex] = arr[numElements - 1];
  arr[numElements - 1] = -1;
  numElements--;
  heapify();
  return maxValue;
}

int minHeap::findMax()
{
  int maxValue = arr[0];
  for(int i = 0; i < numElements; i++)
  {
    if(maxValue < arr[i])
    {
      maxValue = arr[i];
    }
  }
  return maxValue;
}

int minHeap::findMin()
{
  return arr[0];
}

void minHeap::levelOrder()
{
  int tracker = numElements;
  for(int i = 0; i < numElements; i++)
  {
    cout << arr[i] << " ";
    if(i == 0 || i == 5 || i == 25 || i == 125)
    {
      cout << endl;
    }
  }
  cout << endl;
}
