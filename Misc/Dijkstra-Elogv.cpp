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
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <functional>
#include <cctype>
#include <sstream>
#include <cmath>
#include <limits.h>
#include <bitset>
#include <random>

using namespace std;

#define int int
#define pb push_back
#define all(v) v.begin(), v.end()
#define deb(x) cout << #x << " " << x << endl;
#define debxy(x, y) cout << #x << " " << x << "\t" << #y << " " << y << endl;
#define forall(i, a, b) for (int i = a; i < b; ++i)
#define forit(it, a) for (decltype(a.begin()) it = a.begin(); it != a.end(); it++)
#define endl "\n"

typedef long long ll;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<pii> vpii;
typedef map<int, int> mii;

bool isUpper(char c) { return c >= 'A' && c <= 'Z'; }
bool isLower(char c) { return c >= 'a' && c <= 'z'; }
bool isLetter(char c) { return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }
bool isDigit(char c) { return c >= '0' && c <= '9'; }
char toLower(char c) { return (isUpper(c)) ? (c + 32) : c; }
char toUpper(char c) { return (isLower(c)) ? (c - 32) : c; }
int str2int(string s)
{
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
int char2int(char c) { return (int)c; }
bool isPowerOfTwo(const int &x) { return !(x & (x - 1)); }
bool isPerfectSquare(const int &x) { return floor(sqrt(x)) == ceil(sqrt(x)); }
int pow2(const int &x) { return (1LL << x); }
int min(const int &a, const int &b, const int &c) { return min(a, min(b, c)); }

const int mod = 1000000007;

template <typename... T>
void read(T &... args)
{
  ((cin >> args), ...);
}

template <typename... T>
void write(T &&... args)
{
  ((cout << args << " "), ...);
}

template <class T>
void display(const vector<T> &v)
{
  for_each(all(v), [](auto x) {
    cout << x << " ";
  });
  cout << endl;
}

void addEdge(const int &u, const int &v, const int &w, vector<pii> adj[])
{
  adj[u].pb({v, w});
  adj[v].pb({u, w});
}

vi dijkstra(int source, int V, const vector<pii> adj[])
{

  vi distance(V, INT_MAX);

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, source});
  distance[source] = 0;

  while (!pq.empty())
  {
    int u(pq.top().second);
    pq.pop();

    for (auto x : adj[u])
    {
      int v(x.first), d(x.second);
      if (distance[v] > distance[u] + d)
      {
        distance[v] = distance[u] + d;
        pq.push({distance[v], v});
      }
    }
  }

  return distance;
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<pii> adj[100];
  addEdge(0, 1, 4, adj);
  addEdge(0, 7, 8, adj);
  addEdge(1, 2, 8, adj);
  addEdge(1, 7, 11, adj);
  addEdge(2, 3, 7, adj);
  addEdge(2, 8, 2, adj);
  addEdge(2, 5, 4, adj);
  addEdge(3, 4, 9, adj);
  addEdge(3, 5, 14, adj);
  addEdge(4, 5, 10, adj);
  addEdge(5, 6, 2, adj);
  addEdge(6, 7, 1, adj);
  addEdge(6, 8, 6, adj);
  addEdge(7, 8, 7, adj);

  vi distance = dijkstra(0, 9, adj);

  for (int i = 0; i < 9; ++i)
  {
    cout << i << "\t" << distance[i] << endl;
  }

  return 0;
}
