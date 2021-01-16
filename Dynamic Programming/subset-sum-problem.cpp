/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Link:
https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

Input:
4
1 5 11 5

Output:
1

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

vector<int> nums;

bool isSumPossible()
{
  auto sum = accumulate(begin(nums), end(nums), 0);
  if (sum & 1)
    return 0;
  sum /= 2;
  vector<int> prev, cur;
  prev = cur = vector<int>(sum + 1, 0);
  prev[0] = cur[0] = 1;
  for (int j = 0; j < nums.size(); ++j)
  {
    for (int i = 1; i <= sum; ++i)
    {
      if (nums[j] > i)
        cur[i] = prev[i];
      else
        cur[i] = prev[i - nums[j]] || prev[i];
    }
    prev = cur;
    cur[0] = true;
  }
  return prev[sum];
}

void solve()
{
  int n;
  cin >> n;
  nums = vector<int>(n);
  for (int &num : nums)
    cin >> num;
  cout << isSumPossible() << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}