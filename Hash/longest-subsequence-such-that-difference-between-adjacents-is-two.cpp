/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array of size n. The task is to find the longest subsequence such that difference between adjacents is one. Time Complexity of O(n) is required.

Link:
https://www.geeksforgeeks.org/longest-subsequence-difference-adjacents-one-set-2/

Input:
8
1 2 3 2 3 7 2 1

Output:
7

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

void longestSub(const int &n, vector<int> &arr)
{
  unordered_map<int, int> mp;
  int ans(0);
  for (int x : arr)
  {
    mp[x] = 1 + max(mp[x - 1], mp[x + 1]);
    ans = max(ans, mp[x]);
  }
  cout << ans;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;

  longestSub(n, arr);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}