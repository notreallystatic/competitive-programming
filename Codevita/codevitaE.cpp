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

#define  int					 int
#define  pb                     push_back
#define  all(v)                 v.begin(), v.end()
#define  deb(x)                 cout << #x << " " << x << endl;
#define  debxy(x, y)			 cout << #x << " " << x << "\t" << #y << " " << y << endl;
#define  forall(i,a,b)          for(int i=a;i<b;++i)
#define  forit(it, a)           for(decltype(a.begin()) it = a.begin(); it != a.end(); it++)
#define  endl                   "\n"

const int mod = 1000000007;

int32_t main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int costX, costY, costZ, areaX, areaY, areaZ, mx, nx, my, ny, mz, nz, totalArea;

  cin >> costX >> costY >> costZ;
  cin >> areaX >> areaY >> areaZ;
  cin >> mx >> nx;
  cin >> my >> ny;
  cin >> mz >> nz;
  cin >> totalArea;

  // Assign the minimum cost.
  int totalCost(0);
  totalCost += mx * nx * costX;
  totalCost += my * ny * costY;
  totalCost += mz * nz * costZ;

  // Leftout area after we gave the allocated the minimum space.
  totalArea -= (mx * nx);
  totalArea -= (my * ny);
  totalArea -= (mz * nz);

  // Area which we could still give to all the animals.
  areaX -= (mx * nx);
  areaY -= (my * ny);
  areaZ -= (mz * nz);

  vector<pair<int, int>> left = {{costX, areaX}, {costY, areaY}, {costZ, areaZ}};
  sort(all(left));

  int i(0);
  while(totalArea) {
    int minArea = min(left[i].second, totalArea);
    totalCost += minArea * left[i].first;
    totalArea -= minArea;
    ++i;
  }

  cout << totalCost;


  return 0;
}

