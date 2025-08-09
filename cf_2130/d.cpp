/**
 * @file d.cpp
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
#include <iostream>
#include <ostream>
#include <vector>

size_t calcInversion(const std::vector<int> &v) {
  size_t count = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    for (size_t j = i + 1; j < v.size(); ++j) {
      if (v[i] > v[j]) {
        ++count;
      }
    }
  }
  return count;
}

void solve() {
  size_t n;
  std::cin >> n;
  std::vector<int> v(n);

  for (auto &it : v) {
    std::cin >> it;
  }

  // 找到v的第一个递减区间并且将这个区间翻转.
  size_t start = 0;
  while (start + 1 < n && v[start] <= v[start + 1]) {
    ++start;
  }
  if (start + 1 >= n) return;

  size_t end = start + 1;
  while (end + 1 < n && v[end] > v[end + 1]) {
    ++end;
  }

  for (size_t i = start; i <= end; ++i) {
    v[i] = static_cast<int>(2 * n) - v[i];
  }

  std::cout << calcInversion(v) << '\n';
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}
