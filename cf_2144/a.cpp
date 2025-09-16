/**
 * @file a.cpp
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
#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>

int main() {
  size_t t;
  std::cin >> t;

  while (t--) {
    using namespace std;
    size_t n;
    cin >> n;

    std::vector<long> a(n);
    for (auto &it : a) {
      cin >> it;
    }

    std::vector<long> prefix_sum(n);
    partial_sum(a.begin(), a.end(), prefix_sum.begin());

    bool flag = true;

    for (size_t l = 0; l < n - 1; l++) {
      if (flag == false) {
        break;
      }
      for (size_t r = l + 1; r < n - 1; r++) {
        if (flag == false) {
          break;
        }
        auto prefix_val = prefix_sum[l];
        auto mid_val = prefix_sum[r] - prefix_sum[l];
        auto suffix_val = prefix_sum[n - 1] - prefix_sum[r];

        prefix_val %= 3;
        mid_val %= 3;
        suffix_val %= 3;

        if (prefix_val == mid_val && mid_val == suffix_val) {
          auto result_l = l + 1;
          auto result_r = r + 1;
          cout << result_l << ' ' << result_r << endl;
          flag = false;
        } else if (prefix_val != mid_val && prefix_val != suffix_val &&
                   mid_val != suffix_val) {
          auto result_l = l + 1;
          auto result_r = r + 1;
          cout << result_l << ' ' << result_r << endl;
          flag = false;
        }
      }
    }

    if (flag) {
      cout << "0 0\n";
    }
  }
}
