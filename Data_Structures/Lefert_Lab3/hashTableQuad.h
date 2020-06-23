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
  string* tablePtr;
  //number of elements
  int elements;

public:
  //constructor
  hashTableQuad(int size);
  //destructor
  ~hashTableQuad();
  //insert
  void quadInsert(string newString);
  //delete
  void quadDelete(string deleteString);
  //print function
  void quadPrint();
  //hash function
  int wordHash(string newString);
  //hash function for ints
  int hash(int value);
  //rehashing
  hashTableQuad* quadRehash();
  // find function
  bool quadFind(string findString);
  // returns number of elements
  int quadElements();
  //returns m value
  int quadMValue();
  //returns lambda value
  double quadLambda();
  //reverses a string at a location
  void quadReverseString(int location);
  // finds all the palindromes
  void quadFindPalindromes();
  //gives the sum value
  int hashTotal(string newString);
};
#endif
