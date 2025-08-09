/**
 * @file a.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-07
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <array>
#include <cstddef>
#include <iostream>
#include <vector>

void solve() {
  using namespace std;

  size_t n;
  cin >> n;
  vector<int> a(n);
  size_t minus_one_cnt(0);
  bool has_zero(false);
  int max_val = 0, min_val = 1e9;
  std::array<bool, 101> touched({false});
  for (auto &it : a) {
    cin >> it;
    if (it == -1) {
      minus_one_cnt++;
    } else {
      if (it > max_val) {
        max_val = it;
      }
      if (it < min_val) {
        min_val = it;
      }
      touched[it] = true;
    }
    if (it == 0) {
      has_zero = true;
    }
  }

  if (minus_one_cnt == n) {
    cout << "YES\n";
    return;
  }

  if (!has_zero && max_val != min_val) {
    cout << "NO\n";
    return;
  } else if (!has_zero) {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
  return;
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}
