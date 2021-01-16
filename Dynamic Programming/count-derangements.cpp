/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
A Derangement is a permutation of n elements, such that no element appears in its original position. For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.
Given a number n, find total number of Derangements of a set of n elements.

Link:
https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/

Input:
4

Output:
9

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

/*
  Recurrence: D[n] = (n - 1) * (D[n - 1] + D[n - 2]);
  TC: O(n)
  SC: O(n), can be done in O(1) as well just like fibonacci series.
*/

unordered_map<int, int> cache;

int countDerangements(int n)
{
  if (cache.find(n) != cache.end())
    return cache[n];
  if (n <= 2)
    return cache[n] = n - 1;
  return cache[n] = (n - 1) * (countDerangements(n - 1) + countDerangements(n - 2));
}

void solve()
{
  int n;
  cin >> n;
  cout << countDerangements(n) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}