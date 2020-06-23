#include "Node.h"
using namespace std;
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class LinkedList
{
  private:
    //int to keep track of nodes
    int nodes;
    // pointer to the front
    Node* front;
  public:
    //constructor
    LinkedList();
    //destructor
    ~LinkedList();
    //the isEmpty function returns true if empty false otherwise
    bool isEmpty();
    //insert a new node at the front of the List
    void insert(int newValue);
    //searches for and deletes a node with a given value
    void mdelete(int deleteInt);
    //finds the smallest element
    int smallest();
    //finds the largest element
    int largest();
    //averages all the nodes values
    double average();
    //prints the List
    void print();
    //returns nodes
    int getNodes();
    //does a bubblesort on the list
    void mbubbleSort();
    //adds to the node total
    void addNodes();
    //looks for a value in the list
    bool findValue(int findMe);
    // returns the value at the fron and deletes that node
    int frontValue();
    
};
#endif
