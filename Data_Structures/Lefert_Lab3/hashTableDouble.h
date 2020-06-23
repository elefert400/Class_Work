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
  string* tablePtr;
  //number of elements
  int elements;
  //R value for double hashing
  int R = 5;

public:
  //constructor
  hashTableDouble(int size);
  //destructor
  ~hashTableDouble();
  //insert
  void doubleInsert(string newString);
  //delete
  void doubleDelete(string deleteString);
  //print function
  void doublePrint();
  //hash function for strings
  int wordHash(string newString);
  //hash function for ints
  int hash(int value);
  //rehashing
  hashTableDouble* doubleRehash();
  // find function
  bool doubleFind(string findString);
  // returns number of elements
  int doubleElements();
  //returns m value
  int doubleMValue();
  //returns lambda value
  double doubleLambda();
  //reverses a string at a location
  void doubleReverseString(int location);
};
#endif
