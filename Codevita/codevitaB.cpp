/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

#include <iostream>
#include <stdlib.h>
#include <numeric>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <cctype>
#include <sstream>
#include <cmath>
#include <limits.h>
#include <bitset>
#include <random>

using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define deb(x) cout << #x << " " << x << endl;
#define debxy(x, y) cout << #x << " " << x << "\t" << #y << " " << y << endl;
#define forall(i, a, b) for (int i = a; i < b; ++i)
#define forit(it, a) for (decltype(a.begin()) it = a.begin(); it != a.end(); it++)
#define endl "\n"

typedef long long ll;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<pii> vpii;
typedef map<int, int> mii;

bool isUpper(char c) { return c >= 'A' && c <= 'Z'; }
bool isLower(char c) { return c >= 'a' && c <= 'z'; }
bool isLetter(char c) { return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }
bool isDigit(char c) { return c >= '0' && c <= '9'; }
char toLower(char c) { return (isUpper(c)) ? (c + 32) : c; }
char toUpper(char c) { return (isLower(c)) ? (c - 32) : c; }
int str2int(string s)
{
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
int char2int(char c) { return (int)c; }
bool isPowerOfTwo(const int &x) { return !(x & (x - 1)); }
bool isPerfectSquare(const int &x) { return floor(sqrt(x)) == ceil(sqrt(x)); }
int pow2(const int &x) { return (1LL << x); }
int min(const int &a, const int &b, const int &c) { return min(a, min(b, c)); }

const int mod = 1000000007;

int maxBits(int num)
{
  int count(0), setBits(__builtin_popcount(num)), pos(0);
  while (setBits)
  {
    if (num & (1 << pos))
    {
      --setBits;
    }
    ++pos;
  }
  return pos;
}

int totalSubsets(const vi &arr, const int &totalBits)
{
  int n(arr.size()), result(0);
  for (int i = 0; i < (1 << n); ++i)
  {
    int ones(0), zeros(0);
    for (int j = 0; j < n; ++j)
    {
      if (i & (1 << j))
      {
        int setBits(__builtin_popcount(arr[j]));
        ones += setBits;
        zeros += totalBits - setBits;
      }
    }
    if (ones && zeros && (ones == zeros))
    {
      ++result;
    }
  }
  return result;
}

string toBinary(int num)
{
  if (num < 2)
  {
    return to_string(num);
  }
  return to_string(num % 2) + toBinary(num / 2);
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vi arr(n);
  for (int &x : arr)
    cin >> x;
  int maxElement = *max_element(all(arr));
  int totalBits = maxBits(maxElement);

  int result = totalSubsets(arr, totalBits);
  string binary;
  if (result)
  {
    binary = toBinary(result);
    int length = (int)binary.length();
    for (int i = 0; i < totalBits - length; ++i)
    {
      binary += "0";
    }
    reverse(all(binary));
    length = (int)binary.length();
    if (length > totalBits)
    {
      int extraLength = length - totalBits;
      binary = binary.substr(extraLength, length);
    }
  }
  else
  {
    for (int i = 0; i < totalBits; ++i)
    {
      binary += "0";
    }
  }
  cout << binary;
  return 0;
}
