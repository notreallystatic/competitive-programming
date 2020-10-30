/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

Link:
https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together/0

Input:
2
5
2 1 5 6 3
3
7
2 7 9 5 8 7 4
6

Output:
1
2

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

int minSwaps(const int &n, const int &k, const vector<int> &arr)
{
  int total(0), result(INT_MAX), cnt(0);
  for (int x : arr)
  {
    if (x <= k)
      ++total;
  }
  for (int i = 0; i < total; ++i)
  {
    if (arr[i] <= k)
      ++cnt;
  }
  result = total - cnt;
  for (int i = total; i < n; ++i)
  {
    if (arr[i - total] <= k)
      --cnt;
    if (arr[i] <= k)
      ++cnt;
    result = min(result, total - cnt);
  }
  return result;
}

void solve()
{
  int n, k;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  cin >> k;

  cout << minSwaps(n, k, arr) << endl;
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