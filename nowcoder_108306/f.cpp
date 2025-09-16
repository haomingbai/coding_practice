/**
 * @file f.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-12
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <utility>

long judgeParallen(long sx1, long sy1, long sx2, long sy2, long tx1, long ty1,
                   long tx2, long ty2) {
  if ((sx1 > sx2) && (tx1 < tx2)) {
    std::swap(tx1, tx2);
  }
  if ((sy1 > sy2) && (ty1 < ty2)) {
    std::swap(ty1, ty2);
  }

  auto x_diff = std::abs(sx1 - tx1);
  auto y_diff = std::abs(sx2 - ty2);

  return 2 * std::min(x_diff, y_diff);
}

int main() {
  int T;
  std::cin >> T;

  while (T--) {
    long sx1, sy1, sx2, sy2;
    long tx1, ty1, tx2, ty2;
    std::cin >> sx1 >> sy1 >> sx2 >> sy2;
    std::cin >> tx1 >> ty1 >> tx2 >> ty2;

    auto sx_diff = std::abs(sx1 - sx2);
    auto yx_diff = std::abs(tx1 - tx2);

    switch (sx_diff ^ yx_diff) {
      case 0:
        // Parallel
        std::cout << judgeParallen(sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2);
        break;
      case 1:
        auto res = std::min({
            judgeParallen(sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2),
            judgeParallen(sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2),
            judgeParallen(sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2),
            judgeParallen(sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2),
        });
    }
  }
}
