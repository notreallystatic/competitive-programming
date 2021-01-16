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

int knapSack(int W, vector<int> &wt, vector<int> &val, int n)
{

  vector<vector<int>> cache(n, vector<int>(W + 1, 0));

  for (int i = 0; i < n; ++i)
  {
    for (int j = 1; j <= W; ++j)
    {
      if (wt[i] <= j)
      {
        // we can choose this weight.
        // W-wt[i]
        if (i > 0)
          cache[i][j] = max(cache[i][j], val[i] + cache[i - 1][j - wt[i]]);
        else
          cache[i][j] = val[i];
      }
      if (i > 0)
        cache[i][j] = max(cache[i][j], cache[i - 1][j]);
    }
  }

  return cache[n - 1][W];
}

void solve()
{
  int n, W;
  cin >> n >> W;
  vector<int> wt(n), val(n);
  for (int &w : wt)
    cin >> w;
  for (int &v : val)
    cin >> v;
  cout << knapSack(W, wt, val, n) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}