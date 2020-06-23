#include"twoThreeTree.h"
#include"node.h"
#include <fstream>
#include <iostream>
using namespace std;
twoThreeTree::twoThreeTree()
{
  root = nullptr;
}

twoThreeTree::~twoThreeTree(){}

void twoThreeTree::insert(char newData)
{
  // cout << endl;
  // cout << "Inserting: " << newData << endl;
  // cout << endl;
  bool inserted = false;
  //traversal variables
  node* current = root;
  node* previous = current;
  if(find(newData) == true)
  {
    cout << "Char in the tree" << endl;
    return;
  }
  //case where the tree is empty
  if(root == nullptr)
  {
    root = new node(newData, nullptr);
  }//end empty tree case
  //case where the root is the only node and its a two node
  else if(root->height(root) == 1 && root->isTwoNode() == true)
  {
    root->setData(newData);
  }//ends only 1 node case
  //traversing the tree looking for where the element needs to go
  else
  {
    while(inserted != true)
    {
      //checking if the current node is a two or three node
      if(current->isTwoNode() == true)
      {
        if(current->getLeft() == nullptr)
        {
          if(current->isTwoNode() == true)
          {
            current->setData(newData);
            inserted = true;
          }
          //if the node at the end is a three node
          else
          {
            current->setData(newData);
            threeNodeKickUp(current->getParent(), current);
            inserted = true;
          }
        }//end check for inserting
        else
        {
          if(current->getMax() < newData)
          {
            previous = current;
            current = current ->getRight();
          }
          else
          {
            previous = current;
            current = current->getLeft();
          }
        }
      }//end check for two node
      else
      {
        if(current->getMid() == nullptr)
        {
          if(current->isTwoNode() == true)
          {
            current->setData(newData);
            inserted = true;
          }
          //if the node at the end is a three node
          else
          {
            current->setData(newData);
            threeNodeKickUp(current->getParent(), current);
            inserted = true;
          }
        }
        if(current->getMax() < newData)
        {
          previous = current;
          current = current -> getRight();
        }
        else if(current -> getMin() > newData)
        {
          previous = current;
          current = current -> getLeft();
        }
        else
        {
          previous = current;
          current = current->getMid();
        }
      }//end check for three node
    }//end traversal loop
  }//end case it is not the root
}//end insert

void twoThreeTree::threeNodeKickUp(node* parent, node* current)
{
  if(current == root)
  {
    root = new node(current->kickUp(), nullptr);
    node* newRight = new node(current->getMax(), root);
    node* newLeft = new node(current->getMin(), root);
    root->setLeft(newLeft);
    root->setRight(newRight);
  }
  else
  {
    if(parent->isTwoNode() == true)
    {
      parent->setData(current->kickUp());
      if(parent->getLeft() == current)
      {
        //cout << "kickup node is to the left of parent" << endl;
        node* newLeft = new node(current->getMin(), parent);
        node* newMid = new node(current->getMax(), parent);
        parent->setMid(newMid);
        parent->setLeft(newLeft);
        //delete current;
      }
      else
      {
        //cout << "kickup node is to the right of the parent" << endl;
        node* newRight = new node(current->getMax(), parent);
        node* newMid = new node(current->getMin(), parent);
        parent->setMid(newMid);
        parent->setRight(newRight);
        //delete current;
      }
    }//ends parent 2 node case
    else
    {
      //give the parent the kick up value
      parent->setData(current->kickUp());
      threeNodeBreakUp(parent, current);
    }//ends parent 3 node case
  }
}//end function

