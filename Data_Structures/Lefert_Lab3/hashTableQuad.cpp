#include "hashTableQuad.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//constructor
hashTableQuad::hashTableQuad(int size)
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
hashTableQuad::~hashTableQuad()
{}
//inserts
void hashTableQuad::quadInsert(string newString)
{
  //my location in the array
  int hashValue = wordHash(newString);
  //keeps track of how many times I loop
  int loopNum = 1;
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
      hashValue = hash(hashValue + loopNum^2);
      loopNum++;
    }
  }
}

//deletes from the table
void hashTableQuad::quadDelete(string deleteString)
{
  //keeps track of if I deleted the value
  bool deletedIt = false;
  //keeps track of my loops
  int loopNum = 0;
  //holds the has value
  int hashValue = wordHash(deleteString);
  //checks the value is in the table
  if(quadFind(deleteString) == false)
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
void hashTableQuad::quadPrint()
{
  for(int i = 0; i < mValue; i++)
  {
    cout << i << ": " << tablePtr[i] << endl;
  }
}

//hashing words
int hashTableQuad::wordHash(string newString)
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
int hashTableQuad::hash(int value)
{
  return value % mValue;
}

hashTableQuad* hashTableQuad::quadRehash()
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
  hashTableQuad* temp2 = new hashTableQuad(newMValue);
  //temp string to transfer values
  string temp3;
  for(int k = 0; k < mValue; k++)
  {
    if(temp[k].empty() == false)
    {
      temp3 = temp[k];
      temp2->quadInsert(temp3);
    }
  }
  return temp2;
}

//finds if a value is in the hash table
bool hashTableQuad::quadFind(string findString)
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
int hashTableQuad::quadElements()
{
  return elements;
}

//returns m value
int hashTableQuad::quadMValue()
{
  return mValue;
}

//reverses a string
void hashTableQuad::quadReverseString(int location)
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

//returns lambda value
double hashTableQuad::quadLambda()
{
  return double(elements) / mValue;
}

//finds palindromes
void hashTableQuad::quadFindPalindromes()
{
  for(int i = 0; i < mValue; i++)
  {
    if(tablePtr[i] != "")
    {
      //temp string to hold my string
      string forwards = tablePtr[i];
      //temp string to hold the string backwards
      //cout << forwards.length() << endl;
      cout << endl;
      char backwards[forwards.length()];
      for(int k = 0; k < forwards.length(); k++)
      {
        backwards[k] = forwards[forwards.length() - k - 1];
      }
      //string backwardsMore = backwards;
      //cout << tablePtr[i] << endl;
      // cout << "forwards: " << forwards << wordHash(forwards) << endl;
      // cout << "backwards: " << backwards << wordHash(backwards) << endl;
      //cout << "Forwards hash value: " << tablePtr[i] << ": " << wordHash(forwards) << endl;
      //cout << "Backwards hash value: " << tablePtr[i] << ": " << wordHash(backwards) << endl;
       //cout << forwards << ":" << hashTotal(forwards) << endl;
       //cout << backwards << hashTotal(backwards) << endl;
       if(hashTotal(forwards) == hashTotal(backwards))
       {
         cout << forwards << " ";
       }
       //make a new function for hash values
       //cout << "loop number: " << i << endl;
    }
  }
}

//returns hash value
int hashTableQuad::hashTotal(string newString)
{
  // int to keep track of my total
  int total = 0;
  for(int i = 0; i < newString.length() && i < 8; i++)
  {
    total = total + int(newString[i]) * int(pow(10,i));
  }
  return total;
}
