/*
Author : notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

// problem link: interviewbit.com/problems/matrix-median/

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

int upperElements(const vector<int> &arr, const int &x)
{
  int low(0), high(arr.size() - 1);
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] <= x)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}

int countElements(const vector<vector<int>> &matrix, const int &x)
{
  int count(0);
  for (const auto &row : matrix)
    count += upperElements(row, x);
  return count;
}

int findMedian(vector<vector<int>> &A)
{
  long long low(1), high(1e9);
  int total(A.size() * A[0].size());
  int count(0);
  while (low <= high)
  {
    count = 0;
    long long mid = (low + high) / 2;
    count += countElements(A, mid);
    if (count <= total / 2)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> matrix(n, vector<int>(m, 0));
  for (auto &row : matrix)
    for (auto &cell : row)
      cin >> cell;
  cout << findMedian(matrix) << endl;
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}
