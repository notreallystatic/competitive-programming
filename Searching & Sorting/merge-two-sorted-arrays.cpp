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

int gap(int n)
{
  return n / 2 + n % 2;
}

void check(int &a, int &b)
{
  if (a > b)
    swap(a, b);
}

void mergeArrays(const int &n, const int &m, vector<int> &arr1, vector<int> &arr2)
{
  int g(gap(n + m)), p1(0), p2(n + m);
  for (g; g >= 1; g = gap(g))
  {
    p1 = 0, p2 = g;
    for (p1, p2; p2 < n + m; ++p1, ++p2)
    {
      if (p1 < n && p2 < n)
        check(arr1[p1], arr1[p2]);
      else if (p1 < n)
        check(arr1[p1], arr2[p2 - n]);
      else
        check(arr2[p1 - n], arr2[p2 - n]);
    }
    if (g == 1)
      break;
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> arr1(n), arr2(m);
  for (int &x : arr1)
    cin >> x;
  for (int &x : arr2)
    cin >> x;

  mergeArrays(n, m, arr1, arr2);
  for (int x : arr1)
    cout << x << " ";
  cout << endl;
  for (int x : arr2)
    cout << x << " ";
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}
