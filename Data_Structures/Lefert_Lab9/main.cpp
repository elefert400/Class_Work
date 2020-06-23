#include <iostream>
#include <fstream>
#include "minMax.h"
using namespace std;

int main()
{
  // What the user chooses
  string choice;
  //exit bool
  bool exit = false;

  minMax* heap = new minMax();

  while(exit != true)
{
  cout << "Choose one operation from the options below." << endl;
  cout << "1. Insert" << endl;
  cout << "2. DeleteMin" << endl;
  cout << "3. DeleteMax" << endl;
  cout << "4. FindMin" << endl;
  cout << "5. FindMax" << endl;
  cout << "6. levelOrder" << endl;
  cout << "7. Exit" << endl;

  cin >> choice;


  if(choice == "1")
  {
    int newValue, timeValue;
    cout << "Give a priority to insert." << endl;
    cin >> newValue;
    cout << "Give a run time." << endl;
    cin >> timeValue;
    heap->insert(newValue, timeValue);
    //heap->insert(newValue);
    //min->insert(newValue);
  }
  if(choice == "2")
  {
    heap->deleteMin();
  }
  if(choice == "3")
  {
      heap->deleteMax();
  }
  if(choice == "4")
  {
    cout << "Min value in max: " << heap->findMin() << endl;
  }
  if(choice == "5")
  {
    cout << "Max value in max: " << heap->findMax() << endl;
  }
  if(choice == "6")
  {
    cout << "levelOrder" << endl;
    heap->levelOrder();
  }
  if(choice == "7")
  {
    exit = true;
    cout << "Exiting" << endl;
  }
}


return 0;
}
