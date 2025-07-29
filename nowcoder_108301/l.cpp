/**
 * @file l.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-24
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

using ll = long long;

int main() {
  size_t n, q;
  std::cin >> n >> q;

  std::vector<ll> a(n);

  for (auto &it : a) {
    std::cin >> it;
  }

  while (q--) {
    ll x, y;
    std::cin >> x >> y;
    auto ub = std::upper_bound(a.begin(), a.end(), x);
    auto curr = a.end() - ub;
    std::cout << curr << std::endl;
  }
}
