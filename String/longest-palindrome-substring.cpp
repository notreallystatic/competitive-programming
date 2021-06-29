/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

NOTE: Required Time Complexity O(n2).

Link:
https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

Input:
aaaabbaa

Output:
aabbaa

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

// Time: O(n^2)
// Space: O(n^2)
// Note: there is another algorithm with same time complexity but with O(1) space complexity
string lps(const string &str)
{
  int n(str.size());
  string res(str.begin(), str.begin() + 1);
  vector<vector<int>> cache(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i)
    cache[i][i] = 1;

  for (int sl = 2; sl < n; ++sl)
  {
    for (int i = 0; i < n - sl + 1; ++i)
    {
      int j = i + sl - 1;
      if (sl == 2)
        cache[i][j] = str[i] == str[j] ? sl : 0;
      else
      {
        if (cache[i + 1][j - 1] != j - i - 1 || str[i] != str[j])
          cache[i][j] = 0;
        else
          cache[i][j] = sl;
      }
      if (cache[i][j] > res.size())
        res = string(str.begin() + i, str.begin() + j + 1);
    }
  }

  return res;
}

void solve()
{
  string str;
  cin >> str;
  cout << lps(str) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}