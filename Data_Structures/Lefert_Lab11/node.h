using namespace std;
#ifndef NODE_H
#define NODE_H

class node
{
private:
  //the data in the node
  int data;
  //pointers to left and right child
  node* leftPtr;
  node* rightPtr;

public:
  //constructor
  node(int newData);
  //destructor
  ~node();
  // sets leftPtr
  void newLeftPtr(int left);
  //sets right pointer
  void newRightPtr(int right);
  //returns data value
  int getData();
  //returns leftPtr
  node* getLeftPtr();
  //returns rightPtr
  node* getRightPtr();
  //sets pointer = nullptr
  void nullRight();
  void nullLeft();
  //sets the right and left pointers
  void setLeftPtr(node* newNode);
  void setRightPtr(node* newNode);

  //calculates the height of the node
  int height(node* node);

  void setData(int newData);
};
#endif
