#include <iostream>
#include <fstream>
#include "binarySearchTree.h"
using namespace std;

int main()
{
  // What the user chooses
  string choice;
  //exit bool
  bool exit = false;
  binarySearchTree* tree = new binarySearchTree();
  int fileData;
  ifstream infile;
  infile.open("data.txt");
  if(infile.fail())
  {
    cout << "Error opening file" << endl;
  }
  else
  {
    while(infile>>fileData)
    {
      tree->insert(fileData);
    }
  }

  while(exit != true)
  {
  cout << "Choose one operation from the options below." << endl;
  cout << "1. Insert" << endl;
  cout << "2. Delete" << endl;
  cout << "3. Find" << endl;
  cout << "4. FindMin" << endl;
  cout << "5. findMax" << endl;
  cout << "6. Preorder" << endl;
  cout << "7. Inorder" << endl;
  cout << "8. Postoder" << endl;
  cout << "9. Levelorder" << endl;
  cout << "10. Exit" << endl;

  cin >> choice;


  if(choice == "1")
  {
    int newData;
    cout << "Enter a number to insert." << endl;
    cin >> newData;
    tree->insert(newData);
  }
  if(choice == "2")
  {
    int deleteData;
    cout << "Enter a number to delete" << endl;
    cin >> deleteData;
    if(tree->deleteNode(deleteData) == true)
    {
      cout << "The Value was deleted" << endl;
    }
    else
    {
      cout << "The Value was not in the table" << endl;
    }
  }
  if(choice == "3")
  {
    int findMe;
    cout << "Enter a number to search for" << endl;
    cin >> findMe;
    if(tree->find(findMe) == true)
    {
      cout << "Number is present in the tree" << endl;
    }
    else
    {
      cout << "Number is not present in the tree" << endl;
    }
  }
  if(choice == "4")
  {
    int minValue = tree->findMin();
    cout << "The min value is: " << minValue << endl;
  }
  if(choice == "5")
  {
    int maxValue = tree->findMax();
    cout << "The max value is: " << maxValue << endl;
  }
  if(choice == "6")
  {
    string preOrder = tree->preorder();
    cout << preOrder << endl;
  }
  if(choice == "7")
  {
    cout << tree->inorder() << endl;
  }
  if(choice == "8")
  {
    cout << tree->postorder() << endl;
  }
  if(choice == "9")
  {
    tree->levelorder();
    cout << endl;
  }
  if(choice == "10")
  {
    //exit
    exit = true;
    tree-> ~binarySearchTree();
  }
  if(choice == "11")
  {
    for(int i = 0; i < 7; i++)
    {
      cout << tree->findMax() << endl;
      bool dummy = tree->deleteNode(tree->findMax());
      cout << dummy << endl;
      tree->levelorder();
      cout << endl;
    }
  }
}
return 0;
}
