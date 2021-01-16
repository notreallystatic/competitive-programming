/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
A sequence {x1, x2, .. xn} is alternating sequence if its elements satisfy one of the following relations :

x1 < x2 > x3 < x4 > x5..... or  x1 >x2 < x3 > x4 < x5.....

Your task is to find the longest such sequence.

Link:
https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence/0

Input:
2
3
1 5 4
8
10 22 9 33 49 50 31 60

Output:
3
6

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

// Recurrence
// index: current index
// last: last chosen element
// greater: true -> we have to choose greater than last
//          false -> we have to choose smaller than last
int las(const vector<int> &nums, int index, int last, bool greater)
{
  if (index == nums.size())
    return 0;
  if (greater)
  {
    int len1(0), len2;
    if (nums[index] > last)
      len1 = 1 + las(nums, index + 1, nums[index], 1 - greater);
    len2 = las(nums, index + 1, last, greater);
    return max(len1, len2);
  }
  int len1(0), len2;
  if (nums[index] < last)
    len1 = 1 + las(nums, index + 1, nums[index], 1 - greater);
  len2 = las(nums, index + 1, last, greater);
  return max(len1, len2);
}

int lasTabulation(const vector<int> &nums)
{

  int n(nums.size());
  vector<vector<int>> cache(n, vector<int>(2, 1));
  // cache[n][2]
  // cache[i][0]: length of alt seq ending with nums[i], such that
  //              i is greater the the second last element
  // cache[i][1]: length of alt seq ending with nums[i], such that
  //              i is smaller than the second last element.
  int res(1);
  for (int i = 1; i < n; ++i)
  {
    for (int j = i - 1; j >= 0; --j)
    {
      if (nums[i] > nums[j])
        cache[i][0] = max(cache[i][0], 1 + cache[j][1]);
      else if (nums[i] < nums[j])
        cache[i][1] = max(cache[i][1], 1 + cache[j][0]);
    }
    res = max(res, max(cache[i][0], cache[i][1]));
  }

  return res;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int &num : nums)
    cin >> num;
  cout << lasTabulation(nums) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}