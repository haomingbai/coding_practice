/**
 * @file l.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-09
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<char, int> mapping{{'O', 0}, {'B', 1}, {'A', 2}, {'F', 3},
                                      {'G', 4}, {'K', 5}, {'M', 6}};

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    using namespace std;
    string a, b;
    std::cin >> a >> b;
    char la = a[0], lb = b[0];
    if (mapping[la] < mapping[lb]) {
      cout << "hotter\n";
      continue;
    } else if (mapping[la] > mapping[lb]) {
      cout << "cooler\n";
    } else {
      if (a[1] == b[1]) {
        cout << "same\n";
      } else if (a[1] > b[1]) {
        cout << "cooler\n";
      } else {
        cout << "hotter\n";
      }
    }
  }
}
