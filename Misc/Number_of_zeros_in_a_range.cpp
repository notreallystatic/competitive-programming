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

void constructTree(int v, int l, int r, const vi &arr)
{
    if (l == r)
    {
        if (arr[l] == 0)
            tree[v] = 1;
        else
            tree[v] = 0;
        return;
    }
    int mid = (l + r) / 2;
    constructTree(v * 2 + 1, l, mid, arr);
    constructTree(v * 2 + 2, mid + 1, r, arr);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

int countZeros(int v, int l, int r, int ql, int qr)
{
    if (ql > qr)
        return 0;
    if (l == ql && r == qr)
        return tree[v];
    int mid = (l + r) / 2;
    return countZeros(v * 2 + 1, l, mid, ql, min(mid, qr)) + countZeros(v * 2 + 2, mid + 1, r, max(ql, mid + 1), qr);
}

void update(int v, int l, int r, int pos, int value)
{
    if (l == r)
    {
        if (value == 0)
        {
            tree[v] = 1;
        }
        else
        {
            tree[v] = 0;
        }
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
    {
        update(v * 2 + 1, l, mid, pos, value);
    }
    else
    {
        update(v * 2 + 2, mid + 1, r, pos, value);
    }
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    read(n);
    vi arr(n);
    for (auto &x : arr)
    {
        read(x);
    }

    // Construct tree
    tree.resize(4 * n);
    constructTree(0, 0, n - 1, arr);

    // Answer queries
    int queries, ql, qr;
    read(queries);
    while (queries--)
    {
        read(ql, qr);
        cout << countZeros(0, 0, n - 1, ql, qr) << endl;
    }

    // Update the array
    int pos, value;
    read(pos, value);
    update(0, 0, n - 1, pos, value);

    // Answer queries
    read(queries);
    while (queries--)
    {
        read(ql, qr);
        cout << countZeros(0, 0, n - 1, ql, qr) << endl;
    }

    return 0;
}
