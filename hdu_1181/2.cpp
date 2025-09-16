/**
 * @file 2.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-18
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <unordered_set>

struct NumberWithMultipleAndFactor {
  static long long n, m;
  using ll = long long;
  std::unordered_set<ll> multiple;  // 倍数
  std::unordered_set<ll> factor;    // 因数
  ll val;
};

int main() {
}
