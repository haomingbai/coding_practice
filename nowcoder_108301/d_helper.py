#!/bin/python

import sys
import numpy as np

def calculate_determinant_silent():
  """
  从标准输入静默读取矩阵维度和元素，并计算其行列式，
  最后仅输出整数结果。
  """
  try:
    # 从第一行读取维度 N
    n_str = sys.stdin.readline()
    if not n_str:
      return # 如果输入为空则退出
    n = int(n_str)

    if n <= 0:
      return # 维度不合法则退出

    # 读取接下来的 N 行来构建矩阵
    matrix_list = []
    for _ in range(n):
      line = sys.stdin.readline().strip()
      # 将行分割并转换为整数列表
      row = [int(x) for x in line.split()]
      matrix_list.append(row)

    # 将列表转换为 NumPy 数组
    matrix = np.array(matrix_list)

    # 计算行列式
    determinant = np.linalg.det(matrix)

    # 打印最终的整数结果
    print(int(round(determinant)))

  except (ValueError, IndexError):
    # 如果输入格式不正确（例如，非整数或行/列数量不匹配），
    # 程序将静默退出。
    return
  except Exception:
    # 捕获其他潜在错误并静默退出。
    return

if __name__ == "__main__":
  calculate_determinant_silent()
