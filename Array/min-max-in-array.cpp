/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Write a C function to return minimum and maximum in an array. You program should make minimum number of comparisons. 

Link:
https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

Input:
6
1000 11 445 1 330 3000

Output:
3000 1
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

pair<int, int> helper(int low, int high, const vector<int> &arr)
{
  if (low == high)
    return {arr[low], arr[high]};
  if (low + 1 == high)
  {
    int mx, mn;
    if (arr[low] > arr[high])
    {
      mx = arr[low];
      mn = arr[high];
    }
    else
    {
      mx = arr[high];
      mn = arr[low];
    }
    return {mx, mn};
  }
  int mid = low + (high - low) / 2;
  pair<int, int> result;
  auto left = helper(low, mid, arr);
  auto right = helper(mid + 1, high, arr);
  result.first = max(left.first, right.first);
  result.second = min(left.second, right.second);
  return result;
}

pair<int, int> minMax(const int &n, const vector<int> &arr)
{
  return helper(0, n - 1, arr);
}

pair<int, int> minMax2(const int &n, const vector<int> &arr)
{
  pair<int, int> result = {INT_MIN, INT_MAX};
  int i(0);
  if (n & 1)
  {
    result = {arr[0], arr[0]};
    i = 1;
  }
  while (i < n - 1)
  {
    if (arr[i] < arr[i + 1])
    {
      if (result.first < arr[i + 1])
        result.first = arr[i + 1];
      if (result.second > arr[i])
        result.second = arr[i];
    }
    else
    {
      if (result.first < arr[i])
        result.first = arr[i];
      if (result.second > arr[i + 1])
        result.second = arr[i + 1];
    }
    i += 2;
  }
  return result;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  pair<int, int> result = minMax(n, arr);
  cout << result.first << "\t" << result.second << endl;
  result = minMax2(n, arr);
  cout << result.first << "\t" << result.second << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}