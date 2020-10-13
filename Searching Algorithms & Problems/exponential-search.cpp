/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Implement exponential Search

Link:
https://www.geeksforgeeks.org/exponential-search/

Input:
10 5
0 1 2 3 5 6 7 8 9 10 11

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

int binarySearch(const vector<int> &arr, int lo, int hi, const int &target)
{
  if (lo == hi)
  {
    if (arr[lo] == target)
      return lo;
    return -1;
  }
  int mid = (lo + hi) / 2;
  if (arr[mid] == target)
    return mid;
  if (arr[mid] > target)
    return binarySearch(arr, lo, max(lo, mid - 1), target);
  return binarySearch(arr, mid + 1, hi, target);
}

int exponentialSearch(const int &n, const vector<int> &arr, const int &target)
{
  if (arr[0] == target)
    return 0;
  int i(1);
  while (i < n && arr[i] <= target)
  {
    i *= 2;
  }
  return binarySearch(arr, i / 2, min(i, n - 1), target);
}

void solve()
{
  int n, target;
  cin >> n >> target;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  cout << exponentialSearch(n, arr, target) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}