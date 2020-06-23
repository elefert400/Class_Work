#include <string>
using namespace std;
#ifndef HASHTABLEQUAD_H
#define HASHTABLEQUAD_H

class hashTableQuad
{
private:
  // m value
  int mValue;
  //pointer to the hash table
  int* tablePtr;
  //number of elements
  int elements;

public:
  //constructor
  hashTableQuad(int size);
  //destructor
  ~hashTableQuad();
  //insert
  void quadInsert(int newInt);
  //delete
  void quadDelete(int deleteInt);
  //print function
  void quadPrint();
  //hash function for ints
  int hash(int value);
  //rehashing
  hashTableQuad* quadRehash();
  // find function
  bool quadFind(int findInt);
  //returns lambda value
  double quadLambda();
};
#endif
