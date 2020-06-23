#include "maxHeap.h"
#include <fstream>
#include<iostream>
#include<cmath>
using namespace std;

maxHeap::maxHeap()
{
  int newData;
  int tracker = 0;
  numElements = 0;
  int myarrAayA[500];
  arrA = myarrAayA;
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
      arrA[tracker] = newData;
      tracker++;
      numElements++;
    }
  }
  while(tracker < 499)
  {
    arrA[tracker] = -1;
    tracker++;
  }
  heapifyA();
}

maxHeap::~maxHeap()
{
  delete(arrA);
}

void maxHeap::insertA(int newValue)
{
  arrA[numElements] = newValue;
  numElements++;
  heapifyA();
}

void maxHeap::heapifyA()
{
  for(int i = 0; i < 1000; i++)
  {
    recursiveHeapifyA(0);
  }
  //levelOrderA();
}

void maxHeap::recursiveHeapifyA(int index)
{
  //cout << "In recursiveHeapify at index: " << index << endl;
  if(arrA[index] == -1)
  {
    return;
  }
  //check all the children
  for(int i = 1; i < 5; i++)
  {
    int myChild = index * 5 + i;
    //cout << myChild << endl;
    if(arrA[myChild] != -1)
    {
      recursiveHeapifyA(myChild);
    }
  }
  //cout << "Past recursive call" << endl;
  int minChild = -100;
  int minChildIndex;
  int child;
  int childIndex;
  //heapify on the parent level
  for(int j = 1; j < 6; j++)
  {
    childIndex = index * 5 + j;
    child = arrA[childIndex];
    if(child == -1)
    {
      break;
    }
    if(child > minChild)
    {
      minChild = child;
      minChildIndex = childIndex;
    }
  }
  int current = arrA[index];
  if(minChild > current)
  {
    //cout << arrA[index] << " is being swapped with " << minChild << endl;
    arrA[index] = minChild;
    arrA[minChildIndex] = current;

  }
}

int maxHeap::deleteMinA()
{
  int maxValue = arrA[0];
  int maxIndex = 0;
  for(int i = 0; i < numElements; i++)
  {
    if(maxValue > arrA[i])
    {
      maxValue = arrA[i];
      maxIndex = i;
    }
  }
  arrA[maxIndex] = arrA[numElements - 1];
  arrA[numElements - 1] = -1;
  numElements--;
  heapifyA();
  return maxValue;
}

int maxHeap::deleteMaxA()
{
  int deletedValue = arrA[0];
  int newIndex = numElements - 1;
  arrA[0] = arrA[newIndex];
  arrA[numElements] = -1;
  numElements--;
  heapifyA();
  return deletedValue;
}

int maxHeap::findMaxA()
{
  return arrA[0];
}

int maxHeap::findMinA()
{
  int minValue = arrA[0];
  for(int i = 0; i < numElements; i++)
  {
    if(minValue > arrA[i])
    {
      minValue = arrA[i];
    }
  }
  return minValue;
}

void maxHeap::levelOrderA()
{
  int tracker = numElements;
  for(int i = 0; i < numElements; i++)
  {
    cout << arrA[i] << " ";
    if(i == 0 || i == 5 || i == 25 || i == 125)
    {
      cout << endl;
    }
  }
  cout << endl;
}
