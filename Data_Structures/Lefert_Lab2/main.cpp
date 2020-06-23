#include "LinkedList.h"
#include "hashTable.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  // What the user chooses
  string choice;
  //exit bool
  bool exit = false;
  hashTable* primary = nullptr;

  int newData;
  ifstream infile;
  infile.open("data.txt");
//  hashTable* primary = new hashTable(5);
  if(infile.fail())
  {
    cout << "File could not open." << endl;
  }
  else
  {
    //reads from the file into the hash table
    bool firstRead = false;
      while(infile>>newData)
      {
        if(firstRead == false)
        {
          cout << "made the hash table." << endl;
          primary = new hashTable(newData);
          //hashTable* primary = new hashTable(newData);
           firstRead = true;
        }
        else
        {
          //insert a new fail safe for possiblity of no primary hashtable ever being made

          primary->hashInsert(newData);
        }
      }
    }
    infile.close();
  while(exit != true)
  {
  cout << "Choose one operation from the options below." << endl;
  cout << "1. Insert" << endl;
  cout << "2. Delete" << endl;
  cout << "3. Find" << endl;
  cout << "4. Print" << endl;
  cout << "5. Exit" << endl;

  cin >> choice;

    //if(choice == "1" || choice == "2" ||choice == "3" ||choice == "4" ||choice == "5" ||choice == "6" ||choice == "7" ||choice == "8" )
    //{
      if(choice == "1")
      {
        // ask for a new value and use insert
        int newValue;
        cout << "Enter an integer" << endl;
        cin >> newValue;
           primary->hashInsert(newValue);
           primary->hashPrint();
           if(primary->numElements() > primary->numMValue())
           {
              cout << "Rehashing " << endl;
              hashTable* temp = primary->Rehash();
              delete primary;
              primary = temp;
              cout << primary ->numMValue() << endl;
              //hashTable* primary = temp;
              cout << primary ->numMValue() << endl;
              delete temp;
            }
      }
      if(choice == "2")
      {
        //ask for a number to delete and call delete
        int deleteValue;
        cout << "Enter number to be deleted" << endl;
        cin >> deleteValue;
        primary->hashDelete(deleteValue);
      }
      if(choice == "3")
      {
        //ask for a number to find and call find
        int findMe;
        cout << "Enter a number to be found: ";
        cin >> findMe;
         bool found = primary->find(findMe);
         if(found == true)
         {
           int location = primary->hash(findMe);
          cout << "Value found at " << location << endl;
         }
         else
         {
           cout << "Value not found" << endl;
         }
      }
      if(choice == "4")
      {
        // call print function
        primary->hashPrint();

      }
      if(choice == "5")
      {
        //exit
        exit = true;
      }
    //}
      else
      {
        cout << "Enter a valid choice." << endl;
      }
  }
  return 0;
}
