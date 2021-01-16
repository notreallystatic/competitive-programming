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

int max(const int &a, const int &b, const int &c)
{
  if (a > b)
    return a > c ? a : c;
  return b > c ? b : c;
}

int lcs3(string &a, string &b, string &c)
{
  vector<vector<vector<int>>> cache(a.size() + 1, vector<vector<int>>(b.size() + 1, vector<int>(c.size() + 1, 0)));
  for (int i = 0; i <= a.size(); ++i)
  {
    for (int j = 0; j <= b.size(); ++j)
    {
      for (int k = 0; k <= c.size(); ++k)
      {
        if (i == 0 || j == 0 || k == 0)
          cache[i][j][k] = 0;
        else
        {
          if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
            cache[i][j][k] = 1 + cache[i - 1][j - 1][k - 1];
          else
          {
            cache[i][j][k] = max(cache[i - 1][j][k], cache[i][j - 1][k], cache[i][j][k - 1]);
          }
        }
      }
    }
  }
  return cache[a.size()][b.size()][c.size()];
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--)
  {

    int n1, n2, n3;
    string a, b, c;
    cin >> n1 >> n2 >> n3 >> a >> b >> c;
    cout << lcs3(a, b, c) << endl;
  }
  return 0;
}