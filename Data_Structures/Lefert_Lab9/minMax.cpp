#include "minMax.h"
#include<fstream>
#include<iostream>
#include<cmath>
#include<string>
using namespace std;

minMax::minMax()
{
    int firstInt;
    char comma;
    char parethesis;
    int secondInt;
    int tracker = 1;
    numElements = 0;
    int priorityArr[500];
    int timeArr[500];
    priority = priorityArr;
    time = timeArr;
    int name[500];
    names = name;


    ifstream infile;
    infile.open("data.txt");
    if(infile.fail())
    {
      cout << "Error opening file" << endl;
    }
    else
    {
      while(infile>>parethesis>>firstInt>>comma>>secondInt>>parethesis>>comma)
      {
        priority[tracker] = firstInt;
        time[tracker] = secondInt;
        names[tracker] = tracker;
        tracker++;
        numElements++;

      }
    while(tracker < 499)
    {
      priority[tracker] = -1;
      names[tracker] = -1;
      time[tracker] = -1;
      tracker++;
    }
    levelOrder();
    firstHeap();
}
}

minMax::~minMax()
{
  delete(priority);
  delete(time);
  delete(names);
}

void minMax::insert(int newPriority, int newTime)
{
  names[numElements] = numElements;
  time[numElements] = newTime;
  priority[numElements] = newPriority;
  numElements++;
  firstHeap();
}

void minMax::firstHeap()
{
  recursiveFirst(1);
  heapify();
}

void minMax::recursiveFirst(int index)
{
  if(priority[index] == -1)
  {
    return;
  }
  for(int i = 1; i < 5; i++)
  {
    int myChild = index * 5 + i;
    if(priority[myChild] != -1)
    {
      recursiveFirst(myChild);
    }
  }
  int minMaxChild, minMaxChildIndex, child, childIndex;
  int floorValue = floor(log(index));
  if(floorValue % 2 == 0)
  {
    minMaxChild = 100000000;
    for(int j = 1; j < 2; j++)
  {
    childIndex = index * 5 + j;
    child = priority[childIndex];
    if(child == -1)
    {
      break;
    }
    if(child < minMaxChild)
    {
      minMaxChild = child;
      minMaxChildIndex = childIndex;
    }
    if(child == minMaxChild)
    {
      if(time[childIndex] < time[index])
      {
        minMaxChild = child;
        minMaxChildIndex = childIndex;
      }
    }
  }
  int currentPriority = priority[index];
  int currentTime = time[index];
  int currentName = names[index];
  if(minMaxChild < currentPriority)
  {
    cout << "First heap making a switch" << endl;
    priority[index] = minMaxChild;
    time[index] = time[minMaxChildIndex];
    names[index] = names[minMaxChildIndex];

    priority[minMaxChildIndex] = currentPriority;
    time[minMaxChildIndex] = currentTime;
    names[minMaxChildIndex] = currentName;
  }
  if(minMaxChild == currentPriority)
  {
    if(time[minMaxChildIndex] < currentTime)
    {
      priority[index] = minMaxChild;
      time[index] = time[minMaxChildIndex];
      names[index] = names[minMaxChildIndex];

      priority[minMaxChildIndex] = currentPriority;
      time[minMaxChildIndex] = currentTime;
      names[minMaxChildIndex] = currentName;
    }
  }
  }//end even case
  else
  {
    minMaxChild = -2;
    for(int j = 1; j < 2; j++)
  {
    childIndex = index * 2 + j;
    child = priority[childIndex];
    if(child == -1)
    {
      break;
    }
    if(child > minMaxChild)
    {
      minMaxChild = child;
      minMaxChildIndex = childIndex;
    }
    if(child == minMaxChild)
    {
      if(time[childIndex] > time[index])
      {
        minMaxChild = child;
        minMaxChildIndex = childIndex;
      }
    }
  }
  int currentPriority = priority[index];
  int currentTime = time[index];
  int currentName = names[index];
  if(minMaxChild > currentPriority)
  {
  //  cout << arr[index] << " is being swapped with " << minChild << endl;
    priority[index] = minMaxChild;
    time[index] = time[minMaxChildIndex];
    names[index] = names[minMaxChildIndex];

    priority[minMaxChildIndex] = currentPriority;
    time[minMaxChildIndex] = currentTime;
    names[minMaxChildIndex] = currentName;
  }
  if(minMaxChild == currentPriority)
  {
    if(time[minMaxChildIndex] > currentTime)
    {
      priority[index] = minMaxChild;
      time[index] = time[minMaxChildIndex];
      names[index] = names[minMaxChildIndex];

      priority[minMaxChildIndex] = currentPriority;
      time[minMaxChildIndex] = currentTime;
      names[minMaxChildIndex] = currentName;
    }
  }
  }//end odd case
}

void minMax::heapify()
{
  for(int i = 0; i < 2; i++)
  {
    recursiveHeapify(1);
  }
  levelOrder();
}

