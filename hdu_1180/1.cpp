/**
 * @file 1.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-15
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <ios>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    using namespace std;
    using ll = long long;

    ll num_4{0}, num_2{0}, num_69{0}, num_odd{0};
    for (ll i = 0; i <= 9; i++) {
      ll a;
      cin >> a;
      if (i % 4 == 0) {
        num_4 += a;
      } else if (i == 6 || i == 9) {
        num_69 += a;
      } else if (i % 2 == 0) {
        num_2 += a;
      } else {
        num_odd += a;
      }
    }

    ll res{0};
    res += num_4;
    // num4 = 0

    if (num_odd > num_2) {
      res += num_2;
      num_odd -= num_2;
      num_2 = 0;
    } else {
      res += num_odd;
      num_2 -= num_odd;
      num_odd = 0;
    }

    if (num_2) {
      if (num_2 > num_69) {
        res += num_69;
        num_2 -= num_69;
        num_69 = 0;
      } else {
        res += num_2;
        num_69 -= num_2;
        num_2 = 0;
      }
    } else if (num_odd) {
      if (num_odd > num_69) {
        res += num_69;
        num_odd -= num_69;
        num_69 = 0;
      } else {
        res += num_odd;
        num_69 -= num_odd;
        num_odd = 0;
      }
    }

    if (num_69) {
      res += num_69 / 2;
    }

    cout << res << '\n';
  }
}
