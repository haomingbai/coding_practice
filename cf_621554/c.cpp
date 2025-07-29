/**
 * @file c.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-10
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cstddef>
#include <iostream>
#include <ostream>

typedef unsigned long long ull;
typedef long long ll;

ll solve(size_t n, size_t m) {
  auto max_weight = [](ull m, ull j) { return (m - j + 1) * (1ull << j) - 1; };
  auto up_div = [](ll a, ll b) {
    if (a % b) {
      return a / b + 1;
    } else {
      return a / b;
    }
  };

  for (auto j = 0; j < m; j++) {
    if (max_weight(m, j) >= n) {
      return up_div((n - (1 << j) + 1), (m - j));
    }
  }

  return -1;
}

int main() {
  using namespace std;

  size_t T;
  cin >> T;

  while (T--) {
    size_t n, m;
    cin >> n >> m;

    cout << solve(n, m) << endl;
  }
}
