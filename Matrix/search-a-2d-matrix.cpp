/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

Link:
https://leetcode.com/problems/search-a-2d-matrix/

Input:
3 4 11
1 3 5 7
10 11 16 20
23 30 34 60

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

bool search(vector<vector<int>> &matrix, int target)
{
  // multiplication may cause overflow and it's an expensive task
  int r(matrix.size()), c(matrix[0].size());

  int low(0), high(r * c - 1);
  while (low < high)
  {
    int mid = (low + high) / 2;
    int e = matrix[mid / c][mid % c];
    if (e > target)
      high = mid - 1;
    else if (e < target)
      low = mid + 1;
    else
      return true;
  }
  return matrix[low / c][low % c] == target;
}

bool binarySearch(vector<vector<int>> &matrix, int target)
{
  int row(matrix.size()), col(matrix[0].size());
  int low(0), high(row - 1);

  while (low <= high)
  {
    int mid = (low + high) >> 1;
    if (matrix[mid][0] > target)
      high = mid - 1;
    else if (matrix[mid][0] < target)
      low = mid + 1;
    else
      return true;
  }

  int r(high);
  low = 0, high = col - 1;

  if (r >= 0)
  {
    while (low <= high)
    {
      int mid = (low + high) >> 1;
      if (matrix[r][mid] > target)
        high = mid - 1;
      else if (matrix[r][mid] < target)
        low = mid + 1;
      else
        return true;
    }
  }
  return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  if (matrix.size() < 1 || matrix[0].size() < 1)
    return 0;
  return binarySearch(matrix, target);
}

void solve()
{
  int r, c, target;
  cin >> r >> c >> target;
  vector<vector<int>> matrix(r, vector<int>(c, 0));
  for (auto &row : matrix)
  {
    for (int &x : row)
    {
      cin >> x;
    }
  }

  cout << searchMatrix(matrix, target) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}