/**
 * @file i.cpp
 * @brief
 * @author Haoming Bai <haomingbai@hotmail.com>
 * @date   2025-08-14
 *
 * Copyright © 2025 Haoming Bai
 * SPDX-License-Identifier: MIT
 *
 * @details
 */

#include <cstddef>
#include <ios>
#include <iostream>
#include <numeric>
#include <vector>

struct Position {
  long i, j;
};

struct Matrix {
  long n, m;
  std::vector<std::vector<long>> arr;

  Matrix(size_t n, size_t m) : n(n), m(m), arr(n, std::vector<long>(m, 0)) {}

  void moveParallel(Position &pos, long deltaJ) {
    pos.j += deltaJ;
    if (pos.j < 0) {
      pos.j += m * n;
    }
    if (pos.j >= m) {
      pos.j %= m;
    }
  }

  void moveVerticle(Position &pos, long deltaI) {
    pos.i += deltaI;
    if (pos.i < 0) {
      pos.i += m * n;
    }
    if (pos.i >= n) {
      pos.i %= n;
    }
  }

  long &operator[](Position pos) {
    auto &vec = arr[pos.i];
    return vec[pos.j];
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  long n, m;
  std::cin >> n >> m;

  if (std::gcd(n, m) != 1) {
    std::cout << "No\n";
    return 0;
  }

  std::cout << "YES\n";

  Matrix mat(n, m);
  Position pos = {.i = 0, .j = 0};
  long curr = 1;

  long verticleFlag = 1, parallelFlag = 1;
  while (curr <= n * m) {
    while (curr % m != 0) {
      mat[pos] = curr;
      mat.moveParallel(pos, curr * parallelFlag);
      parallelFlag = -parallelFlag;
      curr++;
    }
    mat[pos] = curr;
    mat.moveVerticle(pos, curr * verticleFlag);
    verticleFlag = -verticleFlag;
    curr++;
  }

  for (size_t i = 0; i < mat.n; i++) {
    for (size_t j = 0; j < mat.m; j++) {
      std::cout << mat.arr[i][j] << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
