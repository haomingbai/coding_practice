/**
 * @file g.cpp
 * @brief 
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-12
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

int main() {
  size_t len, qnum;

  std::cin >> len >> qnum;

  std::vector<size_t> v(len + 1, 1);

  for (size_t i = 0; i < qnum; i++) {
    int query_type;
    std::cin >> query_type;

    if (query_type == 1) {
      size_t left, right;
      std::cin >> left >> right;

      if (left == 1) {
        v[left] = 2;
      } else {
        v[left] = v[left - 1] + 1;
      }
    } else {
      size_t i;
      std::cin >> i;
      std::cout << v[i] << std::endl;
    }
  }
}
