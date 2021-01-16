/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given a non negative array, find the number of subsequences having product smaller than K.

Link:
https://www.geeksforgeeks.org/count-subsequences-product-less-k/

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

int countSubsequences(const int &n, const int &k, const vector<int> &nums)
{
  vector<vector<int>> cache(n + 1, vector<int>(k, 0));

  for (int i = 0; i <= n; ++i)
  {
    for (int j = 0; j < k; ++j)
    {
      if (i == 0 || j == 0)
        cache[i][j] = 0;
      else
      {
        cache[i][j] = cache[i - 1][j];
        if (nums[i - 1] <= j && nums[i - 1] > 0)
          cache[i][j] += 1 + cache[i - 1][j / nums[i - 1]];
      }
    }
  }
  return cache[n][k - 1];
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int &num : nums)
    cin >> num;
  cout << countSubsequences(n, k, nums) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}