/**
 * @file h.cpp
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
#include <cassert>
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

class DSU {
  std::vector<std::size_t> parent_, size_;

 public:
  DSU(std::size_t size) : parent_(size), size_(size, 1) {
    for (auto i = 0ul; i < parent_.size(); i++) {
      parent_[i] = i;
    }
  }

  std::size_t findRoot(std::size_t idx) {
    // 递归终止条件, 寻找到根或者当前位置高度为1(根为0).
    if (parent_[idx] == idx || parent_[parent_[idx]] == parent_[idx]) {
      return parent_[idx];
    }

    parent_[idx] = findRoot(parent_[idx]);
    return parent_[idx];
  }

  void unite(std::size_t idx1, std::size_t idx2) {
    // 先找到根节点, 因为只有根节点维护了大小数据.
    idx1 = findRoot(idx1);
    idx2 = findRoot(idx2);

    // 如果二者根相同, 那么二者已经在同一集合.
    if (idx1 == idx2) {
      return;
    }

    // 因为要把2挂靠到1上, 所以下标1必须是较大的.
    if (size_[idx1] < size_[idx2]) {
      std::swap(idx1, idx2);
    }

    // 将2挂靠到1
    parent_[idx2] = idx1;
    // 此时1的树根是二者的共同树根, 所以只有1需要维护树大小.
    // 1的树大小是原先二者树大小之和, 因为2树和1树合并了.
    size_[idx1] += size_[idx2];
    return;
  }

  bool inSameSet(std::size_t idx1, std::size_t idx2) {
    return findRoot(idx1) == findRoot(idx2);
  }
};

template <typename T>
struct Edge {
  size_t p1, p2;
  size_t idx;
  T weight;
};

template <typename T>
std::vector<Edge<T>> Kruskal(std::vector<Edge<T>> edges, size_t max_node_idx) {
  std::sort(edges.begin(), edges.end(),
            [](const auto &a, const auto &b) { return a.weight < b.weight; });

  DSU visited(max_node_idx + 1);

  std::vector<Edge<T>> res;
  for (auto &it : edges) {
    if (!visited.inSameSet(it.p1, it.p2)) {
      res.emplace_back(it);
      visited.unite(it.p1, it.p2);
    }
  }

  return res;
}

int main() {
  using namespace std;
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    size_t n, m, k;
    cin >> n >> m >> k;
    std::vector<Edge<long>> edges;
    edges.reserve(m);
    for (size_t i = 0; i < m; i++) {
      size_t u, v;
      long w;
      cin >> u >> v >> w;
      if (u != v) {
        Edge<long> e = {
            .p1 = u,
            .p2 = v,
            .idx = i + 1,  // 边的序号提前存好.
            .weight = w,
        };
        edges.push_back(e);
      }
    }
    // 计算当前的最小生成树.
    auto selected = Kruskal(edges, n);

    // 按照边权排序
    sort(selected.begin(), selected.end(),
         [](const auto &x, const auto &y) { return x.weight < y.weight; });

    // 弹出边权大于1的边,
    // 弹出的边数不超过k.
    for (size_t cnt = 0;
         !selected.empty() && selected.back().weight > 1 && cnt < k; cnt++) {
      selected.pop_back();
    }

    // 创造一个并查集,
    // 将剩余的边添加到并查集.
    // 将图分成多个连通块.
    DSU dsu(n + 1);
    for (auto &it : selected) {
      dsu.unite(it.p1, it.p2);
    }

    // 本题疑点, 一定存在i和i + 1,
    // 将两个连通块相连.
    std::vector<Edge<long>> to_add;
    for (long i = 1; i < n; i++) {
      if (!dsu.inSameSet(i, i + 1)) {
        auto idx = to_add.size() + m + 1;
        size_t p1 = i, p2 = i + 1;
        Edge<long> edge = {.p1 = p1, .p2 = p2, .idx = idx, .weight = 1};
        dsu.unite(i, i + 1);
        to_add.push_back(edge);
      }
    }

    // 打印结果, 先打印新增的边.
    cout << to_add.size() << '\n';
    for (const auto &it : to_add) {
      cout << it.p1 << ' ' << it.p2 << '\n';
    }

    // 对当前的生成树的边权进行求和.
    auto weight_sum = 0ll;
    for (auto &it : selected) {
      weight_sum += it.weight;
    }
    for (auto &it : to_add) {
      weight_sum += it.weight;
    }
    cout << weight_sum << '\n';

    // 打印所有的边的序号.
    for (const auto &it : selected) {
      cout << it.idx << ' ';
    }
    for (const auto &it : to_add) {
      cout << it.idx << ' ';
    }
    cout << '\n';
  }
}
