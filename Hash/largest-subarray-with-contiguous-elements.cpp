/*
Author : sk92907
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

void largestSub(const int &n, vector<int> &arr)
{
  unordered_set<int> s;
  int start(0), end(1);
  int ans(INT_MIN);
  for (int e : arr)
  {
    if (!s.count(e) || !s.count(e - 1) || !s.count(e + 1))
    {
      ans = max(ans, (int)s.size());
      s.clear();
    }
    s.insert(e);
  }
  ans = max(ans, (int)s.size());
  cout << ans << endl;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  largestSub(n, arr);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}