/**
 * @file d.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-24
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

using ll = long long;

void printMat(const std::vector<ll> &arr) {
  {
    for (const auto &it : arr) {
      switch (it) {
        case 0:
          std::cout << "0 0 0 ";
          break;
        case 1:
          std::cout << "1 0 0 ";
          break;
        case 2:
          std::cout << "1 1 0 ";
          break;
        case -1:
          std::cout << "0 0 1 ";
          break;
      }
    }
  }

  std::cout << '\n';

  {
    for (const auto &it : arr) {
      switch (it) {
        case 0:
          std::cout << "0 0 0 ";
          break;
        case 1:
          std::cout << "0 1 0 ";
          break;
        case 2:
          std::cout << "0 1 1 ";
          break;
        case -1:
          std::cout << "0 1 0 ";
          break;
      }
    }
  }

  std::cout << '\n';

  {
    for (const auto &it : arr) {
      switch (it) {
        case 0:
          std::cout << "0 0 0 ";
          break;
        case 1:
          std::cout << "0 0 1 ";
          break;
        case 2:
          std::cout << "1 0 1 ";
          break;
        case -1:
          std::cout << "1 0 0 ";
          break;
      }
    }
  }

  std::cout << '\n';
}

std::vector<ll> getControlSequence(size_t N) {
  std::vector<ll> res;
  res.reserve(90);
  while (N) {
    if (N % 2) {
      if (res.size() % 2) {
        res.push_back(-1);
      } else {
        res.push_back(1);
      }
    } else {
      res.push_back(0);
    }
    N /= 2;
  }

  return res;
}

int main() {
  size_t N;
  std::cin >> N;

  auto control = getControlSequence(N);
  std::cout << control.size() * 3 << std::endl;
  printMat(control);

  for (size_t i = 1; i < control.size(); i++) {
    std::vector<ll> curr(control.size());
    for (size_t j = 0; j < control.size(); j++) {
      if (j == i) {
        curr[j] = 1;
      } else if (j == i - 1) {
        curr[j] = 2;
      } else {
        curr[j] = 0;
      }
    }
    printMat(curr);
  }
}
