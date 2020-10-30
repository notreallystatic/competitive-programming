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

#define mod 1000000007

vector<int> f[1000001];
long long mp[1000001];

int main()
{
    // Fill up the factors
    long long result(0);
    for (int i = 2; i <= 1e6; ++i)
    {
        for (int j = i + i; j <= 1e6; j += i)
        {
            f[j].push_back(i);
        }
    }
    // Input
    int n, ai;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &ai);
        mp[ai] = 1;
    }
    // Process
    for (int x = 2; x <= 1000000; ++x)
    {
        if (mp[x])
        {
            for (auto i : f[x])
            {
                if (mp[i] && mp[x / i])
                {
                    mp[x] += mp[i] * mp[x / i];
                    if (mp[x] >= mod)
                    {
                        mp[x] %= mod;
                    }
                }
            }
            result += mp[x];
            if (result >= mod)
            {
                result %= mod;
            }
        }
    }
    cout << result << endl;
    return 0;
}