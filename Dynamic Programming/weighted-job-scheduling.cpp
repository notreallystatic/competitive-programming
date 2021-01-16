/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:
Given N jobs where every job is represented by following three elements of it.

1. Start Time
2. Finish Time
3. Profit or Value Associated (>= 0)

Find the maximum profit subset of jobs such that no two jobs in the subset overlap. 

Link:
https://www.geeksforgeeks.org/weighted-job-scheduling/

Input:
4
1 2 50
3 5 20
6 19 100
2 100 200

Output:
250

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

int wjsRecurrence(vector<pair<pair<int, int>, int>> &jobs, int index, int time)
{
  if (index == jobs.size())
    return 0;
  auto job = jobs[index];
  int startTime = job.first.first;
  int finishTime = job.first.second;
  int cost = job.second;
  int ans(0);
  if (startTime >= time)
    ans = cost + wjsRecurrence(jobs, index + 1, finishTime);
  return max(ans, wjsRecurrence(jobs, index + 1, time));
}

int nonConflict(vector<pair<pair<int, int>, int>> &jobs, int index, int time)
{
  for (int i = index - 1; i >= 0; --i)
    if (jobs[i].first.second <= time)
      return i;
  return -1;
}

int wjsTabulation(vector<pair<pair<int, int>, int>> &jobs)
{
  sort(begin(jobs), end(jobs));
  int n(jobs.size());
  vector<int> cache(n, 0);
  cache[0] = jobs[0].second;
  for (int i = 1; i < n; ++i)
  {
    cache[i] = jobs[i].second;
    auto index = nonConflict(jobs, i, jobs[i].first.first);
    if (index != -1)
      cache[i] += cache[index];
  }

  return *max_element(begin(cache), end(cache));
}

void solve()
{
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> jobs(n);
  for (auto &job : jobs)
    cin >> job.first.first >> job.first.second >> job.second;

  cout << wjsTabulation(jobs) << endl;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}