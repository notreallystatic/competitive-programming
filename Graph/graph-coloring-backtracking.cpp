/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an undirected graph and a number m, determine if the graph can be coloured with at most m colours such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. 

Link:
https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/

Input:
4 3
0 1 1 1 
1 0 1 0
1 1 0 1
1 0 1 0

Output:
0	1
1	2
2	3
3	2

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

int V, m;

bool isSafe(int v, int c, const vector<vi> &graph, vi &color)
{
  for (int i = 0; i < V; ++i)
  {
    if (graph[v][i] && color[i] == c)
      return false;
  }
  return true;
}

bool colorGraph(int v, vi &color, const vector<vi> &graph)
{
  if (v == V)
    return true;
  for (int i = 1; i <= m; ++i)
  {
    if (isSafe(v, i, graph, color))
    {
      color[v] = i;
      if (colorGraph(v + 1, color, graph))
        return true;
      color[v] = 0;
    }
  }
  return false;
}

void solve()
{
  cin >> V >> m;
  vector<vi> graph(V, vi(V, 0));
  for (int i = 0; i < V; ++i)
  {
    for (int j = 0; j < V; ++j)
    {
      cin >> graph[i][j];
    }
  }

  vi color(V, 0);

  if (colorGraph(0, color, graph))
  {
    for (int i = 0; i < V; ++i)
    {
      cout << i << "\t" << color[i] << endl;
    }
  }
  else
  {
    cout << "Not Possible" << endl;
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