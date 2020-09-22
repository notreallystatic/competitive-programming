/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given N point on a 2D plane as pair of (x, y) co-ordinates, we need to find maximum number of point which lie on the same line.

Link:
https://www.geeksforgeeks.org/count-maximum-points-on-same-line/

Input:
6
-1 1
0 0
1 1
2 2
3 3
3 4

Output:
4

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

// Custom hash function to get a key from a pair of integers
struct hash_pair
{
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const
  {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};

void maxPoints(vector<pair<int, int>> &points)
{

  unordered_map<pair<int, int>, int, hash_pair> mp;
  int result(0), curMax, overlap, vertical;

  for (int i = 0; i < points.size(); ++i)
  {
    curMax = overlap = vertical = 0;
    int x1(points[i].first), y1(points[i].second);

    for (int j = i + 1; j < points.size(); ++j)
    {
      int x2(points[j].first), y2(points[j].second);
      // Pointes are overlapped
      if (x1 == x2 && y1 == y2)
      {
        ++overlap;
      }
      // Slope is 90deg.
      else if (x1 == x2)
      {
        ++vertical;
      }
      else
      {
        pair<int, int> slope = {y2 - y1, x2 - x1};
        int gcd = __gcd(slope.first, slope.second);
        slope.first /= gcd;
        slope.second /= gcd;
        ++mp[slope];
        curMax = max(curMax, mp[slope]);
      }
      curMax = max(curMax, vertical);
    }
    result = max(result, curMax + overlap + 1);
    mp.clear();
  }

  cout << result << endl;
}

void solve()
{
  int n, x, y;
  cin >> n;
  vector<pair<int, int>> points(n);
  for (auto &x : points)
    cin >> x.first >> x.second;

  maxPoints(points);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}