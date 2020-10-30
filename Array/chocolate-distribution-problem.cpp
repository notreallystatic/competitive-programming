/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array A of positive integers of size N, where each value represents number of chocolates in a packet. Each packet can have variable number of chocolates. There are M students, the task is to distribute chocolate packets such that :
1. Each student gets one packet.
2. The difference between the number of chocolates given to the students having packet with maximum chocolates and student having packet with minimum chocolates is minimum.

Link:
https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0

Input:
2
8
3 4 1 9 56 7 9 12
5
7
7 3 2 4 9 12 56
3

Output:
6
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

int minDiff(const int &n, const int &k, vector<int> &arr)
{
  sort(arr.begin(), arr.end());
  int result(INT_MAX);
  for (int i = k - 1; i < n; ++i)
  {
    result = min(result, arr[i] - arr[i - k + 1]);
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

  cout << minDiff(n, k, arr) << endl;
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