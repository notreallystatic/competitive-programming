/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
A and B are playing a game. At the beginning there are n coins. Given two more numbers x and y. In each move a player can pick x or y or 1 coins. A always starts the game. The player who picks the last coin wins the game. For a given value of n, find whether A will win the game or not if both are playing optimally.

Link:
https://www.geeksforgeeks.org/coin-game-winner-every-player-three-choices/

Input:
// n x y
5 3 4

Output:
A

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

vector<int> choices;

int winner(int n, int currentPlayer)
{
  if (n == 1)
    return currentPlayer;
  if (n == 0)
    return 1 - currentPlayer;
  int res(1 - currentPlayer);
  for (int x : choices)
  {
    if (x <= n && winner(n - x, 1 - currentPlayer) == currentPlayer)
      res = currentPlayer;
  }
  return res;
}

int coinGameTabulation(int n)
{
  vector<int> cache(n + 1, 0);
  cache[0] = false;
  cache[1] = true;
  for (int i = 2; i <= n; ++i)
  {
    for (int x : choices)
    {
      if (i - x >= 0 && !cache[i - x])
        cache[i] = true;
    }
  }
  return cache[n];
}

void solve()
{
  int n, x, y;
  cin >> n >> x >> y;
  choices = {1, x, y};
  int res = coinGameTabulation(n);
  if (res)
    cout << "A" << endl;
  else
    cout << "B" << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}