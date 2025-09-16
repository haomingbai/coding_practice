/**
 * @file j.cpp
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
#include <string>

int main() {
  int n;
  std::cin >> n;
  std::cout << n << " nya\n";
  std::string line;
  std::getline(std::cin, line);
  while (n--) {
    std::string line;
    std::getline(std::cin, line);
    std::cout << line << " nya\n";
  }
}
