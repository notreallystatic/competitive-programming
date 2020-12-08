/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Implement Prim's algorithm

Link:
https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/

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
distance src dest
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

     1--(8)---2---(7)----3
    /         |\          \  
(4)/          | \          \
  /          (2) \          \(9)
 /            |   \          \ 
0             8    \          4
                   (4)     
                     \   
                      \  
                       \ 
     7--(1)---6---(2)----5
  
4	1	0
8	2	1
2	8	2
4	5	2
2	6	5
1	7	6
7	3	2
9	4	3

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

class Graph
{
private:
  // source = {destination, distance}
  int v;
  unordered_map<int, vector<pair<int, int>>> adj;

public:
  // {distance, {src, dest}}
  Graph(const int &v)
  {
    this->v = v;
  }

  void addEdge(const int &src, const int &dest, const int &distance)
  {
    adj[src].push_back({dest, distance});
    adj[dest].push_back({src, distance});
  }

  void createMst()
  {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    unordered_map<int, bool> visited;

    // {distance, {source, parent}}
    vector<pair<int, pair<int, int>>> mst;
    pq.push({0, {0, 0}});
    while (mst.size() <= v - 1)
    {
      auto top = pq.top();
      pq.pop();
      int src = top.second.first;
      int parent = top.second.second;
      int dist = top.first;

      if (!visited[src] || !visited[parent])
      {
        mst.push_back(top);
        visited[src] = true;
        visited[parent] = true;
        for (auto x : adj[src])
        {
          pq.push({x.second, {x.first, src}});
        }
      }
    }

    mst.erase(mst.begin());

    for (auto x : mst)
    {
      cout << x.first << "\t" << x.second.first << "\t" << x.second.second << endl;
    }
  }
};

void solve()
{
  int v, e, src, dest, distance;
  cin >> v >> e;
  Graph g(v);
  while (e--)
  {
    cin >> distance >> src >> dest;
    g.addEdge(src, dest, distance);
  }
  g.createMst();
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}