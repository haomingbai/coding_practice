/**
 * @file k.cpp
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
#include <iostream>
#include <vector>

void solve();

int main() {
  int T;
  std::cin >> T;

  while (T--) {
    solve();
  }
}

void solve() {
  using namespace std;
  long n;
  cin >> n;

  vector<long> arr(n);
  for (auto &it : arr) {
    cin >> it;
  }
  vector<long> sorted(arr);
  sort(sorted.begin(), sorted.end());
}
