/**
 * @file 6.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-08
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cassert>
#include <cstddef>
#include <ios>
#include <iostream>
#include <numeric>
#include <vector>

struct Fraction {
  __int128_t numerator, denominator;

  void simplize() {
    auto g = std::gcd((long)numerator, (long)denominator);
    numerator /= g, denominator /= g;
  }

  Fraction(const Fraction &) = default;
  Fraction(Fraction &&) = default;
  Fraction &operator=(const Fraction &) = default;
  Fraction &operator=(Fraction &&) = default;
  Fraction(__int128_t numerator) : numerator(numerator), denominator(1) {}
  Fraction(__int128_t numerator, __int128_t denominator)
      : numerator(numerator), denominator(denominator) {}
  Fraction() = default;

  Fraction operator*(const Fraction &f) const {
    auto res = Fraction(numerator * f.numerator, denominator * f.denominator);
    res.simplize();
    return res;
  }
  Fraction operator/(const Fraction &f) const {
    auto res = Fraction(numerator * f.denominator, denominator * f.numerator);
    res.simplize();
    return res;
  }
  Fraction operator*(Fraction &&f) const {
    auto res = Fraction(numerator * f.numerator, denominator * f.denominator);
    res.simplize();
    return res;
  }
  Fraction operator/(Fraction &&f) const {
    auto res = Fraction(numerator * f.denominator, denominator * f.numerator);
    res.simplize();
    return res;
  }

  bool operator<(const Fraction &f) const {
    auto to_test =
        Fraction(numerator * f.denominator, denominator * f.numerator);
    return to_test.numerator < to_test.denominator;
  }
  bool operator>(const Fraction &f) const {
    auto to_test =
        Fraction(numerator * f.denominator, denominator * f.numerator);
    return to_test.numerator > to_test.denominator;
  }
  bool operator>=(const Fraction &f) const {
    auto to_test =
        Fraction(numerator * f.denominator, denominator * f.numerator);
    return to_test.numerator >= to_test.denominator;
  }
  bool operator<=(const Fraction &f) const {
    auto to_test =
        Fraction(numerator * f.denominator, denominator * f.numerator);
    return to_test.numerator <= to_test.denominator;
  }
  bool operator<(Fraction &&f) const {
    auto to_test =
        Fraction(numerator * f.denominator, denominator * f.numerator);
    return to_test.numerator < to_test.denominator;
  }
  bool operator>(Fraction &&f) const {
    auto to_test =
        Fraction(numerator * f.denominator, denominator * f.numerator);
    return to_test.numerator > to_test.denominator;
  }
  bool operator>=(Fraction &&f) const {
    auto to_test =
        Fraction(numerator * f.denominator, denominator * f.numerator);
    return to_test.numerator >= to_test.denominator;
  }
  bool operator<=(Fraction &&f) const {
    auto to_test =
        Fraction(numerator * f.denominator, denominator * f.numerator);
    return to_test.numerator <= to_test.denominator;
  }
};

Fraction getUpperX(const Fraction &curr, const Fraction &R) {
  auto tmp = curr / R;
  auto res = curr / Fraction(tmp.numerator / tmp.denominator + 1);
  return res;
}

Fraction getUpperX2(const Fraction &curr, const Fraction &R) {
  auto tmp = curr / R;
  auto res = curr / Fraction(tmp.numerator / tmp.denominator + 1);
  return res;
}

Fraction getLowerX(const Fraction &curr, const Fraction &L) {
  auto tmp = curr / L;
  auto res = curr / Fraction(tmp.numerator / tmp.denominator);
  return res;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T;
  std::cin >> T;

  while (T--) {
    Fraction curr, L, R;
    long K, N, A, B, C, D;
    std::cin >> K >> N >> A >> B >> C >> D;
    curr.numerator = K, curr.denominator = N;
    L.numerator = A, L.denominator = B;
    R.denominator = C, R.denominator = D;
    L.simplize(), R.simplize(), curr.simplize();
    auto X1 = getUpperX(curr, R);
    std::vector<Fraction> v;
    v.emplace_back(L);
    v.emplace_back(R);
    if (X1 >= L) {
      v.emplace_back(X1);
      // assert(X1 < R);
    }
    X1 = getUpperX2(curr, R);
    if (X1 >= L) {
      v.emplace_back(X1);
      // assert(X1 < R);
    }
    Fraction X2;
    if (curr >= L) {
      X2 = getLowerX(curr, L);
      if (X2 <= R) {
        v.emplace_back(X2);
      }
    }
    std::vector<Fraction> resArr;
    for (auto &x : v) {
      auto tmp = curr / x;
      resArr.push_back(x * (tmp.numerator / tmp.denominator + 1));
    }
    auto res = resArr[0];
    for (size_t i = 1; i < resArr.size(); i++) {
      if (resArr[i] > res) {
        res = resArr[i];
      }
    }
    res.simplize();
    std::cout << (long)res.numerator << '/' << (long)res.denominator << '\n';
  }
}
