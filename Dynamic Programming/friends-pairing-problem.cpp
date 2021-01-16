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

// Recurrence
int countFriendsPairings(int n)
{
  if (n <= 2)
    return n;
  int keepSingle = countFriendsPairings(n - 1);
  int pairUp = (n - 1) * countFriendsPairings(n - 2);
  return keepSingle + pairUp;
}

int countFriendsPairingsDP(int n)
{
  if (n <= 2)
    return n;
  const int MOD = 1e9 + 7;
  long long a(1), b(2), c;

  for (int i = 3; i <= n; ++i)
  {
    c = b + ((i - 1) % MOD * a % MOD) % MOD;
    c %= MOD;
    a = b;
    b = c;
  }

  return c;
}

void solve()
{
  int n;
  cin >> n;

  cout << countFriendsPairings(n) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}