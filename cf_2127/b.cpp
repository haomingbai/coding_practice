/**
 * @file b.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-07
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    using namespace std;

    size_t n, x;
    cin >> n >> x;
    x--;
    std::string str;
    cin >> str;

    vector<unsigned char> has_wall(n, false);
    for (size_t i = 0; i < n; i++) {
      if (str[i] == '#') {
        has_wall[i] = true;
      }
    }

    long left_wall = x, right_wall = x;
    while (left_wall >= 0) {
      if (has_wall[left_wall]) {
        break;
      }
      left_wall--;
    }
    while (right_wall < n) {
      if (has_wall[right_wall]) {
        break;
      }
      right_wall++;
    }

    if (left_wall < 0 && right_wall >= n) {
      cout << "1\n";
      continue;
    }

    if (x == 0 || x == n - 1) {
      cout << "1\n";
      continue;
    }

    long left_put = x - 1, right_put = x + 1;
    auto res_right = min<long>(left_wall + 2, n - right_put + 1);
    auto res_left = min<long>(left_put + 2, n - right_wall + 1);
    auto res = max(res_left, res_right);
    cout << res << '\n';
  }
}
