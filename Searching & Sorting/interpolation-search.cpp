/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Implement Interpolation search.

Link:
https://www.geeksforgeeks.org/interpolation-search/

Input: 
10 5
1 2 3 4 5 6 7 8 9 10

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

int search(const int &n, const vector<int> &arr, const int &target)
{
  int lo(0), hi(n - 1), pos;

  while (lo <= hi && target >= arr[lo] && target <= arr[hi])
  {
    if (lo == hi)
    {
      if (arr[lo] == target)
        return lo;
      return -1;
    }
    pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (target - arr[lo]));
    if (arr[pos] == target)
      return pos;
    if (arr[pos] > target)
      hi = pos - 1;
    else
      lo = pos + 1;
  }
  return -1;
}

void solve()
{
  int n, target;
  cin >> n >> target;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  cout << search(n, arr, target) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}