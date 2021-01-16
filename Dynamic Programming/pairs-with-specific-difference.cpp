/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array of integers A[] and a number k.You can pair two number of array if difference between them is strictly less than k. The task is to find maximum possible sum of such disjoint pairs. Sum of P pairs is sum of all 2P numbers of pairs.

Link:
https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference/0

Input:
2
7
3 5 10 15 17 12 9
4
4
5 15 10 300
12

Output:
62
25

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

int pairsMaxDiff(const int &n, const int &k, vector<int> &nums)
{
  sort(nums.begin(), nums.end());

  vector<int> cache(n, 0);

  for (int i = 1; i < n; ++i)
  {
    cache[i] = cache[i - 1];
    if (nums[i] - nums[i - 1] < k)
    {
      if (i >= 2)
      {
        cache[i] = max(cache[i], cache[i - 2] + nums[i] + nums[i - 1]);
      }
      else
      {
        cache[i] = max(cache[i], nums[i] + nums[i - 1]);
      }
    }
  }

  return cache[n - 1];
}

void solve()
{
  int n, k;
  cin >> n;
  vector<int> nums(n);
  for (int &num : nums)
    cin >> num;
  cin >> k;
  cout << pairsMaxDiff(n, k, nums) << endl;
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