/**
 * @file j.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-07
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <string_view>
#include <vector>

void solve();

static std::vector<long long> minus2Pow;

void initPow() {
  minus2Pow.push_back(1);
  while (minus2Pow.back() <= 1e11) {
    minus2Pow.push_back(minus2Pow.back() * -2ull);
  }
}

int main() {
  initPow();
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}

std::string getString(long long n) {
  auto a = std::abs(n);
  if (n > 0) {
  }
}

struct Digit {
  long long re, im;
};

Digit getDigit(std::string_view str) {
  std::string reStr, imStr;
  bool flag = 0;
  for (auto it = str.rbegin(); it != str.rend(); it++) {
    if (flag) {
      imStr.push_back(*it);
    } else {
      reStr.push_back(*it);
    }
    flag = !flag;
  }

  Digit res = {0, 0};
  for (long long i = 0, curr = 1; i < reStr.size(); i++) {
    res.re += curr * (reStr[i] - '0');
    curr *= -2;
  }
  for (long long i = 0, curr = 1; i < imStr.size(); i++) {
    res.im += curr * (imStr[i] - '0');
    curr *= -2;
  }

  return res;
}

void solve() {
  using ll = long long;
  using namespace std;
  string sA, sB;
  cin >> sA >> sB;
  Digit A = getDigit(sA), B = getDigit(sB);
}
