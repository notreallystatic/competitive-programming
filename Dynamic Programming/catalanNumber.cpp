/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Write a program to print the n'th catalan number. 

Link:
https://www.geeksforgeeks.org/program-nth-catalan-number/

Input:
9

Output:
4862

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

unordered_map<int, int> cache;

int nthCatalanNo(int n)
{
  if (cache.find(n) != cache.end())
    return cache[n];
  if (n == 0)
    return 1;
  int sum(0);
  for (int i = 0; i < n; ++i)
  {
    sum += nthCatalanNo(i) * nthCatalanNo(n - i - 1);
  }
  return cache[n] = sum;
}

void solve()
{
  int n;
  cin >> n;
  cout << nthCatalanNo(n) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}