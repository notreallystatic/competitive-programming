/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin. Determine the maximum possible amount of money we can definitely win if we move first.

Link:
https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/

Input:
4
5 3 7 10

Output:
15

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

int gameOfNums(int low, int high)
{
  if (low == high)
    return nums[low];
  if (high == low + 1)
    return max(nums[low], nums[high]);
  return max(nums[low] + min(gameOfNums(low + 2, high), gameOfNums(low + 1, high - 1)), nums[high] + min(gameOfNums(low + 1, high - 1), gameOfNums(low, high - 2)));
}

int gameOfNumsTabulation()
{
  int n = nums.size();
  vector<vector<int>> cache(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i)
    cache[i][i] = nums[i];

  for (int sa = 2; sa <= n; ++sa)
  {
    for (int i = 0; i < n - sa + 1; ++i)
    {
      int j = i + sa - 1;
      if (sa == 2)
        cache[i][j] = max(cache[i][i], cache[j][j]);
      else
        cache[i][j] = max(nums[i] + min(cache[i + 2][j], cache[i + 1][j - 1]), nums[j] + min(cache[i + 1][j - 1], cache[i][j - 2]));
    }
  }

  return cache[0][n - 1];
}

void solve()
{
  int n;
  cin >> n;
  nums = vector<int>(n);
  for (int &x : nums)
    cin >> x;
  // cout << gameOfNums(0, nums.size() - 1);
  cout << gameOfNumsTabulation() << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}