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

class Node
{
public:
  int x;
  int i;
  int index;
  int size;

  Node(const int &x, const int &i, const int &index, const int &size)
  {
    this->x = x;
    this->i = i;
    this->index = index;
    this->size = size;
  }
};

class MergeArrays
{
private:
  vector<vi> arrays;
  vector<Node> heap;
  int size;

public:
  MergeArrays(vector<vi> arrays)
  {
    this->arrays = arrays;
    this->size = arrays.size();
    for (int i = 0; i < size; ++i)
    {
      Node n(arrays[i][0], i, 1, arrays[i].size());
      heap.push_back(n);
    }
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
      heapify(i);
    }
  }

  void heapify(const int &i)
  {
    int l(left(i)), r(right(i)), smallest(i);
    if (l < size && heap[l].x < heap[smallest].x)
      smallest = l;
    if (r < size & heap[r].x < heap[smallest].x)
      smallest = r;
    if (smallest != i)
    {
      swap(heap[i], heap[smallest]);
      heapify(smallest);
    }
  }

  void pop()
  {
    swap(heap[0], heap[size - 1]);
    heap.pop_back();
    --size;
    heapify(0);
  }

  void push(Node n)
  {
    heap.push_back(n);
    ++size;
    int cur(size - 1), p(parent(cur));
    while (cur > 0 && heap[p].x > heap[cur].x)
    {
      swap(heap[p], heap[cur]);
      cur = p;
      p = parent(p);
    }
  }

  Node top()
  {
    return heap[0];
  }

  vi mergeArrays()
  {
    vi result;
    while (size)
    {
      Node top = this->top();
      result.push_back(top.x);
      this->pop();
      if (top.index < top.size)
      {
        top.x = arrays[top.i][top.index];
        ++top.index;
        this->push(top);
      }
    }
    return result;
  }
};

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vi> arrays = {{1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11}};
  MergeArrays m(arrays);
  vi result = m.mergeArrays();
  for (auto x : result)
    cout << x << " ";
  return 0;
}

// Output
// 0 1 2 3 4 5 6 7 8 9 10 11