/**
 * @file a.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-09
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
// #include <print>
#include <vector>

void solve();

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}

void solve() {
  using namespace std;

  int n;
  cin >> n;

  struct Employee {
    long a, b;
    size_t idx;
  };

  // I/O
  std::vector<Employee> dat(n);
  for (size_t i = 0; i < n; i++) {
    cin >> dat[i].a >> dat[i].b;
    dat[i].idx = i + 1;
  }

  // Sort by a and then b;
  std::sort(dat.rbegin(), dat.rend(), [](const auto &x, const auto &y) {
    if (x.a != y.a) {
      return x.a < y.a;
    } else {
      return x.b < y.b;
    }
  });

  // for (auto &it : dat) {
  //   println(cout, "{}: a = {}, b = {}", it.idx, it.a, it.b);
  // }

  // Find the greatest a
  auto max_a = dat.front().a;
  // f[1] to f[max_a + 1];
  std::vector<long> f(max_a + 2, 0);
  std::vector<Employee> results;
  // f[max_a + 1] = 0
  f[max_a + 1] = 0;
  auto curr_a = max_a;
  auto old_a = max_a + 1;
  for (auto it = dat.begin(); it != dat.end(); it++) {
    if (it->a == curr_a) {
      // If the b is large enough to hold.
      if (it->b >= f[old_a]) {
        f[curr_a]++;
        results.emplace_back(*it);
      }
    } else {
      old_a = curr_a;
      curr_a = it->a;
      f[curr_a] = f[old_a];
      // If the b is large enough to hold.
      if (it->b >= f[old_a]) {
        f[curr_a]++;
        results.emplace_back(*it);
      }
    }
  }

  cout << f[curr_a] << '\n';
  for (auto &it : results) {
    cout << it.idx << ' ';
  }
  cout << '\n';
}
