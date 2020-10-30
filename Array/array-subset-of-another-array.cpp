/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given two arrays: arr1[0..m-1] of size m and arr2[0..n-1] of size n. Task is to check whether arr2[] is a subset of arr1[] or not. Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.

Link:
https://practice.geeksforgeeks.org/problems/array-subset-of-another-array/0

Input:
3
6 4
11 1 13 21 3 7
11 3 7 1
6 3
1 2 3 4 5 6
1 2 4
5 3
10 5 2 23 19
19 5 3

Output:
Yes
Yes
No

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
  int n, m;
  cin >> n >> m;
  vector<int> arr1(n);
  vector<int> arr2(m);
  unordered_map<int, int> mp;
  for (int &x : arr1)
    cin >> x;
  for (int &x : arr2)
  {
    cin >> x;
    mp[x]++;
  }

  for (int x : arr1)
  {
    mp[x]--;
  }

  int isSubarray(1);
  for (auto it = mp.begin(); it != mp.end(); ++it)
  {
    if (it->second > 0)
    {
      isSubarray = 0;
      break;
    }
  }
  if (isSubarray)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}