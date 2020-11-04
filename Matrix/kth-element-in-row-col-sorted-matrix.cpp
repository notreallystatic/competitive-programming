/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Link:
https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1#

Input:
4 3
16 28 60 64
22 41 63 91
27 50 87 93
36 78 87 94

Output:
27

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

int kthSmallest(const vector<vector<int>> &matrix, int n, int k)
{
  // {element, {rowIndex, colIndex}}
  priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
  for (int i = 0; i < n; ++i)
  {
    pq.push({matrix[0][i], {0, i}});
  }
  --k;
  while (k--)
  {
    auto top = pq.top();
    pq.pop();
    int i = top.second.first;
    int j = top.second.second;
    if (i + 1 < n)
    {
      ++i;
      pq.push({matrix[i][j], {i, j}});
    }
  }
  return pq.top().first;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<vector<int>> matrix(n, vector<int>(n, 0));

  for (auto &row : matrix)
  {
    for (int &x : row)
    {
      cin >> x;
    }
  }

  cout << kthSmallest(matrix, n, k) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}