/**
 * @file 9.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-11
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#pragma GCC optimize("Ofast")

#include <cstdint>
#include <ios>
#include <iostream>
#include <ostream>
#include <vector>

std::vector<char> st;
void print128(__int128 n) {
  st.clear();
  st.reserve(40);
  while (n) {
    int8_t c = n % 10;
    n /= 10;
    st.push_back(c + '0');
  }

  while (!st.empty()) {
    std::cout << st.back();
    st.pop_back();
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int T;
  std::cin >> T;

  while (T--) {
    using ll = __int128;
    long long n_, w_;
    std::cin >> n_ >> w_;
    ll n = n_, w = w_;

    ll sum = ((1 + n) * n) / 2;

    ll n_copy = n;
    while (n_copy >= w) {
      auto to_subtract = (n_copy / w);
    }

    print128(sum);
    std::cout << '\n';
  }
}
