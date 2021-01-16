/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Find out maximum amount of gold he can collect.

Link:
https://www.geeksforgeeks.org/gold-mine-problem/

Input:
4 4
10 33 13 15
22 21 04 1
5 0 2 3
0 6 14 2

Output:
83
83

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

int m, n;
vector<vector<int>> goldMine;

vector<vector<int>> directions;

bool isValid(const int &x, const int &y)
{
  if (x >= 0 && x < m && y >= 0 && y < n)
    return true;
  return false;
}

int max(const int &a, const int &b, const int &c)
{
  return max(a, max(b, c));
}

int maxGoldRecurrence(int x, int y)
{
  int curValue = goldMine[x][y];
  for (auto &cell : directions)
  {
    int nx = x + cell[0];
    int ny = y + cell[1];
    if (isValid(nx, ny))
    {
      curValue = max(curValue, goldMine[x][y] + maxGoldRecurrence(nx, ny));
    }
  }
  return curValue;
}

int maxGold()
{
  for (int i = 0; i < n; ++i)
  {
    for (int j = 1; j < m; ++j)
    {
      if (i == 0)
      {
        // in the first row, we can only move from the left or from the left bottom diagonal
        goldMine[i][j] += max(goldMine[i][j - 1], goldMine[i + 1][j - 1]);
      }
      else if (i == n - 1)
      {
        // in the last row, we can only move from the left or from the upper left diagonal
        goldMine[i][j] += max(goldMine[i][j - 1], goldMine[i - 1][j - 1]);
      }
      else
      {
        goldMine[i][j] += max(goldMine[i - 1][j - 1], goldMine[i][j - 1], goldMine[i + 1][j - 1]);
      }
    }
  }
  auto result = INT_MIN;
  for (int i = 0; i < n; ++i)
  {
    result = max(result, goldMine[i][m - 1]);
  }
  return result;
}

void solve()
{
  cin >> n >> m;

  goldMine = vector<vector<int>>(n, vector<int>(m));
  for (auto &row : goldMine)
  {
    for (auto &cell : row)
    {
      cin >> cell;
    }
  }
  // directions:
  // right up diagonal: (-1, 1)
  // right: (0, 1)
  // right down diagonal: (1, 1)

  directions = {{-1, 1}, {0, 1}, {1, 1}};
  int result = INT_MIN;
  for (int i = 0; i < m; ++i)
  {
    result = max(result, maxGoldRecurrence(i, 0));
  }
  cout << result << endl;
  cout << maxGold() << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}