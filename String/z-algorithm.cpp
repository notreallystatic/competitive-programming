/*
Author : notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

#include <iostream>
#include <stdlib.h>
#include <numeric>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <cctype>
#include <sstream>
#include <cmath>
#include <limits.h>
#include <bitset>
#include <random>

using namespace std;

void zArrayHelper(const string &str, vector<int> &zArray, int &l, int &r, int &i)
{
  int lIndex(1);
  zArray[i++] = r - l;
  while (i < r)
  {
    if (i + zArray[lIndex] < r)
      zArray[i++] = zArray[lIndex++];
    else
    {
      l = zArray[lIndex];
      while (r < str.size() && str[l] == str[r])
        ++l, ++r;
      zArray[i++] = r - i;
      lIndex = 1;
    }
  }
}

vector<int> constructZArray(const string &str)
{
  const int N = str.size();
  vector<int> zArray(N, 0);
  int i = 1;
  while (i < N)
  {
    if (str[0] == str[i])
    {
      int l(i), r(i + 1);
      while (r < str.size() && str[r - i] == str[r])
        ++r;
      if (r - l == 1)
      {
        zArray[i] = 1;
        ++i;
      }
      else
        zArrayHelper(str, zArray, l, r, i);
    }
    else
      ++i;
  }
  return zArray;
}

vector<int> ZAlgorithm(const string &T, const string &P)
{
  string str = P + '_' + T;
  // stores the longest prefix which is also a substring at current position
  vector<int> zArray = constructZArray(str);
  vector<int> result;

  for (int i = P.size(); i < str.size(); ++i)
  {
    if (zArray[i] >= P.size())
      result.push_back(i - P.size() - 1);
  }
  return result;
}

void solve()
{
  string text, pattern;
  cin >> text >> pattern;
  vector<int> res = ZAlgorithm(text, pattern);
  for (int x : res)
    cout << x << " ";
  cout << endl;
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}
