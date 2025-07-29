/**
 * @file d.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-22
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
#include <string>

int main() {
  int T;
  std::cin >> T;

  while (T--) {
    int n, a;
    std::cin >> n >> a;
    std::string str;
    std::cin >> str;

    char curr = str[0];
    size_t cnt = 1;
    size_t max_one_blk_len = 0, max_zero_blk_len = 0;

    for (size_t i = 1; i < str.length(); i++) {
      char new_char = str[i];
      if (new_char == curr) {
        cnt++;
      } else {
        if (curr == '0') {
          max_zero_blk_len = std::max(max_zero_blk_len, cnt);
          curr = new_char;
          cnt = 1;
        } else {
          max_one_blk_len = std::max(max_one_blk_len, cnt);
          curr = new_char;
          cnt = 1;
        }
      }
    }

    if (curr == '0') {
      max_zero_blk_len = std::max(max_zero_blk_len, cnt);
    } else {
      max_one_blk_len = std::max(max_one_blk_len, cnt);
    }

    if (max_one_blk_len >= a || max_zero_blk_len >= a + 1) {
      std::cout << n << std::endl;
    } else {
      std::cout << std::count(str.begin(), str.end(), '1') << std::endl;
    }
  }
}
