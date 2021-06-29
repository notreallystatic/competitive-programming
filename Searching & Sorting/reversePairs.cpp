/*
Author : notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

#include <iostream>
#include <stdlib.h>
#include <numeric>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <cctype>
#include <sstream>
#include <cmath>
#include <limits.h>
#include <bitset>
#include <random>

using namespace std;

int merge(vector<int> &nums, int left, int mid, int right)
{
  vector<int> temp(right - left + 1);
  int count(0);
  int i(0), l(left), r(mid + 1), j(mid + 1);

  for (int i = left; i <= mid; ++i)
  {
    while (j <= right && nums[i] > (2 * (long)nums[j]))
      ++j;
    count += j - mid - 1;
  }

  l = left, r = mid + 1;
  while (l <= mid && r <= right)
  {
    if (nums[l] <= nums[r])
      temp[i++] = nums[l++];
    else
      temp[i++] = nums[r++];
  }
  while (l <= mid)
    temp[i++] = nums[l++];
  while (r <= right)
    temp[i++] = nums[r++];
  for (int i = left; i <= right; ++i)
  {
    nums[i] = temp[i - left];
  }
  return count;
}

int mergeSort(vector<int> &nums, int left, int right)
{
  int count(0);
  if (left >= right)
    return 0;
  int mid = (left + right) / 2;
  count += mergeSort(nums, left, mid);
  count += mergeSort(nums, mid + 1, right);
  count += merge(nums, left, mid, right);
  return count;
}

int reversePairs(vector<int> &nums)
{
  return mergeSort(nums, 0, nums.size() - 1);
}

void solve()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int &x : nums)
    cin >> x;
  cout << reversePairs(nums) << endl;
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}
