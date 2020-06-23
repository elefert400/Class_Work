#include "LinkedList.h"
using namespace std;
#ifndef HASHTABLE_H
#define HASHTABLE_H

class hashTable
{
private:
  //the number of buckets
  int mValue;
  //ptr to my array
  LinkedList** tableptr;
  //element value
  int elements;
public:
  //constructor
  hashTable(int size);
  //destructor
  ~hashTable();
  //insert into new place
  void hashInsert(int newValue);
  //delete function
  void hashDelete(int deleteInt);
  //print function
  void hashPrint();
  //hash function
  int hash(int newValue);
  //rehash function
  hashTable* Rehash();
  //search function
  bool find(int value);
  //returns the elements value
  int numElements();
  //returns the mValue
  int numMValue();
};
#endif
