/*
Author : notreallystatic
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

//  Rabin-Karp Using rolling-hash

#define int long long

const int PRIME = 101;

// sometimes pow(a, b) gives wrong answer, so user pow(a, b) + 1e-9
// int pow(int a, int b)
// {
//   int res(1);
//   for (int i = 1; i <= b; ++i)
//     res *= a;
//   return res;
// }

int calculateHash(const string &str, const int &length)
{
  int hash(0);
  for (int i = 0; i < length; ++i)
    hash += (str[i] * (pow(PRIME, i) + 1e-9));
  return hash;
}

int recalculateHash(const string &str, const int &current, const int &oldHash, const int &length)
{
  int hash(oldHash);
  hash -= str[current - length];
  hash /= PRIME;
  hash += (str[current] * (pow(PRIME, length - 1) + 1e-9));
  return hash;
}

vector<int> fillHash(const string &T, const string &P)
{
  vector<int> hash(T.size(), 0);
  hash[P.size() - 1] = calculateHash(T, P.size());

  for (int i = P.size(); i < T.size(); ++i)
    hash[i] = recalculateHash(T, i, hash[i - 1], P.size());

  return hash;
}

vector<int> rabinKarp(const string &T, const string &P)
{
  if (T.size() < P.size())
    return {};

  int patternHash = calculateHash(P, P.size());
  vector<int> hash = fillHash(T, P);
  vector<int> result;

  for (int i = P.size() - 1; i < T.size(); ++i)
  {
    if (hash[i] == patternHash && T.substr(i - P.size() + 1, P.size()) == P)
      result.push_back(i - P.size() + 1);
  }
  return result;
}

void solve()
{
  string text, pattern;
  cin >> text >> pattern;
  vector<int> res = rabinKarp(text, pattern);
  for (int x : res)
    cout << x << " ";
  cout << endl;
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}
