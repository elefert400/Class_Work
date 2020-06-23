#include <iostream>
#include <fstream>
#include "skew.h"
#include "leftest.h"
using namespace std;

int main()
{
  // What the user chooses
  string choice;
  //exit bool
  bool exit = false;

  leftest* lefty = new leftest();
  skew* skewy = new skew();

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
      skewy->insert(fileData);
      lefty->insert(fileData);
    }
  }

  while(exit != true)
{
  cout << "Choose one operation from the options below." << endl;
  cout << "1. Insert" << endl;
  cout << "2. DeleteMax" << endl;
  cout << "3. FindMax" << endl;
  cout << "4. Preorder" << endl;
  cout << "5. Inorder" << endl;
  cout << "6. Postorder" << endl;
  cout << "7. Levelorder" << endl;
  cout << "8. Exit" << endl;

  cin >> choice;


  if(choice == "1")
  {
    int newValue;
    cout << "Give a number to insert." << endl;
    cin >> newValue;
    skewy->insert(newValue);
    lefty->insert(newValue);
  }
  if(choice == "2")
  {
    cout << "Skew max deleted: " << skewy->deleteMax() << endl;
    cout << "leftest max deleted: " << lefty->deleteMax() << endl;
  }
  if(choice == "3")
  {
    cout << "Skew max: " << skewy->findMax() << endl;
    cout << "left max: " << lefty->findMax() << endl;
  }
  if(choice == "4")
  {
    cout << "Skew: " << skewy->preOrder() << endl;
    cout << "Leftest: " << lefty->preOrder() << endl;
  }
  if(choice == "5")
  {
    cout << "Skew: " << skewy->inOrder() << endl;
    cout << "Leftest: " << lefty->inOrder() << endl;
  }
  if(choice == "6")
  {
    cout << "Skew: " << skewy->postOrder() << endl;
    cout << "Leftest: " << lefty->postOrder() << endl;
  }
  if(choice == "7")
  {
    cout << "Skew: ";
    skewy->levelOrder();
    cout << endl;
    cout << "Leftest: ";
    lefty->levelOrder();
    cout << endl;
  }
  if(choice == "8")
  {
    exit = true;
    cout << "Exiting" << endl;
  }
}


return 0;
}
