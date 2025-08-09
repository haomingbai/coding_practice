/**
 * @file 5.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-08
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
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--) {
    using namespace std;

    long n, m, k;
    cin >> n >> m >> k;
    std::vector<std::vector<char>> graph(n, std::vector<char>(m, '.'));

    struct TreeInfo {
      long x, y, i;
      TreeInfo() = default;
      TreeInfo(const TreeInfo &) = default;
      TreeInfo(TreeInfo &&) = default;
      TreeInfo &operator=(const TreeInfo &) = default;
      TreeInfo &operator=(TreeInfo &&) = default;

      bool operator<(const TreeInfo &t) const { return x < t.x; }
      bool operator<(TreeInfo &&t) const { return x < t.x; }
    };

    vector<TreeInfo> trees(k);
    for (size_t i = 0; i < k; i++) {
      trees[i].i = i + 1;
      cin >> trees[i].x >> trees[i].y;
    }

    std::sort(trees.begin(), trees.end());

    auto paint_tree = [&graph, &m](const TreeInfo &t) {
      auto x = t.x - 1;
      auto y = t.y - 1;
      graph[x][y] = '0' + t.i;
      x--;
      if (x >= 0) {
        graph[x][y] = '0' + t.i;
      }
      x--;
      if (x >= 0) {
        for (long delta = -2; delta <= 2; delta++) {
          if (y + delta >= 0 && y + delta < graph[0].size()) {
            graph[x][y + delta] = '0' + t.i;
          }
        }
      }
      x--;
      if (x >= 0) {
        for (long delta = -1; delta <= 1; delta++) {
          if (y + delta >= 0 && y + delta < m) {
            graph[x][y + delta] = '0' + t.i;
          }
        }
      }
      x--;
      if (x >= 0) {
        graph[x][y] = '0' + t.i;
      }
    };

    for (const auto &it : trees) {
      paint_tree(it);
    }
    for (long i = 0; i < n; i++) {
      for (long j = 0; j < m; j++) {
        cout << graph[i][j];
      }
      cout << '\n';
    }
  }
}
