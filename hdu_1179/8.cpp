/**
 * @file 8.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-11
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>

int main() {
  int T;
  std::cin >> T;

  while (T--) {
    size_t n, m;
    std::cin >> n >> m;

    std::string s, t;
    s.reserve(n), t.reserve(m);
    std::cin >> s >> t;

    auto s_start = s.find('1'), t_start = t.find('1');
    if (t_start > s_start) {
      std::cout << "-1\n";
      continue;
    }
    s = s.substr(s_start), t = t.substr(t_start);

    if (s.size() == 0) {
      std::cout << "0\n";
      continue;
    }
    if (t.size() == 0) {
      std::cout << "-1\n";
      continue;
    }

    size_t ptr = 0;
    size_t cnt = 0;
    while (ptr <= (s.size() - t.size())) {
      for (size_t i = 0; i < t.size(); i++) {
        s[ptr + i] = (t[i] == s[ptr + i]) ? '0' : '1';
      }
      cnt++;
      ptr = s.find('1', ptr);
    }

    bool succ = true;
    for (const auto it : s) {
      if (it == '1') {
        succ = false;
        break;
      }
    }

    if (succ) {
      std::cout << cnt << '\n';
    } else {
      std::cout << "-1\n";
    }
  }
}
