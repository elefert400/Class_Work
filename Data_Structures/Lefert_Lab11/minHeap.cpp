#include "minHeap.h"
#include <fstream>
#include<iostream>
#include<cmath>
using namespace std;

minHeap::minHeap(bool test, int testSize)
{
  //cout << "making min" << endl;
  //setting random seed
  srand(time(NULL));
  int mValues = 1000003;
  int newData;
  int loopNum = 0;
  int tracker = 0;
  numElements = 0;
  arr = new int [10000000];
  //cout << "getting to if statements" << endl;
  if(test == true)
  {
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
    while(tracker < 99999)
    {
      arr[tracker] = -1;
      tracker++;
    }
    heapify();
  }
  else
  {
    while(loopNum < testSize)
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        arr[loopNum] = num;
        loopNum++;
        tracker++;
        numElements++;
      //  cout << loopNum << endl;
      }
      while(tracker < 9999999)
      {
        arr[tracker] = -1;
        tracker++;
      }
      heapify();
  }
}

minHeap::~minHeap()
{
  delete(arr);
}

void minHeap::insert(int newValue)
{
  arr[numElements] = newValue;
  numElements++;
  cout << "New Element: " << newValue << " numElements: " << numElements << endl;
  heapify();
}

void minHeap::heapify()
{
  for(int i = 1; i < 2; i++)
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
    if(myChild > 10000000)
    {
      return;
    }
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
