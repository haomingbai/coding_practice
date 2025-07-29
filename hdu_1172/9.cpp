/**
 * @file 9.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-18
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

int main(void) {
  size_t T;
  std::cin >> T;
  while (T--) {
    long n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (size_t i = 0; i < n; i++) {
      std::cin >> arr[i];
    }

    // 左侧和右侧有几个数比当前数字小
    std::vector<std::pair<long, size_t>> left_side_smaller_than;
    std::vector<std::pair<long, size_t>> right_side_smaller_than;

    long left_max = 0, right_max = 0;
    for (long i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
      if (arr[i] > left_max) {
        left_side_smaller_than.emplace_back(arr[i], i);
      }
      if (arr[j] > right_max) {
        right_side_smaller_than.emplace_back(arr[j], n - j - 1);
      }
    }

    for (auto &it_l : left_side_smaller_than) {
      for (auto &it_r : right_side_smaller_than) {
        
      }
    }
  }
}
