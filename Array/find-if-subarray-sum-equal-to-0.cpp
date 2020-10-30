/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array a[] of N positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Link:
https://practice.geeksforgeeks.org/problems/subarray-with-0-sum/0

Input:
2
5
4 2 -3 1 6
5
4 2 0 1 6

Output:
Yes
Yes

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

bool containsZeroSumSubarray(const int &n, const vector<int> &arr)
{
  unordered_map<int, int> mp;
  vector<int> ps(n);
  ps[0] = arr[0];

  for (int i = 1; i < n; ++i)
  {
    ps[i] = arr[i] + ps[i - 1];
  }

  for (int x : ps)
  {
    if (x == 0)
      return 1;
    if (mp.find(x) != mp.end())
      return 1;
    mp[x]++;
  }
  return 0;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;

  bool result = containsZeroSumSubarray(n, arr);
  if (result)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
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