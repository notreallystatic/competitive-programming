/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array of N non-negative integers, task is to find the maximum size of a subarray such that the pairwise sum of the elements of this subarray is not divisible by a given integer, K. Also, print this subarray as well. If there are two or more subarrays which follow the above stated condition, then print the first one from the left.

Link:
https://www.geeksforgeeks.org/subarray-no-pair-sum-divisible-k/

Input:
5 3
3 7 1 9 2

Output:
3
3 7 1

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

void longestSubarray(const int &n, const int &k, const vector<int> &arr)
{
  unordered_map<int, int> freq;
  int start(0), end(0), maxS(0), maxE(0);

  // Put the remainder of starting element in hash-map
  freq[arr[0] % k]++;

  for (int i = 1; i < n; ++i)
  {
    int mod(arr[i] % k);
    // if (k - mod) exists, it means that we can create a pair whose sum is divisible by k, or if mod = 0 and freq[0] exists in map.
    while (freq[k - mod] != 0 || (mod == 0 && freq[mod] != 0))
    {
      freq[arr[start] % k]--;
      // Move the left pointer, until we get (k-mod) = 0 or (mod == 0 and freq[0] = 0)
      ++start;
    }
    ++end;
    ++freq[mod];
    if ((end - start) > (maxE - maxS))
    {
      maxE = end;
      maxS = start;
    }
  }

  cout << (maxE - maxS + 1) << endl;
  for (int i = maxS; i <= maxE; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;

  longestSubarray(n, k, arr);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}