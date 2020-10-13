/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Implement Jump Searchs

Link:
https://www.geeksforgeeks.org/jump-search/

Input:
11 5
-10 -9 -8 -7 -6 -5 -4 -3 -2 0 5

Output:
10

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

int jumpSearch(const int &n, vector<int> &arr, const int &target)
{
  int step, prev, inc(sqrt(n));
  step = inc;
  while (arr[min(n, step) - 1] < target)
  {
    prev = step;
    step += inc;
    if (prev >= n)
      return -1;
  }

  while (arr[prev] < target)
  {
    ++prev;
    if (prev == min(step, n))
      return -1;
  }

  if (arr[prev] == target)
    return prev;
  return -1;
}

void solve()
{
  int n, target;
  cin >> n >> target;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  cout << jumpSearch(n, arr, target) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}