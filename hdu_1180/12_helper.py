"""
@file: 12_helper.py
@brief 
@author Haoming Bai 
@date   2025-08-15

Copyright © 2025 Haoming Bai
SPDX-License-Identifier: MIT
"""

# gen_with_replacement.py
import random

def gen_randoms(n: int, m: int):
    """生成 m 个在 [1, n] 的随机整数（允许重复）"""
    if n < 1 or m < 0:
        raise ValueError("要求 n >= 1 且 m >= 0")
    return [random.randint(1, n) for _ in range(m)]

def gen():
    n = int(input().strip())
    m = int(input().strip())
    nums = gen_randoms(n, m)
    print(n, m)
    print(*nums)  # 空格分隔输出

if __name__ == "__main__":
    t = int(input().strip())
    print(t)
    for i in range(t):
        gen()

