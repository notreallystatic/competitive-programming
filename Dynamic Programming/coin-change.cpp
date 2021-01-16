/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 

Link:
https://practice.geeksforgeeks.org/problems/coin-change2448/1

Input:
4 3
1 2 3

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

int count (const int&n, const int& m, const vector<int> &coins) {
  vector<int> cache(n + 1, 0);
  cache[0] = 1;
  for(int i = 0; i < m; ++i) {
    for(int j = coins[i]; j <= n; ++j) {
      cache[j] += cache[j - coins[i]];
    }
  }
  return cache[n];
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> coins(n);
  for(int &x: coins) cin >> x;

  cout << count(n, m, coins) << endl; 
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}