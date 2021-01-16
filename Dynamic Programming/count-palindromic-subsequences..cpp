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

string str;

// Recurrence
int cps(int low, int high)
{
  // single character counts for one palindromice-substring.
  if (low == high)
    return 1;
  // if last characters are same then it is one ps + other two possible cases
  if (str[low] == str[high])
    return 1 + cps(low + 1, high) + cps(low, high - 1);
  // we can generate ps in two possible ways, but the common ps are counted twice, so we gotta subtract that
  return cps(low + 1, high) + cps(low, high - 1) - cps(low + 1, high - 1);
}

int cpsTabulation()
{
  int n = str.size();
  vector<vector<int>> cache(n, vector<int>(n, 0));

  for (int i = 0; i < n; ++i)
    cache[i][i] = 1;

  for (int sl = 2; sl <= n; ++sl)
  {
    for (int i = 0; i < n - sl + 1; ++i)
    {
      int j = i + sl - 1;
      if (str[i] == str[j] && sl == 2)
        cache[i][j] = 3;
      else if (str[i] == str[j])
        cache[i][j] = 1 + cache[i + 1][j] + cache[i][j - 1];
      else
        cache[i][j] = cache[i + 1][j] + cache[i][j - 1] - cache[i + 1][j - 1];
    }
  }

  return cache[0][n - 1];
}

void solve()
{
  cin >> str;
  cout << cpsTabulation() << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}