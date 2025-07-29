/**
 * @file j_helper.cpp
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
#include <ostream>

int main() {
  int n, m, cnt = 0;

  std::cin >> n >> m;

  auto mx = (n + m) * (n + m);

  while (n && m) {
    if (n <= m) {
      m -= n;
      n *= 2;
    } else {
      n -= m;
      m *= 2;
    }
    std::cout << n << ' ' << m << std::endl;
    cnt++;
    if (cnt > mx + 1) {
      break;
    }
  }

  if (cnt > mx + 1) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << cnt << std::endl;
  }
}
