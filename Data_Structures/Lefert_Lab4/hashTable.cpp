#include "hashTable.h"
#include <iostream>

using namespace std;

//constructor
hashTable::hashTable(int size)
{
  //sets the size of the array
  mValue = size;
  //sets elements value to zero
  elements = 0;
  //make my array
  tableptr = new LinkedList*[mValue];
  //making my table and filling it with empty LL
  for(int i = 0; i < mValue; i++)
  {
    tableptr[i] = new LinkedList();
  }
}

//deconstructor
hashTable::~hashTable(){}

//insert function
void hashTable::hashInsert(int newValue)
{
   if(find(newValue) == true)
   {
    //cout << "Value already in table, insert aborted." << endl;
   }
  else
  {
    int hashValue = hash(newValue);
    tableptr[hashValue] -> insert(newValue);
    elements++;
  }
}

//delete a value from the table
void hashTable::hashDelete(int deleteInt)
{
  //value from my hashing function
  int hashValue = hash(deleteInt);
  // checking if the value is in the hash table
  bool amIHere = find(deleteInt);
  if(amIHere == true)
  {
    tableptr[hashValue] -> mdelete(deleteInt);
    elements--;
    //cout << "Value found and deleted" << endl;
  }
  else
  {
    //cout << "Value not in the hash table." << endl;
  }
}

//print the table
void hashTable::hashPrint()
{
  //cout << mValue << endl;
  for(int i = 0; i < mValue; i++)
  {
    cout << i << ": ->";
    tableptr[i] -> print();
  }
}

//computes the hash and returns it
int hashTable::hash(int newValue)
{
  return newValue % mValue;
}

//rehash function
hashTable* hashTable::Rehash()
{
  // temp linked list to hold all my old values
  LinkedList temp;

  //loops through the elements of the hash table
  for(int i = 0; i < mValue; i++)
  {
    int currentArrayIndexSize = tableptr[i] -> getNodes();
    //loops through the list in the linked list at the hash table spot we are at
    for(int k = 0; k < currentArrayIndexSize; k++)
    {
      int nextValue = tableptr[i] -> frontValue();
      temp.insert(nextValue);
    }
  }
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
        //cout << "in if for new m" << endl;
        isPrime = false;
        break;
      }
    }
    //  newMValue++;
      cout << newMValue << endl;
  }
  hashTable* newHash = new hashTable(newMValue);
  while(temp.getNodes() != 0)
  {
    newHash -> hashInsert(temp.frontValue());
  }
  newHash -> hashPrint();
  return newHash;
}

//search function
bool hashTable::find(int value)
{
  // finds hash value
  int hashValue = hash(value);
  bool foundIt = tableptr[hashValue] -> findValue(value);
  return foundIt;
}

//returns number of elements
int hashTable::numElements()
{
  return elements;
}

// returns the m value
int hashTable::numMValue()
{
  return mValue;
}
