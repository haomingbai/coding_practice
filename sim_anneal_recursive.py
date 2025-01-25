# 模拟退火示例，但是使用递归和状态思维

import math
import random
import matplotlib.pyplot as plt
import sys  # 导入sys模块
sys.setrecursionlimit(10000)  # 将默认的递归深度修改为3000

# 目标函数
def objfunc(x):
    return x**2 + 4 * math.sin(5 * x)

# 退火函数：第一个参数为目标函数，其余参数为状态
def simulated_annealing(objective_function, current_x = 0, current_temp = 1000, cooling_rate = 0.99, iterate_time = 1000, vals = [], best_x = 0):
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
        if len(vals) == 0: # 第一次接受数据永远为最优
            vals.append(new_val)
            best_x = new_x
        elif vals[len(vals) - 1] > new_val and vals[len(vals) - 1] - new_val > 1e-10: # 如果函数值确实变小，则更新最优解
            vals.append(new_val)
            best_x = new_x
        current_x = new_x # 更新下一次递归时用到的x值

    if current_temp < 1e-10 or iterate_time == 0: # 终止条件：递归次数用完或者温度足够低
        return best_x, vals[len(vals) - 1], current_temp, vals
    else: # 否则进行下一次递归
        return simulated_annealing(objective_function, current_x, current_temp, cooling_rate, iterate_time, vals, best_x)

if __name__ == '__main__':
    # 参数设置：初始状态
    initial_x = 0.0
    initial_temp = 100000
    cooling_rate = 0.99
    max_iter = 10000
     
    # 执行模拟退火算法
    best_x, best_energy, temperatures, energies = simulated_annealing(objfunc, current_x=initial_x, cooling_rate=cooling_rate,iterate_time=max_iter,current_temp=initial_temp)
     
    print(f"最优解 x: {best_x}")
    print(f"最优能量 f(x): {best_energy}")

    for e in energies:
        print(e, end=' ')

    print()
    print(f"The time of updating the best energy is {len(energies)}")
    
    # 可视化结果
    x_values = [x / 100.0 for x in range(-200, 200)]
    y_values = [objfunc(x) for x in x_values]
     
    plt.figure(figsize=(12, 6))
    plt.plot(x_values, y_values, label='Target function f(x)')
    plt.scatter(best_x, best_energy, color='red', label='Optimized solution')
    plt.title('Simulated annealing sample')
    plt.xlabel('x')
    plt.ylabel('f(x)')
    plt.legend()
    plt.grid(True)
    plt.show()