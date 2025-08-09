/**
 * @file b.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-31
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
#include <ostream>
#include <vector>

void solve() {
  using l = long;
  using namespace std;

  l n, s;
  std::cin >> n >> s;
  vector<l> a(n);
  for (auto &it : a) {
    cin >> it;
  }

  auto sum = std::accumulate(a.begin(), a.end(), 0);
  auto cnt_0 = std::count(a.begin(), a.end(), 0);
  auto cnt_1 = std::count(a.begin(), a.end(), 1);
  auto cnt_2 = std::count(a.begin(), a.end(), 2);

  if (sum > s) {
    for (const auto &it : a) {
      cout << it << ' ';
    }
    cout << '\n';
    return;
  } else if (sum == s) {
    cout << "-1\n";
    return;
  } else {
    switch (s - sum) {
      case 1: {
        for (size_t i = 0; i < cnt_0; i++) {
          cout << "0 ";
        }
        cout << "2 ";
        for (size_t i = 0; i < cnt_1; i++) {
          cout << "1 ";
        }
        for (size_t i = 0; i < cnt_2 - 1; i++) {
          cout << "2 ";
        }
        cout << '\n';
        return;
      }
      default:
        cout << "-1\n";
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}
