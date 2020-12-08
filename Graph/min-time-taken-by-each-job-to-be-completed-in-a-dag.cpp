/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given a Directed Acyclic Graph having V vertices and E edges, where each edge {U, V} represents the Jobs U and V such that Job V can only be started only after completion of Job U. The task is to determine the minimum time taken by each job to be completed where each Job takes unit time to get completed.

Link:
https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/

Input:
10 13
1 3
1 4
1 5
2 3
2 8
2 9
3 6
4 6
4 8
5 8
6 7
7 8
8 10

Output:
1	1
2	1
3	2
4	2
5	2
6	3
7	4
8	5
9	2
10 6

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

#define V 1000

using namespace std;

class Graph
{
private:
  vector<int> adj[V];
  vector<int> inDegree;

public:
  Graph()
  {
    inDegree.resize(V);
    fill(inDegree.begin(), inDegree.end(), 0);
  }

  void addEdge(const int &u, const int &v)
  {
    adj[u].push_back(v);
    ++inDegree[v];
  }

  void jobTime(const int &n)
  {
    vector<int> time(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; ++i)
    {
      if (inDegree[i] == 0)
      {
        q.push(i);
        time[i] = 1;
      }
    }

    while (!q.empty())
    {
      int top = q.front();
      q.pop();

      for (int v : adj[top])
      {
        --inDegree[v];
        if (time[v] < 1 + time[top])
          time[v] = 1 + time[top];
        if (inDegree[v] == 0)
          q.push(v);
      }
    }

    for (int i = 1; i <= n; ++i)
    {
      cout << i << "\t" << time[i] << endl;
    }
  }
};

void solve()
{
  int n, m, u, v;

  cin >> n >> m;
  Graph g;
  while (m--)
  {
    cin >> u >> v;
    g.addEdge(u, v);
  }

  g.jobTime(n);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}