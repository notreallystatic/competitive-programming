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

vi tree;

void constructTree(const vi &arr, int v, int l, int r)
{
    if (l == r)
    {
        tree[v] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    constructTree(arr, v * 2 + 1, l, mid);
    constructTree(arr, v * 2 + 2, mid + 1, r);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

int sum(int v, int l, int r, int ql, int qr)
{
    if (ql > qr)
    {
        return 0;
    }
    if (l == ql && r == qr)
    {
        return tree[v];
    }
    int mid = (l + r) / 2;
    return sum(v * 2 + 1, l, mid, ql, min(mid, qr)) + sum(v * 2 + 2, mid + 1, r, max(ql, mid + 1), qr);
}

void update(const vi &arr, int v, int l, int r, const int &pos, const int &val)
{
    if (l == r)
    {
        tree[v] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(arr, v * 2 + 1, l, mid, pos, val);
    else
        update(arr, v * 2 + 2, mid + 1, r, pos, val);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deb("here");
    int n, queries, l, r;
    read(n);
    vi arr(n);

    // 5
    // 1 2 3 4 5
    for (auto &x : arr)
        read(x);

    // Construct tree
    tree.resize(4 * n);
    constructTree(arr, 0, 0, n - 1);
    // Check queries
    /* 
        Input:  4
                0 4 => 15
                2 4 => 12
                1 3 => 9
                2 2 => 3
    */
    read(queries);
    while (queries--)
    {

        read(l, r);
        cout << sum(0, 0, n - 1, l, r) << endl;
    }
    // update
    int pos, value;
    // 2 6
    read(pos, value);
    update(arr, 0, 0, n - 1, pos, value);

    display(tree);
    // 18 9 9 3 6 4 5 1 2 0 0 0 0 0 0 0 0 0 0 0

    return 0;
}
