/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an arr[] containing n integers and a positive integer k. The problem is to find the length of the longest subarray with sum of the elements divisible by the given value k.

Link:
https://www.geeksforgeeks.org/longest-subarray-sum-divisible-k/

Input:
6 3
2 7 6 1 4 5

Output:
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

int longestSubarray(const int &n, const int &k, const vector<int> &arr)
{
  unordered_map<int, int> index;
  vector<int> modArr(n);
  int sum(0), rem(0), result(INT_MIN);

  for (int i = 0; i < n; ++i)
  {
    sum += arr[i];
    modArr[i] = ((sum % k) + k) % k;
  }

  for (int i = 0; i < n; ++i)
  {
    if (modArr[i] == 0)
      result = i + 1;
    else if (index.find(modArr[i]) == index.end())
      index[modArr[i]] = i;
    else
      result = max(result, i - modArr[i]);
  }
  return result;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;

  cout << longestSubarray(n, k, arr);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}