/*
Author : notreallystatic
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

class Node
{
public:
  char ch;
  bool ends;
  int nodes;
  vector<Node *> children;

  Node()
  {
    ends = false;
    nodes = 0;
    children = vector<Node *>(26, nullptr);
  }

  Node(const char &ch)
  {
    this->ch = ch;
    ends = false;
    nodes = 0;
    children = vector<Node *>(26, nullptr);
  }
};

void fillString(Node *root, string str)
{
  for (auto ch : str)
  {
    if (root->children[ch - 'a'] == nullptr)
    {
      root->children[ch - 'a'] = new Node(ch);
      root->nodes += 1;
    }
    root = root->children[ch - 'a'];
  }
  root->ends = true;
}

void dfs(Node *root, string current = "")
{
  if (root->ends)
    cout << current + root->ch << endl;
  if (root->nodes != 1)
  {
    cout << current + root->ch;
    return;
  }
  for (auto node : root->children)
    if (node != nullptr)
      dfs(node, current + root->ch);
}

void solve()
{
  int n;
  cin >> n;
  vector<string> strs(n);
  for (auto &str : strs)
    cin >> str;

  Node *root = new Node('_');

  for (auto str : strs)
    fillString(root, str);

  cout << root->nodes << endl;
  dfs(root);
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();

  return 0;
}
