#include"node.h"
using namespace std;
#ifndef TWOTHREETREE_H
#define TWOTHREETREE_H

class twoThreeTree
{
private:
  bool isBalanced;
  node* root;
public:
  //constructor, destructor
  twoThreeTree();
  ~twoThreeTree();
  //inserts a new data element
  void insert(char newData);
  //helper functions for insert
  void threeNodeKickUp(node* parent, node* current);
  void threeNodeBreakUp(node* current, node* kickUpNode);
  //deletes a character from the tree
  void mdelete(char newData);
  //deletes the min value
  void deleteMin();
  //deletes the max value
  void deleteMax();
  //find a value in the tree
  bool find(char findMe);
  //finds the min
  char findMin();
  //finds the max
  char findMax();
  //gets the level order
  void levelorder();
  //helper function for level order
  void levelRecusrive(node* rootT, int height);
};
#endif
