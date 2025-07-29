/**
 * @file d_ai.cpp
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

// 将 x (可以是负数也可以是正数) 转成“负二进制”表示，结果存在 b 中，
// 保证 x = sum_{i=0..b.size()-1} b[i]*(-1)^i，b[i]∈{0,1}。
// 负二进制除法同普通除法，但取余要确保余数非负。
vector<int> to_neg2(int x) {
  vector<int> b;
  while (x != 0) {
    int r = x % -2;
    x /= -2;
    if (r < 0) {
      r += 2;
      x += 1;
    }
    b.push_back(r);
  }
  if (b.empty()) b.push_back(0);
  return b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long N;
  cin >> N;

  // 我们对 N-1 做负二进制表示，使得 N-1 = sum b[i]*(-1)^i
  auto b = to_neg2((int)(N - 1));
  int L = b.size();
  int n = L + 2;
  vector<vector<int>> A(n, vector<int>(n, 0));

  // 第一行
  A[0][0] = 1;
  for (int i = 0; i < L; i++) {
    A[0][i + 1] = b[i];
  }
  // A[0][n-1] 已经是 0

  // 下标从 1..n-1：主对角和下对角都置 1
  for (int i = 1; i < n; i++) {
    A[i][i] = 1;
    A[i][i - 1] = 1;
  }

  // 输出
  cout << n << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << A[i][j] << (j + 1 == n ? '\n' : ' ');
    }
  }
  return 0;
}
