/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given a string which consists of only 0s, 1s or 2s, count the number of substrings that have equal number of 0s, 1s and 2s.

Link:
https://www.geeksforgeeks.org/substring-equal-number-0-1-2/

Input:
102100211

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

void totalSub(int n, string &str)
{
  int result(0);
  map<pair<int, int>, int> mp;
  mp[{0, 0}] = 1;
  int zc(0), oc(0), tc(0);
  for (int i = 0; i < n; ++i)
  {
    if (str[i] == '0')
      ++zc;
    else if (str[i] == '1')
      ++oc;
    else
      ++tc;

    pair<int, int> temp = {zc - oc, zc - tc};

    result += mp[temp];
    ++mp[temp];
  }
  cout << result << endl;
}

void solve()
{
  string str;
  cin >> str;
  totalSub(str.length(), str);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}