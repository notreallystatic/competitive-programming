/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given two strings, find the length of longest subsequence present in both of them.

Link:
https://www.geeksforgeeks.org/space-optimized-solution-lcs/

Input:
6 7
AGGTAB
GXTXAYB

Output:
4

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

// space optimized LCS
int lcs(const string &a, const string &b)
{
  vector<vector<int>> cache(2, vector<int>(b.size() + 1, 0));

  bool bi;
  for (int i = 0; i <= a.size(); ++i)
  {
    bi = i & 1;
    for (int j = 0; j <= b.size(); ++j)
    {
      if (i == 0 || j == 0)
        cache[bi][j] = 0;
      else if (a[i - 1] == b[j - 1])
        cache[bi][j] = 1 + cache[1 - bi][j - 1];
      else
        cache[bi][j] = max(cache[bi][j - 1], cache[1 - bi][j]);
    }
  }
  return cache[bi][b.size()];
}

void solve()
{
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
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