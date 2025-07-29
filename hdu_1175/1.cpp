/**
 * @file 1.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-28
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <numeric>
#include <vector>

constexpr long long MOD = 998244353;

long long calc(std::vector<long long> &arr) {
  auto n = arr.size();
  long long cnt_front_0;
  for (cnt_front_0 = 0; cnt_front_0 < arr.size() && arr[cnt_front_0] == 0;
       cnt_front_0++);
  long long cnt_back_0;
  for (cnt_back_0 = 0;
       cnt_back_0 < arr.size() && arr[arr.size() - cnt_back_0 - 1] == 0;
       cnt_back_0++);

  long long res = 1;
  if (cnt_front_0 == arr.size()) {
    const long long inv2 = (MOD + 1) / 2;
    res = res * (((n % MOD) * ((n + 1) % MOD)) % MOD) % MOD * inv2 % MOD;
  } else {
    res *= (cnt_front_0 + 1) * (cnt_back_0 + 1);
  }

  res %= MOD;

  arr.erase(std::remove(arr.begin(), arr.end(), 0), arr.end());

  if (arr.empty()) {
    res *= ((n + 1) * (n + 1)) % MOD;
  } else {
    long long max = 0, min = n + 1;
    for (size_t i = 0; i < arr.size(); i++) {
      if (arr[i] > max) {
        max = arr[i];
      }
      if (arr[i] < min) {
        min = arr[i];
      }
    }

    res *= ((n - max + 1) * (min + n + 1)) % MOD;
  }

  res %= MOD;

  return res;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);

  size_t T;
  std::cin >> T;

  while (T--) {
    long long n;
    std::cin >> n;
    std::vector<long long> arr(n);
    for (auto &it : arr) {
      std::cin >> it;
    }
    auto res = calc(arr);
    std::cout << std::accumulate(arr.begin(), arr.end(), 0) << ' ' << res
              << '\n';
  }
}
