/**
 * @file m.cpp
 * @brief 
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-12
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <iostream>

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    using ll = long long;
    ll n;
    std::cin >> n;
    if (n < 10) {
      std::cout << "1\n";
    } else {
      std::cout << "-1\n";
    }
  }
}
