/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Write a function `canSum(targetSum, numbets)` that takes in a targetSum and an array of numbers as arguments.
The function should return a boolen indicating whether or not it is possible to generate the targetSum using numbers from the array.
You may use an element of the array as many times as needed.
You may assume that all input numbers are non-negative.

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

vector<int> numbers;

bool canSum(int target)
{
  vector<int> cache(target + 1, 0);
  cache[0] = 1;
  for (int i = 0; i <= target; ++i)
  {
    if (cache[i])
      for (int num : numbers)
        if (i + num <= target)
          cache[i + num] = true;
  }

  return cache[target] == true;
}

void solve()
{
  int n, target;
  cin >> n >> target;
  numbers = vector<int>(n);
  for (int &x : numbers)
    cin >> x;

  cout << canSum(target);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}