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

#define int int
#define vi vector<int>

using namespace std;

/*
Change this functions according to the need.
Here, we are simply choosing the min contestant as value.
*/
int tournament(const int &a, const int &b)
{
  return (a < b ? a : b);
}

class WinnerTree
{
private:
  vi heap;
  int size;
  int winnerNo;

public:
  WinnerTree(int n, const vi &players)
  {

    int levels = ceil(log2(2 * n - 1)); // Level of the tree.
    size = (1 << levels) - 1;           // A tree with n outer nodes(leaves) will have (n - 1) interior nodes.
    heap.resize(size, INT_MAX);
    winnerNo = 0;
    // Fill all the leaves.
    for (int i = 0; i < n; ++i)
    {
      heap[i + n] = players[i];
    }
    // If leaves are still left, intialize them with a value such that if any player competes with this value then always players is choosen.
    // Here, since we selecting winner based on the min value, so assign INT_MAX.
    makeHeap();
  }

  int parent(const int &i)
  {
    return (i - 1) / 2;
  }

  int left(const int &i)
  {
    return (2 * i + 1);
  }

  int right(const int &i)
  {
    return (2 * i + 2);
  }

  void makeHeap()
  {
    for (int i = size / 2 - 1; i >= 0; --i)
    {
      heap[i] = tournament(heap[left(i)], heap[right(i)]);
    }
  }

  int currentWinner()
  {
    return heap[0];
  }

  int findNexWinner()
  {
    ++winnerNo;
    heapify(0);
    return heap[0];
  }

  void heapify(int i)
  {
    int l(left(i)), r(right(i));
    if (i > size)
      return;
    int next = heap[l] == heap[i] ? l : r;
    heap[i] = INT_MAX;
    heapify(next);
    if (l < size && r < size)
    {
      heap[i] = tournament(heap[l], heap[r]);
    }
  }

  void display()
  {
    for (int x : heap)
    {
      cout << x << " ";
    }
    cout << endl;
  }
};

void solve()
{
  int n;
  cin >> n;
  vi players(n);
  for (int &x : players)
    cin >> x;
  WinnerTree t(n, players);
  t.display();
  cout << t.currentWinner() << endl;
  cout << t.findNexWinner() << endl;
  t.display();
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}

/*
Input:
7
5 2 0 1 4 9 3
Output:
0 0 3 2 0 4 3 5 2 0 1 4 9 3 2147483647 
0
1
1 1 3 2 1 4 3 5 2 2147483647 1 4 9 3 2147483647 
*/