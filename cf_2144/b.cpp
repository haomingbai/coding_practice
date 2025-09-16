/**
 * @file b.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-09-15
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    using namespace std;

    size_t n;
    cin >> n;
    std::vector<long> a(n);
    size_t cnt_zero = 0;

    // IO
    for (auto &it : a) {
      cin >> it;
      if (it == 0) {
        cnt_zero++;
      }
    }

    if (cnt_zero == 0 || cnt_zero == 1) {
      long left_mixed = n;
      long right_mixed = -1;

      // Fill the zero.
      if (cnt_zero) {
        long miss = 0;
        size_t pos = SIZE_MAX;
        std::vector<uint8_t> bucket(n + 1, false);
        for (size_t i = 0; i < n; i++) {
          if (a[i] != 0) {
            bucket[a[i]] = true;
          } else {
            pos = i;
          }
        }
        for (long i = 1; i <= n; i++) {
          if (!bucket[i]) {
            miss = i;
            a[pos] = miss;
          }
        }
      }

      // Get the left pos.
      for (size_t i = 0; i < n; i++) {
        if (a[i] != i + 1) {
          left_mixed = i;
          break;
        }
      }

      for (long i = n - 1; i >= 0; i--) {
        if (a[i] != i + 1) {
          right_mixed = i;
          break;
        }
      }

      if (left_mixed == n) {
        cout << "0\n";
      } else {
        cout << (right_mixed - left_mixed + 1) << '\n';
      }
    } else {
      long left_mixed = n;
      long right_mixed = -1;

      for (size_t i = 0; i < n; i++) {
        if (a[i] != i + 1 || a[i] == 0) {
          left_mixed = i;
          break;
        }
      }

      for (long i = n - 1; i >= 0; i--) {
        if (a[i] != i + 1 || a[i] == 0) {
          right_mixed = i;
          break;
        }
      }

      cout << (right_mixed - left_mixed + 1) << '\n';
    }
  }
}
