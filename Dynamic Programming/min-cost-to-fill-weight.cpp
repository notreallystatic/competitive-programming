/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges, the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1

Link:
https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1#

Input:
5 5
20 10 4 50 100

Output:
14

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

#define int long long

int minimumCost(vector<int> cost, int n, int W)
{
  vector<vector<int>> cache(n + 1, vector<int>(W + 1));
  for (int i = 0; i <= W; ++i)
    cache[0][i] = INT_MAX;
  for (int i = 1; i <= n; ++i)
    cache[i][0] = 0;

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= W; ++j)
    {
      if (cost[i - 1] == -1 || i > j)
        cache[i][j] = cache[i - 1][j];
      else
        cache[i][j] = min(cache[i - 1][j], cache[i][j - i] + cost[i - 1]);
    }
  }

  int totalCost = cache[n][W];
  if (totalCost == INT_MAX)
    totalCost = -1;
  return totalCost;
}

void solve()
{
  int n, w;
  cin >> n >> w;
  vector<int> cost(n);
  for (int &x : cost)
    cin >> x;
  cout << minimumCost(cost, n, w) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}