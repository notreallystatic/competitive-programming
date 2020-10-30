/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.

Link:
https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1

Input:
4 5
1 3 5 7
0 2 6 8 9

Output:
0 1 2 3 5 6 7 8 9

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

int left(const int &i)
{
  return (2 * i + 1);
}

int right(const int &i)
{
  return (2 * i + 2);
}

void heapify(vector<int> &arr, const int &size, int i)
{
  int current(i), l(left(i)), r(right(i));
  if (l < size && arr[l] > arr[current])
    current = l;
  if (r < size && arr[r] > arr[current])
    current = r;
  if (current != i)
  {
    swap(arr[current], arr[i]);
    heapify(arr, size, current);
  }
}

void constructHeap(vector<int> &arr, const int &n)
{
  for (int i = n / 2 - 1; i >= 0; --i)
    heapify(arr, n, i);
}

void popHeap(vector<int> &arr, int &n)
{
  int size(n - 1);
  swap(arr[0], arr[n - 1]);
  --n;
  heapify(arr, size, 0);
}

void pushHeap(vector<int> &arr, int &n, const int &x)
{
  int size(n + 1);
  ++n;
  arr[size - 1] = x;
  int cur(n - 1);
  int parent((cur - 1) / 2);
  while (parent >= 0 && arr[parent] < arr[cur])
  {
    swap(arr[parent], arr[cur]);
    cur = parent;
    parent = (cur - 1) / 2;
  }
}

int top(const vector<int> &arr, const int &size)
{
  if (size == 0)
    return -1;
  return arr[0];
}

void reverse(vector<int> &arr, int n)
{
  for (int i = 0; i < n / 2; ++i)
    swap(arr[i], arr[n - i - 1]);
}

void merge(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
  constructHeap(arr1, n);
  constructHeap(arr2, m);
  int sizem(m), sizen(n);

  while (sizem)
  {
    int top1(top(arr2, sizem));
    int top2(top(arr1, sizen));
    if (top1 < top2)
    {
      popHeap(arr1, sizen);
      pushHeap(arr1, sizen, top1);
      arr2[0] = top2;
    }
    popHeap(arr2, sizem);
  }
  while (sizen)
  {
    popHeap(arr1, sizen);
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> arr1(n), arr2(m);
  for (int &x : arr1)
    cin >> x;
  for (int &x : arr2)
    cin >> x;
  merge(arr1, arr2, n, m);
  for (int x : arr1)
    cout << x << " ";
  for (int x : arr2)
    cout << x << " ";
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}