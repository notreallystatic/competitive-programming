/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Find the articulation points in a graph.

Link:
https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
https://codeforces.com/blog/entry/71146

Input:

  1-----0--------3
  |    /         |
  |   /          |
  |  /           |
  | /            |
  |/             |
  2              4


5 5
1 0
0 3
2 1
0 2
3 4

Output:
0 3

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

int time;
vector<int> ap, low, disc;
vector<int> adj[100];

void addEdge(const int &u, const int &v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

/*
  Conditions:
    1) u is root of DFS tree and it has at least two children.
    2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v has a back edge to one of the ancestors (in DFS tree) of u.
*/

int dfsAP(int u, int p)
{
  int children = 0;
  disc[u] = low[u] = ++time;
  for (int v : adj[u])
  {
    if (v == p) // we don't want to go back through the same path
      continue; // if we go back is because we found another way back
    if (!disc[v])
    { // if v had not been discovered
      ++children;
      dfsAP(v, u);
      if (disc[u] <= low[v]) // condition #2
        ap[u] = 1;
      low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
    }
    else
    {                                // if v was already discovered means that we found an ancestor
      low[u] = min(low[u], disc[v]); // find the ancestor with the least discovery time
    }
  }
  return children;
}

void AP(const int &V)
{
  time = 0;
  for (int u = 0; u < V; ++u)
  {
    if (!disc[u])
      ap[u] = dfsAP(u, u) > 1; // condition #1
  }

  for (int u = 0; u < V; ++u)
  {
    if (ap[u])
      cout << u << " ";
  }
}

void solve()
{
  int V, u, e, v;
  cin >> V >> e;
  ap = low = disc = vector<int>(V);
  while (e--)
  {
    cin >> u >> v;
    addEdge(u, v);
  }
  AP(V);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}