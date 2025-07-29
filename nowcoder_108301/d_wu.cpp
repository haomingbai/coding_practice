/**
 * @file d_wu.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-24
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 210;
int b[N][N];
void funct(int i, int x) {
  if (x == 0)
    cout << "0 0 0 ";
  else if (x == 1) {
    if (i % 3 == 0)
      cout << "1 0 0 ";
    else if (i % 3 == 1)
      cout << "0 1 0 ";
    else
      cout << "0 0 1 ";
  } else if (x == -1) {
    if (i % 3 == 0)
      cout << "0 1 0 ";
    else if (i % 3 == 1)
      cout << "1 0 0 ";
    else
      cout << "0 0 1 ";
  } else {
    if (i % 3 == 0)
      cout << "1 1 0 ";
    else if (i % 3 == 1)
      cout << "0 1 1 ";
    else
      cout << "1 0 1 ";
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> v;
  while (n) {
    int x = n & 1;
    v.push_back(x);
    n >>= 1;
  }
  vector<int> a;
  int sign = 1;
  for (int i = v.size() - 1; i >= 0; i--) {
    if (v[i] == 0)
      a.push_back(0);
    else {
      a.push_back(sign);
    }
    sign = -sign;
  }
  int l = v.size();
  cout << 3 * l << endl;
  for (int i = 0; i < 3; i++) {
    for (int j : a) funct(i, j);
    cout << endl;
  }
  for (int i = 0; i < l - 1; i++) {
    for (int k = 0; k < 3; k++) {
      for (int j = 0; j < l; j++) {
        if (j == i)
          funct(k, 1);
        else if (j == i + 1)
          funct(k, 2);
        else
          funct(k, 0);
      }
      cout << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
