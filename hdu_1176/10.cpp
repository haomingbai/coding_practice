/**
 * @file 10.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-01
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

void solve() {
  using ld = long double;
  using namespace std;
  size_t n;
  cin >> n;

  std::vector<ld> p(n);
  std::vector<int> x(n);
  for (size_t i = 0; i < n; i++) {
    cin >> x[i];
    p[i] = ((ld)x[i] / (ld)(1000));
  }

  if (n == 1) {
    cout << "1\n";
    return;
  }

  std::vector<ld> expected_val(n);
  expected_val[n - 1] = n;
  long next_time = n;
  std::vector<size_t> res_stack;
  res_stack.reserve(n);
  res_stack.push_back(n - 1);

  for (long i = n - 2; i >= 0; i--) {
    long curr_time = i + 1;
    long next_idx = next_time - 1;
    ld e_submit =
        p[i] * (20 + expected_val[next_idx]) + (1 - p[i]) * (curr_time);
    ld e_not = expected_val[next_idx];

    // < or <=
    if (e_submit <= e_not) {
      expected_val[i] = e_submit;
      next_time = curr_time;
      res_stack.push_back(i);
    } else {
      expected_val[i] = e_not;
    }
  }

  std::reverse(res_stack.begin(), res_stack.end());

  ld curr_p = 1;
  ld res = 0;
  size_t cnt_submit = 0;
  for (auto &i : res_stack) {
    auto curr_time = i + 1;
    res += curr_p * (1 - p[i]) * (cnt_submit * 20 + curr_time);
    curr_p *= p[i];
    cnt_submit++;
  }

  cout << setprecision(10) << fixed << res << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int T;
  std::cin >> T;

  while (T--) {
    solve();
  }
}
