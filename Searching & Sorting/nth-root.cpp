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

// return n^m in log m
double binaryExponentiation(double n, int m)
{
  double ans = 1;
  while (m)
  {
    if (m & 1)
      ans *= n;
    n *= n;
    m /= 2;
  }
  return ans;
}

double nthRoot(int n, int m)
{
  double low = 1;
  double high = n;
  double diff = 1e-6;
  while (high - low > diff)
  {
    double mid = (low + high) / 2.0;
    double value = binaryExponentiation(mid, m);
    if (value == n)
      return mid;
    if (value > n)
      high = mid;
    else
      low = mid;
  }
  return low;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  cout << nthRoot(n, m) << endl;
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}
