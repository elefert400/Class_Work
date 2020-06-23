using namespace std;
#ifndef NODE_H
#define NODE_H

class node
{
private:
  //boolean to control if it is a two node
  bool TwoNode;
  //boolean to control if it is a three node
  bool ThreeNode;
  //pointers to other nodes
  node* leftChild;
  node* rightChild;
  node* middleChild;
  //array of data chars
  char data[3];
  //height of the node
  int m_height;
  //pointer to the parent of the node
  node* parent;
  //pointers to left middle and right middle for kickups


public:
  node(char newData, node* m_parent);
  ~node();
  //returns data array

  //inserts data in the array
  void setData(char newData);
  // returns true if the data array is full
  bool dataFull();
  //returns the left node
  node* getLeft();
  //returns the right node
  node* getRight();
  //returns middle
  node* getMid();
  //calculates the height
  int height(node* node);
  //returns true if a two node
  bool isTwoNode();
  //returns true if a three node;
  bool isThreeNode();
  //returns the height
  int getHeight();
  //returns the min value of the node
  char getMin();
  //returns the max value
  char getMax();
  //returns the kick up value and deletes it
  char kickUp();
  //sets mid ptr
  void setMid(node* newMid);
  //sets left ptr
  void setLeft(node* newLeft);
  //sets right ptr
  void setRight(node* newRight);
  //returns the parent node
  node* getParent();
};
#endif
