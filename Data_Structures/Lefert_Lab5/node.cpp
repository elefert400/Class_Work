#include "node.h"
using namespace std;

//constructor
node::node(int newData)
{
  //setting the data in the node
  data = newData;
  leftPtr = nullptr;
  rightPtr = nullptr;
}
//destructor
node::~node()
{}
//sets leftPtr
void node::newLeftPtr(int left)
{
  //setting leftPtr to the node* passed in
  leftPtr = new node(left);
}
//sets rightPtr
void node::newRightPtr(int right)
{
  //setting rightPtr to the node* passed in
  rightPtr = new node(right);
}
//returns the data in the node
int node::getData()
{
  return data;
}
//returns left pointer
node* node::getLeftPtr()
{
  return leftPtr;
}
//returns right pointer
node* node::getRightPtr()
{
  return rightPtr;
}

//sets pointer to nullptr
void node::nullRight()
{
  rightPtr = nullptr;
}
void node::nullLeft()
{
  leftPtr = nullptr;
}

void node::setLeftPtr(node* newNode)
{
  leftPtr = newNode;
}
void node::setRightPtr(node* newNode)
{
  rightPtr = newNode;
}

int node::height(node* node)
{
  if (node == nullptr)
  {
    return 0;
  }
  else
    {
        int leftheight = height(node->leftPtr);
        int rightheight = height(node->rightPtr);
        if (leftheight > rightheight)
        {
          return ++leftheight;
        }
        else
        {
          return ++rightheight;
        }
    }
}

void node::setData(int newData)
{
  data = newData;
}
