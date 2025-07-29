/**
 * @file a.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-29
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cstdlib>
#include <iostream>
#include <ostream>

using ll = long long;

ll calc(ll n, ll k, ll s, ll t) {
  auto diff = std::abs(s - t);
  if (diff % k) {
    auto mod = diff % k;
    auto res = diff / k;
    if ((k - mod) % 2) {
      return -1;
    } else {
    }
  } else {
    return diff / k;
  }
}

int main() {
  ll T;
  std::cin >> T;

  while (T--) {
    ll n, k, s, t;
    std::cin >> n >> k >> s >> t;
    std::cout << calc(n, k, s, t) << std::endl;
  }
}
