/**
 * @file c.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-07-31
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
#include <map>
#include <ostream>
#include <utility>
#include <vector>

class dsu {
  std::vector<std::size_t> parent;

 public:
  dsu(std::size_t size) : parent(size) {
    for (auto i = 0uz; i < parent.size(); i++) {
      parent[i] = i;
    }
  }

  std::size_t findRoot(std::size_t idx) {
    if (parent[idx] == idx) {
      return idx;
    }

    std::size_t res = idx;
    while (res != parent[res]) {
      res = parent[res];
    }

    std::size_t curr = idx;
    while (parent[curr] != res) {
      auto to_modify = curr;
      curr = parent[to_modify];
      parent[to_modify] = res;
    }

    return res;
  }

  void unite(std::size_t idx1, std::size_t idx2) {
    parent[findRoot(idx2)] = findRoot(idx1);
  }

  bool inSameTree(std::size_t idx1, std::size_t idx2) {
    return findRoot(idx1) == findRoot(idx2);
  }
};

void solve();

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}

void solve() {
  size_t n;
  std::cin >> n;

  struct PairWithId {
    std::pair<int, int> p;
    size_t id;

    bool operator<(const PairWithId &pa) {
      if (p.first < pa.p.first) {
        return true;
      } else if (p.first == pa.p.first) {
        return p.second > pa.p.second;
      }
      return false;
    }

    PairWithId() = default;
    PairWithId(std::pair<int, int> p) : p(p) {}
    PairWithId(const PairWithId &) = default;
    PairWithId(PairWithId &&) = default;

    PairWithId &operator=(const PairWithId &) = default;
    PairWithId &operator=(PairWithId &&) = default;
  };

  std::vector<PairWithId> dat(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> dat[i].p.first >> dat[i].p.second;
    dat[i].id = i + 1;
  }

  std::sort(dat.begin(), dat.end());

  dsu visited(2 * n + 1);

  std::vector<size_t> st;
  st.reserve(n);

  while (true) {
    for (auto &it : dat) {
      if (!visited.inSameTree(it.p.first, it.p.second)) {
        st.push_back(it.id);
        visited.unite(it.p.first, it.p.second);
        goto next;
      }
    }

    break;
  next:
    continue;
  }

  std::sort(st.begin(), st.end());

  std::cout << st.size() << '\n';
  for (auto &it : st) {
    std::cout << it << ' ';
  }
  std::cout << '\n';
}
