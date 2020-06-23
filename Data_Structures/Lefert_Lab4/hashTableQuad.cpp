#include "hashTableQuad.h"
#include <iostream>
#include <string>
#include <cmath>
#include<math.h>
using namespace std;
//constructor
hashTableQuad::hashTableQuad(int size)
{
  //setting m value
  mValue = size;
  //setting elements
  elements = 0;
  //making the array
  tablePtr = new int[mValue];
  for(int i = 0; i < mValue; i++)
  {
    tablePtr[i] = -1;
  }
}

//destructor
hashTableQuad::~hashTableQuad()
{}
//inserts
void hashTableQuad::quadInsert(int newInt)
{
  //my location in the array
  int hashValue = hash(newInt);
  //keeps track of how many times I loop
  int loopNum = 1;
  if(quadFind(newInt) == true)
  {
    //cout << "Value already in the table" << endl;
  }
  else
  {
    //keeps track of if the string has been inserted
    bool inserted = false;
    while(inserted == false)
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
        hashValue = hash(hashValue + pow(loopNum, 2));
        loopNum++;
      }
      if(loopNum == 3 * mValue)
      {
        //cout << "Cycling occured, insert failed." << endl;
      }
    }
  }
}

//deletes from the table
void hashTableQuad::quadDelete(int deleteInt)
{
  //keeps track of if I deleted the value
  bool deletedIt = false;
  //keeps track of my loops
  int loopNum = 0;
  //holds the has value
  int hashValue = hash(deleteInt);
  //checks the value is in the table
  if(quadFind(deleteInt) == false)
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
        cout << "Value found and deleted" << endl;
        elements--;
        foundIt = true;
        break;
      }
      loopNum++;
    }
  }
}

//print function
void hashTableQuad::quadPrint()
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
int hashTableQuad::hash(int value)
{
  return value % mValue;
}

hashTableQuad* hashTableQuad::quadRehash()
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
  hashTableQuad* temp2 = new hashTableQuad(newMValue);
  //temp string to transfer values
  int temp3;
  for(int k = 0; k < mValue; k++)
  {
    if(temp[k] == -1)
    {
      temp3 = temp[k];
      temp2->quadInsert(temp3);
    }
  }
  return temp2;
}

//finds if a value is in the hash table
bool hashTableQuad::quadFind(int findInt)
{
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
      hashValue = hash(hashValue + pow(i, 2));
    }
  }
  return false;
}

//returns lambda value
double hashTableQuad::quadLambda()
{
  return double(elements) / mValue;
}
