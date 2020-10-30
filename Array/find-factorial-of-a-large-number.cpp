/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given an integer, the task is to find factorial of the number.

Link:
https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0

Input:
3
5
10
2

Output:
120
3628800
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

string add(string &a, string &b)
{
  int la(a.length()), lb(b.length());
  int diff = abs(la - lb);
  if (la < lb)
  {
    while (diff--)
      a += "0";
  }
  else
  {
    while (diff--)
      b += "0";
  }
  string result;
  int carry(0);
  for (int i = 0; i < a.length(); ++i)
  {
    int n1 = a[i] - '0';
    int n2 = b[i] - '0';
    n1 += n2 + carry;
    result += to_string(n1 % 10);
    carry = n1 / 10;
  }
  if (carry)
  {
    result += to_string(carry);
  }
  return result;
}

string multiply(const string &a, const string &b)
{
  string temp, result;
  int lb(b.length()), la(a.length()), n1, carry, n2;

  for (int i = lb - 1; i >= 0; --i)
  {
    temp = "";
    int pad(lb - i - 1);
    while (pad--)
      temp += "0";
    n1 = b[i] - '0';
    carry = 0;
    for (int j = la - 1; j >= 0; --j)
    {
      n2 = a[j] - '0';
      n2 = (n1 * n2) + carry;
      temp += to_string(n2 % 10);
      carry = n2 / 10;
    }
    if (carry)
      temp += to_string(carry);
    if (result.length())
    {
      string ret;
      ret = add(temp, result);
      result = ret;
    }
    else
    {
      result = temp;
    }
  }

  reverse(result.begin(), result.end());
  return result;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string dp[1001];
  dp[0] = "1";
  for (int i = 1; i <= 1000; ++i)
  {
    string a = to_string(i);
    dp[i] = multiply(dp[i - 1], a);
  }

  int t, n;
  cin >> t;
  while (t--)
  {
    cin >> n;
    cout << dp[n] << endl;
  }

  return 0;
}