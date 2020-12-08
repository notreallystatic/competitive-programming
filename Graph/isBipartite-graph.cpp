/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:


Link:


Input:


Output:


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

#define vi vector<int>

using namespace std;

int V;
vector<vi> adj;

void addEdge(const int &u, const int &v)
{
  adj[u].push_back(v);
}

bool isBipartiteUtil(const int &src, vector<int> &color)
{
  queue<int> q;
  color[src] = 1;
  q.push(src);
  while (!q.empty())
  {
    auto u = q.front();
    q.pop();
    for (int v : adj[u])
    {
      if (u == v) // there is a loop
        return false;
      if (color[v] == -1) // if not yet colored
      {
        color[v] = 1 - color[u];
        q.push(v);
      }
      else if (color[v] == color[u]) // if color matches to the current vertex
        return false;
    }
  }
  return true;
}

bool isBipartite()
{
  vector<int> color(V, -1);
  for (int u = 0; u < V; ++u)
  {
    if (color[u] == -1 && !isBipartiteUtil(u, color))
    {
      return false;
    }
  }
  return true;
}

void solve()
{
  int e, u, v;
  cin >> V >> e;

  adj = vector<vi>(V);

  while (e--)
  {
    cin >> u >> v;
    addEdge(u, v);
  }

  cout << isBipartite() << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}