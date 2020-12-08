/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
There are a total of n tasks you have to pick, labeled from 0 to n-1. Some tasks may have prerequisites, for example to pick task 0 you have to first pick task 1, which is expressed as a pair: [0, 1]

Given the total number of tasks and a list of prerequisite pairs, is it possible for you to finish all tasks?

Link:
https://www.geeksforgeeks.org/find-whether-it-is-possible-to-finish-all-tasks-or-not-from-given-dependencies/

Input:
3
1 0
2 1
3 2

Output:
1

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
  unordered_map<int, vector<pair<int, int>>> adj;

public:
  void addEdge(const int &u, const int &v)
  {
    adj[u].push_back({v, 1});
  }

  bool containsCycle(const int &source, unordered_map<int, int> &locallyVisited, unordered_map<int, int> &visited)
  {
    if (visited[source])
      return false;
    visited[source] = locallyVisited[source] = true;
    for (auto x : adj[source])
    {
      if (locallyVisited[x.first] || containsCycle(x.first, locallyVisited, visited))
        return true;
    }
    return locallyVisited[source] = false;
  }

  bool isPossible()
  {
    unordered_map<int, int> locallyVisited;
    unordered_map<int, int> visited;
    for (auto x : adj)
    {
      if (!visited[x.first] && containsCycle(x.first, locallyVisited, visited))
        return false;
    }
    return true;
  }
};

void solve()
{
  Graph g;
  int m, u, v;
  cin >> m;
  while (m--)
  {
    cin >> u >> v;
    g.addEdge(u, v);
  }
  cout << g.isPossible() << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}