/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array A[] and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified arranged array.

Link:
https://practice.geeksforgeeks.org/problems/three-way-partitioning/1

Input:
5 10 15
12 17 5 10 20

Output:
5 1 0 12 20 17

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

vector<int> threeWayPartition(vector<int> arr, int a, int b)
{
  int n(arr.size()), start(0), i(0), end(n - 1);
  while (i <= end)
  {
    if (arr[i] < a)
    {
      swap(arr[i], arr[start]);
      ++start;
      ++i;
    }
    else if (arr[i] > b)
    {
      swap(arr[i], arr[end]);
      --end;
    }
    else
    {
      ++i;
    }
  }
  vector<int> result = arr;
  return result;
}

void solve()
{
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;

  vector<int> result;
  result = threeWayPartition(arr, a, b);

  for (int x : result)
    cout << x << " ";
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}