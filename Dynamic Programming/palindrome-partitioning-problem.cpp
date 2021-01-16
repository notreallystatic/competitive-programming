/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. For example, “aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”. Determine the fewest cuts needed for a palindrome partitioning of a given string. For example, minimum of 3 cuts are needed for “ababbbabbababa”. The three cuts are “a|babbbab|b|ababa”. If a string is a palindrome, then minimum 0 cuts are needed. If a string of length n containing all different characters, then minimum n-1 cuts are needed.

Link:
https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/

Input:
ababbbabbababa

Output:
3

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

int isPalindrome(const string &str, int lo, int hi)
{
  while (lo < hi)
  {
    if (str[lo] != str[hi])
      return str.size() - 1;
    ++lo, --hi;
  }
  return 0;
}

// Recurrence
int countPartitions(const string &str, int lo, int hi)
{
  if (lo >= hi)
    return 0;
  if (str[lo] == str[hi])
  {
    int count = isPalindrome(str, lo, hi);
    if (count == 0)
      return count;
  }
  int ans(INT_MAX);
  for (int i = lo; i < hi; ++i)
  {
    ans = min(ans, 1 + countPartitions(str, lo, i) + countPartitions(str, i + 1, hi));
  }
  return ans;
}

// time complexity: O(n^3). Can be further optimized to O(n^2)
int countPartitionsTabulation(const string &str)
{
  int n = str.size();
  vector<vector<int>> cache(n, vector<int>(n, INT_MAX));

  for (int i = 0; i < n; ++i)
    cache[i][i] = 0;

  for (int sl = 2; sl <= n; ++sl)
  {
    for (int i = 0; i < n - sl + 1; ++i)
    {
      int j = i + sl - 1;
      if (str[i] == str[j] && sl == 2)
        cache[i][j] = 0;
      else if (str[i] == str[j] && cache[i + 1][j - 1] == 0)
        cache[i][j] = 0;

      if (cache[i][j] != 0)
      {
        for (int k = i; k < j; ++k)
          cache[i][j] = min(cache[i][j], 1 + cache[i][k] + cache[k + 1][j]);
      }
    }
  }

  return cache[0][n - 1];
}

void solve()
{
  string str;
  cin >> str;
  cout << countPartitionsTabulation(str) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}