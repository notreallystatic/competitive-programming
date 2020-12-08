/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Find all the bridges in a graph

Link:
https://codeforces.com/blog/entry/71146

Input:
5 5
0 1
1 2
2 3
3 4
4 1

             2
            / \
           /   \
   0------1     3
           \   /
            \ /
             4
              

Output:
0 1

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

int V, time;
vector<vector<int>> adj;
vector<int> disc, low;
vector<pair<int, int>> bridges;

void addEdge(const int &u, const int &v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void dfsBR(int u, int p)
{
  disc[u] = low[u] = ++time;
  for (int v : adj[u])
  {
    if (v == p)
      continue;
    if (!disc[v])
    {                       // if not yet visited
      dfsBR(v, u);          // recursive DFS call
      if (disc[u] < low[v]) // condition to find a bridge
        bridges.push_back({u, v});
      low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
    }
    else
    {                                // already discovered
      low[u] = min(low[u], disc[v]); // finds the ancestor with the least discovery time
    }
  }
}

void BR()
{
  time = 0;
  disc = low = vector<int>(V);
  for (int u = 0; u < V; ++u)
  {
    if (!disc[u])
      dfsBR(u, u);
  }

  for (auto edge : bridges)
  {
    cout << edge.first << " " << edge.second << endl;
  }
}

void solve()
{
  int u, v, e;
  cin >> V >> e;
  adj = vector<vector<int>>(V);
  while (e--)
  {
    cin >> u >> v;
    addEdge(u, v);
  }
  BR();
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}