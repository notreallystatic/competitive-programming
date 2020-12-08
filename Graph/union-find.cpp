/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Implement Disjoint set union.

Link:
https://www.geeksforgeeks.org/disjoint-set-data-structures/

Input:
NA

Output:
0	0
1	0
2	0
3	3
4	3
5	3
6	3
7	3

*/

#include <iostream>
#include <stdlib.h>
#include <numeric>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <limits.h>
#include <bitset>
#include <random>

using namespace std;

struct node
{
  int parent;
  int rank;
};

class DSU
{
private:
  // {value = {parent, rank}}
  unordered_map<int, node> nodes;

public:
  DSU(int V)
  {
    for (auto i = 0; i < V; ++i)
    {
      nodes[i].parent = i;
      nodes[i].rank = 0;
    }
  }

  int find(int i)
  {
    if (i != nodes[i].parent)
      nodes[i].parent = find(nodes[i].parent);
    return nodes[i].parent;
  }

  void unionAB(const int &a, const int &b)
  {
    int rootA = find(a);
    int rootB = find(b);
    if (nodes[rootA].rank > nodes[rootB].rank)
    {
      nodes[rootB].parent = rootA;
      return;
    }
    else if (nodes[rootA].rank < nodes[rootB].rank)
    {
      nodes[rootA].parent = rootB;
      return;
    }
    nodes[rootB].parent = rootA;
    nodes[rootA].rank++;
  }

  bool isCycle(const int &src, const int &dest)
  {
    int rootSrc = find(src);
    int rootDest = find(dest);
    return rootSrc == rootDest;
  }

  void print(int v)
  {
    for (int i = 0; i < v; ++i)
    {
      cout << i << "\t" << nodes[i].parent << endl;
    }
  }
};

void solve()
{
  DSU dsu(8);
  dsu.unionAB(0, 1);
  dsu.unionAB(0, 2);
  dsu.unionAB(3, 6);
  dsu.unionAB(3, 4);
  dsu.unionAB(4, 7);
  dsu.unionAB(4, 5);
  dsu.print(8);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}