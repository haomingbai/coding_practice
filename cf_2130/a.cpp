/**
 * @file a.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-31
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>

using ll = long long;

void solve() {
  size_t n;
  std::cin >> n;
  std::vector<ll> a(n);
  size_t cnt_0 = 0;
  for (auto &it : a) {
    std::cin >> it;
    if (it == 0) {
      cnt_0++;
    }
  }

  std::sort(a.begin(), a.end());
  a.erase(std::remove(a.begin(), a.end(), 0), a.end());
  ll res = std::accumulate(a.begin(), a.end(), cnt_0);

  std::cout << res << std::endl;
}

int main() {
  int T;
  std::cin >> T;

  while (T--) {
    solve();
  }
}
