/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Link:
https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

Input:
4 4
0 1 1 1
0 0 1 1
1 1 1 1
0 0 0 0

Output:
2

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

int solution1(vector<vector<int>> matrix, int n, int m)
{
  // worse case: O(nlogm)
  int lastIndex(m), currentIndex, row(-1);
  for (int i = 0; i < n; ++i)
  {
    if (lastIndex > 0 && matrix[i][lastIndex - 1] > 0)
    {
      lastIndex = upper_bound(matrix[i].begin(), matrix[i].end(), 0) - matrix[i].begin();
      row = i;
    }
  }
  return row;
}

int rowWithMax1s(vector<vector<int>> matrix, int n, int m)
{
  // code here
  // O(m+n) solution
  int lastIndex(m), row(-1);
  for (int i = 0; i < n; ++i)
  {
    while (lastIndex > 0 && matrix[i][lastIndex - 1] > 0)
    {
      --lastIndex;
      row = i;
    }
  }
  return row;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m, 0));

  for (auto &row : matrix)
  {
    for (int &x : row)
    {
      cin >> x;
    }
  }

  cout << rowWithMax1s(matrix, n, m) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}