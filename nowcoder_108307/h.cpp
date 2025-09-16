/**
 * @file h.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-14
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <ios>
#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    std::string s;
    std::cin >> s;
    if (s[0] == s[2]) {
      std::cout << "No\n";
      continue;
    } else if (s[1] == '-') {
      if (s[0] == '0') {
        std::cout << "Yes\n";
      } else {
        std::cout << "No\n";
      }
      continue;
    } else {
      std::cout << "Yes\n";
      continue;
    }
  }
}
