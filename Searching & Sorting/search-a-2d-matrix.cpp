/*
Author : notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

#include <iostream>
#include <stdlib.h>
#include <numeric>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <cctype>
#include <sstream>
#include <cmath>
#include <limits.h>
#include <bitset>
#include <random>

using namespace std;

int row, col;

bool binarySearch(const vector<vector<int>> &matrix, const int &target, int lo, int hi)
{
  if (lo > hi)
    return false;
  for (int i = lo; i <= hi; ++i)
    {
    int mid = i;
    // int mid = (lo + hi) >> 1;
    int rowIndex = ceil((double)mid / (double)row) - 1;
    int colIndex = mid % col;
    colIndex = colIndex > 0 ? colIndex - 1 : col - 1;
    cout << i << "\t" << rowIndex << " " << colIndex << endl;
  }
  return true;
  // if (matrix[rowIndex][colIndex] == target)
  //   return true;
  // else if (matrix[rowIndex][colIndex] > target)
  //   return binarySearch(matrix, target, lo, mid - 1);
  // return binarySearch(matrix, target, mid + 1, hi);
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  row = matrix.size();
  col = matrix[0].size();
  return binarySearch(matrix, target, 1, row * col);
}

void solve()
{
  int r, c, target;
  cin >> r >> c >> target;
  vector<vector<int>> matrix(r, vector<int>(c));
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
