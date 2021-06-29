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

int kthLargest(vector<int> &a, vector<int> &b, const int &k)
{
  if (a.size() < b.size())
    return kthLargest(b, a, k);
  const int n(a.size()), m(b.size());
  int total = n + m - k;
  int low(0), high(n), i, j;
  while (low <= high)
  {
    i = (low + high) >> 1;
    j = total - i;
    cout << low << " " << high << " " << i << " " << j << endl;
    if (j >= m)
      low = i + 1;
    else if (i > 0 && a[i - 1] > b[j])
      high = i - 1;
    else if (i < n && a[i] < b[j - 1])
      low = i + 1;
    else
    {
      if (i == n)
        return b[j];
      if (j == m)
        return a[i];
      return min(a[i], b[j]);
    }
  }
  return 0;
}

void solve()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;
  cout << kthLargest(a, b, k) << endl;
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}
