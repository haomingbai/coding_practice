/**
 * @file a.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-10
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cassert>
#include <cstddef>
#include <iostream>
#include <list>
#include <ostream>
#include <string>
#include <string_view>

using ll = long long;
using ull = unsigned long long;

struct CharBlock {
  char ch;
  size_t len;
};

std::list<CharBlock> getBlock(std::string_view str) {
  std::list<CharBlock> lst;

  while (!str.empty()) {
    auto ch = str.front();
    auto len = str.find_first_not_of(ch);

    if (len == std::string::npos) {
      CharBlock blk = {.ch = ch, .len = str.size()};
      lst.push_back(blk);
      break;
    }

    CharBlock blk = {.ch = ch, .len = len};
    lst.push_back(blk);
    str = str.substr(len);
  }

  return lst;
}

std::string solve(std::string_view s) {
  if (s.empty()) {
    return std::string(s);
  }

  if (s.front() != s.back()) {
    return std::string();
  }

  std::list<CharBlock> lst = getBlock(s);

  if (lst.front().ch == '0') {
    size_t max_size_of_1blk = 0;
    size_t min_size_of_0blk = 1 << 30;
    for (auto &it : lst) {
      if (it.ch == '1' && it.len > max_size_of_1blk) {
        max_size_of_1blk = it.len;
        if (max_size_of_1blk >= 2) {
          return std::string();
        }
      }
      if (it.ch == '0' && it.len < min_size_of_0blk) {
        min_size_of_0blk = it.len;
      }
    }
    return std::string(min_size_of_0blk, '0');
  } else {
    size_t max_size_of_0blk = 0;
    size_t min_size_of_1blk = 1 << 30;
    for (auto &it : lst) {
      if (it.ch == '0' && it.len > max_size_of_0blk) {
        max_size_of_0blk = it.len;
        if (max_size_of_0blk >= 2) {
          return std::string();
        }
      }
      if (it.ch == '1' && it.len < min_size_of_1blk) {
        min_size_of_1blk = it.len;
      }
    }
    return std::string(min_size_of_1blk, '1');
  }
  return std::string();
}

int main(void) {
  ull T;
  std::cin >> T;

  while (T--) {
    ull n;
    std::string s;
    std::cin >> n;
    s.reserve(n);
    std::cin >> s;

    auto res = solve(s);

    if (res.empty()) {
      std::cout << "empty" << std::endl;
    } else {
      std::cout << res << std::endl;
    }
  }
}
