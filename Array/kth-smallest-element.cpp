/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Link:
https://practice.geeksforgeeks.org/problems/kth-smallest-element/0

Input:
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4

Output:
7
15

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
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  cin >> k;

  priority_queue<int> pq;
  int i = 0;
  while (i < k)
  {
    pq.push(arr[i]);
    ++i;
  }

  while (i != n)
  {
    if (pq.top() > arr[i])
    {
      pq.pop();
      pq.push(arr[i]);
    }
    ++i;
  }
  cout << pq.top() << endl;
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