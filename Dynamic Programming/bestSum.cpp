/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Write a function `bestSum(targetSum, numbers)` that takes in a targetSum and an array of numbers aas arguments.
The function should return an array containing the shortest combination of nubmers that add up to exactly the targetSum.
If there is a tie for the shortest combination that add up to exactly the targetSum.
If there is a tie for the shortest combination, you may return any one of the shortest.

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

vector<int> nums, cur;
unordered_map<int, vector<int>> cache;

vector<int> bestSum(int targetSum)
{
  if (cache.find(targetSum) != cache.end())
    return cache[targetSum];
  if (targetSum == 0)
    return {0};
  if (targetSum < 0)
    return {};
  vector<int> tempArr;
  for (int x : nums)
  {
    auto result = bestSum(targetSum - x);
    if (result.size())
    {
      result.push_back(x);
      if (tempArr.size())
      {
        if (tempArr.size() > result.size())
          tempArr = result;
      }
      else
      {
        tempArr = result;
      }
    }
  }
  return cache[targetSum] = tempArr;
}

void solve()
{
  int n, targetSum;
  cin >> n >> targetSum;
  nums = vector<int>(n);
  for (int &x : nums)
    cin >> x;
  auto result = bestSum(targetSum);
  result.erase(result.begin());
  for (int x : result)
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