/**
 * @file 2.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-21
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cstddef>
#include <iostream>
#include <ostream>

using ll = long long;

std::size_t count(ll x) {
  size_t res = 0;

  while (x) {
    if (x % 2) {
      res++;
    }
    x /= 2;
  }

  return res;
}

ll lowbit(ll x) { return -x & x; }

int main(void) {
  size_t T;
  std::cin >> T;

  while (T--) {
    ll n, x, y;
    std::cin >> n >> x >> y;

    auto cnt_x = count(x), cnt_y = count(y);
    auto low_x = lowbit(x), low_y = lowbit(y);

    if (x == y) {
      std::cout << 0 << std::endl;
    } else if (cnt_x == cnt_y) {
    }
  }
}
