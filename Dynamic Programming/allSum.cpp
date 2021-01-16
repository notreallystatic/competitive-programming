/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:


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

vector<int> nums;
unordered_map<int, vector<vector<int>>> cache;

vector<vector<int>> allSum(int targetSum)
{
  if (cache.find(targetSum) != cache.end())
    return cache[targetSum];
  if (targetSum == 0)
    return {{0}};
  if (targetSum < 0)
    return {};
  vector<vector<int>> cur;
  for (int x : nums)
  {
    auto result = allSum(targetSum - x);
    if (result.size())
    {
      for (auto &v : result)
        v.push_back(x);
      cur.insert(cur.end(), result.begin(), result.end());
    }
  }
  return cache[targetSum] = cur;
}

void solve()
{
  int n, targetSum;
  cin >> n >> targetSum;
  nums = vector<int>(n);
  for (int &x : nums)
    cin >> x;
  auto result = allSum(targetSum);
  for (auto v : result)
  {
    v.erase(v.begin());
    for (int x : v)
    {
      cout << x << " ";
    }
    cout << "\n";
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