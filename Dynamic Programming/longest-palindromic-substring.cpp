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

bool isPlaindrome(int low, int high)
{
  while (low <= high)
  {
    if (str[low++] != str[high--])
      return false;
  }
  return true;
}

string lps(int low, int high)
{

  if (low == high)
    return string(1, str[low]);
  if (str[low] == str[high])
  {
    if (isPlaindrome(low, high))
      return string(str.begin() + low, str.begin() + high + 1);
  }
  string res1, res2;
  res1 = lps(low + 1, high);
  res2 = lps(low, high - 1);
  return res1.size() > res2.size() ? res1 : res2;
}

string lpsTabulation()
{
  int n = str.size();
  vector<vector<bool>> cache(n, vector<bool>(n, false));

  pair<int, int> res = {0, 0};

  for (int i = 0; i < n; ++i)
    cache[i][i] = true;

  for (int sl = 2; sl <= n; ++sl)
  {
    for (int i = 0; i < n - sl + 1; ++i)
    {
      int j = i + sl - 1;
      if (str[i] == str[j] && sl == 2)
        cache[i][j] = true;
      else if (str[i] == str[j])
        cache[i][j] = cache[i + 1][j - 1] ? true : false;

      if (cache[i][j])
      {
        if (j - i + 1 > res.second - res.first + 1)
          res = {i, j};
      }
    }
  }

  return string(str.begin() + res.first, str.begin() + res.second + 1);
}

void solve()
{
  cin >> str;
  cout << lpsTabulation() << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}