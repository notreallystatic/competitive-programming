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

int limit;

int count(int n, int index = 0)
{
  if (n == limit || index >= 5)
    return 0;
  int res(0);
  res += count(n + 1, index) + count(n + 1, index + 1) + count(n, index + 1);
  return res;
}

void solve()
{
  int n;
  cin >> n;
  limit = n;
  cout << count(0) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}