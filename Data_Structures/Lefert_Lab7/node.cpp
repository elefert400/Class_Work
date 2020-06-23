#include "node.h"
#include <iostream>
using namespace std;

node::node(char newData, node* parentPtr)
{
  //setting up the node as if it has no children
  //cout << "new node: " << newData << endl;
  parent = parentPtr;
  data[0] = newData;
  data[1] = ' ';
  data[2] = ' ';
  leftChild = nullptr;
  rightChild = nullptr;
  middleChild = nullptr;
  TwoNode = true;
  ThreeNode = false;
}

node::~node(){}

void node::setData(char newData)
{
  if(ThreeNode == true)
  {
    //cout << "Inserting into a three node" << endl;
    //cout << "Current three node: " << data[0] << " " << data[1] << endl;
    if(data[0] > newData)
    {
      data[2] = data[1];
      data[1] = data[0];
      data[0] = newData;
    }
    else if(data[1] < newData)
    {
      data[2] = newData;
    }
    else
    {
      data[2] = data[1];
      data[1] = newData;
    }
  }
  else
  {
    //cout << "Inserting into a two node." << endl;
    //cout << "Current two node: " << data[0] << endl;
    if(newData < data[0])
    {
      data[2] = data[1];
      data[1] = data[0];
      data[0] = newData;
      TwoNode = false;
      ThreeNode = true;
    }
    else
    {
      data[2] = data[1];
      data[1] = newData;
      TwoNode = false;
      ThreeNode = true;
    }
  }//end insert for a two node
}

bool node::dataFull()
{
  if(data[0] != ' ')
  {
    if(data[1] != ' ')
    {
      if(data[2] != ' ')
      {
        return true;
      }//check data[2]
      else
      {
        return false;
      }//check data[2]
    }//check data[1]
    else
    {
      return false;
    }//check data[1]
  }//check data[0]
  else
  {
    return false;
  }//check data[0]
}

node* node::getLeft()
{
  return leftChild;
}

node* node::getRight()
{
  return rightChild;
}

node* node::getMid()
{
  return middleChild;
}

int node::height(node* node)
{
  if(node == nullptr)
  {
    m_height = 0;
    return 0;
  }
  else
  {
    if(TwoNode == true)
    {
      int leftheight = height(node->leftChild);
      int rightheight = height(node->rightChild);
      if (leftheight > rightheight)
      {
        return ++leftheight;
      }
      else
      {
        return ++rightheight;
      }
    }//end two node case
    else
    {
      int leftheight = height(node->leftChild);
      int midheight = height(node->middleChild);
      int rightheight = height(node->rightChild);
      if (leftheight > rightheight && leftheight > midheight)
      {
        return ++leftheight;
      }
      else if (rightheight > midheight)
      {
        return ++rightheight;
      }
      else
      {
        return ++ midheight;
      }
    }
  }
}

bool node::isTwoNode()
{
  return TwoNode;
}

bool node::isThreeNode()
{
  return ThreeNode;
}

char node::getMin()
{
  return data[0];
}

char node::getMax()
{
  if(data[2] != ' ')
  {
    return data[2];
  }
  else if(data[1] != ' ')
  {
    return data[1];
  }
  else
  {
    return data[0];
  }
}

node* node::getParent()
{
  return parent;
}

char node::kickUp()
{
  char temp = data[1];
  data[1] = data[2];
  data[2] = ' ';
  return temp;
}

int node::getHeight()
{
  return m_height;
}

void node::setMid(node* mid)
{
  middleChild = mid;
}

void node::setRight(node* right)
{
  rightChild = right;
}

void node::setLeft(node* left)
{
  leftChild = left;
}
