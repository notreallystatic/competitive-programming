/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Link:
https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

Input:
2
5
1 2 3 -2 5
4
-1 -2 -3 -4

Output:
9
-1

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
  for (int &x : arr)
    cin >> x;
  int result(arr[0]), curSum(arr[0]);
  for (int i = 1; i < n; ++i)
  {
    if (curSum + arr[i] >= arr[i])
      curSum += arr[i];
    else
      curSum = arr[i];
    result = max(result, curSum);
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