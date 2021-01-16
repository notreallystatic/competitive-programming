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
5 10
1 2 3 4 5

Output:
5 5

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

vector<int> numbers;

vector<int> howSum(int target)
{
  vector<vector<int>> cache(target + 1);
  for (int i = 0; i <= target; ++i)
  {
    if (cache[i].size() || i == 0)
    {
      auto cur = cache[i];
      for (int num : numbers)
      {
        cur.push_back(num);
        if (i + num <= target)
        {
          if (cache[i + num].size() == 0 || cache[i + num].size() > cur.size())
            cache[i + num] = cur;
        }
        cur.pop_back();
      }
    }
  }
  return cache[target];
}

void solve()
{
  int n, target;
  cin >> n >> target;
  numbers = vector<int>(n);
  for (int &x : numbers)
    cin >> x;

  auto result = howSum(target);
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