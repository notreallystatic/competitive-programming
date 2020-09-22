/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

Link:
https://www.geeksforgeeks.org/check-if-an-array-can-be-divided-into-pairs-whose-sum-is-divisible-by-k/

Input:
4 6
9 7 5 3

Output:
1

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

bool isPossible(const vector<int> &arr, const int &n, const int &k)
{
  // (x % k + k) % k is done to take care of the negative numbers;
  unordered_map<int, int> mp;
  // Store the remainders in a hash map.
  for (int x : arr)
    ++mp[(x % k + k) % k];

  for (int x : arr)
  {
    int rem = (x % k + k) % k;
    if (rem == 0 || (rem * 2) == k)
    {
      // If the number of numbers whose remainder is 0 is odd, then it's not possible.
      // If remainder divided k in half, then the count of these numbers should be even.
      if (mp[rem] & 1)
        return false;
    }
    else
    {
      if (mp[rem] != mp[k - rem])
        return false;
    }
  }
  return true;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;

  cout << isPossible(arr, n, k);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}