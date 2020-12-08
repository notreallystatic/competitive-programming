/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Implement Kruskal's algorithm

Link:
https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/

Input:
     1--(8)---2---(7)----3
    /|        |\         |\  
(4)/ |        | \        | \
  /  |       (2) \       |  \(9)
 /   |        |   \      |   \ 
0   (11)      8    \    (14)  4
 \   |     __/|    (4)   |    /  
  \  |    /   |      \   |   /
(8)\ |  (7)  (6)      \  |  /(10)
    \| /      |        \ | /
     7--(1)---6---(2)----5
V E
dst src dest

9 14
4 0 1
8 0 7
11 1 7
8 1 2
7 7 8
1 7 6
2 2 8
6 8 6
4 2 5
2 6 5
7 2 3
9 3 4
14 3 5
10 4 5

Output:
     1        2---(7)----3
    /         |\          \  
(4)/          | \          \
  /          (2) \          \(9)
 /            |   \          \ 
0             8    \          4
 \                 (4)        
  \                  \     
(8)\                  \   
    \                  \ 
     7--(1)---6---(2)----5
dist  src  dest
1	7	6
2	2	8
2	6	5
4	0	1
4	2	5
7	2	3
8	0	7
9	3	4
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

  vector<pair<int, pair<int, int>>> createMST(int v, vector<pair<int, pair<int, int>>> &edges)
  {
    // edges[i] = {distance, {source, destination}}
    // sort all the edge pairs
    sort(edges.begin(), edges.end());
    vector<pair<int, pair<int, int>>> mstEdges;
    for (int i = 0; i < edges.size() && mstEdges.size() < v - 1; ++i)
    {
      // pick out the minimum edge from what's left behind.
      // if adding this edge doesn't create a cycle, then add it else move on.
      int src = edges[i].second.first;
      int dest = edges[i].second.second;
      if (!isCycle(src, dest))
      {
        mstEdges.push_back(edges[i]);
        unionAB(src, dest);
      }
    }
    return mstEdges;
  }
};

void solve()
{
  int v, e, src, dest, dist;
  cin >> v >> e;
  DSU graph(v);
  // edges[i] = {distance, {src, dest}}
  vector<pair<int, pair<int, int>>> edges, result;
  while (e--)
  {
    cin >> dist >> src >> dest;
    edges.push_back({dist, {src, dest}});
  }

  result = graph.createMST(v, edges);

  for (auto x : result)
  {
    cout << x.first << "\t" << x.second.first << "\t" << x.second.second << endl;
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}