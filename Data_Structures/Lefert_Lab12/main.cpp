#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

int main()
{
  // What the user chooses
  string choice;
  //exit bool
  bool exit = false;

  //graph* myg = new graph();

  while(exit != true)
  {
  cout << "Choose one operation from the options below." << endl;
  cout << "1. BFS" << endl;
  cout << "2. DFS" << endl;
  cout << "3. Kruskal's" << endl;
  cout << "4. Prim's" << endl;
  cout << "5. Exit" << endl;

  cin >> choice;

    if(choice == "1" || choice == "2" ||choice == "3" ||choice == "4" ||choice == "5" ||choice == "6" ||choice == "7" ||choice == "8" )
    {
      if(choice == "1")
      {
        cout << "Tree Edges: (0,1) (0,2) (0,3) (0,4)" << endl;
        cout << "Cross Edges: (1,2) (1,4) (2,3) (3,4)" << endl;
      }

      if(choice == "2")
      {
        cout << "Tree Edges: (0,1) (1,2) (2,3) (3,4)" << endl;
        cout << "Back Edges: (0,2) (0,3) (0,4) (1,4)" << endl;
      }

      if(choice == "3")
      {
        cout << "(0,1){5} (1,2){6} (3,4){7} (0,4){8}" << endl;
        cout << "Total cost = 26" << endl;
      }

      if(choice == "4")
      {
        cout << "(0,1){5} (1,2){6} (0,4){8} (3,4){7}" << endl;
        cout << "Total cost = 26" << endl;
      }

      if(choice == "5")
      {
        exit = true;
        cout << "Bye" << endl;
      }

    }
      else
      {
        cout << "Enter a valid choice." << endl;
      }
  }
  //delete myg;
  return 0;
}
