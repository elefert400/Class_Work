#include <iostream>
#include <fstream>
#include "minHeap.h"
#include "maxHeap.h"
using namespace std;

int main()
{
  // What the user chooses
  string choice;
  //exit bool
  bool exit = false;

  maxHeap* max;
  minHeap* min;
//  minHeap* minA = new minHeap();
cout << "Max 1 or Min 2?" << endl;
cin >> choice;
if(choice == "1")
{
  max = new maxHeap();
  while(exit != true)
  {
  cout << "Choose one operation from the options below." << endl;
  cout << "1. Insert" << endl;
  cout << "2. DeleteMin" << endl;
  cout << "3. DeleteMax" << endl;
  cout << "4. FindMin" << endl;
  cout << "5. FindMax" << endl;
  cout << "6. LevelOrder" << endl;
  cout << "7. Exit" << endl;

  cin >> choice;


  if(choice == "1")
  {
    int newValue;
    cout << "Give a value to insert." << endl;
    cin >> newValue;
    max->insertA(newValue);
    //min->insert(newValue);
  }
  if(choice == "2")
  {
    cout << "Value deleted from max: " << max->deleteMinA() << endl;
  }
  if(choice == "3")
  {
      cout << "Value deleted from max: " << max->deleteMaxA() << endl;
  }
  if(choice == "4")
  {
    cout << "Min value in max: " << max->findMinA() << endl;
  }
  if(choice == "5")
  {
    cout << "Max value in max: " << max->findMaxA() << endl;
  }
  if(choice == "6")
  {
    cout << "levelOrder Max: " << endl;
    max->levelOrderA();
  }
  if(choice == "7")
  {
    exit = true;
    cout << "Exiting" << endl;
  }
}
}
else
{
  min = new minHeap();
  while(exit != true)
  {
  cout << "Choose one operation from the options below." << endl;
  cout << "1. Insert" << endl;
  cout << "2. DeleteMin" << endl;
  cout << "3. DeleteMax" << endl;
  cout << "4. FindMin" << endl;
  cout << "5. FindMax" << endl;
  cout << "6. LevelOrder" << endl;
  cout << "7. Exit" << endl;

  cin >> choice;


  if(choice == "1")
  {
    int newValue;
    cout << "Give a value to insert." << endl;
    cin >> newValue;
    //max->insert(newValue);
    min->insert(newValue);
  }
  if(choice == "2")
  {
    cout << "Value deleted from min " << min->deleteMin() << endl;
  }
  if(choice == "3")
  {
      cout <<"Value deleted from min " << min->deleteMax() << endl;
  }
  if(choice == "4")
  {
    cout << "Min value in min: " << min->findMin() << endl;
  }
  if(choice == "5")
  {
    cout << " Max value in min: " << min->findMax() << endl;
  }
  if(choice == "6")
  {
    cout << "levelOrder Min: " << endl;
    min->levelOrder();
    //max->levelOrder();
  }
  if(choice == "7")
  {
    exit = true;
    cout << "Exiting" << endl;
  }
}//end while
}//end else

return 0;
}
