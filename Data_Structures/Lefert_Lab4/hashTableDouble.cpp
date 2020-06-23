#include "hashTableDouble.h"
#include <iostream>
#include <string>
#include <cmath>
#include<math.h>
using namespace std;
//constructor
hashTableDouble::hashTableDouble(int size, int newR)
{
  //setting m value
  mValue = size;
  //setting elements
  elements = 0;
  R = newR;
  //making the array
  tablePtr = new int[mValue];
  for(int i = 0; i < mValue; i++)
  {
    tablePtr[i] = -1;
  }
}

//destructor
hashTableDouble::~hashTableDouble()
{}
//inserts
void hashTableDouble::doubleInsert(int newInt)
{
  //my location in the array
  int hashValue = hash(newInt);
  //keeps track of how many times I loop
  int loopNum = 1;
  // keeps track of my h+ value
  int hValue = R - (newInt % R);
  if(doubleFind(newInt) == true)
  {
    //cout << "Value already in the table." << endl;
  }
  else
  {
    //keeps track of if the string has been inserted
    bool inserted = false;
    while(inserted == false && loopNum < mValue)
    {
      //checks if the array spot is empty
      if(tablePtr[hashValue] == -1)
      {
        tablePtr[hashValue] = newInt;
        inserted = true;
        elements++;
        //cout << newInt << " has been inserted." << endl;
      }
      else
      {
        hashValue = hash(hashValue + loopNum * hValue);
        loopNum++;
      }
    }
    if(loopNum == mValue)
    {
      //cout << "Cycling occured, insert failed." << endl;
    }
  }
}

//deletes from the table
void hashTableDouble::doubleDelete(int deleteInt)
{
  //keeps track of if I deleted the value
  bool deletedIt = false;
  //keeps track of my loops
  int loopNum = 0;
  //holds the has value
  int hashValue = hash(deleteInt);
  //checks the value is in the table
  if(doubleFind(deleteInt) == false)
  {
    //cout << "Value not in the table" << endl;
  }
  else
  {
    bool foundIt = false;
    while(foundIt == false && loopNum < mValue - 1)
    {
      if(tablePtr[loopNum] == deleteInt)
      {
        tablePtr[loopNum] = -1;
        //cout << "Value found and deleted" << endl;
        elements--;
        foundIt = true;
        break;
      }
      loopNum++;
    }
  }
}

//print function
void hashTableDouble::doublePrint()
{
  for(int i = 0; i < mValue; i++)
  {
    cout << i << ": ";
    if(tablePtr[i] == -1)
    {
      cout << endl;
    }
    else
    {
      cout << tablePtr[i] << endl;
    }
  }
}

//hashing numbers
int hashTableDouble::hash(int value)
{
  return value % mValue;
}

hashTableDouble* hashTableDouble::doubleRehash()
{
  //temp array to hold old values
  int temp[mValue];
  for(int i = 0; i < mValue; i++)
  {
    if(tablePtr[i] == -1)
    {
      temp[i] = tablePtr[i];
    }
  }
  //calculated new m value
  int newMValue = mValue * 2;
  bool isPrime = false;
  //check new m value is prime and adds 1 if not prime
  while(isPrime == false)
  {
    isPrime = true;
    newMValue++;
    for(int w = 2; w < newMValue; w++)
    {
      if(newMValue % w == 0)
      {
        isPrime = false;
        break;
      }
    }
  }
  //new hash table
  hashTableDouble* temp2 = new hashTableDouble(newMValue, R);
  //temp string to transfer values
  int temp3;
  for(int k = 0; k < mValue; k++)
  {
    if(temp[k] == -1)
    {
      temp3 = temp[k];
      temp2->doubleInsert(temp3);
    }
  }
  return temp2;
}

//finds if a value is in the hash table
bool hashTableDouble::doubleFind(int findInt)
{
  int hValue = R - (findInt % R);
  int hashValue = hash(findInt);
  for(int i = 0; i < 21; i++)
  {
    if(tablePtr[hashValue] == findInt)
    {
      //cout << "Found " << findInt << " at location " << i << endl;
      return true;
    }
    else
    {
      hashValue = hash(hashValue + i * hValue);
    }
  }
  return false;
}

double hashTableDouble::doubleLambda()
{
  return double(elements) / mValue;
}
