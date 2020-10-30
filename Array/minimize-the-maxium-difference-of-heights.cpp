/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array arr[] denoting heights of N towers and a positive integer K, modify the heights of each tower either by increasing or decreasing them by K only once. Find out the minimum difference of the heights of shortest and longest modified towers.

Link:
https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

Input:
2
2 4
1 5 8 10
3 5
3 9 12 16 20

Output:
5
11

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

int getMinDiff(vector<int> &arr, int n, int k)
{
  sort(arr.begin(), arr.end());
  int result(arr[n - 1] - arr[0]), mx, mn;
  mx = arr[n - 1] - k;
  mn = arr[0] + k;
  if (mn > mx)
    swap(mn, mx);
  for (int i = 1; i < n - 1; ++i)
  {
    int add, sub;
    add = arr[i] + k;
    sub = arr[i] - k;
    if (add <= mx || sub >= mn)
      continue;
    if (mx - sub <= add - mn)
      mn = sub;
    else
      mx = add;
  }
  return min(result, mx - mn);
}

void solve()
{
  int k, n;
  cin >> k >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  cout << getMinDiff(arr, n, k) << endl;
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