/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:


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

int longestRepeatingSubsequence(const string &str)
{
  unordered_map<string, int> mp;
  string res, temp;

  for (int i = 1; i <= str.size(); ++i)
  {
    for (int j = 0; j + i <= str.size(); ++j)
    {
      temp = str.substr(j, i);
      mp[temp]++;
      if (mp[temp] >= 2 && temp.size() > res.size())
        res = temp;
    }
  }

  return res.size();
}

void solve()
{
  string str;
  cin >> str;
  cout << longestRepeatingSubsequence(str);
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}