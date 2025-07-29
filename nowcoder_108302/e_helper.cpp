/**
 * @file e_helper.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-29
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

ll mest_proc(ll val) {
  ll cnt = 0;
  ll res = 0;
  while (val) {
    res *= 2;
    if (val % 2) {
      cnt++;
      if (cnt % 2) {
        res += 1;
      }
    }
    val /= 2;
  }

  return res;
}

ll mest_xor(ll a, ll b) { return mest_proc(a ^ b); }

// int main() {
//   ll n;
//   std::cin >> n;
//   std::vector<ll> dat(n);
// 
//   for (auto &it : dat) {
//     std::cin >> it;
//   }
// 
//   ll res = 0;
//   for (size_t i = 0; i < n; i++) {
//     for (size_t j = i + 1; j < n; j++) {
//       res += mest_xor(dat[i], dat[j]);
//     }
//   }
// 
//   std::cout << res << std::endl;
// }

int main() {
  while (1) {
    ll a, b;
    std::cin >> a >> b;
    std::cout << mest_xor(a, b) << std::endl;
  }
}
