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
#define int long long

const int mod = 1e9 + 7;

int32_t main()
{
    int n, max3, result(0);
    cin >> n;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        mp[i] += mp[i - 1] + mp[i - 3];
        if (mp[i] > mod)
        {
            mp[i] -= mod;
        }
    }
    cout << mp[n] << endl;
    return 0;
}