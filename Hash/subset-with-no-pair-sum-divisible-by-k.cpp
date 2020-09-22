/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array of integer numbers, we need to find maximum size of a subset such that sum of each pair of this subset is not divisible by K.

Link:
https://www.geeksforgeeks.org/subset-no-pair-sum-divisible-k/

Input:
6 5
3 17 12 9 11 15

Output:
4

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

int minSubset(const int &n, const int &k, const vector<int> &arr)
{
  vector<int> mod(k, 0);
  int res(0);

  for (int x : arr)
    ++mod[(x % k + k) % k];

  if (!(k & 1))
    mod[k / 2] = min(arr[k / 2], 1);

  res = min(1, mod[0]);

  for (int i = 1; i <= k / 2; ++i)
    res += max(mod[i], mod[k - i]);

  return res;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;

  cout << minSubset(n, k, arr) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}