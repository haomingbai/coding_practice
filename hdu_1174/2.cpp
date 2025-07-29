/**
 * @file 2.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-25
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <numeric>
#include <vector>

bool judge(long long M, const std::vector<long long> &b, const std::vector<long long> &c) {
  auto N = c.size();
  std::vector<long long> a_min(N), a_max(N);

  a_min[0] = b[0];
  for (size_t i = 1; i < N; i++) {
    a_min[i] = std::max(a_min[i - 1], b[i]);
  }

  a_max[N - 1] = c[N - 1];
  for (long long i = N - 2; i >= 0; i--) {
    a_max[i] = std::min(a_max[i + 1], c[i]);
  }

  for (size_t i = 0; i < N; i++) {
    if (a_min[i] > a_max[i]) {
      return false;
    }
  }

  long long total_min = std::accumulate(a_min.begin(), a_min.end(), 0);
  long long total_max = std::accumulate(a_max.begin(), a_max.end(), 0);

  if (total_min <= M && total_max >= M) {
    return true;
  } else {
    return false;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int T;
  std::cin >> T;

  while (T--) {
    long long N, M;
    std::cin >> N >> M;
    std::vector<long long> b(N), c(N);
    for (auto &it : b) {
      std::cin >> it;
    }
    for (auto &it : c) {
      std::cin >> it;
    }

    auto res = judge(M, b, c);
    if (res) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}
