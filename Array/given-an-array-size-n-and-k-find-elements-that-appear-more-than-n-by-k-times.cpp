/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array of size n, find all elements in array that appear more than n/k times. For example, if the input arrays is {3, 1, 2, 2, 1, 2, 3, 3} and k is 4, then the output should be [2, 3]. Note that size of array is 8 (or n = 8), so we need to find all elements that appear more than 2 (or 8/4) times. There are two elements that appear more than two times, 2 and 3. 

Link:
geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/

Input:
7 3
4 5 6 7 8 4 4

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

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;

  vector<pair<int, int>> cnt(k - 1);

  for (int i = 0; i < n; ++i)
  {
    int j(0);
    // Increase the frequence
    for (j = 0; j < k - 1; ++j)
    {
      if (cnt[j].first == arr[i])
      {
        cnt[j].second++;
        break;
      }
    }
    // if not present, insert it
    for (j = 0; j < k - 1; ++j)
    {
      if (cnt[j].second == 0)
      {
        cnt[j].first = arr[i];
        cnt[j].second++;
        break;
      }
    }
    // If can't insert, decrease the frequence
    if (j == k - 1)
    {
      for (j = 0; j < k - 1; ++j)
      {
        cnt[j].second--;
      }
    }
  }

  // Count the frequence of remaining elements;
  for (int j = 0; j < k - 1; ++j)
  {
    cnt[j].second = 0;
    for (int i = 0; i < n; ++i)
    {
      if (arr[i] == cnt[j].first)
        ++cnt[j].second;
    }
    if (cnt[j].second > n / k)
    {
      cout << cnt[j].first << " ";
    }
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}