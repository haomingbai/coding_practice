/**
 * @file k.cpp
 * @brief 
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-12
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <iostream>
#include <ostream>

int main(void) {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << 0 << std::endl  << 1 << std::endl;
    return 0;
  }

  std::cout << n << std::endl;

  for (int i = 2; i <= n; i++) {
    std::cout << i << ' ';
  }

  std::cout << 1 << std::endl;
}
