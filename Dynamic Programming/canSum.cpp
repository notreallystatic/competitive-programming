/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array of numbers and a target sum, find if it's possible to get the desired sum from the array elements. You can assume that there is infinite supply of each number in the array.
A[i] > 0

Link:


Input:
4 7
2 3 5 7

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

vector<int> v;
unordered_map<int, int> mp;

bool canSum(int sum)
{
  if (mp.find(sum) != mp.end())
    return mp[sum];
  if (sum == 0)
    return 1;
  if (sum < 0)
    return 0;
  for (int x : v)
    mp[sum] |= canSum(sum - x);
  return mp[sum];
}

void solve()
{
  int n, sum;
  cin >> n >> sum;
  v = vector<int>(n);
  for (int &x : v)
    cin >> x;

  cout << canSum(sum) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}