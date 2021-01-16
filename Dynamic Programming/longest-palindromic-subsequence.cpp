/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given a sequence, find the length of the longest palindromic subsequence in it.

Link:
https://www.geeksforgeeks.org/longest-palindromic-subsequence-dp-12/

Input:
agbdba

Output:
5

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

string str;

int lpsRecurrence(int lo, int hi)
{
  if (lo == hi)
    return 1;
  if (lo > hi)
    return 0;
  if (str[lo] == str[hi])
    return 2 + lpsRecurrence(lo + 1, hi - 1);
  return max(lpsRecurrence(lo + 1, hi), lpsRecurrence(lo, hi - 1));
}

int lpsTabulation(string str)
{
  int n = str.size();
  vector<vector<int>> cache(n, vector<int>(n, 0));

  for (int i = 0; i < n; ++i)
    cache[i][i] = 1;

  for (int sl = 2; sl <= n; ++sl)
  {
    for (int i = 0; i < n - sl + 1; ++i)
    {
      int j = i + sl - 1;
      if (str[i] == str[j] && sl == 2)
        cache[i][j] = 2;
      else if (str[i] == str[j])
        cache[i][j] = 2 + cache[i + 1][j - 1];
      else
        cache[i][j] = max(cache[i][j - 1], cache[i + 1][j]);
    }
  }

  return cache[0][n - 1];
}

void solve()
{
  cin >> str;
  cout << lpsTabulation(str) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}