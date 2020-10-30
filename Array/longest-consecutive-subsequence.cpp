/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array arr[] of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Link:
https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence/0#

Input:
2
7
2 6 1 9 4 5 3
7
1 9 3 10 4 20 2

Output:
6
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

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  unordered_map<int, int> mp;
  for (int &x : arr)
  {
    cin >> x;
    mp[x] = 1;
  }
  int result(INT_MIN);
  for (int x : arr)
  {
    int temp(x), cnt(0);
    while (mp[temp])
    {
      cnt += mp[temp];
      --temp;
      mp[temp + 1] = 0;
    }

    mp[x] = cnt;
    result = max(result, mp[x]);
  }
  cout << result << endl;
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