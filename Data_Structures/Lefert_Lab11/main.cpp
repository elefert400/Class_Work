#include "binarySearchTree.h"
#include "maxHeap.h"
#include "minHeap.h"

#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
  // What the user chooses
  string choice;
  //exit bool
  bool exit = false;
  binarySearchTree* tree;
  maxHeap* max;
  minHeap* min;

  while(exit != true)
  {
  cout << "Choose one operation from the options below." << endl;
  cout << "1. Test" << endl;
  cout << "2. Performance Comparison" << endl;
  cout << "3. Exit" << endl;

  cin >> choice;
  if(choice == "1")
  {
    tree = new binarySearchTree();
    max = new maxHeap(true, 10);
    int newData;
    ifstream infile;
    infile.open("data.txt");
    if(infile.fail())
    {
      cout << "File Could not Open" << endl;
    }
    else
    {
      while(infile>>newData)
        {
          tree->insert(newData);
        }
    }
    cout << "BST:" << endl;
    tree->levelorder();
    cout << endl;
    cout << "MAX:" << endl;
    max->levelOrderA();
    cout << endl;
    min = new minHeap(true, 10);
    cout << "MIN:" << endl;
    min->levelOrder();
    cout << endl;
    //delete min;
    //delete tree;
    //delete max;
  }//end choice 1
  if(choice == "3")
  {
    cout << "bye" << endl;
    exit = true;
  }
  if(choice == "2")
  {
    cout << "This will take about 6 hours" << endl;
    float BSTBuild1;
    float BSTBuild2;
    float BSTBuild3;
    float BSTBuild4;
    float BSTBuild5;
    float maxBuild1;
    float maxBuild2;
    float maxBuild3;
    float maxBuild4;
    float maxBuild5;
    float minBuild1;
    float minBuild2;
    float minBuild3;
    float minBuild4;
    float minBuild5;

    float BSTmin1;
    float BSTmin2;
    float BSTmin3;
    float BSTmin4;
    float BSTmin5;
    float maxmin1;
    float maxmin2;
    float maxmin3;
    float maxmin4;
    float maxmin5;
    float minmin1;
    float minmin2;
    float minmin3;
    float minmin4;
    float minmin5;

    float BSTmax1;
    float BSTmax2;
    float BSTmax3;
    float BSTmax4;
    float BSTmax5;
    float maxmax1;
    float maxmax2;
    float maxmax3;
    float maxmax4;
    float maxmax5;
    float minmax1;
    float minmax2;
    float minmax3;
    float minmax4;
    float minmax5;
    int mValues = 1000003;

    bool dummy;
    int dummer;

    //build clock variable
    clock_t t;
    //delete min clock variable
    clock_t s;
    //delete max clock variable
    clock_t d;
    //control how many times we run the timer experiment
    int controlLoop = 0;
    //int to keep track of total for building the averaging
    float buildTotal = 0;
    //keeps track of total for deleteMin values
    float minTotal = 0;
    //keeps track of total deleteMax values
    float maxTotal = 0;

    int loopNum = 0;

    //cout << CLOCKS_PER_SEC << endl;

    cout << "BST 1" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      tree = new binarySearchTree();
      while(loopNum < floor(((double)mValues * 1)))
      {
        //cout << "Trying to insert" << loopNum << endl;
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        tree->insert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      t = clock() - t;
      //cout << t << endl;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the timer
        s = clock();
        dummy = tree->deleteNode(tree->findMax());

      //  cout << dummy << endl;
        s = clock() - s;
      //s = ((float)s/CLOCKS_PER_SEC) * 1000;
        //cout << s << endl;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummy = tree->deleteNode(tree->findMin());
        d = clock() - d;
        //d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      delete tree;
    }
    //cout << "maxtotal before conversion: " << maxTotal << endl;
    maxTotal = ((float)maxTotal/CLOCKS_PER_SEC) * 1000;
    minTotal = ((float)minTotal/CLOCKS_PER_SEC) * 1000;
    BSTBuild1 = buildTotal / (double)controlLoop;
    BSTmin1 = minTotal / (double)controlLoop;
    BSTmax1 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout << "BST 2" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      tree = new binarySearchTree();
      while(loopNum < floor(((double)mValues * 2)))
      {
        //cout << "Trying to insert" << loopNum << endl;
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        tree->insert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      t = clock() - t;
      //cout << t << endl;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the timer
        s = clock();
        dummy = tree->deleteNode(tree->findMax());

      //  cout << dummy << endl;
        s = clock() - s;
      //s = ((float)s/CLOCKS_PER_SEC) * 1000;
        //cout << s << endl;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummy = tree->deleteNode(tree->findMin());
        d = clock() - d;
        //d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      delete tree;
    }
    //cout << "maxtotal before conversion: " << maxTotal << endl;
    maxTotal = ((float)maxTotal/CLOCKS_PER_SEC) * 1000;
    minTotal = ((float)minTotal/CLOCKS_PER_SEC) * 1000;
    BSTBuild2 = buildTotal / (double)controlLoop;
    BSTmin2 = minTotal / (double)controlLoop;
    BSTmax2 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout << "BST 3" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      tree = new binarySearchTree();
      while(loopNum < floor(((double)mValues * 3)))
      {
        //cout << "Trying to insert" << loopNum << endl;
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        tree->insert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      t = clock() - t;
      //cout << t << endl;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the timer
        s = clock();
        dummy = tree->deleteNode(tree->findMax());

      //  cout << dummy << endl;
        s = clock() - s;
      //s = ((float)s/CLOCKS_PER_SEC) * 1000;
        //cout << s << endl;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummy = tree->deleteNode(tree->findMin());
        d = clock() - d;
        //d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      delete tree;
    }
    //cout << "maxtotal before conversion: " << maxTotal << endl;
    maxTotal = ((float)maxTotal/CLOCKS_PER_SEC) * 1000;
    minTotal = ((float)minTotal/CLOCKS_PER_SEC) * 1000;
    BSTBuild3 = buildTotal / (double)controlLoop;
    BSTmin3 = minTotal / (double)controlLoop;
    BSTmax3 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout << "BST 4" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      tree = new binarySearchTree();
      while(loopNum < floor(((double)mValues * 4)))
      {
        //cout << "Trying to insert" << loopNum << endl;
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        tree->insert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      t = clock() - t;
      //cout << t << endl;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the timer
        s = clock();
        dummy = tree->deleteNode(tree->findMax());

      //  cout << dummy << endl;
        s = clock() - s;
      //s = ((float)s/CLOCKS_PER_SEC) * 1000;
        //cout << s << endl;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummy = tree->deleteNode(tree->findMin());
        d = clock() - d;
        //d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      delete tree;
    }
    //cout << "maxtotal before conversion: " << maxTotal << endl;
    maxTotal = ((float)maxTotal/CLOCKS_PER_SEC) * 1000;
    minTotal = ((float)minTotal/CLOCKS_PER_SEC) * 1000;
    BSTBuild4 = buildTotal / (double)controlLoop;
    BSTmin4 = minTotal / (double)controlLoop;
    BSTmax4 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout << "BST 5" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      tree = new binarySearchTree();
      while(loopNum < floor(((double)mValues * 5)))
      {
        //cout << "Trying to insert" << loopNum << endl;
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        tree->insert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      t = clock() - t;
      //cout << t << endl;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the timer
        s = clock();
        dummy = tree->deleteNode(tree->findMax());

      //  cout << dummy << endl;
        s = clock() - s;
      //s = ((float)s/CLOCKS_PER_SEC) * 1000;
        //cout << s << endl;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummy = tree->deleteNode(tree->findMin());
        d = clock() - d;
        //d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      delete tree;
    }
    //cout << "maxtotal before conversion: " << maxTotal << endl;
    maxTotal = ((float)maxTotal/CLOCKS_PER_SEC) * 1000;
    minTotal = ((float)minTotal/CLOCKS_PER_SEC) * 1000;
    BSTBuild5 = buildTotal / (double)controlLoop;
    BSTmin5 = minTotal / (double)controlLoop;
    BSTmax5 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout <<  fixed << setprecision(3) << "Performance (BST):" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "|               | 100,000 | 200,000 | 300,000 | 400,000 | 500,000 |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Build(ms)     |  "<< BSTBuild1 <<"  | "<< BSTBuild2 <<" | "<< BSTBuild3 <<" | "<< BSTBuild4 <<" | "<< BSTBuild5 <<" |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Delete Min(ms)     |  "<< BSTmin1 <<"  |  "<< BSTmin2 <<"  |  "<< BSTmin3 <<"  |  "<< BSTmin4 <<"  |  "<< BSTmin5 <<"  |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Delete Max(ms) |  "<< BSTmax1 <<"  | "<< BSTmax2 <<"  |  "<< BSTmax3 <<" | "<< BSTmax4 <<"  | "<< BSTmax5 <<"  |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

    cout << "Build: " << BSTBuild1 << " MIN: " << BSTmin1 << " MAX: " << BSTmax1 << endl;

    cout << "MAX 1" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      max = new maxHeap(false, 1000000);
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      //max->levelOrderA();
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the find timer
        s = clock();
        dummer = max->deleteMaxA();
        //cout << "done delete" << endl;
        s = clock() - s;
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummer = max->deleteMinA();
        d = clock() - d;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      cout << controlLoop << endl;
      delete max;
    }
    maxBuild1 = buildTotal / (double)controlLoop;
    maxmin1 = minTotal / (double)controlLoop;
    maxmax1 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout << "MAX 2" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      max = new maxHeap(false, 2000000);
      cout << "made heap" << endl;
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      //max->levelOrderA();
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the find timer
        s = clock();
        dummer = max->deleteMaxA();
        //cout << "done delete" << endl;
        s = clock() - s;
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummer = max->deleteMinA();
        d = clock() - d;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      cout << controlLoop << endl;
      delete max;
    }
    maxBuild2 = buildTotal / (double)controlLoop;
    maxmin2 = minTotal / (double)controlLoop;
    maxmax2 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout << "MAX 3" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      max = new maxHeap(false, 3000000);
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      //max->levelOrderA();
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the find timer
        s = clock();
        dummer = max->deleteMaxA();
        //cout << "done delete" << endl;
        s = clock() - s;
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummer = max->deleteMinA();
        d = clock() - d;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      cout << controlLoop << endl;
      delete max;
    }
    maxBuild3 = buildTotal / (double)controlLoop;
    maxmin3 = minTotal / (double)controlLoop;
    maxmax3 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout << "MAX 4" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      max = new maxHeap(false, 4000000);
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      //max->levelOrderA();
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the find timer
        s = clock();
        dummer = max->deleteMaxA();
        //cout << "done delete" << endl;
        s = clock() - s;
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummer = max->deleteMinA();
        d = clock() - d;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      cout << controlLoop << endl;
      delete max;
    }
    maxBuild4 = buildTotal / (double)controlLoop;
    maxmin4 = minTotal / (double)controlLoop;
    maxmax4 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout << "MAX 5" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      max = new maxHeap(false, 5000000);
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      //max->levelOrderA();
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the find timer
        s = clock();
        dummer = max->deleteMaxA();
        //cout << "done delete" << endl;
        s = clock() - s;
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummer = max->deleteMinA();
        d = clock() - d;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      cout << controlLoop << endl;
      delete max;
    }
    maxBuild5 = buildTotal / (double)controlLoop;
    maxmin5 = minTotal / (double)controlLoop;
    maxmax5 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout <<  fixed << setprecision(3) << "Performance (Max):" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "|               | 100,000 | 200,000 | 300,000 | 400,000 | 500,000 |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Build(ms)     |  "<< maxBuild1 <<"  | "<< maxBuild2 <<" | "<< maxBuild3 <<" | "<< maxBuild4 <<" | "<< maxBuild5 <<" |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Delete Min(ms)     |  "<< maxmin1 <<"  |  "<< maxmin2 <<"  |  "<< maxmin3 <<"  |  "<< maxmin4 <<"  |  "<< maxmin5 <<"  |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Delete Max(ms) |  "<< maxmax1 <<"  | "<< maxmax2 <<"  |  "<< maxmax3 <<" | "<< maxmax4 <<"  | "<< maxmax5 <<"  |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

    cout << "MIN 1" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      min = new minHeap(false, 1000000);
      //cout << "Made min heap" << endl;
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      //max->levelOrderA();
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the find timer
        s = clock();
        dummer = min->deleteMax();
        //cout << "done delete" << endl;
        s = clock() - s;
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummer = min->deleteMin();
        d = clock() - d;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      cout << controlLoop << endl;
      delete max;
    }
    minBuild1 = buildTotal / (double)controlLoop;
    minmin1 = minTotal / (double)controlLoop;
    minmax1 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout << "MIN 2" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      min = new minHeap(false, 2000000);
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      //max->levelOrderA();
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the find timer
        s = clock();
        dummer = min->deleteMax();
        //cout << "done delete" << endl;
        s = clock() - s;
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummer = min->deleteMin();
        d = clock() - d;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      cout << controlLoop << endl;
      delete max;
    }
    minBuild2 = buildTotal / (double)controlLoop;
    minmin2 = minTotal / (double)controlLoop;
    minmax2 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout << "MIN 3" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      min = new minHeap(false, 3000000);
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      //max->levelOrderA();
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the find timer
        s = clock();
        dummer = min->deleteMax();
        //cout << "done delete" << endl;
        s = clock() - s;
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummer = min->deleteMin();
        d = clock() - d;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      cout << controlLoop << endl;
      delete max;
    }
    minBuild3 = buildTotal / (double)controlLoop;
    minmin3 = minTotal / (double)controlLoop;
    minmax3 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout << "MIN 4" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      min = new minHeap(false, 4000000);
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      //max->levelOrderA();
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the find timer
        s = clock();
        dummer = min->deleteMax();
        //cout << "done delete" << endl;
        s = clock() - s;
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummer = min->deleteMin();
        d = clock() - d;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      cout << controlLoop << endl;
      delete max;
    }
    minBuild4 = buildTotal / (double)controlLoop;
    minmin4 = minTotal / (double)controlLoop;
    minmax4 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout << "MIN 5" << endl;
    while(controlLoop < 5)
    {
      //cout << "Entering main loop" << endl;
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      min = new minHeap(false, 5000000);
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //tree->levelorder();
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      //max->levelOrderA();
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing max" << endl;
        //starts the find timer
        s = clock();
        dummer = min->deleteMax();
        //cout << "done delete" << endl;
        s = clock() - s;
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        maxTotal = maxTotal + s;
        loopNum++;
      }
      loopNum = 0;
      while(loopNum < floor((double)mValues * .001))
      {
        //cout << "Deleteing min" << endl;
        //starts the find timer
        d = clock();
        dummer = min->deleteMin();
        d = clock() - d;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        //cout << d << endl;
        minTotal = minTotal + d;
        //cout << minTotal << endl;
        loopNum++;
      }
      cout << controlLoop << endl;
      delete max;
    }
    minBuild5 = buildTotal / (double)controlLoop;
    minmin5 = minTotal / (double)controlLoop;
    minmax5 = maxTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    minTotal = 0;
    maxTotal = 0;

    cout <<  fixed << setprecision(3) << "Performance (Min):" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "|               | 100,000 | 200,000 | 300,000 | 400,000 | 500,000 |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Build(ms)     |  "<< minBuild1 <<"  | "<< minBuild2 <<" | "<< minBuild3 <<" | "<< minBuild4 <<" | "<< minBuild5 <<" |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Delete Min(ms)     |  "<< minmin1 <<"  |  "<< minmin2 <<"  |  "<< minmin3 <<"  |  "<< minmin4 <<"  |  "<< minmin5 <<"  |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Delete Max(ms) |  "<< minmax1 <<"  | "<< minmax2 <<"  |  "<< minmax3 <<" | "<< minmax4 <<"  | "<< minmax5 <<"  |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;
    //
    //
    //

    //


    //cout << "Build: " << maxBuild1 << " MIN: " << maxmin1 << " MAX: " << maxmax1 << endl;
  }// end choice 2
}//end while
return 0;
}//end main
