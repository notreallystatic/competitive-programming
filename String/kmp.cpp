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

vector<int> constructPrefixSuffix(const string &P)
{
  vector<int> arr(P.size(), 0);
  int i(1), j(0);
  while (i < P.size())
  {
    if (P[i] == P[j])
    {
      arr[i] = j + 1;
      ++i, ++j;
    }
    else
    {
      if (j != 0)
        j = arr[j - 1];
      else
      {
        arr[i] = 0;
        ++i;
      }
    }
  }
  return arr;
}

int kmp(const string &T, const string &P)
{
  if (T.size() < P.size())
    return -1;
  vector<int> helper = constructPrefixSuffix(P);
  int i(0), j(0);
  while (i < T.size())
  {
    if (T[i] == P[j])
      ++i, ++j;
    else
    {
      if (j == 0)
        ++i;
      else
        j = helper[j - 1];
    }
    if (j == P.size())
      return i - j;
  }
  return -1;
}

void solve()
{
  string text, pattern;
  cin >> text >> pattern;
  cout << kmp(text, pattern);
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}
