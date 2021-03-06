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

bool isPossible(const string &str, const int &n, int index, const int &target, int k)
{
    while (index < n)
    {
        if (index == target && str[target] == '0')
        {
            ++index;
            while (k && index < n)
            {
                if (str[index] == '1')
                    return 0;
                ++index;
                --k;
            }
            return 1;
        }
        if (str[index] == '1')
            return 0;
        ++index;
    }
    return 0;
}

bool isEmpty(const string &str)
{
    for (char ch : str)
        if (ch == '1')
            return 0;
    return 1;
}

void solve()
{
    int n, k;
    string str;
    read(n, k, str);

    int result(0);
    if (isEmpty(str))
    {
        str[0] = '1';
        result = 1;
    }
    int i = 0;
    while (i < n)
    {
        if (str[i] == '1')
        {

            if (isPossible(str, n, i + 1, i + k + 1, k))
            {
                // debxy(i, str[i]);
                str[i + k + 1] = '1';
                ++result;
                i += k;
            }
            else
            {
                ++i;
            }
        }
        else
        {
            ++i;
        }
    }
    // deb(str);
    reverse(all(str));
    // deb("reversed");
    i = 0;
    while (i < n)
    {
        if (str[i] == '1')
        {

            if (isPossible(str, n, i + 1, i + k + 1, k))
            {
                // debxy(i, str[i]);
                str[i + k + 1] = '1';
                ++result;
                i += k;
            }
            else
            {
                ++i;
            }
        }
        else
        {
            ++i;
        }
    }
    cout << result << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    read(t);
    while (t--)
    {
        solve();
    }

    return 0;
}
