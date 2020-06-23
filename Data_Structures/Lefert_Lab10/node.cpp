#include "node.h"
using namespace std;

node::node(int newData)
{
  rank = 1;
  data = newData;
  left = nullptr;
  right = nullptr;
}

node::~node()
{
  delete(left);
  delete(right);
}

int node::calcRank(node* mNode)
{
  if (mNode == nullptr)
  {
    return 0;
  }
  else
    {
        int leftheight = calcRank(mNode->left);
        int rightheight = calcRank(mNode->right);
        if (leftheight < rightheight)
        {
          return ++leftheight;
        }
        else
        {
          return ++rightheight;
        }
    }
}

void node::rotate()
{
  node* oldRight = right;
  node* oldLeft = left;
  right = oldLeft;
  left = oldRight;
}

node* node::getRight()
{
  return right;
}

node* node::getLeft()
{
  return left;
}

int node::getData()
{
  return data;
}

void node::setRight(node* newNode)
{
  right = newNode;
}

void node::setLeft(node* newNode)
{
  left = newNode;
}

int node::height(node* node)
{
  if (node == nullptr)
  {
    return 0;
  }
  else
    {
        int leftheight = height(node->left);
        int rightheight = height(node->right);
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
