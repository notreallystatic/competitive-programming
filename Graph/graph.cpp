/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Implement a graph, BFS, DFS.

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
#include <functional>
#include <random>

using namespace std;

template <typename T>
class Graph
{
public:
  bool isBiDirec;
  Graph(bool isBiDirec = true)
  {
    this->isBiDirec = isBiDirec;
  }
  // [startingEdge] = [{endingEdge, distance},...]
  map<T, list<pair<T, int>>> adjList;

  void addEdge(T u, T v, int dist = 1)
  {
    adjList[u].push_back({v, dist});
    if (isBiDirec)
      adjList[v].push_back({u, dist});
  }

  void printGraph()
  {
    for (auto n : adjList)
    {
      cout << n.first << " : ";
      for (auto p : n.second)
      {
        cout << "( " << p.first << " ," << p.second << " ) ";
      }
      cout << endl;
    }
  }

  void bfs(T source)
  {
    unordered_map<T, bool> visited;
    queue<T> q;
    q.push(source);
    while (q.size())
    {
      auto top = q.front();
      q.pop();
      if (!visited[top])
      {
        cout << top << " ";
        visited[top] = true;
      }
      for (auto p : adjList[top])
      {
        if (!visited[p.first])
          q.push(p.first);
      }
    }
    cout << endl;
  }

  void dfsUtilRecursion(T source, unordered_map<T, bool> &visited)
  {
    if (!visited[source])
    {
      visited[source] = true;
      cout << source << " ";
      for (auto p : adjList[source])
      {
        if (!visited[p.first])
        {
          dfsUtilRecursion(p.first, visited);
        }
      }
    }
  }

  void dfsUtilStack(T source)
  {
    stack<T> s;
    unordered_map<T, bool> visited;
    s.push(source);
    while (!s.empty())
    {
      auto top = s.top();
      s.pop();
      if (!visited[top])
      {
        cout << top << " ";
        visited[top] = true;
      }
      for (auto p : adjList[top])
      {
        if (!visited[p.first])
          s.push(p.first);
      }
    }
  }

  void dfs(T source)
  {
    // unordered_map<T, bool> visited;
    // dfsRecursion(source, visited);
    dfsUtilStack(source);
    cout << endl;
  }

  // for directed graph
  bool containsCycleUtilBFS(T source, unordered_map<T, bool> &visited)
  {
    unordered_map<T, bool> localVisited;
    queue<T> q;

    localVisited[source] = true;
    visited[source] = true;
    q.push(source);
    while (!q.empty())
    {
      auto top = q.front();
      q.pop();
      visited[top] = true;
      localVisited[top] = true;
      for (auto p : adjList[top])
      {
        if (localVisited[p.first])
          return true;
        else
          q.push(p.first);
      }
    }
    return false;
  }

  // for direct graph
  bool containsCycleUtilDFS(T source, unordered_map<T, bool> &visited)
  {
    unordered_map<T, bool> locallyVisited;
    stack<T> s;

    s.push(source);

    while (!s.empty())
    {
      auto top = s.top();
      s.pop();
      visited[top] = true;
      locallyVisited[top] = true;

      for (auto p : adjList[top])
      {
        if (locallyVisited[p.first])
          return true;
        else
          s.push(p.first);
      }
    }

    return false;
  }

  bool containsCycle()
  {
    unordered_map<T, bool> visited;
    for (auto x : adjList)
    {
      if (!visited[x.first])
      {
        if (containsCycleUtilBFS(x.first, visited))
          return true;
      }
    }
    return false;
  }

  void dijsktra(T source)
  {
    map<T, int> distance;
    set<pair<int, T>> s;

    for (auto x : adjList)
      distance[x.first] = INT_MAX;

    distance[source] = 0;
    s.insert({0, source});

    while (!s.empty())
    {
      auto top = *(s.begin());
      int vertex = top.second;
      int dist = top.first;
      s.erase(s.begin());

      for (auto x : adjList[vertex])
      {
        int newDistance = x.second + dist;
        if (distance[x.first] > newDistance)
        {
          s.erase({distance[x.first], x.first});
          distance[x.first] = newDistance;
          s.insert({newDistance, x.first});
        }
      }
      cout << vertex << "\t" << dist << endl;
    }
  }

  void topologicalSortUtil(T source, stack<T> &s, map<T, bool> &visited)
  {
    visited[source] = true;
    for (auto x : adjList[source])
    {
      if (!visited[x.first])
        topologicalSortUtil(x.first, s, visited);
    }
    s.push(source);
  }

  void topologicalSort()
  {
    map<T, bool> visited;
    stack<T> s;
    for (auto x : adjList)
    {
      if (!visited[x.first])
        topologicalSortUtil(x.first, s, visited);
    }
    while (!s.empty())
    {
      cout << s.top() << " ";
      s.pop();
    }
    cout << endl;
  }
};

void solve()
{
  Graph<int> g(false);
  // g.addEdge(0, 1, 4);
  // g.addEdge(0, 7, 8);
  // g.addEdge(1, 2, 8);
  // g.addEdge(1, 7, 11);
  // g.addEdge(7, 8, 7);
  // g.addEdge(7, 6, 1);
  // g.addEdge(2, 3, 7);
  // g.addEdge(2, 8, 2);
  // g.addEdge(8, 6, 6);
  // g.addEdge(6, 5, 2);
  // g.addEdge(2, 5, 4);
  // g.addEdge(3, 4, 9);
  // g.addEdge(3, 5, 14);
  // g.addEdge(4, 5, 10);
  // g.dijsktra(0);

  g.addEdge(5, 0);
  g.addEdge(5, 2);
  g.addEdge(2, 3);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(1, 3);
  g.topologicalSort();
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}