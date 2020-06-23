#include <string>
#include <iostream>
#include <limits.h>
#include <fstream>
#include <float.h>
using namespace std;
//arrays that hold all my strings and probablilies
const int arraySize = 20;
int nodesInTree = 0;
string arry[arraySize];
int freq[arraySize];
float prob[arraySize];

//parses data.txt so all the strings are read in and probablilies are calculated
void parse()
{
  //variables to hold stuff from data.txt
  int total = 0;
  string newData;
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
      bool alreadyInTable = false;
      //checks if the string array already has that value
      for(int i = 0; i < arraySize; i++)
      {
        if(arry[i] == newData)
        {
          freq[i] = freq[i] + 1;
          total = total + 1;
          alreadyInTable = true;
          //cout << arry[i] << ":" << freq[i] << " ";
          break;
        }
      }//end for
      //looks for an empty spot in the array if the value is not in the array
      if(alreadyInTable == false)
      {
        for(int k = 0; k < arraySize; k++)
        {
          if(arry[k] == "")
          {
            arry[k] = newData;
            freq[k] = 1;
            total = total + 1;
            nodesInTree++;
            //cout << arry[k] << ":" << freq[k] << " ";
            break;
          }
        }//end for
      }
    }//end while for data read
    //calculating the probablilies for each string
    //cout << "Total words: " << total << endl;
    int x = 0;
    while(arry[x] != "")
    {
      //cout << "string: " << arry[x] << " freq: " << freq[x];
      prob[x] = (float)freq[x] / (float)total;
      // cout << " probability: " << prob[x] << endl;
      x++;
      //cout << arry[x] << ":" << prob[x] << " ";
    }
    cout << endl;
  }//end else
}//end parse

//sums probablilies
float probSum(int i, int j)
{
    float s = 0;
    for (int k = i; k <= j; k++)
       s += prob[k];
    return s;
}

void optimalSearchTreeCost()
{
    //t table
    float cost[nodesInTree][nodesInTree];

    // set the cost of a node to its probability
    for (int i = 0; i < nodesInTree; i++)
    {
        cost[i][i] = prob[i];
    }

    //chains of length > 1
    for (int L = 2; L <=nodesInTree; L++)
    {
        // i is row number in cost[][]
        for (int i = 0; i <= nodesInTree - L + 1; i++)
        {
            // Get column number j from row number i and
            // chain length L
            int j = i + L - 1;
            cost[i][j] = FLT_MAX;

            // Try making all keys in interval keys[i..j] as root
            for (int r = i; r <= j; r++)
            {
               // c = cost when keys[r] becomes root of this subtree
               float c = ((r > i)? cost[i][r-1]:0) + ((r < j)? cost[r+1][j]:0) + probSum(i, j);
               if(c < cost[i][j])
               {
                 cost[i][j] = c;
               }//close if
            }//close for
        }//close for
    }//close chains for
    // for(int ty = 0; ty < nodesInTree; ty++)
    // {
    //   for(int xy = 0; xy < nodesInTree; xy++)
    //   {
    //     cout << cost[ty][xy] << " ";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    cout << "The Minimal Cost of the Tree is: " << cost[0][nodesInTree - 1] << endl;
}

void optimalSearchTreeStructure()
{

}

int main()
{
  //sets up arrays
  parse();
  // for(int ty = 0; ty < nodesInTree; ty++)
  // {
  //   cout << arry[ty] << ":" << prob[ty] << " ";
  // }
  // cout << endl;
  optimalSearchTreeCost();
  optimalSearchTreeStructure();
  return 0;
}
