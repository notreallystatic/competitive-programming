/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

Link:
https://leetcode.com/problems/next-permutation/

Input:
3
1 2 3

Output:
1 3 2

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

void nextPermutation(vector<int> &nums)
{
  int n(nums.size()), i(n - 2);
  while (i >= 0 && nums[i] >= nums[i + 1])
  {
    --i;
  }
  if (i >= 0)
  {
    int j = n - 1;
    while (j >= 0 && nums[j] <= nums[i])
    {
      --j;
    }
    swap(nums[i], nums[j]);
  }
  reverse(nums.begin() + i + 1, nums.end());
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  nextPermutation(arr);
  for (int x : arr)
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