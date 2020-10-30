/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

Link:
https://leetcode.com/problems/find-the-duplicate-number/

Input:
5
1 3 4 2 2

Output:
2

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

int findDuplicate(vector<int> &nums)
{
  for (int i = 0; i < nums.size(); ++i)
  {
    int x = abs(nums[i]);
    if (nums[x] < 0)
      return x;
    else
      nums[x] *= -1;
  }
  return -1;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  cout << findDuplicate(arr) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}