#include <fstream>
#include <iostream>
#include <string>
#include "hashTableDouble.h"
#include "hashTableQuad.h"
using namespace std;

int main()
{
  // What the user chooses
  string choice;
  //exit bool
  bool exit = false;


  hashTableDouble* doub;;
  hashTableQuad* quad;
  int newData;
  string dataRead;
  ifstream infile;
  infile.open("data.txt");
  if(infile.fail())
  {
    cout << "File Could not Open" << endl;
  }
  else
{
  //reads from the file into the hash table
  bool firstRead = false;
    if(firstRead == false)
    {
      infile>>newData;
      doub = new hashTableDouble(newData);
      quad = new hashTableQuad(newData);
      firstRead = true;
    }
      while(infile>>dataRead)
      {
        doub -> doubleInsert(dataRead);
        quad->quadInsert(dataRead);
      }
  }

  while(exit != true)
  {
  cout << "Choose one operation from the options below." << endl;
  cout << "1. Insert" << endl;
  cout << "2. Delete" << endl;
  cout << "3. Find" << endl;
  cout << "4. Find Parlindrome" << endl;
  cout << "5. Reverse String" << endl;
  cout << "6. Print" << endl;
  cout << "7. Exit" << endl;

  cin >> choice;


  if(choice == "1")
  {
    // ask for a new value and use insert
    string newValue;
    cout << "Enter an string" << endl;
    cin >> newValue;
    doub -> doubleInsert(newValue);
    quad->quadInsert(newValue);
    if(doub->doubleLambda() >= .5)
    {
      cout << "Rehashing double"<< endl;
      doub = doub -> doubleRehash();
    }
    if(quad->quadLambda() >= .5)
    {
      cout << "Rehashing quad" << endl;
      quad = quad->quadRehash();
    }
  }
  if(choice == "2")
  {
    //ask for a string to delete and call delete
    string deleteValue;
    cout << "Enter string to be deleted" << endl;
    cin >> deleteValue;
    doub->doubleDelete(deleteValue);
    quad->quadDelete(deleteValue);
  }
  if(choice == "3")
  {
    //ask for a strng to find and call find
    string findMe;
    cout << "Enter a string to be found: ";
    cin >> findMe;
    bool foundDouble = doub -> doubleFind(findMe);
    bool foundQuad = quad->quadFind(findMe);
    // if(foundQuad == true)
    // {
    //   cout << "Found: " << findMe << endl;
    // }
    // if(foundDouble == true)
    // {
    //   cout << "Found: " << findMe << endl;
    // }
  }
  if(choice == "4")
  {
    //call palindrome
    cout << "Palindromes: ";
    quad->quadFindPalindromes();
    cout << endl;
  }
  if(choice == "5")
  {
    //call reverse string
    int location;
    cout << "Enter a location to be reversed: ";
    cin >> location;
    doub->doubleReverseString(location);
    quad->quadReverseString(location);
  }
  if(choice == "6")
  {
    // call print
    cout << "Double Hash Table" << endl;
    doub->doublePrint();
    cout << "Quad Hash Table" << endl;
    quad->quadPrint();
  }
  if(choice == "7")
  {
    //exit
    exit = true;
  }
}
return 0;
}
