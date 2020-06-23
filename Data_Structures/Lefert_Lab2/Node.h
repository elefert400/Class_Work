//node class for holding my data and a pointer to the next node.
#ifndef NODE_H
#define NODE_H
using namespace std;

class Node{
private:
  // the integar data
  int data;
  //pointer to the next node
  Node* ptrNext = nullptr;
public:
  //constructor
  Node(int newValue);
  //destructor
  ~Node();
  //set the data
  void setData(int newData);
  //set the pointer
  void setPointer(Node* newNode);
  //returns the pointer next
  Node* getPointer();
  //returns the data
  int getData();
};
#endif
