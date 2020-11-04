/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.

Link:
https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0#

Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12

Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 8 12 11 10 9 5 6 7

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

void printSpiral(int m, int n, vector<vector<int>> &matrix)
{
  int rlow(0), rhigh(m - 1), clow(0), chigh(n - 1);
  while (rlow <= rhigh && clow <= chigh)
  {
    // print the top row
    for (int i = clow; i <= chigh; ++i)
    {
      cout << matrix[rlow][i] << " ";
    }
    ++rlow;
    // print the right col
    for (int j = rlow; j <= rhigh; ++j)
    {
      cout << matrix[j][chigh] << " ";
    }
    --chigh;
    // print the bottom row
    if (rlow <= rhigh)
    {
      for (int k = chigh; k >= clow; --k)
      {
        cout << matrix[rhigh][k] << " ";
      }
      --rhigh;
    }
    // print the left col
    if (clow <= chigh)
    {
      for (int l = rhigh; l >= rlow; --l)
      {
        cout << matrix[l][clow] << " ";
      }
      ++clow;
    }
  }
  cout << endl;
}

void solve()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> matrix(m, vector<int>(n, 0));

  for (auto &row : matrix)
  {
    for (int &element : row)
    {
      cin >> element;
    }
  }

  printSpiral(m, n, matrix);
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