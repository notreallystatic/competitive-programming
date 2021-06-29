/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:


Link:


Input:


Output:


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

int findPivot(vector<int> &nums)
{
  int l(0), r(nums.size() - 1), mid;
  while (l < r)
  {
    mid = (l + r) / 2;
    if (nums[mid] >= nums[0])
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}

int findAroundPivot(vector<int> &nums, int x, int pivot)
{
  int l(0), r(nums.size() - 1);
  if (x >= nums[pivot] && x <= nums.back())
    l = pivot;
  else
    r = pivot;

  while (l <= r)
  {
    int mid = (l + r) >> 1;
    if (nums[mid] == x)
      return mid;
    else if (nums[mid] > x)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return -1;
}

int findElement(vector<int> &nums, int x)
{
  int pivot = findPivot(nums);
  cout << pivot << endl;
  return findAroundPivot(nums, x, pivot);
}

void solve()
{
  int n, x;
  cin >> n >> x;
  vector<int> nums(n);
  for (int &e : nums)
    cin >> e;
  cout << findElement(nums, x) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}