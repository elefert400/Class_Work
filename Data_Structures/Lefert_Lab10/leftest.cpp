#include "leftest.h"
#include<iostream>
#include <sstream>
#include <string>

using namespace std;

leftest::leftest()
{
  root = nullptr;
}

leftest::~leftest()
{
  delete(root);
}

void leftest::setRoot(node* node)
{
  root = node;
}

void leftest::insert(int newElement)
{
  node* newNode = new node(newElement);
  if(root == nullptr)
  {
    root = newNode;
  }
  else
  {
    node* mergable = new node(newElement);
    root = merge(root, mergable);
    // node* rootRight = root->getRight();
    // node* rootLeft = root->getLeft();
    // if(rootLeft->calcRank(rootLeft) >= rootRight->calcRank(rootRight))
    // {
    //   root->rotate();
    // }
  }
}

int leftest::deleteMax()
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
  node* rootRight = root->getRight();
  node* rootLeft = root->getLeft();
  // if(rootLeft->calcRank(rootLeft) >= rootRight->calcRank(rootRight))
  // {
  //   root->rotate();
  // }
  return oldMax;
}

int leftest::findMax()
{
  return root->getData();
}

node* leftest::merge(node* h1, node* h2)
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
  if(h1->getLeft() == nullptr)
  {
    h1->rotate();
  }
  if(h1->getLeft()->calcRank(h1->getLeft()) < h1->getRight()->calcRank(h1->getRight()))
  {
    h1->rotate();
  }
  return h1;
}

node* leftest::getRoot()
{
  return root;
}

string leftest::preOrder()
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
void leftest::recursivePre(node* current, stringstream& preStream)
{
  if(current != nullptr)
  {
    preStream << current->getData() << "  ";
    recursivePre(current->getLeft(), preStream);
    recursivePre(current->getRight(), preStream);
  }
}
string leftest::postOrder()
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
void leftest::recursivePost(node* current, stringstream& postStream)
{
  if(current != nullptr)
  {
    recursivePost(current->getLeft(), postStream);
    recursivePost(current->getRight(), postStream);
    postStream << current->getData() << " ";
  }
}
string leftest::inOrder()
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
void leftest::recursiveIn(node* current, stringstream& inStream)
{
  if(current != nullptr)
  {
    recursiveIn(current->getLeft(), inStream);
    inStream << current->getData() << " ";
    recursiveIn(current->getRight(), inStream);
  }
}
void leftest::levelOrder()
{
  int height = root->height(root);
  //cout << "height of the tree: " << height << endl;
  //levelRecusrive(root, height);
  for(int i = 0; i < height + 1; i++)
  {
    levelRecusrive(root,i);
  }
}

void leftest::levelRecusrive(node* rootT, int height)
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
