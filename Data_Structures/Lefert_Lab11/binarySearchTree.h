//greater or equal too go right
#include "node.h"
#include <sstream>
#include <string>

using namespace std;
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class binarySearchTree
{
private:
  //pointer to the root node
  node* root = nullptr;
public:
  //constructor
  binarySearchTree();
  //destructor
  ~binarySearchTree();
  //checks if the tree is empty
  bool isEmpty();
  //inserts a new node into the tree
  void insert(int newData);
  //deletes a node from a tree based on the data returns true if it deletes
  bool deleteNode(int data);
  //searches for a node in the tree based on the int passed
  bool find(int findMe);
  //finds the min value in a tree
  int findMin();
  //finds the max value in a tree
  int findMax();
  //prints the tree in preorder
  string preorder();
  void recursivePre(node* current, stringstream& preStream);
  //prints the tree in postorder
  string postorder();
  void recursivePost(node* current, stringstream& postStream);
  //prints the tree in inorder
  string inorder();
  void recursiveIn(node* current, stringstream& inStream);
  //prints the tree in levelorder
  void levelorder();
  void levelRecusrive(node* root, int height);
};
#endif
