/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Link:
https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

Input:
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2 
0 0 1

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
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  int start(0), end(n - 1), i(0);
  while (i < n && i <= end)
  {
    if (arr[i] == 0)
      swap(arr[i++], arr[start++]);
    else if (arr[i] == 1)
      ++i;
    else
      swap(arr[i], arr[end--]);
  }
  for (int x : arr)
    cout << x << " ";
  cout << endl;
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