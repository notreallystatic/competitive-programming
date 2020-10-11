/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given n elements, write a program that prints the longest increasing subsequence whose adjacent element difference is one.

Link:
https://www.geeksforgeeks.org/printing-longest-increasing-consecutive-subsequence/

Input:
8
6 7 8 3 4 5 9 10

Output:
5
6 7 8 9 10

NOTE: This problem can also be solved by dp.
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

void longestSequence(const int &n, vector<int> &arr)
{
  unordered_map<int, int> mp;
  for (int x : arr)
  {
    ++mp[x];
  }
  vector<int> result;
  vector<int> temp;
  for (int x : arr)
  {
    while (mp[x])
    {
      temp.push_back(x);
      --mp[x];
      ++x;
    }
    if (temp.size() > result.size())
      result = temp;
    temp.clear();
  }

  cout << result.size() << endl;
  for (int x : result)
    cout << x << " ";
  cout << endl;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  longestSequence(n, arr);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}