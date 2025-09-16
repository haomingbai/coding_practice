/**
 * @file 13.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-18
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <iostream>

int main() {
  int q;
  std::cin >> q;

  while (q--) {
    unsigned long long n, m;

    std::cin >> n >> m;

    auto res = n * m;
    std::cout << res << '\n';
  }
}
