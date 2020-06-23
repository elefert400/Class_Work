#include <iostream>
#include <fstream>
#include "twoThreeTree.h"
using namespace std;

int main()
{
  // What the user chooses
  string choice;
  //exit bool
  bool exit = false;
  twoThreeTree* tree = new twoThreeTree();
  char fileData;
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
      //tree->levelorder();
    }
  }

  while(exit != true)
  {
  cout << "Choose one operation from the options below." << endl;
  cout << "1. Insert" << endl;
  cout << "2. Delete" << endl;
  cout << "3. DeleteMin" << endl;
  cout << "4. DeleteMax" << endl;
  cout << "5. Find" << endl;
  cout << "6. FindMin" << endl;
  cout << "7. FindMax" << endl;
  cout << "8. Levelorder" << endl;
  cout << "9. Exit" << endl;

  cin >> choice;


  if(choice == "1")
  {
    char newData;
    cout << "Enter a char to insert." << endl;
    cin >> newData;
    tree->insert(newData);
  }
  if(choice == "2")
  {
    char deleteData;
    cout << "Enter a char to delete" << endl;
    cin >> deleteData;
    // if(tree->deleteNode(deleteData) == true)
    // {
    //   cout << "The Value was deleted" << endl;
    // }
    // else
    // {
    //   cout << "The Value was not in the table" << endl;
    // }
  }
  if(choice == "3")
  {

  }
  if(choice == "4")
  {

  }
  if(choice == "5")
  {
    char findMe;
    cout << "Enter a char to find" << endl;
    cin >> findMe;
    if(tree->find(findMe) == true);
    {
      cout << "Found: " << findMe << endl;
    }
    if(tree->find(findMe) == false)
    {
      cout << "Value not found" << endl;
    }
  }
  if(choice == "6")
  {
    char minValue = tree->findMin();
    cout << minValue << " is the min value." << endl;
  }
  if(choice == "7")
  {
    char maxValue = tree->findMax();
    cout << maxValue << " is the max value" << endl;
  }
  if(choice == "8")
  {
    tree->levelorder();
    cout << endl;
  }
  if(choice == "9")
  {
    cout << "exiting" << endl;
    exit = true;
    //tree -> ~twoThreeTree();
  }
}
return 0;
}
