/**
 * @file c.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-07
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <bits/utility.h>

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

struct Element {
  long long a, b;
  size_t idx;

  long long diff() const { return std::abs(a - b); }

  bool operator<(const Element &e) { return diff() < e.diff(); }
  bool operator<(Element &&e) { return diff() < e.diff(); }
};

long long sumDiff(std::vector<Element> &v) {
  long long res = 0;
  for (size_t i = 0; i < v.size(); i++) {
    res += v[i].diff();
  }
  return res;
}

void solve() {
  using namespace std;
  size_t n, k;
  cin >> n >> k;
  vector<Element> v(n);

  for (size_t i = 0; i < v.size(); i++) {
    cin >> v[i].a;
    v[i].idx = i;
  }
  for (size_t i = 0; i < v.size(); i++) {
    cin >> v[i].b;
    auto a = v[i].a, b = v[i].b;
    v[i].a = min(a, b), v[i].b = max(a, b);
  }

  // std::sort(v.rbegin(), v.rend(),
  //           [](const auto &x, const auto &y) { return x.a < y.a; });
  // auto ubound = v.rbegin()->a;

  std::sort(v.rbegin(), v.rend());
  vector<long long> diff_vec;
  diff_vec.reserve(n);
  for (auto it = next(v.begin()), begin = v.begin(); it != v.end(); it++) {
    auto col_diff_sum = abs(begin->a - it->a) + abs(begin->b - it->b);
    auto row_diff_sum = begin->diff() + it->diff();
    if (row_diff_sum >= col_diff_sum) {
      cout << sumDiff(v) << '\n';
      return;
    } else {
      diff_vec.push_back(col_diff_sum - row_diff_sum);
    }
  }
  for (auto it = v.begin() + 2, begin = v.begin() + 1; it != v.end(); it++) {
    auto col_diff_sum = abs(begin->a - it->a) + abs(begin->b - it->b);
    auto row_diff_sum = begin->diff() + it->diff();
    if (row_diff_sum >= col_diff_sum) {
      cout << sumDiff(v) << '\n';
      return;
    } else {
      diff_vec.push_back(col_diff_sum - row_diff_sum);
    }
  }
  std::sort(diff_vec.begin(), diff_vec.end());
  cout << diff_vec.front() + sumDiff(v) << '\n';
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}
