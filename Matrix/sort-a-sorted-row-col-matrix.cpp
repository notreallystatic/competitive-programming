/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an n x n matrix, where every row and column is sorted in non-decreasing order. Print all elements of matrix in sorted order.

Link:
https://practice.geeksforgeeks.org/problems/sorted-matrix/0#

Input:
2
4
10 20 30 40 15 25 35 45 27 29 37 48 32 33 39 50
3
1 3 4 2 6 7 5 8 9

Output:
10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50 
1 2 3 4 5 6 7 8 9 

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
#define inf INT_MAX

using namespace std;

void youngify(vector<vector<int>> &matrix, int i, int j, const int &n)
{
  int right = (j + 1) < n ? matrix[i][j + 1] : inf;
  int bottom = (i + 1) < n ? matrix[i + 1][j] : inf;

  if (right == inf && bottom == inf)
    return;
  if (right < bottom)
  {
    swap(matrix[i][j], matrix[i][j + 1]);
    youngify(matrix, i, j + 1, n);
  }
  else
  {
    swap(matrix[i][j], matrix[i + 1][j]);
    youngify(matrix, i + 1, j, n);
  }
}

int extractMin(vector<vector<int>> &matrix, const int &n)
{
  int top = matrix[0][0];
  matrix[0][0] = inf;
  youngify(matrix, 0, 0, n);
  return top;
}

// Young tableau method
// Time Complexity: O(n^3)
// Space Complexity: O(1)
void sortMatrix(vector<vector<int>> &matrix, const int &n)
{
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cout << extractMin(matrix, n) << " ";
    }
  }
  cout << endl;
}

// Using minHeap, similar to sort k-sorted arrays
// Time Complexity: O(n^2logn)
// Space Compexity: O(n)

void sortMatrixII(vector<vector<int>> &matrix, const int &n)
{
  // {element, {rowIndex, colIndex}}
  priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

  for (int i = 0; i < n; ++i)
    pq.push({matrix[0][i], {0, i}});

  while (pq.size())
  {
    auto top = pq.top();
    int i = top.second.first;
    int j = top.second.second;
    pq.pop();
    cout << top.first << " ";
    if (i < n - 1)
      pq.push({matrix[i + 1][j], {i + 1, j}});
  }

  cout << endl;
}

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  for (auto &row : matrix)
  {
    for (int &x : row)
    {
      cin >> x;
    }
  }

  sortMatrixII(matrix, n);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}