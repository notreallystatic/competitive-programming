/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Write a function `howSum(targetSum, numbers)` that takes in a targetSum and array of numbers as arguments.
The function should return an array containing any combination of elements that add up to exactly the targetSum.
If there is no combination that adds up to the targetSum, then return null.
If there are multiple combinations possible, you may return any single one.

Link:


Input:
4 7
2 3 4 7

Output:
3 2 2

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

unordered_map<int, vector<int>> cache;
vector<int> nums;

vector<int> howSum(int target)
{
  if (cache.find(target) != cache.end())
    return cache[target];

  if (target == 0)
    return {0};
  if (target < 0)
    return {};

  for (int num : nums)
  {
    auto ans = howSum(target - num);
    if (ans.size())
    {
      ans.push_back(num);
      return cache[target] = ans;
    }
  }

  return cache[target] = {};
}

void solve()
{
  int n, targetSum;
  cin >> n >> targetSum;

  nums = vector<int>(n);
  for (int &num : nums)
    cin >> num;

  auto result = howSum(targetSum);
  // first element will be zero, just remove that.
  for (int x : result)
  {
    cout << x << " ";
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}