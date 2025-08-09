/**
 * @file 4.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-04
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

int main() {
  int T;
  std::cin >> T;

  while (T--) {
    using namespace std;
    long n;
    cin >> n;
    vector<long> arr(n);
    for (auto &it : arr) {
      cin >> it;
    }
    if (n == 1) {
      cout << "0\n";
      continue;
    }
    vector<long> pos(n + 1);
    for (long i = 0; i < n; i++) {
      pos[arr[i]] = i;
    }

    vector<long> seg_len;
    seg_len.reserve(n);
    long len = 1;
    for (long i = 2; i <= n; i++) {
      if (pos[i] > pos[i - 1]) {
        len++;
      } else {
        seg_len.push_back(len);
        len = 1;
      }
    }
    seg_len.push_back(len - 1);
    long d = max(seg_len.front(), seg_len.back());
    for (long i = 1; i < seg_len.size() - 1; i++) {
      d = max(d, seg_len[i] - 1);
    }
    cout << n - d << '\n';
  }
}
