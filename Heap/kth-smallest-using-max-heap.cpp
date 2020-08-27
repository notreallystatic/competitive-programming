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

class Heap
{
private:
  vi heap;
  int size;
  int k;

public:
  Heap(vi &arr, const int &k)
  {
    this->k = k;
    this->size = k;
    this->heap.resize(k);
    for (int i = 0; i < k; ++i)
      this->heap[i] = arr[i];
    this->makeHeap();
  }

  int parent(const int &i)
  {
    return ((i - 1) / 2);
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
      this->heapify(i);
  }

  void heapify(const int &i)
  {
    int largest(i), l(left(i)), r(right(i));
    if (l < this->size && this->heap[l] > this->heap[largest])
      largest = l;
    if (r < this->size && this->heap[r] > this->heap[largest])
      largest = r;
    if (i != largest)
    {
      swap(this->heap[i], this->heap[largest]);
      heapify(largest);
    }
  }

  void replaceMax(const int &num)
  {
    if (this->heap[0] > num)
    {
      this->heap[0] = num;
      this->heapify(0);
    }
  }

  int top()
  {
    return this->heap[0];
  }
};

void solve()
{
  int n, k;
  cin >> n >> k;
  vi arr(n);
  for (int &x : arr)
    cin >> x;
  Heap h(arr, k);
  for (int i = k; i < n; ++i)
  {
    h.replaceMax(arr[i]);
  }
  cout << h.top() << endl;
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
7 3
1 23 12 9 30 2 50

Output: 
3
*/