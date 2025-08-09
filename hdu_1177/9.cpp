/**
 * @file 9.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-04
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <ios>
#include <iostream>
#include <ostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--) {
    size_t n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (auto &it : arr) {
      std::cin >> it;
    }

    if (n <= 2) {
      std::cout << "0\n";
      continue;
    }

    size_t pivot = SIZE_MAX;
    int max_val = -1;

    for (size_t i = 0; i < n; i++) {
      if (arr[i] > max_val) {
        pivot = i;
        max_val = arr[i];
      }
    }

    if (pivot == 0 || pivot == n - 1) {
      std::cout << max_val * (n - 2) << '\n';
    } else {
      std::cout << max_val * (n - 3) + std::max(arr.front(), arr.back())
                << '\n';
    }
  }
}
