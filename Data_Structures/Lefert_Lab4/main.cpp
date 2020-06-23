#include <fstream>
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<iomanip>
#include "hashTableDouble.h"
#include "hashTableQuad.h"
#include "hashTable.h"
using namespace std;

int main()
{
  // What the user chooses
  string choice;
  //exit bool
  bool exit = false;

  while(exit != true)
  {
  cout << "Choose one operation from the options below." << endl;
  cout << "1. Test Hash Tables" << endl;
  cout << "2. Performance Comparison" << endl;
  cout << "3. Exit" << endl;

  cin >> choice;


  if(choice == "1")
  {

      hashTableDouble* doub = new hashTableDouble(7, 5);
      hashTableQuad* quad = new hashTableQuad(7);
      hashTable* table = new hashTable(7);
      int newData;
      ifstream infile;
      infile.open("data.txt");
      if(infile.fail())
      {
        cout << "File Could not Open" << endl;
      }
      else
    {
      //reads from the file into the hash table
      while(infile>>newData)
      {
        doub ->doubleInsert(newData);
        quad->quadInsert(newData);
        table->hashInsert(newData);
      }
    }
    cout << "Open hashing:" << endl;
    table->hashPrint();
    cout << "Hash Table with Quadratic Probing:" << endl;
    quad->quadPrint();
    cout << "Hash Table with Double Hashing:" << endl;
    doub->doublePrint();
    delete table;
    delete quad;
    delete doub;
  }
  if(choice == "2")
  {
    // ints to keep track of time results
    float openBuild1;
    float openBuild2;
    float openBuild3;
    float openBuild4;
    float openBuild5;
    float doubleBuild1;
    float doubleBuild2;
    float doubleBuild3;
    float doubleBuild4;
    float doubleBuild5;
    float quadBuild1;
    float quadBuild2;
    float quadBuild3;
    float quadBuild4;
    float quadBuild5;
    float openFound1;
    float openFound2;
    float openFound3;
    float openFound4;
    float openFound5;
    float quadFound1;
    float quadFound2;
    float quadFound3;
    float quadFound4;
    float quadFound5;
    float doubleFound1;
    float doubleFound2;
    float doubleFound3;
    float doubleFound4;
    float doubleFound5;
    float openNotFound1;
    float openNotFound2;
    float openNotFound3;
    float openNotFound4;
    float openNotFound5;
    float quadNotFound1;
    float quadNotFound2;
    float quadNotFound3;
    float quadNotFound4;
    float quadNotFound5;
    float doubleNotFound1;
    float doubleNotFound2;
    float doubleNotFound3;
    float doubleNotFound4;
    float doubleNotFound5;
    int mValues = 1000003;
    //control how many times the random number inserter loop runs
    int loopNum = 0;
    //control how many times we run the timer experiment
    int controlLoop = 0;
    //int to keep track of total for building the averaging
    float buildTotal = 0;
    //keeps track of total for found values
    float foundTotal = 0;
    //keeps track of total not found values
    float notFoundTotal = 0;
    //build clock variable
    clock_t t;
    //found clock variable
    clock_t s;
    //not found clock variable
    clock_t d;

    //double hashing with 100000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTableDouble* doub = new hashTableDouble(mValues, 100003);
      while(loopNum < floor(((double)mValues * .1)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        doub->doubleInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      while(loopNum < floor((double)mValues * .01))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(doub -> doubleFind(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      delete doub;
    }
    doubleBuild1 = buildTotal / (double)controlLoop;
    doubleFound1 = foundTotal / (double)controlLoop;
    doubleNotFound1 = notFoundTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //double with 200000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTableDouble* doub = new hashTableDouble(mValues, 100003);
      while(loopNum < floor(((double)mValues * .2)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        doub->doubleInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      while(loopNum < floor((double)mValues * .02))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(doub -> doubleFind(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      delete doub;
    }
    doubleBuild2 = buildTotal / (double)controlLoop;
    doubleFound2 = foundTotal / (double)controlLoop;
    doubleNotFound2 = notFoundTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //double with 300000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTableDouble* doub = new hashTableDouble(mValues, 100003);
      while(loopNum < floor(((double)mValues * .3)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        doub->doubleInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      while(loopNum < floor((double)mValues * .03))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(doub -> doubleFind(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      delete doub;
    }
    doubleBuild3 = buildTotal / (double)controlLoop;
    doubleFound3 = foundTotal / (double)controlLoop;
    doubleNotFound3 = notFoundTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //double with 400000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTableDouble* doub = new hashTableDouble(mValues, 100003);
      while(loopNum < floor(((double)mValues * .4)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        doub->doubleInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      while(loopNum < floor((double)mValues * .04))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(doub -> doubleFind(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      delete doub;
    }
    doubleBuild4 = buildTotal / (double)controlLoop;
    doubleFound4 = foundTotal / (double)controlLoop;
    doubleNotFound4 = notFoundTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //double with 500000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTableDouble* doub = new hashTableDouble(mValues, 100003);
      while(loopNum < floor(((double)mValues * .5)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        doub->doubleInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      controlLoop++;
      loopNum = 0;
      while(loopNum < floor((double)mValues * .05))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(doub -> doubleFind(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      delete doub;
    }
    doubleBuild5 = buildTotal / (double)controlLoop;
    doubleFound5 = foundTotal / (double)controlLoop;
    doubleNotFound5 = notFoundTotal / (double)controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //quad with 100000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTableQuad* quad = new hashTableQuad(mValues);
      //makes the table
      while(loopNum < floor(((double)mValues * .1)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        quad->quadInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      loopNum = 0;

      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      //does the find and not finds
      while(loopNum < floor((double)mValues * .01))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(quad -> quadFind(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      controlLoop++;
      delete quad;
      loopNum = 0;
    }
    quadBuild1 = buildTotal / (float) controlLoop;
    quadFound1 = foundTotal / (float) controlLoop;
    quadNotFound1 = notFoundTotal / (float) controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //quad with 200000while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTableQuad* quad = new hashTableQuad(mValues);
      //makes the table
      while(loopNum < floor(((double)mValues * .2)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        quad->quadInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      loopNum = 0;

      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      //does the find and not finds
      while(loopNum < floor((double)mValues * .02))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(quad -> quadFind(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      controlLoop++;
      delete quad;
      loopNum = 0;
    }
    quadBuild2 = buildTotal / (float) controlLoop;
    quadFound2 = foundTotal / (float) controlLoop;
    quadNotFound2 = notFoundTotal / (float) controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //quad table with 300000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTableQuad* quad = new hashTableQuad(mValues);
      //makes the table
      while(loopNum < floor(((double)mValues * .3)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        quad->quadInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      loopNum = 0;

      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      //does the find and not finds
      while(loopNum < floor((double)mValues * .03))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(quad -> quadFind(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      controlLoop++;
      delete quad;
      loopNum = 0;
    }
    quadBuild3 = buildTotal / (float) controlLoop;
    quadFound3 = foundTotal / (float) controlLoop;
    quadNotFound3 = notFoundTotal / (float) controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //quad table with 400000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTableQuad* quad = new hashTableQuad(mValues);
      //makes the table
      while(loopNum < floor(((double)mValues * .4)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        quad->quadInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      loopNum = 0;

      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      //does the find and not finds
      while(loopNum < floor((double)mValues * .04))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(quad -> quadFind(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      controlLoop++;
      delete quad;
      loopNum = 0;
    }
    quadBuild4 = buildTotal / (float) controlLoop;
    quadFound4 = foundTotal / (float) controlLoop;
    quadNotFound4 = notFoundTotal / (float) controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //quad table with 500000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTableQuad* quad = new hashTableQuad(mValues);
      //makes the table
      while(loopNum < floor(((double)mValues * .5)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        quad->quadInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      loopNum = 0;

      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      //does the find and not finds
      while(loopNum < floor((double)mValues * .05))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(quad -> quadFind(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      controlLoop++;
      delete quad;
      loopNum = 0;
    }
    quadBuild5 = buildTotal / (float) controlLoop;
    quadFound5 = foundTotal / (float) controlLoop;
    quadNotFound5 = notFoundTotal / (float) controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //open with 100000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTable* table = new hashTable(mValues);
      //makes the table
      while(loopNum < floor(((double)mValues * .1)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        table->hashInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      loopNum = 0;

      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      //does the find and not finds
      while(loopNum < floor((double)mValues * .01))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(table -> find(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      controlLoop++;
      delete table;
      loopNum = 0;
    }
    openBuild1 = buildTotal / (float) controlLoop;
    openFound1 = foundTotal / (float) controlLoop;
    openNotFound1 = notFoundTotal / (float) controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //open with 200000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTable* table = new hashTable(mValues);
      //makes the table
      while(loopNum < floor(((double)mValues * .2)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        table->hashInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      loopNum = 0;

      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      //does the find and not finds
      while(loopNum < floor((double)mValues * .02))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(table -> find(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      controlLoop++;
      delete table;
      loopNum = 0;
    }
    openBuild2 = buildTotal / (float) controlLoop;
    openFound2 = foundTotal / (float) controlLoop;
    openNotFound2 = notFoundTotal / (float) controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //open with 300000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTable* table = new hashTable(mValues);
      //makes the table
      while(loopNum < floor(((double)mValues * .3)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        table->hashInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      loopNum = 0;

      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      //does the find and not finds
      while(loopNum < floor((double)mValues * .03))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(table -> find(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      controlLoop++;
      delete table;
      loopNum = 0;
    }
    openBuild3 = buildTotal / (float) controlLoop;
    openFound3 = foundTotal / (float) controlLoop;
    openNotFound3 = notFoundTotal / (float) controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //open with 400000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTable* table = new hashTable(mValues);
      //makes the table
      while(loopNum < floor(((double)mValues * .4)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        table->hashInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      loopNum = 0;

      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      //does the find and not finds
      while(loopNum < floor((double)mValues * .04))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(table -> find(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      controlLoop++;
      delete table;
      loopNum = 0;
    }
    openBuild4 = buildTotal / (float) controlLoop;
    openFound4 = foundTotal / (float) controlLoop;
    openNotFound4 = notFoundTotal / (float) controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    //open with 500000
    while(controlLoop < 5)
    {
      //setting random seed
      srand(time(NULL));
      //start timer
      t = clock();
      hashTable* table = new hashTable(mValues);
      //makes the table
      while(loopNum < floor(((double)mValues * .5)))
      {
        //generates a random number from 1 - 5mValues
        int num = rand()%(mValues * 5) + 1;
        table->hashInsert(num);
        loopNum++;
      //  cout << loopNum << endl;
      }
      loopNum = 0;

      //end timer
      t = clock() - t;
      t = ((float)t/CLOCKS_PER_SEC) * 1000;
      //cout << "Cycle time: " << t << endl;
      buildTotal = t + buildTotal;
      //does the find and not finds
      while(loopNum < floor((double)mValues * .05))
      {
        //starts the find timer
        t = clock();
        //generates a random number
        int num = rand()%(mValues * 5) + 1;
        if(table -> find(num) == true)
        {
          t = clock() - t;
          s = s + t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          foundTotal = foundTotal + t;
        }
        else
        {
          t = clock() - t;
          //t = ((float)t/CLOCKS_PER_SEC) * 1000;
          d = d + t;
          notFoundTotal = notFoundTotal + t;
        }
        s = ((float)s/CLOCKS_PER_SEC) * 1000;
        d = ((float)d/CLOCKS_PER_SEC) * 1000;
        foundTotal = s + foundTotal;
        notFoundTotal = d + notFoundTotal;
        loopNum++;
      }
      controlLoop++;
      delete table;
      loopNum = 0;
    }
    openBuild5 = buildTotal / (float) controlLoop;
    openFound5 = foundTotal / (float) controlLoop;
    openNotFound5 = notFoundTotal / (float) controlLoop;
    buildTotal = 0;
    controlLoop = 0;
    loopNum = 0;
    foundTotal = 0;
    notFoundTotal = 0;

    cout <<  fixed << setprecision(3) << "Performance (Open Hashing):" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "|               | 100,000 | 200,000 | 300,000 | 400,000 | 500,000 |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Build(ms)     |  "<< openBuild1 <<"  | "<< openBuild2 <<" | "<< openBuild3 <<" | "<< openBuild4 <<" | "<< openBuild5 <<" |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Found(ms)     |  "<< openFound1 <<"  |  "<< openFound2 <<"  |  "<< openFound3 <<"  |  "<< openFound4 <<"  |  "<< openFound5 <<"  |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Not Found(ms) |  "<< openNotFound1 <<"  | "<< openNotFound2 <<"  |  "<< openNotFound3 <<" | "<< openNotFound4 <<"  | "<< openNotFound5 <<"  |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

    cout <<  fixed << setprecision(3) << "Performance (Double Probing):" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "|               | 100,000 | 200,000 | 300,000 | 400,000 | 500,000 |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Build(ms)     |  "<< doubleBuild1 <<"  | "<< doubleBuild2 <<" | "<< doubleBuild3 <<" | "<< doubleBuild4 <<" | "<< doubleBuild5 <<" |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Found(ms)     |  "<< doubleFound1 <<"  |  "<< doubleFound2 <<"  |  "<< doubleFound3 <<"  |  "<< doubleFound4 <<"  |  "<< doubleFound5 <<"  |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Not Found(ms) |  "<< doubleNotFound1 <<"  | "<< doubleNotFound2 <<"  |  "<< doubleNotFound3 <<" | "<< doubleNotFound4 <<"  | "<< doubleNotFound5 <<"  |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

    cout <<  fixed << setprecision(3) << "Performance (Quadratic Probing):" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "|               | 100,000 | 200,000 | 300,000 | 400,000 | 500,000 |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Build(ms)     |  "<< quadBuild1 <<"  | "<< quadBuild2 <<" | "<< quadBuild3 <<" | "<< quadBuild4 <<" | "<< quadBuild5 <<" |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Found(ms)     |  "<< quadFound1 <<"  |  "<< quadFound2 <<"  |  "<< quadFound3 <<"  |  "<< quadFound4 <<"  |  "<< quadFound5 <<"  |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;

                                cout << "| Not Found(ms) |  "<< quadNotFound1 <<"  | "<< quadNotFound2 <<"  |  "<< quadNotFound3 <<" | "<< quadNotFound4 <<"  | "<< quadNotFound5 <<"  |" << endl;

                                cout << "-------------------------------------------------------------------" << endl;
  }//ends option 2
  if(choice == "3")
  {
    //exit
    exit = true;
  }

}//ends menu while

return 0;
}
