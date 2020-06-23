#include "LinkedList.h"
#include "Node.h"
#include <fstream>
#include <iostream>

using namespace std;

//constructor for linked list
LinkedList::LinkedList(){
  nodes = 0;
  front = nullptr;
}

//destructor for linked List
LinkedList::~LinkedList(){}

//isEmpty
bool LinkedList::isEmpty(){
  if(nodes == 0){
    return true;
  }else{
    return false;
  }
}

//Inserts new node at the back of the List
void LinkedList::insert(int newValue){
  if(findValue(newValue) == true)
  {
    cout << "Value already in the table" << endl;
  }
  else
  {

    //making the new nodes
    Node* temp = new Node(newValue);
    //putting it at the front if the list is is empty
    if(nodes == 0)
    {
      front = temp;
      nodes++;
      cout << "Value inserted" << endl;
    }
    //setting it to the front
    else
    {
      temp->setPointer(front);
      front = temp;
      nodes++;
      cout << "Value inserted" << endl;
    }
  }
}
//finds and deletes a node with a given value
void LinkedList::mdelete(int deleteInt)
{
  //pointers to the current node and the previous node
  Node* previous = front;
  Node* current = front;
  while(current != nullptr && current -> getData() != deleteInt)
  {
    previous = current;
    current = current -> getPointer();
  }
  //case where the value is the front
  int currentValue = current -> getData();
  if(current == front && currentValue == deleteInt)
  {
    front = front -> getPointer();
    delete current;
    nodes--;
  }
  else if(currentValue == deleteInt)
  {
    previous -> setPointer(current -> getPointer());
    delete current;
    nodes--;
  }
  else
  {
    cout << "Value not found" << endl;
  }
}

void LinkedList::print()
{
  //checks if the list is isEmpty
  if(nodes == 0)
  {
    cout << "Empty" << endl;
  }
  else
  {
    //keeps track of where we are in the list
    Node* temp = front;
    cout << "List: ";
    for(int i = 0; i < nodes; i++){
      cout << temp -> getData() << " -> ";
      temp = temp -> getPointer();
    }
  }
  cout << endl;
}
//returns the size of the list
int LinkedList::getNodes(){
  return nodes;
}


void LinkedList::addNodes()
{
  nodes++;
}

bool LinkedList::findValue(int findMe)
{
  //pointers to the current node and the previous node
  Node* previous = front;
  Node* current = front;
  if(nodes == 0)
  {
    return false;
  }
  // loop to look for the value
  while(current != nullptr && current -> getData() != findMe)
  {
    if(current->getPointer() == nullptr)
    {
      break;
    }
    previous = current;
    current = current -> getPointer();
  }
  if(current ->getData() == findMe)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int LinkedList::frontValue()
{
  int currentFront = front -> getData();
  mdelete(currentFront);
  return currentFront;
}
