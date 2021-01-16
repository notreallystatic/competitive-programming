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

bool canConstruct(string target)
{
  vector<int> cache(target.length() + 1, 0);
  cache[0] = 1;
  for (int i = 0; i < target.length(); ++i)
  {
    string suffix = target.substr(i, target.length());
    if (cache[i])
    {
      for (auto word : wordBank)
      {
        if (word.length() <= suffix.length())
        {
          if (suffix.substr(0, word.length()) == word)
          {
            cache[i + word.length()] = true;
          }
        }
      }
    }
  }
  return cache[target.length()];
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