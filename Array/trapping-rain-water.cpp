/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai where the width of each block is 1. Compute how much water can be trapped in between blocks after raining.
Structure is like below:
| |
|_|
We can trap 2 units of water in the middle gap.

Link:
https://practice.geeksforgeeks.org/problems/trapping-rain-water/0

Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
0

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

int trapRainwater(const int &n, const vector<int> &arr)
{
  int lmax(0), rmax(0), result(0), lo(0), hi(n - 1);
  while (lo <= hi)
  {
    if (arr[lo] < arr[hi])
    {
      if (arr[lo] > lmax)
        lmax = arr[lo];
      result += lmax - arr[lo];
      ++lo;
    }
    else
    {
      if (arr[hi] > rmax)
        rmax = arr[hi];
      result += rmax - arr[hi];
      --hi;
    }
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

  cout << trapRainwater(n, arr) << endl;
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