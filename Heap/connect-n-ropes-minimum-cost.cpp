// Sachin Sheoran

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

#define ll long long
#define ull unsigned ll
#define vi vector<int>
#define si set<int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define vii vi::iterator
#define mx(a, b) a >= b ? a : b
#define mn(a, b) a <= b ? a : b
#define all(v) v.begin(), v.end()
#define endl '\n'
#define mem(a, i) memset(a, i, sizeof(a))
#define deb(x) cout << #x << " " << x << endl;
#define forall(i, a, b) for (int i = a; i < b; i++)
#define forit(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)

using namespace std;

int main()
{
  fastio;

  int t;
  cin >> t;
  while (t--)
  {
    int n, a, b;
    cin >> n;
    // min heap
    priority_queue<int, vi, greater<int>> pq;
    for (int i = 0; i < n; ++i)
    {
      cin >> a;
      pq.push(a);
    }
    long long result = 0;
    while (pq.size() != 1)
    {
      a = pq.top();
      pq.pop();
      b = pq.top();
      pq.pop();
      result += a + b;
      pq.push(a + b);
    }
    cout << result << endl;
  }
  return 0;
}
