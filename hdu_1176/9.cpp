/**
 * @file 9.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-01
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cassert>
#include <cstddef>
#include <ios>
#include <iostream>
#include <map>
#include <vector>

void solve();

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

void solve() {
  using namespace std;

  size_t n;
  cin >> n;
  vector<int> A(n), B(n);
  for (auto &it : A) {
    cin >> it;
  }
  for (auto &it : B) {
    cin >> it;
  }

  map<int, size_t> mpA, mpB;
  for (size_t i = 0; i < n; i++) {
    mpA[A[i]] = i, mpB[B[i]] = i;
  }

  long max_idx = n - 1;
  long cnt = 0;
  while (max_idx >= 0) {
    cnt++;
    auto i_b = max_idx;
    long i_a = mpA[B[i_b]];
    // println(cout, "i_a = {}, A[i_a] = {}, i_b = {}, B[i_b] = {}", i_a, A[i_a], i_b, B[i_b]);

    while (i_b >= 0 && i_a >= 0) {
      if (A[i_a] == B[i_b]) {
        i_b--, i_a--;
      } else {
        break;
      }
    }

    max_idx = i_b;
  }

  cout << cnt << '\n';
}
