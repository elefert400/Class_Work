using namespace std;
#ifndef NODE_H
#define NODE_H

class node
{
private:
  node* right;
  node* left;
  int rank;
  int data;

public:
  node(int newData);
  ~node();
  int calcRank(node* mNode);
  void rotate();
  node* getRight();
  node* getLeft();
  int getData();
  void setRight(node* newNode);
  void setLeft(node* newNode);
  int height(node* node);
};
#endif
