"""
@file: 9.py
@brief 
@author Haoming Bai 
@date   2025-08-11

Copyright © 2025 Haoming Bai
SPDX-License-Identifier: MIT
"""

# 9.py — Python 版，按你 C++ 的思路实现
import sys

def solve():
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    try:
        T = next(it)
    except StopIteration:
        return

    out_lines = []
    for _ in range(T):
        n = next(it)
        w = next(it)

        # 初始和 1..n
        total = (1 + n) * n // 2

        n_copy = n
        # 与 C++ 行为一致：只要 n_copy >= w，就继续，每步用整数除法
        while n_copy >= w:
            n_copy -= (n_copy // w)
            # 对应 ((n + (n - n_copy + 1)) * (n_copy)) / 2
            total += ((2 * n - n_copy + 1) * n_copy) // 2

        out_lines.append(str(total))

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()

