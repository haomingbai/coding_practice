/**
 * @file 12.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-01
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <vector>

void solve();

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}

template <typename P>
long long calc(const P &p1, const P &p2) {
  return std::abs(std::abs(p1.a - p2.a) - std::abs(p1.b - p2.b));
}

void solve() {
  using namespace std;

  struct Point {
    long long a, b;
  };

  size_t n;
  cin >> n;
  vector<Point> arr(n);
  for (size_t i = 0; i < n; i++) {
    cin >> arr[i].a;
  }
  for (size_t i = 0; i < n; i++) {
    cin >> arr[i].b;
  }

  std::vector<Point> seq_a(arr), seq_b(arr), seq_pos(arr), seq_neg(arr);
  std::sort(seq_a.begin(), seq_a.end(),
            [](const auto &p1, const auto &p2) { return p1.a < p2.a; });
  std::sort(seq_b.begin(), seq_b.end(),
            [](const auto &p1, const auto &p2) { return p1.b < p2.b; });
  std::sort(seq_pos.begin(), seq_pos.end(), [](const auto &p1, const auto &p2) {
    return p1.a - p1.b < p2.a - p2.b;
  });
  std::sort(seq_neg.begin(), seq_neg.end(), [](const auto &p1, const auto &p2) {
    return p1.a + p1.b < p2.a + p2.b;
  });

  std::vector<pair<size_t, size_t>> ps;
  for (long i = 0; i < n; i++) {
    auto k = min<long>(10l, n - i - 1);
    for (long j = 1; j <= k; j++) {
      ps.emplace_back(i, i + j);
    }
  }

  long long min_res = 1e15;
  for (auto &it : ps) {
    min_res = min({min_res, calc(seq_a[it.first], seq_a[it.second]),
                   calc(seq_b[it.first], seq_b[it.second]),
                   calc(seq_pos[it.first], seq_pos[it.second]),
                   calc(seq_neg[it.first], seq_neg[it.second])});
  }

  cout << min_res << '\n';
}
