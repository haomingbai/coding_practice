/**
 * @file 7.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-25
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cstddef>
#include <iostream>
#include <vector>

struct Interval {
  long l, r;
  Interval(const Interval &) = default;
  Interval(Interval &&) = default;
  Interval(long l, long r) : l(l), r(r) {}
  bool operator<(const Interval &i) const { return l < i.l; }
};

int main() {
  long t;
  std::cin >> t;

  while (t--) {
    size_t n;
    std::cin >> n;
    std::vector<Interval> arr(n);

    for (auto &it : arr) {
      std::cin >> it.l >> it.r;
    }
  }
}
