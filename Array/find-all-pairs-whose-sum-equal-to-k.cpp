/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

Link:
https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

Input:
4 6
1 5 7 1

Output:
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

int getPairsCount(vector<int> &arr, const int &n, const int &k)
{
  unordered_map<int, int> mp;
  int result(0);

  for (int i = 0; i < n; ++i)
    ++mp[arr[i]];

  for (int i = 0; i < n; ++i)
  {
    result += mp[k - arr[i]];
    if (arr[i] == k - arr[i])
      --result;
  }

  return result / 2;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;

  cout << getPairsCount(arr, n, k) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}