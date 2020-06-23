#include "node.h"
#include <string>
#include <sstream>

using namespace std;
#ifndef SKEW_H
#define SKEW_H

class skew
{
private:
  node* root;

public:
  skew();
  ~skew();
  void setRoot(node* newRoot);
  void insert(int newData);
  int deleteMax();
  int findMax();
  node* merge(node* h1, node* h2);
  node* getRoot();
  string preOrder();
  void recursivePre(node* current, stringstream& preStream);
  string inOrder();
  void recursiveIn(node* current, stringstream& inStream);
  string postOrder();
  void recursivePost(node* current, stringstream& postStream);
  void levelOrder();
  void levelRecusrive(node* rootT, int height);
};
#endif
