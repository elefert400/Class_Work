#include "hashTableDouble.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//constructor
hashTableDouble::hashTableDouble(int size)
{
  //setting m value
  mValue = size;
  //setting elements
  elements = 0;
  //making the array
  tablePtr = new string[mValue];
  for(int i = 0; i < mValue; i++)
  {
    tablePtr[i] = "";
  }
}

//destructor
hashTableDouble::~hashTableDouble()
{}
//inserts
void hashTableDouble::doubleInsert(string newString)
{
  //my location in the array
  int hashValue = wordHash(newString);
  //keeps track of how many times I loop
  int loopNum = 1;
  // keeps track of my h+ value
  int hValue = R - hashValue;
  //keeps track of if the string has been inserted
  bool inserted = false;
  while(inserted == false && loopNum < mValue)
  {
    //checks if the array spot is empty
    if(tablePtr[hashValue].empty() == true)
    {
      tablePtr[hashValue] = newString;
      inserted = true;
      elements++;
      cout << newString << " has been inserted." << endl;
    }
    else
    {
      hashValue = hash(hashValue + loopNum * hValue);
      loopNum++;
    }
  }
  if(loopNum == mValue)
  {
    cout << "Cycling occured, insert failed." << endl;
  }
}

//deletes from the table
void hashTableDouble::doubleDelete(string deleteString)
{
  //keeps track of if I deleted the value
  bool deletedIt = false;
  //keeps track of my loops
  int loopNum = 0;
  //holds the has value
  int hashValue = wordHash(deleteString);
  //checks the value is in the table
  if(doubleFind(deleteString) == false)
  {
    cout << "Value not in the table" << endl;
  }
  else
  {
    bool foundIt = false;
    while(foundIt == false && loopNum < mValue - 1)
    {
      if(tablePtr[loopNum] == deleteString)
      {
        tablePtr[loopNum] = "";
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
void hashTableDouble::doublePrint()
{
  for(int i = 0; i < mValue; i++)
  {
    cout << i << ": " << tablePtr[i] << endl;
  }
}

//hashing words
int hashTableDouble::wordHash(string newString)
{
  // int to keep track of my total
  int total = 0;
  for(int i = 0; i < 8; i++)
  {
    total = total + int(newString[i]) * int(pow(10,i));
  }
  return total % mValue;
}

//hashing numbers
int hashTableDouble::hash(int value)
{
  return value % mValue;
}

hashTableDouble* hashTableDouble::doubleRehash()
{
  //temp array to hold old values
  string temp[mValue];
  for(int i = 0; i < mValue; i++)
  {
    if(tablePtr[i].empty() == false)
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
  hashTableDouble* temp2 = new hashTableDouble(newMValue);
  //temp string to transfer values
  string temp3;
  for(int k = 0; k < mValue; k++)
  {
    if(temp[k].empty() == false)
    {
      temp3 = temp[k];
      temp2->doubleInsert(temp3);
    }
  }
  return temp2;
}

//finds if a value is in the hash table
bool hashTableDouble::doubleFind(string findString)
{
  for(int i = 0; i < mValue - 1; i++)
  {
    if(tablePtr[i] == findString)
    {
      cout << "Found " << findString << " at location " << i << endl;
      return true;
    }
  }
  return false;
}

//returns elements
int hashTableDouble::doubleElements()
{
  return elements;
}

//returns m value
int hashTableDouble::doubleMValue()
{
  return mValue;
}

void hashTableDouble::doubleReverseString(int location)
{
  if(tablePtr[location].empty() == true)
  {
    cout << "Location empty try again" << endl;
  }
  else
  {
    //temp string to hold my string
    string forwards = tablePtr[location];
    //temp string to hold the string backwards
    char backwards[forwards.length()];
    for(int i = 0; i < forwards.length(); i++)
    {
      backwards[i] = forwards[forwards.length() - i - 1];
    }
    tablePtr[location] = backwards;
  }
}

double hashTableDouble::doubleLambda()
{
  return double(elements) / mValue;
}
