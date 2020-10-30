/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.

Link:
https://practice.geeksforgeeks.org/problems/common-elements1132/1

Input:
6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120

Output:
20 80

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

vector<int> commonElements(vector<int> &A, vector<int> &B, vector<int> &C, const int &n1, const int &n2, const int &n3)
{
  vector<int> result;
  int i(0), j(0), k(0);
  while (i < n1 && j < n2 && k < n3)
  {
    if (A[i] == B[j] && B[j] == C[k])
    {
      if ((!result.size()) || (result.size() && result[result.size() - 1] != A[i]))
        result.push_back(A[i]);
      ++i, ++j, ++k;
    }
    else if (A[i] < B[j])
      ++i;
    else if (B[j] < C[k])
      ++j;
    else
      ++k;
  }
  return result;
}

void solve()
{
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  vector<int> arr1(n1), arr2(n2), arr3(n3);
  for (int &x : arr1)
    cin >> x;
  for (int &x : arr2)
    cin >> x;
  for (int &x : arr3)
    cin >> x;

  vector<int> result = commonElements(arr1, arr2, arr3, n1, n2, n3);
  for (int x : result)
    cout << x << " ";
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}