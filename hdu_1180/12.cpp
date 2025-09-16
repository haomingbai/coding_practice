/**
 * @file 12.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-15
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#pragma GCC optimize(3)

#include <cassert>
#include <cstddef>
#include <cstdio>
#include <vector>

int Read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}

void Write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) Write(x / 10);
  putchar(x % 10 + '0');
  return;
}

int main() {
  // std::ios::sync_with_stdio(false);
  // std::cin.tie(nullptr);
  // std::cout.tie(nullptr);

  long T = Read();

  while (T--) {
    long n = Read(), m = Read();

    std::vector<long> in_contest;
    in_contest.reserve(n);
    std::vector<long> score_board(n + 1, 0);

    // I/O Process.
    for (size_t i = 0; i < m; i++) {
      long a = Read();
      if (score_board[a] == 0) {
        in_contest.emplace_back(a);
      }
      score_board[a]++;
    }

    for (size_t i = 1; i <= n; i++) {
      if (score_board[i] == 0) {
        in_contest.emplace_back(i);
      }
    }

    std::vector<std::vector<long>> bucket(m + 1);
    // for (auto &it : bucket) {
    //   it.reserve(100);
    // }

    for (long i = 1; i <= n; i++) {
      bucket[score_board[i]].emplace_back(i);
    }

    std::vector<long> completed;
    completed.reserve(n);

    for (auto i = m; i >= 0; i--) {
      for (auto &it : bucket[i]) {
        completed.emplace_back(it);
      }
    }

    long res = 0;
    for (size_t i = 0; i < n; i++) {
      if (in_contest[i] != completed[i]) {
        res++;
      }
    }

    Write(res);
    putchar('\n');
  }
}
