#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

#define deb(x) cout << #x << " " << x << endl
#define all(x) x.begin(), x.end()

using namespace std;

int main()
{

  int n, countA(0), countB(0);
  string arr;
  cin >> n >> arr;
  string str = arr;
  vector<pair<int, int>> time(n, {INT_MAX, INT_MAX});

  int start = -1;
  for (int i = 0; i < n; ++i)
  {
    if (arr[i] == 'A')
      start = -1;
    if (arr[i] == 'B')
    {
      start = 0;
    }
    else if (start != -1)
    {
      time[i].first = ++start;
    }
  }

  start = -1;
  for (int i = n - 1; i >= 0; --i)
  {
    if (arr[i] == 'B')
      start = -1;
    if (arr[i] == 'A')
    {
      start = 0;
    }
    else if (start != -1)
    {
      time[i].second = ++start;
    }
  }

  for (int i = 0; i < n; ++i)
  {
    if (str[i] != '-')
      continue;
    if (time[i].first == time[i].second)
    {
      continue;
    }
    else if (time[i].first < time[i].second)
    {
      arr[i] = 'B';
    }
    else
    {
      arr[i] = 'A';
    }
  }

  countA = count(all(arr), 'A');
  countB = count(all(arr), 'B');
  if (countA == countB)
  {
    cout << "Coalition government";
  }
  else if (countA > countB)
  {
    cout << "A";
  }
  else
  {
    cout << "B";
  }

  return 0;
}
