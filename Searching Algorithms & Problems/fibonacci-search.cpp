/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Implement Fibonacci search

Link:
https://www.geeksforgeeks.org/fibonacci-search/

Input:
12 60
5 10 15 20 25 30 35 40 45 50 55 60

Output:
11

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

int fibonacciSearch(const int &n, const vector<int> &arr, const int &target)
{
  int fib(1), fib1(1), fib2(0);
  while (fib < n)
  {
    fib2 = fib1;
    fib1 = fib;
    fib = fib1 + fib2;
  }
  int offset(-1);
  while (fib > 1)
  {
    int i = min(offset + fib2, n - 1);

    if (arr[i] > target)
    {
      // If target is smaller than current, move the fib two down,
      // indicating that we eliminated two thirds of the rear array.
      fib = fib2;
      fib1 = fib1 - fib2;
      fib2 = fib - fib1;
    }
    else if (arr[i] < target)
    {
      // If target is greater than current, move the fib one down,
      // indicating that we eliminated one third of the front array.
      // Mark the offset, in order to get the correct index of the right sub-array.
      fib = fib1;
      fib1 = fib2;
      fib2 = fib - fib1;
      offset = i;
    }
    else
      return i;
  }
  if (fib1 && arr[offset + 1] == target)
    return offset + 1;
  return -1;
}

void solve()
{
  int n, target;
  cin >> n >> target;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  cout << fibonacciSearch(n, arr, target) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}