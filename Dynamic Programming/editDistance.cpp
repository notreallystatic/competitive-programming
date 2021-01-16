/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:

Insert
Remove
Replace

Link:
https://practice.geeksforgeeks.org/problems/edit-distance3702/1

Input:
ecfbefdcfca badfcbebbf

Output:
9

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

int min(const int &a, const int &b, const int &c)
{
  return min(a, min(b, c));
}

int editDistance(string s, string t)
{
  vector<vector<int>> cache(s.size() + 1, vector<int>(t.size() + 1, 0));
  for (int i = 0; i <= s.size(); ++i)
  {
    for (int j = 0; j <= t.size(); ++j)
    {
      if (i == 0)
        cache[i][j] = j;
      else if (j == 0)
        cache[i][j] = i;
      else if (s[i - 1] == t[j - 1])
        cache[i][j] = cache[i - 1][j - 1];
      else
      {
        //  insert  (i, j - 1)
        // remove  (i - 1, j)
        // replace (i - 1, j - 1)
        cache[i][j] = 1 + min(cache[i][j - 1], cache[i - 1][j], cache[i - 1][j - 1]);
      }
    }
  }
  return cache[s.size()][t.size()];
}

void solve()
{
  string str1, str2;
  cin >> str1 >> str2;
  cout << editDistance(str1, str2) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}