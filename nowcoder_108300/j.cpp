/**
 * @file j.cpp
 * @brief 
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-22
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <iostream>
#include <numeric>
#include <ostream>

bool isTwoPower(long long x) {
  while (x > 1) {
    if (x % 2) {
      return false;
    }
    x >>= 1;
  }
  return true;
}

int getTwoPower(long long x) {
  int cnt = 0;
  while (x > 1) {
    cnt++;
    x >>= 1;
  }

  return cnt;
}

int main() {
  using ll = long long;
  ll T;
  std::cin >> T;

  while (T--) {
    ll a, b;
    std::cin >> a >> b;

    auto g = std::gcd(a, b);
    a /= g, b /= g;

    auto sum = a + b;

    if (isTwoPower(sum)) {
      std::cout << getTwoPower(sum) << std::endl;
    } else {
      std::cout << "-1" << std::endl;
    }
  }
}
