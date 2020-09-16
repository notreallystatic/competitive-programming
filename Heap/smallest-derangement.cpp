/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/* 
  Problem Statement:
  Given an array, fine the lexicographically smallest derangement of S.
  
  Link: https://www.geeksforgeeks.org/smallest-derangement-sequence/
  
  Input: 
  5
  1 2 3 4 5

  Output:
  2 1 4 5 3 
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

void smallestDerangement(const vector<int> &arr, const int &n)
{
  vector<int> result(n, 0);
  // Min Heap to store the min element at top, cause we need lexicographically smallest.
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int x : arr)
    pq.push(x);

  int index(0);
  while (!pq.empty())
  {
    int top = pq.top();
    // If this element's position is same as previous, then we can't put it here cause we need derangement. Hence, insert the next min here & put the current one back into the heap.
    if (top == arr[index])
    {
      pq.pop();
      result[index] = pq.top();
      pq.pop();
      pq.push(top);
    }
    // If this position is different, then simply put the min element here.
    else
    {
      result[index] = top;
      pq.pop();
    }
    ++index;
  }

  if (result[n-1] == arr[n - 1]) {
    swap(result[n-1], result[n-2]);
  }

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
  smallestDerangement(arr, n);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}