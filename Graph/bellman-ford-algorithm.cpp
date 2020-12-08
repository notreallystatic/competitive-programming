/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Implement Bellman Ford Algorithm. 

Link:
https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/

Input:
5 8
0 1 -1
1 4 2
4 3 -3
1 3 1
3 1 2
3 2 5
1 2 3
0 2 4
0

Output:
i: 0	dist[i]: 0	parent[i]: 0
i: 1	dist[i]: -1	parent[i]: 0
i: 2	dist[i]: 2	parent[i]: 1
i: 3	dist[i]: -2	parent[i]: 4
i: 4	dist[i]: 1	parent[i]: 1

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

#define pii pair<int, int>

using namespace std;

void findDistance(const int &src, const int &v, const vector<pair<int, pii>> &edges)
{

  // result[i] = weight from src to i
  // parent[i] = parent of i
  vector<int> result(v), parent(v);
  for (int i = 0; i < v; ++i)
  {
    result[i] = INT_MAX;
    parent[i] = i;
  }

  result[src] = 0;

  // We do it (v - 1) times so that we minimize edge between every other node.
  // check for every vertex, u->v that,
  // result[tv] = distance of tv from source
  // result[tu] = distance o tu from source
  // tdist = distance from u->v
  // if (result[tv] > result[tu] + tdist),
  // then it means that the distance can be further reduce, hence update it
  // edge = {src, {dest, dist}}
  for (int i = 0; i < v - 1; ++i)
  {
    for (auto x : edges)
    {
      int tu = x.first;
      int tv = x.second.first;
      int tdist = x.second.second;
      if (result[tu] != INT_MAX && result[tv] > result[tu] + tdist)
      {
        result[tv] = result[tu] + tdist;
        parent[tv] = tu;
      }
    }
  }

  // Now, we have already minimized distance of every edge, but if this distance could still be minimised then it means that there is a NEGATIVE EDGE CYCLE.
  for (auto x : edges)
  {
    int tu(x.first), tv(x.second.first), tdist(x.second.second);
    if (result[tv] > result[tu] + tdist)
    {
      cout << "Graph contains negative weight cycle" << endl;
      return;
    }
  }

  // show the result
  for (int i = 0; i < v; ++i)
  {
    cout << "i: " << i << "\tdist[i]: " << result[i] << "\tparent[i]: " << parent[i] << endl;
  }
}

void solve()
{
  int v, e, src, dest, weight;
  cin >> v >> e;
  vector<pair<int, pii>> edges;
  while (e--)
  {
    cin >> src >> dest >> weight;
    edges.push_back({src, {dest, weight}});
  }
  cin >> src;

  findDistance(src, v, edges);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}