/*
Author : sk92907
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given that integers are being read from a data stream. Find the median of all the elements read so far starting from the first integer till the last integer. This is also called the Median of Running Integers. The data stream can be any source of data, for example, a file, an array of integers, input stream etc.

Link:
https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/

Input:
3
1 2 3

Output:
1 1.5 2
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

class Stream
{
private:
  int lenMax;
  int lenMin;
  double avg;
  // Max Heap
  priority_queue<int> mx;
  // Min Heap
  priority_queue<int, vi, greater<int>> mn;

public:
  Stream()
  {
    lenMax = lenMin = 0;
  }

  void setAverage()
  {
    if (lenMax == lenMin)
    {
      avg = (double)mx.top() + (double)mn.top();
      avg /= (double)2;
    }
    else if (lenMax > lenMin)
    {
      avg = mx.top();
    }
    else
    {
      avg = mn.top();
    }
  }

  void insert(const int &num)
  {
    /*
      Try to balance both the heaps, left(max) & right(min).
      Cases:
        1. If size(max) > size(min):
          -if new element is less than avg, then remove the top from max and insert it into min & push the new element in max.
          -if new element is greater than avg, then push it in min.
        2. If size(max) < size(min):
          -if new element is less than avg, push it into max.
          -if new elements is greater than avg, them remove the top from min and insert it into max & push the new element in min.
        3. If size(max) = size(min):
          -if new element is less than avg, push it in max.
          -else, push it in min.
    */
    if (lenMax == lenMin && lenMin == 0)
    {
      mx.push(num);
      ++lenMax;
    }
    else if (lenMax > lenMin)
    {
      if (num < avg)
      {
        mn.push(mx.top());
        mx.pop();
        mx.push(num);
      }
      else
      {
        mn.push(num);
      }
      ++lenMin;
    }
    else if (lenMin > lenMax)
    {
      if (num < avg)
      {
        mx.push(num);
      }
      else
      {
        mx.push(mn.top());
        mn.pop();
        mn.push(num);
      }
      ++lenMax;
    }
    else
    {
      if (num < avg)
      {
        ++lenMax;
        mx.push(num);
      }
      else
      {
        ++lenMin;
        mx.push(num);
      }
    }

    setAverage();
  }

  double average()
  {
    return avg;
  }
};

void solve()
{
  int n;
  cin >> n;
  vi arr(n);
  for (int &x : arr)
    cin >> x;

  Stream s;
  for (int x : arr)
  {
    s.insert(x);
    cout << s.average() << " ";
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}