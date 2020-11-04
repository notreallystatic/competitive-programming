/*
Author : sk92907/notreallystatic
github:https://github.com/notreallystatic
linkedin : https://www.linkedin.com/in/notreallystatic/
*/

/*
Problem Statement:


Link:


Input:


Output:


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

void rotateMatrix(const int&n, vector<vector<int>>& matrix) {

  
}

void printMatrix(const int&n, const vector<vector<int>>& matrix) {
  for(auto row: matrix) {
    for(int x: row) {
      cout << x << " ";
    }
    cout << endl;
  }
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  
  for(auto &row: matrix) {
    for(int &x: row) {
      cin >>  x;
    }
  }

  rotateMatrix(n, matrix);
  printMatrix(n, matrix); 
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}