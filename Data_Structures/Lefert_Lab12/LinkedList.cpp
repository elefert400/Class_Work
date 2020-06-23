#include "LinkedList.h"
#include "Node.h"
#include <fstream>
#include <iostream>

using namespace std;

//constructor for linked list
LinkedList::LinkedList(){
  nodes = 0;
    int newData;
    ifstream infile;
    infile.open("data.txt");
    if(infile.fail())
    {
      cout << "File could not open." << endl;
    }
    else
    {
      //reads from the file into the list
        while(infile>>newData)
        {
          Node* temp = new Node(newData);
          if(nodes == 0)
          {
            temp -> setPointer(nullptr);
            front = temp;
            back = temp;
            nodes++;
          }
          else
          {
            back -> setPointer(temp);
            back = temp;
            nodes++;
          }
        }
    }
    infile.close();
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
  //making the new nodes
  Node* temp = new Node(newValue);
  //putting a new node at the front if the list is empty
  if(nodes == 0)
  {
    front = temp;
    back = temp;
    temp -> setPointer(NULL);
    nodes++;
  }
  //adds the node to the back of the list
  else{
    back -> setPointer(temp);
    back = temp;
    nodes++;
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
  cout << "Got out of while" << endl;
  //case where the value is the front
  int currentValue = current -> getData();
  cout << currentValue << endl;
  if(current == front && currentValue == deleteInt)
  {
    cout <<"Front" << endl;
    front = front -> getPointer();
    delete current;
    nodes--;
    cout << "Value found at the front and deleted" << endl;
  }
  else if(current == back && currentValue == deleteInt)
  {
    cout <<"back" << endl;
    back = previous;
    delete current;
    nodes--;
    cout << "Value found at the back and deleted" << endl;
  }
  else if(currentValue == deleteInt)
  {
    cout <<"mid" << endl;
    previous -> setPointer(current -> getPointer());
    delete current;
    nodes--;
    cout << "Value found and deleted" << endl;
  }
  else
  {
    cout << "Value not found" << endl;
  }
}

//finds the smallest value in the list
int LinkedList::smallest(){
  //keeps track of where we are in the list
  Node* temp = front;
  //int to hold the smallest number
  int smallest = front -> getData();
  for(int i = 0; i < nodes; i++){
    if(smallest > temp -> getData())
    {
      smallest = temp -> getData();
      temp = temp -> getPointer();
    }
    else
    {
      temp = temp -> getPointer();
    }
  }
  return smallest;
}

//finds the largest value in the list
int LinkedList::largest(){
  //keeps track of where we are in the list
  Node* temp = front;
  //int to hold the smallest number
  int largest = front -> getData();
  for(int i = 0; i < nodes; i++){
    if(largest < temp -> getData())
    {
      largest = temp -> getData();
      temp = temp -> getPointer();
    }
    else
    {
      temp = temp -> getPointer();
    }
  }
  return largest;
}
//takes the average of the list and returns a double
double LinkedList::average(){
  // keeps track of where we are in the list
  Node* temp = front;
  int sum = 0;
  for(int i = 0; i < nodes; i++){
    sum = sum + temp -> getData();
    temp = temp -> getPointer();
  }
  return ((double)sum / (double)nodes);
}
//prints the List
void LinkedList::print(){
  //keeps track of where we are in the list
  Node* temp = front;
  cout << "List: ";
  for(int i = 0; i < nodes; i++){
    cout << temp -> getData() << " ";
    temp = temp -> getPointer();
  }
  cout << endl;
}
//returns the size of the list
int LinkedList::getNodes(){
  return nodes;
}

//bubblesort for my LinkedList
void LinkedList::mbubbleSort()
{
  //pointers for keeping track of where I am in the list
  Node* previous = front;
  Node* leftHand = front;
  Node* rightHand = front;
  //bool to keep track of if I swapped
  bool sorted = false;
  //int to keep track of how many nodes I have been over
  while(!sorted)
  {
    sorted = true;
    for(int i = 0; i < nodes - 1; i++)
    {
      previous = leftHand;
      leftHand = rightHand;
      rightHand = rightHand -> getPointer();
      if(front == leftHand && leftHand -> getData() > rightHand -> getData())
      {
        sorted = false;
        leftHand -> setPointer(rightHand -> getPointer());
        front = rightHand;
        rightHand -> setPointer(leftHand);
        leftHand = rightHand;
        previous = rightHand;
        rightHand = rightHand -> getPointer();
      }
      else if(back == rightHand && leftHand -> getData() > rightHand -> getData())
      {
        sorted = false;
        rightHand -> setPointer(leftHand);
        back = leftHand;
        leftHand -> setPointer(nullptr);
        previous -> setPointer(rightHand);
      }
      else if(leftHand -> getData() > rightHand -> getData())
      {
        sorted = false;
        leftHand -> setPointer(rightHand -> getPointer());
        rightHand -> setPointer(leftHand);
        previous -> setPointer(rightHand);
        rightHand = leftHand;
        leftHand = previous -> getPointer();
      }
    }
    rightHand = front;
    leftHand = front;
    previous = front;
  }
}

void LinkedList::addNodes()
{
  nodes++;
}
