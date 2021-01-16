/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given two strings X and Y. The task is to find the length of the longest common substring.

Link:
https://practice.geeksforgeeks.org/problems/longest-common-substring/0#

Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
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

int lcs(const string &a, const string &b)
{
  int n(a.size()), m(b.size());

  vector<vector<int>> cache(n + 1, vector<int>(m + 1, 0));
  int res(0);
  for (int i = 0; i <= n; ++i)
  {
    for (int j = 0; j <= m; ++j)
    {
      if (i == 0 || j == 0)
        cache[i][j] = 0;
      else
      {
        if (a[i - 1] == b[j - 1])
          cache[i][j] = 1 + cache[i - 1][j - 1];
      }
      res = max(res, cache[i][j]);
    }
  }

  return res;
}

void solve()
{
  int n, m;
  string a, b;
  cin >> n >> m >> a >> b;

  cout << lcs(a, b) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}