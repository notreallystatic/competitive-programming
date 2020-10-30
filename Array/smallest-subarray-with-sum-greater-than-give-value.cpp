/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Link:
https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x/0

Input:
2
6 51
1 4 45 6 0 19
5 9
1 10 5 2 7

Output:
3
1

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

int smallestSubarray(const int &n, const int &x, vector<int> &arr)
{
  int start(0), end(0), subLength(n + 1), sum(0);

  while (end < n)
  {
    while (end < n && sum <= x)
    {
      sum += arr[end];
      ++end;
    }
    while (start < n && sum > x)
    {
      if (end - start < subLength)
        subLength = end - start;
      sum -= arr[start];
      ++start;
    }
  }
  return subLength;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;

  cout << smallestSubarray(n, k, arr) << endl;
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