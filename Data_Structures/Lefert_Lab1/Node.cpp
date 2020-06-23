#include "Node.h"
using namespace std;

  //constructor
  Node::Node(int newValue){
    data = newValue;
  }
  //destructor
  Node::~Node()
  {
    ptrNext = nullptr;
  }
  //sets the data in the node
  void Node::setData(int newValue){
    data = newValue;
  }
  //sets the pointer for the node
  void Node::setPointer(Node* newPtr){
    ptrNext = newPtr;
  }
  //gets the node the pointer is pointing to
  Node* Node::getPointer(){
    return ptrNext;
  }
  //returns the data in the node
  int Node::getData(){
    return data;
  }
