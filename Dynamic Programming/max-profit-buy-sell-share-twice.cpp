/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
In a daily share trading, a buyer buys shares in the morning and sells it on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Sell->buy->sell->buy). Given stock prices throughout the day, find out the maximum profit that a share trader could have made

Link:
https://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-twice/

Input:
7
1 10 5 12 2 10 1

Output:
19

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

vector<int> prices;

// Recurrence
int maxProfit(int index, int price, int purchasesLeft)
{
  if (index == prices.size())
    return -price;
  // if already bought, try selling it and purchase more if you can do
  if (price > 0)
  {
    int profit = prices[index] - price;
    // sell it now & purchase more, sell it later
    return max(profit + maxProfit(index + 1, 0, purchasesLeft), maxProfit(index + 1, price, purchasesLeft));
  }
  // if not yet purchased, then check if we can still purchase
  if (purchasesLeft)
  {
    return max(maxProfit(index + 1, prices[index], purchasesLeft - 1), maxProfit(index + 1, 0, purchasesLeft));
  }
  return -price;
}

int maxProfitTabulation()
{
  int n = prices.size();
  vector<int> profit(n, 0);
  int maxPrice = prices[n - 1];
  for (int i = n - 2; i >= 0; --i)
  {
    if (prices[i] > maxPrice)
      maxPrice = prices[i];
    profit[i] = max(profit[i + 1], maxPrice - prices[i]);
  }
  int minPrice = prices[0];
  for (int i = 1; i < n; ++i)
  {
    if (prices[i] < minPrice)
      minPrice = prices[i];
    profit[i] = max(profit[i - 1], profit[i] + prices[i] - minPrice);
  }
  return profit[n - 1];
}

void solve()
{
  int n;
  cin >> n;
  prices = vector<int>(n);
  for (int &x : prices)
    cin >> x;
  cout << maxProfitTabulation() << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}