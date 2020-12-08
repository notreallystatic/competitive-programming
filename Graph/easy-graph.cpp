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

using namespace std;

class Graph
{
private:
  int V;
  bool isBiDirectional;
  vector<vector<int>> adjM;
  vector<vector<int>> adjL;

public:
  Graph(const int &V, bool isBiDirectional = true)
  {
    this->V = V;
    this->isBiDirectional = isBiDirectional;
    /* 
    Let, V = 4
      {   0  1  2  3
      0  {0, 0, 0, 0},
      1  {0, 0, 0, 0},
      2  {0, 0, 0, 0},
      3  {0, 0, 0, 0}
      } 
    */

    this->adjM = vector<vector<int>>(V, vector<int>(V, 0));
    /*
      {
      0  {},
      1  {},
      2  {},
      3  {}
      }
    */
    this->adjL = vector<vector<int>>(V);
  }

  void addEdge(const int &u, const int &v)
  {
    adjL[u].push_back(v);
    if (isBiDirectional)
      adjL[v].push_back(u);
  }

  void dfsUtil(int src, vector<int> &visited)
  {
    visited[src] = true;
    cout << src << " ";
    for (int v : adjL[src])
    {
      if (!visited[v])
        dfsUtil(v, visited);
    }
  }

  void dfs()
  {
    vector<int> visited(V, 0);

    cout << "DFS:\t";
    for (int u = 0; u < V; ++u)
    {
      if (!visited[u])
        dfsUtil(u, visited);
    }
    cout << endl;
  }

  void bfsUtil(int src, vector<int> &visited)
  {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
      int u = q.front();
      cout << u << " ";
      q.pop();
      for (int v : adjL[u])
      {
        if (!visited[v])
        {
          q.push(v);
          visited[v] = true;
        }
      }
    }
  }

  void bfs()
  {
    vector<int> visited(V, 0);

    cout << "BFS:\t";
    for (int u = 0; u < V; ++u)
    {
      if (!visited[u])
        bfsUtil(u, visited);
    }
    cout << endl;
  }

  void topoSortUtil(int src, vector<int> &visited, stack<int> &result)
  {
    for (int v : adjL[src])
    {
      if (!visited[v])
        topoSortUtil(v, visited, result);
    }
    visited[src] = true;
    result.push(src);
  }

  void topoSort()
  {
    // only possible when there are no self loops & no cycles.
    vector<int> visited(V, 0);
    stack<int> result;
    for (int u = 0; u < V; ++u)
    {
      if (!visited[u])
        topoSortUtil(u, visited, result);
    }

    cout << "Topological Sort:\t";
    while (!result.empty())
    {
      cout << result.top() << " ";
      result.pop();
    }
    cout << endl;
  }
};

void solve()
{
  int V, v, u, e;
  cin >> V >> e;
  Graph g(V);

  while (e--)
  {
    cin >> u >> v;
    g.addEdge(u, v);
  }

  g.bfs();
  g.dfs();
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}