/**
 * @file 9.cpp
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
#include <iostream>
#include <vector>

bool judge(std::vector<long> &vec) {
  std::sort(vec.begin(), vec.end());

  if (vec.front() == 0) {
    return false;
  }

  using namespace std;
  auto count_one = [](const vector<long> &v) {
    size_t cnt;
    for (cnt = 0; cnt < v.size() && v[cnt] == 1; cnt++);
    return cnt;
  };

  auto one_num = count_one(vec);
  auto back = vec.back();
  if (back >= one_num) {
    return true;
  } else {
    return false;
  }
}

int main(void) {
  size_t T;
  std::cin >> T;

  while (T--) {
    using namespace std;
    size_t n;
    cin >> n;
    vector<long> vec(n);
    for (auto &it : vec) {
      cin >> it;
    }
    auto res = judge(vec);

    if (res) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
