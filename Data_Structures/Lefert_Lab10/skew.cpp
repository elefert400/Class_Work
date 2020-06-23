#include "skew.h"
#include<iostream>
#include <sstream>
#include <string>

using namespace std;

skew::skew()
{
  root = nullptr;
}

skew::~skew()
{
  delete(root);
}

void skew::setRoot(node* newRoot)
{
  root = newRoot;
}

void skew::insert(int newData)
{
  node* insertVal = new node(newData);
  if(root == nullptr)
  {
    root = insertVal;
  }
  else
  {
    root = merge(root, insertVal);
  }
}

int skew::deleteMax()
{
  int oldMax = root->getData();
  node* right = root->getRight();
  node* left = root->getLeft();
  if(left == nullptr && right == nullptr)
  {
    root = nullptr;
    return oldMax;
  }
  root = merge(left, right);
  return oldMax;
}

int skew::findMax()
{
  return root->getData();
}

node* skew::merge(node* h1, node* h2)
{
  if(h1 == nullptr)
  {
    return h2;
  }
  if(h2 == nullptr)
  {
    return h1;
  }

  if(h1->getData() < h2->getData())
  {
    return merge(h2, h1);
  }

  h1->setRight(merge(h1->getRight(), h2));
  h1->rotate();
  return h1;
}

node* skew::getRoot()
{
  return root;
}

string skew::preOrder()
{
  stringstream preStream;
  recursivePre(root, preStream);
  string temp;
  string holder;
  while(preStream >> holder)
  {
    temp += holder;
    temp += " ";
  }
  return temp;
}
void skew::recursivePre(node* current, stringstream& preStream)
{
  if(current != nullptr)
  {
    preStream << current->getData() << "  ";
    recursivePre(current->getLeft(), preStream);
    recursivePre(current->getRight(), preStream);
  }
}
string skew::postOrder()
{
  stringstream postStream;
  recursivePost(root, postStream);
  string temp;
  string holder;
  while(postStream >> holder)
  {
    temp += holder;
    temp += " ";
  }
  return temp;
}
void skew::recursivePost(node* current, stringstream& postStream)
{
  if(current != nullptr)
  {
    recursivePost(current->getLeft(), postStream);
    recursivePost(current->getRight(), postStream);
    postStream << current->getData() << " ";
  }
}
string skew::inOrder()
{
  stringstream inStream;
  recursiveIn(root, inStream);
  string temp;
  string holder;
  while(inStream >> holder)
  {
    temp += holder;
    temp += " ";
  }
  return temp;
}
void skew::recursiveIn(node* current, stringstream& inStream)
{
  if(current != nullptr)
  {
    recursiveIn(current->getLeft(), inStream);
    inStream << current->getData() << " ";
    recursiveIn(current->getRight(), inStream);
  }
}
void skew::levelOrder()
{
  int height = root->height(root);
  //cout << "height of the tree: " << height << endl;
  //levelRecusrive(root, height);
  for(int i = 0; i < height + 1; i++)
  {
    levelRecusrive(root,i);
  }
}

void skew::levelRecusrive(node* rootT, int height)
{
  if(rootT == nullptr)
  {
    return;
  }
  if(height == 1)
  {
    cout << rootT->getData() << " ";
  }
  if(rootT->getRight() == nullptr && rootT->getLeft() == nullptr)
  {
    return;
  }
  else if(height > 1)
  {
    levelRecusrive(rootT->getLeft(), height - 1);
    levelRecusrive(rootT->getRight(), height - 1);
  }
}
