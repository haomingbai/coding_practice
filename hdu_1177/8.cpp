/**
 * @file 8.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-04
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cstddef>
#include <iostream>
#include <vector>

int main() {
  int T;
  std::cin >> T;

  while (T--) {
    using ll = long long;
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<ll>> matrix(n, std::vector<ll>(m));
    for (auto &row : matrix) {
      for (auto &it : row) {
        std::cin >> it;
      }
    }

    std::vector<ll> max_row(m);
    std::vector<size_t> max_row_idx(m);

  }
}
