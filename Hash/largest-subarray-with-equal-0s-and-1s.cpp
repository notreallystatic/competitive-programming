/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array containing only 0s and 1s, find the largest subarray which contains equal no of 0s and 1s. Expected time complexity is O(n).

Link:
https://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/

Input:
7
1 0 1 1 1 0 0

Output:
6

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

void largestSub(const int &n, vector<int> &arr)
{
  if (n == 0)
    return;
  vector<int> prefix(n);
  unordered_map<int, int> mp;
  int result(0);

  prefix[0] = arr[0] == 0 ? -1 : 1;
  for (int i = 1; i < n; ++i)
    prefix[i] = prefix[i - 1] + (arr[i] == 0 ? -1 : 1);

  for (int i = 0; i < n; ++i)
  {
    if (prefix[i] == 0)
      result = i + 1;
    else if (mp.find(prefix[i]) != mp.end())
      result = max(result, i - mp[prefix[i]]);
    else
      mp[prefix[i]] = i;
  }

  cout << result << endl;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  largestSub(n, arr);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}