void twoThreeTree::threeNodeBreakUp(node* current, node* kickUpNode)
{
  //cout << "Attempting three node break up" << endl;
  node* parent = current->getParent();
  node* temp;
  if(current->getRight() == kickUpNode)
  {
    //cout << "Breaking Right child" << endl;
    temp = new node(current->kickUp(), parent);
    node* newRight = new node(current->getMax(), temp);
    node* newLeft = new node(current->getMin(), temp);
    temp->setLeft(newLeft);
    temp->setRight(newRight);
    newLeft->setRight(current->getMid());
    newLeft->setLeft(current->getLeft());
    node* kickupRight = new node(kickUpNode->getMax(), newRight);
    node* kickupLeft = new node(kickUpNode->getMin(), newRight);
    newRight->setLeft(kickupLeft);
    newRight->setRight(kickupRight);
    delete kickUpNode;
  }//end right child is breaking up
  else if(current->getLeft() == kickUpNode)
  {
    //cout << "Breaking Left child" << endl;
    temp = new node(current->kickUp(), parent);
    node* newRight = new node(current->getMax(), temp);
    node* newLeft = new node(current->getMin(), temp);
    newRight->setLeft(current->getMid());
    newRight->setRight(current->getRight());
    node* newkickupRight =  new node(kickUpNode->getMax(), newLeft);
    node* newkickupLeft = new node(kickUpNode->getMin(), newLeft);
    newLeft->setLeft(newkickupLeft);
    newLeft->setRight(newkickupRight);
    temp->setRight(newRight);
    temp->setLeft(newLeft);
    delete kickUpNode;
  }//end left child is breaking up
  else
  {
    //cout << "Breaking Middle Child" << endl;
    temp = new node(current->kickUp(), parent);
    node* newRight = new node(current->getMax(), temp);
    node* newLeft = new node(current->getMin(), temp);
    temp->setLeft(newLeft);
    temp->setRight(newRight);
    newLeft->setLeft(current->getLeft());
    newRight->setRight(current->getRight());
    node* kickupMin = new node(kickUpNode->getMin(), newLeft);
    node* kickupMax = new node(kickUpNode->getMax(), newRight);
    newLeft->setRight(kickupMin);
    newRight->setLeft(kickupMax);
    delete kickUpNode;
  }//middle child is breaking up
  if(parent == nullptr)
  {
    root = temp;
  }
  else
  {
    if(parent->getRight() == current)
    {
      parent->setRight(temp);
    }
    else if (parent->getLeft() == current)
    {
      parent->setLeft(temp);
    }
    else
    {
      parent ->setMid(temp);
    }
  }
}

void twoThreeTree::levelorder()
{
  int height = root->height(root);
  //cout << "height of the tree: " << height << endl;
  //levelRecusrive(root, height);
  for(int i = 0; i < height + 1; i++)
  {
    levelRecusrive(root,i);
  }
}

void twoThreeTree::levelRecusrive(node* rootT, int height)
{
  if(rootT == nullptr)
  {
    return;
  }
  if(height == 1)
  {
    cout << rootT->getMin() << " ";
    if(rootT->getMax() != rootT->getMin())
    {
      cout << rootT->getMax() << " ";
    }
    //cout << endl;
  }
  if(rootT->getRight() == nullptr && rootT->getLeft() == nullptr)
  {
    return;
  }
  else if(height > 1)
  {
    if(rootT->isTwoNode() == true)
    {
      levelRecusrive(rootT->getLeft(), height - 1);
      levelRecusrive(rootT->getRight(), height - 1);
    }
    else
    {
      levelRecusrive(rootT->getLeft(), height - 1);
      levelRecusrive(rootT->getMid(), height - 1);
      levelRecusrive(rootT->getRight(), height - 1);
    }
  }
}

bool twoThreeTree::find(char findMe)
{
  node* current = root;
  node* previous = current;
  while(current != nullptr)
  {
    if(current->isTwoNode() == true)
    {
      if(current->getMax() == findMe || current->getMin() == findMe)
      {
        return true;
      }
      if(current->getMax() < findMe)
      {
        previous = current;
        current = current->getRight();
      }
      else
      {
        previous = current;
        current = current->getLeft();
      }
    }
    else
    {
      if(current->getMax() == findMe || current->getMin() == findMe)
      {
        return true;
      }
      if(current->getMax() < findMe)
      {
        previous = current;
        current = current ->getRight();
      }
      else if(current->getMin() > findMe)
      {
        previous = current;
        current = current->getLeft();
      }
      else
      {
        previous = current;
        current = current ->getMid();
      }
    }//end 3 node case
  }//end traversal
  return false;
}

char twoThreeTree::findMax()
{
  node* current = root;
  node* previous = current;
  while(current != nullptr)
  {
    previous = current;
    current = current->getRight();
  }
  return previous->getMax();
}

char twoThreeTree::findMin()
{
  node* current = root;
  node* previous = current;
  while(current != nullptr)
  {
    previous = current;
    current = current->getLeft();
  }
  return previous->getMin();
}
