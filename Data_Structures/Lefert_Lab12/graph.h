#include <iostream>
using namespace std;
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
class graph
{
private:
  int* cost;
  //node* nodeArr;
  int nodes;
public:
  graph();
  ~graph();
  int** BFS();
  int** DFS();
  int* Kruskal();
  int* Prim();
};
#endif
