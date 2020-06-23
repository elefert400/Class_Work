#include"node.h"
#include <string>
#include <sstream>

using namespace std;
#ifndef LEFTEST_H
#define LEFTEST_H

class leftest
{
private:
  node* root;

public:
  leftest();
  ~leftest();
  void setRoot(node* node);
  void insert(int newElement);
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
  void levelRecusrive(node* root, int height);
};
#endif
