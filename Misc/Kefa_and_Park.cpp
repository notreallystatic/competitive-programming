/*
Author : sk92907
github:https://github.com/sk92907
linkedin : https://www.linkedin.com/in/sk92907/
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

const int maxN = 1e5 + 1;
vi adl[maxN];
unordered_map<int, int> catHere;
unordered_map<int, int> visited;

bool isLeaf(const int &vertex)
{
    for (auto x : adl[vertex])
        if (!visited[x])
            return 0;
    return 1;
}

void addEdge(const int &a, const int &b)
{
    adl[a].pb(b);
    adl[b].pb(a);
}

int result(0);

void dfs(const int &vertex, int cats, const int &maxCats)
{
    if (cats > maxCats)
        return;
    if (isLeaf(vertex) && vertex != 1)
        ++result;
    for (auto x : adl[vertex])
    {
        if (!visited[x])
        {
            visited[x] = 1;
            dfs(x, catHere[x] ? cats + 1 : 0, maxCats);
        }
    }
}

void solve()
{
    int n, m, par, child;
    read(n, m);
    vi a(n);
    for (auto &x : a)
        read(x);
    forall(i, 0, n)
    {
        if (a[i])
        {
            ++catHere[i + 1];
        }
    }
    forall(i, 0, n - 1)
    {
        read(par, child);
        addEdge(par, child);
    }
    visited[1] = 1;
    dfs(1, catHere[1], m);
    cout << result << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
