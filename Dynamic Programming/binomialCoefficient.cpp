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

map<pair<int, int>, int> cache;

// might exceed the time limit, as search and insert operation takes log(n) time.
int nCr(int n, int r)
{
  if (cache.find({n, r}) != cache.end())
    return cache[{n, r}];
  if (r == 1)
    return n;
  if (n < r)
    return 0;
  return cache[{n, r}] = nCr(n - 1, r) + nCr(n - 1, r - 1);
}

int nCrTabulation(int n, int r)
{
  if (n < r)
    return 0;
  vector<int> prev(n + 1), cur(n + 1);
  for (int i = 0; i <= n; ++i)
    prev[i] = i;
  for (int i = 2; i <= r; ++i)
  {
    cur[i] = 1;
    for (int j = i + 1; j <= n; ++j)
    {
      cur[j] = prev[j - 1] + cur[j - 1];
    }
    prev = cur;
  }
  return prev[n];
}

void solve()
{
  int n, r;
  cin >> n >> r;
  cout << nCrTabulation(n, r) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}