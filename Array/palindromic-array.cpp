/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
You are given an array A of size N. Your task is to find the minimum number of operations needed to convert the given array to 'Palindromic Array'.
Palindromic Array:
[23,15,23] is a ‘Palindromic Array’ but [2,0,1] is not.
The only allowed operation is that you can merge two adjacent elements in the array and replace them with their sum.

Link:
https://practice.geeksforgeeks.org/problems/palindromic-array/0

Input:
2
5
3 2 3 3 5
4
5 3 3 4

Output:
1
3

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

int minSteps(const int &n, vector<int> &arr)
{
  int lo(0), hi(n - 1), steps(0);
  while (lo < hi)
  {
    if (arr[lo] == arr[hi])
    {
      ++lo;
      --hi;
    }
    else if (arr[lo] < arr[hi])
    {
      arr[lo + 1] += arr[lo];
      ++lo;
      ++steps;
    }
    else
    {
      arr[hi - 1] += arr[hi];
      --hi;
      ++steps;
    }
  }
  return steps;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;

  cout << minSteps(n, arr) << endl;
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