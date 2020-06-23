#include <string>
using namespace std;
#ifndef HASHTABLEDOUBLE_H
#define HASHTABLEDOUBLE_H

class hashTableDouble
{
private:
  // m value
  int mValue;
  //pointer to the hash table
  int* tablePtr;
  //number of elements
  int elements;
  //R value for double hashing
  int R;

public:
  //constructor
  hashTableDouble(int size, int newR);
  //destructor
  ~hashTableDouble();
  //insert
  void doubleInsert(int newInt);
  //delete
  void doubleDelete(int deleteInt);
  //print function
  void doublePrint();
  //hash function for ints
  int hash(int value);
  //rehashing
  hashTableDouble* doubleRehash();
  // find function
  bool doubleFind(int findInt);
  //returns lambda value
  double doubleLambda();
};
#endif
