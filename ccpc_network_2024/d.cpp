/**
 * @file d.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-09-05
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <array>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <string_view>
#include <unordered_map>

constexpr long long MOD = 998244353;

std::string S, T;

long long Solve(int t, std::string_view sub) {
  static std::unordered_map<std::string_view, std::array<long long, 101>>
      result_map;

  if (!result_map.count(sub)) {
    result_map[sub] = {0};
  }

  if (result_map[sub][t]) {
    return result_map[sub][t];
  }

  if (sub.size() == 0) {
    return 1;
  } else if (t == 0) {
    result_map[sub][t] = 0;
    return 0;
  } else if (t == 1) {
    result_map[sub][t] = (sub.size() == 1 && S[t - 1] == sub.front());
    return result_map[sub][t];
  } else {
    long long result = 0;

    // Front-back mode.
    {
      for (size_t i = 0; i < sub.size(); i++) {
        long long tmp = 1;

        tmp *= Solve(t - 1, sub.substr(0, i));
        tmp %= MOD;
        tmp *= Solve(t - 1, sub.substr(i));
        tmp %= MOD;

        result += tmp;
        result %= MOD;
      }
      result += Solve(t - 1, sub) % MOD;
      result %= MOD;
    }

    // Front-mid-back mode.
    {
      if (sub[0] == S[t - 1]) {
        result += (Solve(t - 1, sub.substr(1)) % MOD);
        result %= MOD;
      }
      for (size_t i = 1; i < sub.size() - 1; i++) {
        if (sub[i] == S[t - 1]) {
          long long tmp = 1;

          tmp *= Solve(t - 1, sub.substr(0, i));
          tmp %= MOD;
          tmp *= Solve(t - 1, sub.substr(i + 1));
          tmp %= MOD;

          result += tmp;
          result %= MOD;
        }
      }
      {
        auto i = sub.size() - 1;

        if (sub[i] == S[t - 1]) {
          long long tmp = 1;

          tmp *= Solve(t - 1, sub.substr(0, i - 1));
          tmp %= MOD;

          result += tmp;
          result %= MOD;
        }
      }
    }

    result_map[sub][t] = result;
    return result;
  }
}

int main() {
  std::cin >> S >> T;
  auto result = Solve(S.size(), T);

  std::cout << result << std::endl;
}
