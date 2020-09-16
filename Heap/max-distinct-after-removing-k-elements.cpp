/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array arr[] containing n elements. The problem is to find maximum number of distinct elements (non-repeating) after removing k elements from the array.

Link:
https://www.geeksforgeeks.org/maximum-distinct-elements-removing-k-elements/

Input:
7 3
5 7 5 5 1 2 2

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

#define int int
#define vi vector<int>

using namespace std;

int maxDistinct(const int &n, vector<int> &arr, int k)
{
  unordered_map<int, int> freq;
  priority_queue<int> pq;

  for (int x : arr)
    ++freq[x];

  for (auto p : freq)
    pq.push(p.second);

  while (k--)
  {
    int top = pq.top();
    --top;
    pq.pop();
    if (top > 0)
      pq.push(top);
  }

  int result(0);

  while (!pq.empty())
  {
    int top = pq.top();
    pq.pop();
    if (top == 1)
      ++result;
  }

  return result;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vi arr(n);
  for (int &x : arr)
    cin >> x;

  cout << maxDistinct(n, arr, k) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}