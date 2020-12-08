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
stack<int> s;
vector<int> visited;

void reverse(vector<vi> &revAdj)
{
  for (int u = 0; u < V; ++u)
  {
    for (int v : adj[u])
    {
      revAdj[v].push_back(u);
    }
  }
}

void DFS1(int u)
{
  visited[u] = 1;
  for (int v : adj[u])
  {
    if (!visited[v])
      DFS1(v);
  }
  s.push(u);
}

void DFS2(int u, const vector<vi> &revAdj)
{
  visited[u] = 1;
  for (int v : revAdj[u])
  {
    if (!visited[v])
      DFS2(v, revAdj);
  }
}

int kosaraju()
{
  int components(0);
  vector<vi> revAdj(V);

  reverse(revAdj);

  visited = vector<int>(V, 0);

  for (int u = 0; u < V; ++u)
  {
    if (!visited[u])
    {
      DFS1(u);
    }
  }

  fill(visited.begin(), visited.end(), 0);

  while (!s.empty())
  {
    auto top = s.top();
    s.pop();
    if (!visited[top])
    {
      DFS2(top, revAdj);
      ++components;
    }
  }

  return components;
}

void addEdge(const int &u, const int &v)
{
  adj[u].push_back(v);
}

void solve()
{
  int u, v, e;
  cin >> V >> e;
  adj = vector<vi>(V);
  while (e--)
  {
    cin >> u >> v;
  }

  cout << "No. of components: " << kosaraju() << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}