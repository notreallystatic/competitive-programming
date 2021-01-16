/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Write a function `countConstruct(target, wordBank)` that accepts a target string and an array of strings.
The function should return the number of ways that the `target` can be constructed by concatenting elements of the `wordBank` array.
You may reuse elements of `wordBank` as many times as needed.

Link:


Input:


Output:


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

#define int long long

vector<string> wordBank;
unordered_map<string, int> cache;

int countConstruct(string target)
{
  if (cache.find(target) != cache.end())
    return cache[target];
  if (target.length() == 0)
    return 1;
  int count(0);
  for (auto word : wordBank)
  {
    if (target.substr(0, word.length()) == word)
    {
      auto suffix = target.substr(word.length(), target.length());
      auto result = countConstruct(suffix);
      cache[suffix] = result;
      count += result;
    }
  }
  return cache[target] = count;
}

void solve()
{
  int n;
  string target;
  cin >> n >> target;
  wordBank = vector<string>(n);
  for (auto &word : wordBank)
    cin >> word;

  cout << countConstruct(target);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}