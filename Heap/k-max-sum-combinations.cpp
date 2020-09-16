/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/* 
  Problem Statement:
  Given two equally sized arrays (A, B) and N (size of both arrays).
  A sum combination is made by adding one element from array A and another element of array B. Display the maximum K valid sum combinations from all the possible sum combinations.
  
  Link: https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/
  
  Input: 
  4
  4
  1 4 2 3
  2 5 1 6

  Output:
  10 9 9 8
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

void kMaxSum(const int &n, vector<int> &A, vector<int> &B, int k)
{

  // To check if a given pair of set is already taken or not.
  set<pair<int, int>> present;
  // To store possible pairs
  priority_queue<pair<int, pair<int, int>>> pq;
  vi result;

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  // Push the max pair in the heap.
  pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
  present.insert({n - 1, n - 1});

  while (k--)
  {
    auto top = pq.top();
    pq.pop();
    result.push_back(top.first);
    int i(top.second.first), j(top.second.second);
    // Possible pairs from here: (i - 1, j) & (i, j - 1)

    if (!present.count({i - 1, j}))
    {
      present.insert({i - 1, j});
      pq.push({A[i - 1] + B[j], {i - 1, j}});
    }
    if (!present.count({i, j - 1}))
    {
      present.insert({i, j - 1});
      pq.push({A[i] + B[j - 1], {i, j - 1}});
    }
  }

  // Print the result
  for (int x : result)
    cout << x << " ";
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vi A(n), B(n);
  for (int &x : A)
    cin >> x;
  for (int &x : B)
    cin >> x;

  kMaxSum(n, A, B, k);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}