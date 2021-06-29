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

void display(const vector<int> &nums)
{
  for (auto x : nums)
    cout << x << " ";
  cout << "\n";
}

int merge(int left, int mid, int right, vector<int> &nums)
{
  int inversions(0);
  vector<int> temp(right - left + 1);
  int l(left), r(mid + 1), i(0);
  while (l <= mid && r <= right)
  {
    if (nums[l] <= nums[r])
      temp[i] = nums[l++];
    else
    {
      temp[i] = nums[r++];
      inversions += mid - l + 1;
    }
    ++i;
  }
  while (l <= mid)
    temp[i++] = nums[l++];
  while (r <= right)
    temp[i++] = nums[r++];
  for (int i = left; i <= right; ++i)
  {
    nums[i] = temp[i - left];
  }
  return inversions;
}

int mergeSort(int left, int right, vector<int> &nums)
{
  int inversions(0);
  if (left < right)
  {
    int mid = (left + right) / 2;
    inversions += mergeSort(left, mid, nums);
    inversions += mergeSort(mid + 1, right, nums);
    inversions += merge(left, mid, right, nums);
  }
  return inversions;
}

int countInversions(const int &n, vector<int> &nums)
{
  int res = mergeSort(0, n - 1, nums);
  for (int x : nums)
    cout << x << " ";
  cout << endl;
  return res;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int &x : nums)
    cin >> x;
  cout << countInversions(n, nums) << endl;
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}
