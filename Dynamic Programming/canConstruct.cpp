/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Write a function `canConstruct(target, wordBank)` that accepts a target string and an array of strings.
The function should return a boolean indicating whether or not the `target` can be constructed by concatenating of elements of the `wordBank` array.

Link:


Input:
5 abcdef
ab
abc
cd
def
abcd

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

vector<string> wordBank;
unordered_map<string, bool> cache;

bool canConstruct(string target)
{
  if (cache.find(target) != cache.end())
    return cache[target];
  if (target.length() == 0)
    return true;
  for (auto word : wordBank)
  {
    if (word == target.substr(0, word.length()))
    {
      cache[target] = canConstruct(target.substr(word.length(), target.length()));
      if (cache[target])
        return true;
    }
  }
  return cache[target] = false;
}

void solve()
{
  int n;
  string target;
  cin >> n >> target;
  wordBank = vector<string>(n);
  for (auto &word : wordBank)
    cin >> word;

  cout << canConstruct(target);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}