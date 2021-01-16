/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Write a function `allConstruct(target, wordBank)` that accepts a target string and an array of strings.
The function should return a 2D array containing all of the ways that the `target` can be constructed by concatenating elements of the `wordBank` array. Each element of the 2D array should represent one combination that constructs the `target`.
You may reuse elements of `wordBank` as many times as needed.

Link:


Input:
7 abcdef
ab
abc
cd
def
abcd
ef
c

Output:
ab cd ef 
ab c def 
abc def 
abcd ef

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

vector<string> wordBank;
unordered_map<string, vector<vector<string>>> cache;

vector<vector<string>> allConstruct(string target)
{
  if (cache.find(target) != cache.end())
    return cache[target];
  if (target.length() == 0)
    return {{}};
  vector<vector<string>> result = {};
  for (auto word : wordBank)
  {
    if (target.substr(0, word.length()) == word)
    {
      auto suffix = target.substr(word.length(), target.length());
      auto suffixWays = allConstruct(suffix);
      if (suffixWays.size())
      {
        for (auto &way : suffixWays)
          way.insert(way.begin(), word);
        result.insert(result.end(), suffixWays.begin(), suffixWays.end());
      }
    }
  }
  return cache[target] = result;
}

void solve()
{
  int n;
  string target;
  cin >> n >> target;
  wordBank = vector<string>(n);
  for (auto &word : wordBank)
    cin >> word;
  auto allWays = allConstruct(target);
  for (auto &way : allWays)
  {
    for (auto word : way)
    {
      cout << word << " ";
    }
    cout << endl;
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}