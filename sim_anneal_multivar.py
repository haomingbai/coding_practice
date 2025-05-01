import math
import random
import numpy as np
import collections.abc
import typing
import sys


# 退火函数：第一个参数为目标函数，其余参数为状态
def simulated_annealing(
    objective_function,
    current_x=0,
    current_temp=1000,
    cooling_rate=0.99,
    iterate_time=1000,
    vals=[],
    best_x=0,
):
    sys.setrecursionlimit(1000000)  # 设置递归深度
    # 数据迭代一次
    current_temp = current_temp * cooling_rate
    iterate_time -= 1
    new_x = current_x + random.uniform(-1, 1)

    # 计算函数值
    current_val = objective_function(current_x)
    new_val = objective_function(new_x)
    dist = new_val - current_val

    # 处理数据
    if new_val < current_val or random.random() < math.exp(-dist / current_temp):
        if len(vals) == 0:  # 第一次接受数据永远为最优
            vals.append(new_val)
            best_x = new_x
        elif (
            vals[len(vals) - 1] > new_val and vals[len(vals) - 1] - new_val > 1e-10
        ):  # 如果函数值确实变小，则更新最优解
            vals.append(new_val)
            best_x = new_x
        current_x = new_x  # 更新下一次递归时用到的x值

    if (
        current_temp < 1e-10 or iterate_time == 0
    ):  # 终止条件：递归次数用完或者温度足够低
        sys.setrecursionlimit(1000)  # 恢复递归深度
        return best_x, vals[len(vals) - 1], current_temp, vals
    else:  # 否则进行下一次递归
        return simulated_annealing(
            objective_function,
            current_x,
            current_temp,
            cooling_rate,
            iterate_time,
            vals,
            best_x,
        )


# 退火算法，循环实现
def sim_anneal_multivar(
    objFunc: collections.abc.Callable[[typing.List[float | int]], float | int],
    punishFunc: collections.abc.Callable[[typing.List[float | int]], float | int],
    initFunc: collections.abc.Callable[
        [], typing.Tuple[float, float, np.ndarray, int, int, float]
    ],
) -> typing.Tuple[typing.List[float | int], typing.List[float | int]]:
    # 参数设置，设置初始化温度，降温速率，初始坐标，最大外部迭代次数，最大内部迭代次数，初始惩罚因子
    initTemp, tempDecayRate, initCoord, maxOuterIter, maxInnerIter, initPenalty = (
        initFunc()
    )

    # 初始化当前坐标，当前温度，当前迭代次数，当前惩罚因子
    currCoord = initCoord
    currTemp = initTemp
    currPenalty = initPenalty
    dimension = len(currCoord)
    currObjVal = objFunc(currCoord)
    values = [currObjVal]  # 每次函数值达到最优时，记录函数值
    cords = [currCoord]  # 每次函数值达到最优时，记录坐标

    # 开始迭代
    for currOuterIter in range(maxOuterIter):
        # 内部循环，确保达到次数或者获取一个最优解
        for currInnerIter in range(maxInnerIter):
            # 生成新的坐标
            newCoord = np.random.normal(currCoord, 1, dimension)
            # 计算新的函数值，寻找最小值时，函数值 = 函数值 + 惩罚因子 * 惩罚函数值
            newObjVal = objFunc(newCoord) + currPenalty * punishFunc(newCoord)
            # 计算函数值差
            deltaObjVal = newObjVal - currObjVal

            # 坐标更新条件：新的函数值更小或者更新概率大于随机数
            if deltaObjVal < 0 or np.random.rand() < np.exp(-deltaObjVal / currTemp):
                currCoord = newCoord
                currObjVal = newObjVal

                # 取出当前最优解
                currBestObjVal = values[-1]
                if currObjVal < currBestObjVal:
                    values.append(currObjVal)
                    cords.append(currCoord)
                    break

        # 更新温度
        currTemp = currTemp * tempDecayRate
        # 更新惩罚因子
        currPenalty += initPenalty

        # 额外退出条件：温度小于阈值
        if currTemp < 1e-10:
            break

    return cords, values


objFunc = lambda x: x[0] ** 2 + x[1] ** 2

punishFunc = lambda x: 0

initFunc = lambda: (1000, 0.99, [1, 1], 1000, 100, 0.1)

rangeOfParams = [(-10, 10), (-10, 10)]

setps = 0.1

# 敏感度分析
def sensitivityAnalysis(
    objFunc: collections.abc.Callable[[np.ndarray], float | int],
    punishFunc: collections.abc.Callable[[typing.List[int | float]], float | int],
    initFunc: collections.abc.Callable[
        [],
        typing.Tuple[float, float, np.ndarray, int, int, float],
    ],
    rangeOfParams: typing.List[typing.Tuple[float, float]],
    stepLength: float,
):
    return None