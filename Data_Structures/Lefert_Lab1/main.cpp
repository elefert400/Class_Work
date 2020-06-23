#include <iostream>
#include <fstream>
#include <sstream>
#include "LinkedList.h"

using namespace std;

int main()
{
  // What the user chooses
  string choice;
  //exit bool
  bool exit = false;

  //make a new LinkedList
  LinkedList ethan;

  while(exit != true)
  {
  cout << "Choose one operation from the options below." << endl;
  cout << "1. Insert" << endl;
  cout << "2. Delete" << endl;
  cout << "3. Find Smallest number" << endl;
  cout << "4. Find Largest number" << endl;
  cout << "5. Average of numbers" << endl;
  cout << "6. Merge two Lists" << endl;
  cout << "7. Print" << endl;
  cout << "8. Exit" << endl;

  cin >> choice;

    if(choice == "1" || choice == "2" ||choice == "3" ||choice == "4" ||choice == "5" ||choice == "6" ||choice == "7" ||choice == "8" )
    {
      if(choice == "1")
      {
        // ask for a new value and use insert
        int newValue;
        cout << "Enter an integer" << endl;
        cin >> newValue;
        ethan.insert(newValue);
      }
      if(choice == "2")
      {
        //ask for a number to delete and call delete
        int deleteValue;
        cout << "Enter number to be deleted" << endl;
        cin >> deleteValue;
        if(!ethan.isEmpty()){
          ethan.mdelete(deleteValue);
        }else{
          cout << "Cannot delete from an empty list." << endl;
        }
      }
      if(choice == "3")
      {
        //call smallest number function
        int smallestValue = ethan.smallest();
        cout << smallestValue << endl;
      }
      if(choice == "4")
      {
        // call largest number function
        int largestValue = ethan.largest();
        cout << largestValue << endl;
      }
      if(choice == "5")
      {
        //call average numbers function
        double averageValue = ethan.average();
        cout << averageValue << endl;
      }
      if(choice == "6")
      {
        //merge lists
        string secondList;
        int newValue;
        cout << "Input the new list: " << endl;
        cin.ignore();
        getline(cin, secondList);
        cout << secondList << endl;
        stringstream stream (secondList);
        while(stream >> newValue)
        {
            ethan.insert(newValue);
            //ethan.addNodes();
        }
        ethan.mbubbleSort();
        ethan.print();
    }
      if(choice == "7")
      {
        //call print function
        ethan.print();
      }
      if(choice == "8")
      {
        // set exit to true and say goodbye
        exit = true;
        cout << "Goodbye" << endl;
      }
    }
      else
      {
        cout << "Enter a valid choice." << endl;
      }
  }
  return 0;
}
