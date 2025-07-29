/**
 * @file e.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-22
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <array>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>

constexpr std::size_t MAXN = 5e6;  // 修改为需要的最大范围

// constexpr 欧拉筛
constexpr auto generatePrimes() {
  std::array<bool, MAXN + 1> is_prime{};
  std::array<int, MAXN> primes({0});
  size_t cnt = 0;
  for (std::size_t i = 2; i <= MAXN; ++i) {
    if (!is_prime[i]) {
      primes[cnt] = i;
      cnt++;
    }
    for (size_t j = 0; j < cnt; j++) {
      const auto &p = primes[j];
      if (i * p > MAXN) break;
      is_prime[i * p] = true;
      if (i % p == 0) break;
    }
  }
  return std::pair<std::array<int, MAXN>, size_t>(primes, cnt);
}

// 在编译期生成素数表
auto [primes, size] = generatePrimes();

int main() {
  int T;
  std::cin >> T;

  while (T--) {
    size_t n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (auto &it : arr) {
      std::cin >> it;
    }
  }
}
