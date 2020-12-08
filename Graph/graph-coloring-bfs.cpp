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

void colorGraph(const vector<vi> &graph)
{
  vi color(V, 1);
  vi visited(V, 0);

  for (int i = 0; i < V; ++i)
  {
    if (visited[i])
      continue;
    queue<int> q;
    int maxColor = 1;
    q.push(i);
    while (!q.empty())
    {
      auto top = q.front();
      q.pop();
      for (int i = 0; i < V; ++i)
      {
        // if there exists an edge
        if (graph[top][i])
        {
          // check if the color is same
          if (color[i] == color[top])
          {
            color[i]++;
            maxColor = max(maxColor, max(color[i], color[top]));
            if (maxColor > m)
            {
              cout << "Not possible" << endl;
              return;
            }
          }
          if (!visited[i])
          {
            q.push(i);
            visited[i] = 1;
          }
        }
      }
    }
  }

  for (int i = 0; i < V; ++i)
  {
    cout << i << "\t" << color[i] << endl;
  }
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

  colorGraph(graph);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}