void minMax::recursiveHeapify(int index)
{
    if(priority[index] == -1)
    {
      return;
    }
    //calls it for its children
    for(int i = 1; i < 2; i++)
    {
      int myChild = index * 2 + i;
      recursiveHeapify(myChild);
    }

    int floorValue;
    if(floorValue % 2 == 0)
    {
      int minPriority = 100;
      int minTime = 100;
      int minName;
      int minIndex;

      for(int k = numElements; k > 0; k--)
      {
        floorValue = floor(log(k / 4));
        floorValue++;
        // if(index == 1)
        // {
        //   cout << floorValue  << ", " << index << endl;
        // }
        if(floorValue == index)
        {
          //cout << "In if" << endl;
          if(priority[k] < minPriority)
          {
            minPriority = priority[k];
            minTime = time[k];
            minIndex = k;
            minName = names[k];
          }
          if(priority[k] == minPriority)
          {
            if(time[k] < minTime)
            {
              minPriority = priority[k];
              minTime = time[k];
              minIndex = k;
              minName = names[k];
            }
          }
        }
      }
      int currentTime = time[index];
      int currentName = names[index];
      int currentPriority = priority[index];
      //cout << "even case" << minPriority << " " << currentPriority << endl;
      if(minPriority < currentPriority)
      {
        cout << "Making a swap" << endl;
        priority[index] = minPriority;
        time[index] = minTime;
        names[index] = minName;
        priority[numElements] = currentPriority;
        time[numElements] = currentTime;
        names[numElements] = currentName;
      }
      if(minPriority == currentPriority)
      {
        if(minTime < currentTime)
        {
          cout << "Making a swap" << endl;
          priority[index] = minPriority;
          time[index] = minTime;
          names[index] = minName;
          priority[numElements] = currentPriority;
          time[numElements] = currentTime;
          names[numElements] = currentName;
        }
      }
    }//end even case
    else
    {
      int maxPriority = -2;
      int maxTime = -100;
      int maxName;
      int maxIndex;
      for(int k = numElements; k > 0; k--)
      {
        floorValue = floor(log(k / 4));
        floorValue++;
        //cout << floorValue  << ", " << index << endl;
        // if(index == 1)
        // {
        //   cout << floorValue  << ", " << index << endl;
        // }
        if(floorValue == index)
        {
          if(priority[k] > maxPriority)
          {
            maxPriority = priority[k];
            maxTime = time[k];
            maxIndex = k;
            maxName = names[k];
          }
          if(priority[k] == maxPriority)
          {
            if(time[k] > maxTime)
            {
              maxPriority = priority[k];
              maxTime = time[k];
              maxIndex = k;
              maxName = names[k];
            }
          }
        }
      }
      int currentTime = time[index];
      int currentName = names[index];
      int currentPriority = priority[index];
      //cout << "odd case" << maxPriority << " " << currentPriority << endl;
      if(maxPriority > currentPriority)
      {
        cout << "Making a swap" << endl;
        priority[index] = maxPriority;
        time[index] = maxTime;
        names[index] = maxName;
        priority[numElements] = currentPriority;
        time[numElements] = currentTime;
        names[numElements] = currentName;
      }
      if(maxPriority == currentPriority)
      {
        if(maxTime > currentTime)
        {
          cout << "Making a swap" << endl;
          priority[index] = maxPriority;
          time[index] = maxTime;
          names[index] = maxName;
          priority[numElements] = currentPriority;
          time[numElements] = currentTime;
          names[numElements] = currentName;
        }
      }
    }//end odd case
}

void minMax::deleteMin()
{
  names[1] = names[numElements];
  time[1] = time[numElements];
  priority[1] = priority[numElements];
  names[numElements] = -1;
  time[1] = -1;
  priority[1] = -1;
  numElements--;
  firstHeap();
}

void minMax::deleteMax()
{
  if(priority[2] > priority[3])
  {
    priority[2] = priority[numElements];
    time[2] = time[numElements];
    names[2] = names[numElements];
    numElements--;
    firstHeap();
  }
  else if(priority[2] < priority[3])
  {
    priority[3] = priority[numElements];
    time[3] = time[numElements];
    names[3] = names[numElements];
    numElements--;
    firstHeap();
  }
  else
  {
    if(time[2] > time[3])
    {
      priority[2] = priority[numElements];
      time[2] = time[numElements];
      names[2] = names[numElements];
      numElements--;
      firstHeap();
    }
    else
    {
      priority[3] = priority[numElements];
      time[3] = time[numElements];
      names[3] = names[numElements];
      numElements--;
      firstHeap();
    }
  }
}

int minMax::findMin()
{
  cout << "P" << names[1] << " (" << priority[1] << "," << time[1] << ")" << endl;
}

int minMax::findMax()
{
  if(priority[2] > priority[3])
  {
    cout << "P" << names[2] << " (" << priority[2] << "," << time[2] << ")" << endl;
  }
  else if(priority[2] < priority[3])
  {
    cout << "P" << names[3] << " (" << priority[3] << "," << time[3] << ")" << endl;
  }
  else
  {
    if(time[2] > time[3])
    {
      cout << "P" << names[2] << " (" << priority[2] << "," << time[2] << ")" << endl;
    }
    else
    {
      cout << "P" << names[3] << " (" << priority[3] << "," << time[3] << ")" << endl;
    }
  }
}

void minMax::runSchedule()
{

}

void minMax::levelOrder()
{
  int tracker = numElements;
  for(int i = 1; i < numElements + 1; i++)
  {
    cout << "P" << names[i] << " ( " << priority[i] << ", " << time[i] << ")";
    if(i == 1 || i == 3 || i == 7 || i == 25 || i == 33)
    {
      cout << endl;
    }
  }
  cout << endl;
}
