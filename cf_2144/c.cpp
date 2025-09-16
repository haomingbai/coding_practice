/**
 * @file c.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-09-15
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <array>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

constexpr unsigned long long MOD = 998244353;

long long CheckSwitchibility(std::vector<int> &a, std::vector<int> &b,
                             size_t i) {
  auto should_switch = false;
  auto can_switch = true;

  unsigned long long result = 0;

  if (i) {
    // Check the left side.
    if (a[i - 1] > a[i] || b[i - 1] > b[i]) {
      should_switch = true;
    }

    if (b[i - 1] > a[i] || a[i - 1] > b[i]) {
      can_switch = false;
    }
  }

  if (i + 1 < a.size()) {
    // Check the right side.
    if (a[i + 1] < a[i] || b[i + 1] < b[i]) {
      should_switch = true;
    }

    if (b[i + 1] < a[i] || a[i + 1] < b[i]) {
      can_switch = false;
    }
  }

  if (should_switch) {
    result = 1;
  } else if (can_switch) {
    result = 2;
  } else {
    result = -1;
  }

  return result;
}

int main() {
  size_t t;
  std::cin >> t;

  while (t--) {
    using ull = unsigned long long;
    using ll = long long;

    size_t n;
    std::cin >> n;
    std::vector<int> a(n), b(n);

    // I/O
    {
      for (auto &elem : a) {
        std::cin >> elem;
      }
      for (auto &elem : b) {
        std::cin >> elem;
      }
    }

    std::vector<std::array<ull, 2>> dp(n, std::array<ull, 2>{0, 0});

    // Defering the first elem.
    switch (CheckSwitchibility(a, b, 0)) {
      case 2: {
        dp[0][0] = 1;
        dp[0][1] = 1;
        break;
      }

      case 1: {
        dp[0][1] = 1;
        dp[0][0] = 0;
        break;
      }

      case -1: {
        dp[0][1] = 0;
        dp[0][0] = 1;
        break;
      }

      default: {
        assert(0);
        break;
      }
    }

    for (size_t i = 1; i < n; i++) {
      if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) {
        dp[i][1] += dp[i - 1][1];
        dp[i][0] += dp[i - 1][0];
      }
      if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) {
        dp[i][1] += dp[i - 1][0];
        dp[i][0] += dp[i - 1][1];
      }
    }

    auto res = (dp.back()[0] + dp.back()[1]) % MOD;

    if (CheckSwitchibility(a, b, n - 1) == 1 ||
        CheckSwitchibility(a, b, n - 1) == -1) {
      res *= 2;
      res %= MOD;
    }

    std::cout << res << '\n';
  }
}
