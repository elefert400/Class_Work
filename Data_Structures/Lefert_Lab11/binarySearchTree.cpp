#include "binarySearchTree.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//constructor
binarySearchTree::binarySearchTree()
{}
//destructor
binarySearchTree::~binarySearchTree()
{}
bool binarySearchTree::isEmpty()
{
  if(root == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}
void binarySearchTree::insert(int newData)
{
  //checks if we have any nodes or not
  if(root == nullptr)
  {
    root = new node(newData);
  //  cout << newData << " is the root." << endl;
  }
  else
  {
    //keeps track of my current node
    node* current = root;
    //keeps track of if I have inserted yet
    bool inserted = false;
    //looping until I can insert the value
    while(inserted == false)
    {
      //checking if the new data belongs on the left
      if(current->getData() > newData)
      {
        //checking if there is a node on the left
        if(current->getLeftPtr() == nullptr)
        {
          //setting the pointer to the new node with the data
          //and breaking
          current->newLeftPtr(newData);
          inserted = true;
          //cout << newData << " is to the left of " << current->getData() << endl;
        }
        else
        {
          //going to the left child since one exists
          current = current->getLeftPtr();
        }
      }//end left tree if
      //it must go on the right if it is greater than or equal to
      //so if it fails to go on the left it must go right
      else
      {
        //if the right tree is empty, insert there and break
        if(current->getRightPtr() == nullptr)
        {
          current->newRightPtr(newData);
          inserted = true;
        //  cout << newData << " is to the right of " << current->getData() << endl;
        }
        else
        {
          current = current->getRightPtr();
        }
      }//end right tree case
    }//end while for inserting
  }
}
bool binarySearchTree::deleteNode(int data)
{
  //cout << "Deleing nodes" << endl;
  //setting pointer to my node to check and node before
  node* current = root;
  node* previous = root;
  if(find(data) == false)
  {
    return false;
  }
  else
  {
    while(1)
    {
      if(current -> getRightPtr() == nullptr && current->getLeftPtr() == nullptr && current -> getData() == data)
      {
        //cout << "0 child case" << endl;
        if(previous -> getLeftPtr() == current)
        {
          previous -> nullLeft();
          delete current;
          return true;
        }
        else
        {
          previous -> nullRight();
          delete current;
          return true;
        }
      }//ends no children case
      if(current -> getRightPtr() == nullptr || current->getLeftPtr() == nullptr && current -> getData() == data)
      {
      //  cout << "1 child case" << endl;
        //if it has a right child
        if(current->getLeftPtr() == nullptr)
        {
          //checking if the node I delete is a right child
          if(previous->getRightPtr() == current)
          {
            //cout << "case 1" << endl;
            if(current == root)
            {
              root = current->getRightPtr();
              delete current;
              return true;
            }
            previous -> setRightPtr(current->getRightPtr());
            delete current;
            return true;
          }
          else
          {
          //  cout << "case 2" << endl;
            if(current == root)
            {
              root = current->getRightPtr();
              delete current;
              return true;
            }
            previous -> setLeftPtr(current -> getRightPtr());
            delete current;
            return true;
          }
        }
        else
        {
          //checking if the node I delete is a left child
          if(previous->getRightPtr() == current)
          {
            //cout << "case 3" << endl;
            if(current == root)
            {
              root = current->getLeftPtr();
              delete current;
              return true;
            }
            previous -> setRightPtr(current->getLeftPtr());
            delete current;
            return true;
          }
          else
          {
            //cout << "case 4" << endl;
            if(current == root)
            {
              root = current->getLeftPtr();
              delete current;
              return true;
            }
            previous -> setLeftPtr(current -> getLeftPtr());
            delete current;
            return true;
          }
        }
      }//ends 1 child case
       if(current->getData() == data && current->getLeftPtr() != nullptr && current -> getRightPtr() != nullptr)
       {
         //cout << "two child" << endl;
       }
      // {
      //    //root of the deleted nodes right subtree
      //   node* newRoot = current->getRightPtr();
      //   node* newRootPtr = current;
      //   while(newRoot->getLeftPtr() != nullptr)
      //   {
      //     newRootPtr = newRoot;
      //     newRoot = newRoot->getLeftPtr();
      //   }
      //   if(current == root)
      //   {
      //     root ->setData(newRoot->getData());
      //     //delete newRoot;
      //     free(newRoot);
      //     return true;
      //   }
      //   //checking if it is a left node
      //   // else if(previous->getLeftPtr() == current)
      //   // {
      //   //   current->setData(newRoot->getData());
      //   //   newRootPtr->setLeftPtr(newRoot->getRightPtr());
      //   //   delete newRoot;
      //   //   return true;
      //   // }
      //   else
      //   {
      //     current->setData(newRoot->getData());
      //     newRootPtr->setLeftPtr(newRoot->getRightPtr());
      //     //delete newRoot;
      //     free(newRoot);
      //     return true;
      //   }
      // }//2 children case
      previous = current;
      //cehcking if newData is on the left
      if(current->getData() > data)
      {
        current = current->getLeftPtr();
      }
      else
      {
        current = current->getRightPtr();
      }
    }//end while
  }//end else
}
bool binarySearchTree::find(int findMe)
{
  node* current = root;
  while(1)
  {
    //cout << "At Node " << current->getData() << endl;
    if(current->getData() == findMe)
    {
      return true;
    }
    else
    {
      if(current->getData() > findMe)
      {
        if(current->getLeftPtr() == nullptr)
        {
          return false;
        }
        else
        {
          current = current->getLeftPtr();
        }
      }//end left check
      else
      {
        if(current->getRightPtr() == nullptr)
        {
          return false;
        }
        else
        {
          current = current->getRightPtr();
        }
      }//end right node check
    }//end big else
  }//end while
}
int binarySearchTree::findMin()
{
  node* current = root;
  while(1)
  {
    if(current->getLeftPtr() == nullptr)
    {
      return current->getData();
    }
    else
    {
      current = current ->getLeftPtr();
    }
  }
}
int binarySearchTree::findMax()
{
  node* current = root;
  while(1)
  {
    if(current->getRightPtr() == nullptr)
    {
      return current->getData();
    }
    else
    {
      current = current ->getRightPtr();
    }
  }
}
string binarySearchTree::preorder()
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
void binarySearchTree::recursivePre(node* current, stringstream& preStream)
{
  if(current != nullptr)
  {
    preStream << current->getData() << "  ";
    recursivePre(current->getLeftPtr(), preStream);
    recursivePre(current->getRightPtr(), preStream);
  }
}
string binarySearchTree::postorder()
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
void binarySearchTree::recursivePost(node* current, stringstream& postStream)
{
  if(current != nullptr)
  {
    recursivePost(current->getLeftPtr(), postStream);
    recursivePost(current->getRightPtr(), postStream);
    postStream << current->getData() << " ";
  }
}
string binarySearchTree::inorder()
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
void binarySearchTree::recursiveIn(node* current, stringstream& inStream)
{
  if(current != nullptr)
  {
    recursiveIn(current->getLeftPtr(), inStream);
    inStream << current->getData() << " ";
    recursiveIn(current->getRightPtr(), inStream);
  }
}
void binarySearchTree::levelorder()
{
  int height = root->height(root);
  //cout << "height of the tree: " << height << endl;
  //levelRecusrive(root, height);
  for(int i = 0; i < height + 1; i++)
  {
    levelRecusrive(root,i);
  }
}

void binarySearchTree::levelRecusrive(node* rootT, int height)
{
  if(rootT == nullptr)
  {
    return;
  }
  if(height == 1)
  {
    cout << rootT->getData() << " ";
  }
  if(rootT->getRightPtr() == nullptr && rootT->getLeftPtr() == nullptr)
  {
    return;
  }
  else if(height > 1)
  {
    levelRecusrive(rootT->getLeftPtr(), height - 1);
    levelRecusrive(rootT->getRightPtr(), height - 1);
  }
}
