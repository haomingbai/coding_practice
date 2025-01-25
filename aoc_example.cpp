#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define Ants 100 // 蚂蚁的个数
#define C 83     // 城市的数量
#define I 200    // 最大迭代次数
#define Alpha 1  // 表征信息素重要程度的参数
#define Beta 5   // 表征启发式因子重要程度的参数
#define Rho 0.1  // 信息素蒸发系数
#define Q 100    // 信息素增加强度系数

const double City_Position[C][2] = // 各个城市的坐标数据

    {
        {1304, 2312},    {3639, 1315},    {4177, 2244},    {3712, 1399},     {3488, 1535},    {3326, 1556},
        {3238, 1229},    {4196, 1004},    {4312, 790},     {4386, 570},      {3007, 1970},    {2562, 1756},
        {2788, 1491},    {2381, 1676},    {1332, 695},     {3715, 1678},     {3918, 2179},    {4061, 2370},
        {3780, 2212},    {3676, 2578},    {4029, 2838},    {4263, 2931},     {3429, 1908},    {3507, 2367},
        {3394, 2643},    {3439, 3201},    {2935, 3240},    {3140, 3550},     {2545, 2357},    {2778, 2826},
        {2370, 2975},    {565.0, 575.0},  {25.0, 185.0},   {345.0, 750.0},   {945.0, 685.0},  {845.0, 655.0},
        {880.0, 660.0},  {25.0, 230.0},   {525.0, 1000.0}, {580.0, 1175.0},  {650.0, 1130.0}, {1605.0, 620.0},
        {1220.0, 580.0}, {1465.0, 200.0}, {1530.0, 5.0},   {845.0, 680.0},   {725.0, 370.0},  {145.0, 665.0},
        {415.0, 635.0},  {510.0, 875.0},  {560.0, 365.0},  {300.0, 465.0},   {520.0, 585.0},  {480.0, 415.0},
        {835.0, 625.0},  {975.0, 580.0},  {1215.0, 245.0}, {1320.0, 315.0},  {1250.0, 400.0}, {660.0, 180.0},
        {410.0, 250.0},  {420.0, 555.0},  {575.0, 665.0},  {1150.0, 1160.0}, {700.0, 580.0},  {685.0, 595.0},
        {685.0, 610.0},  {770.0, 610.0},  {795.0, 645.0},  {720.0, 635.0},   {760.0, 650.0},  {475.0, 960.0},
        {95.0, 260.0},   {875.0, 920.0},  {700.0, 500.0},  {555.0, 815.0},   {830.0, 485.0},  {1170.0, 65.0},
        {830.0, 610.0},  {605.0, 625.0},  {595.0, 360.0},  {1340.0, 725.0},  {1740.0, 245.0},
};

int Tabu[Ants][C];     // 禁忌表，存储走过的路径
double Dist[C][C];     // 表示两两城市间的欧氏距离
double Eta[C][C];      // 表示启发式因子，为Dist[][]中距离的倒数
double Tau[C][C];      // 表示两两节点间信息素浓度
double DeltaTau[C][C]; // 表示两两节点间信息素的变化量
double L_best[I];      // 存储每次迭代的路径的最短长度
double L_ave[I];       // 存储每次迭代的路径的平均长度
int R_best[I][C];      // 存储每次迭代的最佳路线

/*《函数ValueInit：初始化各变量数组》*/
void ValueInit()
{
    for (int i = 0; i < C; i++) // 初始化 Dist[C][C]，计算城市间的欧氏距离

    {
        for (int j = 0; j < C; j++)
        {
            if (i != j)
                Dist[i][j] = pow(pow((City_Position[i][0] - City_Position[j][0]), 2) +
                                     pow((City_Position[i][1] - City_Position[j][1]), 2),
                                 0.5);
            else
                Dist[i][j] = 0;
        }
    }
    for (int i = 0; i < C; i++) // 初始化 Eta[n][n]，城市间欧氏距离的倒数
    {
        for (int j = 0; j < C; j++)
        {
            Eta[i][j] = 1.0 / Dist[i][j];
        }
    }
    for (int i = 0; i < C; i++) // 初始化 Tau[n][n]，两两节点间的初始信息素浓度
    {
        for (int j = 0; j < C; j++)
        {
            Tau[i][j] = 1.0;
        }
    }
    for (int i = 0; i < C; i++) // 初始化 DeltaEta[n][n],两两节点间信息素的变化量
    {
        for (int j = 0; j < C; j++)
        {
            DeltaTau[i][j] = 0;
        }
    }
    for (int i = 0; i < Ants; i++) // 初始化 Tabu[m][n]，禁忌表
    {
        for (int j = 0; j < C; j++)
        {
            Tabu[i][j] = 0;
        }
    }
}
/*《函数Random_Num：生成lower和uper之间的一个double类型随机数》*/
double Random_Num(double lower, double uper)
{
    return (rand() / (double)RAND_MAX) * (uper - lower) + lower;
}

int all_citys[C]; // 生成一个待访问城市全序列
int main()
{
    int i, j;
    /*Step1：调用函数《ValueInit》:初始化各变量数组*/
    ValueInit();

    int it = 0; // 迭代参数
    while (it < I)
    {
        for (i = 0; i < C; i++)
        {
            all_citys[i] = i + 1; // 生成一个待访问城市全序列
        }
        /*Step2：将 Ants 只蚂蚁随机平均放到 C 个城市上*/
        // ①一维向量，连续存放几轮对各城市安放蚂蚁的结果
        vector<int> temp;
        // ②ceil()函数向上取整；floor()函数向下取整；round()四舍五入
        for (int i = 0; i < ceil((double)Ants / (double)C); i++)
        {
            for (int j = 0; j < C; j++)
                temp.push_back(j);
        }
        // ③打乱temp数组中元素的次序
        random_shuffle(temp.begin(), temp.end());
        // ④更新每只蚂蚁的禁忌表，实际只用到temp前m个节点的信息
        for (int i = 0; i < Ants; i++)
        {
            Tabu[i][0] = temp[i];
        }
        /*
        for (int i = 0; i < Ants; i++)
        {
            int rand_city = rand() % C;			//随机为当前蚂蚁选择一个出发城市索引
            Tabu[i][0] = all_citys[rand_city];	//同时更新每只蚂蚁的禁忌表
        }
        */
        /*Step3：Ants只蚂蚁按概率函数选择下一座城市进行访问，并完成各自的周游*/
        // ①禁忌表已经有第一个出发城市，所以从第二个点开始概率选择访问（基于信息素和启发因子）
        for (int j = 1; j < C; j++)
        {
            // ②Ants只蚂蚁并行
            for (int i = 0; i < Ants; i++)
            {
                vector<int> visited; // 第i只蚂蚁，已访问过的城市，集合
                vector<int> J;       // 第i只蚂蚁，待访问的城市，集合
                vector<double> V;    // 第i只蚂蚁，待访问城市的竞争值，的集合
                vector<double> P;    // 第i只蚂蚁，待访问城市的被选概率，的集合

                double Vsum = 0.0;      // 竞争值和
                double Psum = 0.0;      // 概率和
                double rand_rate = 0.0; // 随机概率
                double choose = 0.0;    // 轮盘赌累加概率（用于和rand_rate比较）
                int to_visit = 0;       // 下一个要去的城市

                // ③visited，结算当前蚂蚁已访问节点
                for (int k = 0; k < j; k++) // j控制当前已访问节点个数（包含出发点）
                {
                    visited.push_back(Tabu[i][k]); // 把当前蚂蚁的禁忌表拿来赋值
                }

                // ④J，添加待访问节点
                for (int k = 0; k < C; k++)
                {
                    // 若在visited中没有找到某节点all_citys[k]，则说明还未被访问
                    if (find(visited.begin(), visited.end(), all_citys[k]) == visited.end())
                    {
                        J.push_back(all_citys[k]); // J初始化，添加到待访问城市集合
                        P.push_back(0.0);          // P初始化，待访问城市被选概率占坑
                        V.push_back(0.0);          // V初始化，待访问城市竞争值占坑
                    }
                }

                // ⑤计算各待访城市的竞争值（已访问节点中最后一个城市—>各待访问各节点）
                for (int k = 0; k < V.size(); k++)
                {
                    V[k] = pow(Tau[visited.back()][J[k]], Alpha) * pow(Eta[visited.back()][J[k]], Beta);
                    Vsum += V[k];
                }

                // ⑥计算去下一座城市的各种概率（已访问节点中最后一个城市—>各待访问各节点）
                for (int k = 0; k < P.size(); k++)
                {
                    P[k] = V[k] / Vsum;
                    Psum += P[k];
                }

                // ⑦使用轮盘赌算法，挑选下一座要去的城市
                rand_rate = Random_Num(0.0, Psum); // 随机概率
                for (int k = 0; k < P.size(); k++)
                {
                    choose += P[k]; // 概率小累计，用于与随机概率比较
                    if (choose > rand_rate)
                    {
                        to_visit = J[k]; // 根据概率选择下一访问城市
                        break;
                    }
                }

                // ⑧更新禁忌表（把刚选出的下一访问节点及时加入）
                Tabu[i][j] = to_visit;
            }
        }

        // Step4：计算本次迭代各蚂蚁的旅行数据（距离、时间等）
        // ①记录本代每只蚂蚁走的总路程
        double L[Ants];
        for (int i = 0; i < Ants; i++)
        {
            L[i] = 0.0; // 初始化
        }
        for (int i = 0; i < Ants; i++)
        {
            for (int j = 0; j < C - 1; j++)
            {
                // 禁忌表中就是最终的访问路径（但禁忌表从1开始，而Dist[][]从0开始存储，所以要减一）
                L[i] += Dist[Tabu[i][j] - 1][Tabu[i][j + 1] - 1];
            }
            L[i] += Dist[Tabu[i][0] - 1][Tabu[i][C - 1] - 1];
        }
        // ②计算当前迭代所有蚂蚁路径中的最小蚂蚁路径
        double min_value = L[0]; // 声明求本代所有蚂蚁行走距离最小值的临时变量
        double sum_value = L[0]; // 声明求本代所有蚂蚁行走距离总值的临时变量
        int min_index = 0;       // 记录本代所有蚂蚁行走距离最小值的下标
        for (int i = 1; i < Ants; i++)
        {
            sum_value += L[i];
            if (L[i] < min_value)
            {
                min_value = L[i];
                min_index = i;
            }
        }
        // ③将本次迭代的最小路径值、平均路径值、最短路径数据存在全局迭代数组中
        L_best[it] = min_value;       // 每代中路径的最短长度
        L_ave[it] = sum_value / Ants; // 每代中路径的平均长度
        for (int i = 0; i < C; i++)
        {
            R_best[it][i] = Tabu[min_index][i]; // 记录每代最短的路径数据
        }
        // ④打印各代距离信息
        cout << it << ": L_best is " << L_best[it] << "    " << "L_ave is " << L_ave[it] << endl;

        // ⑤迭代继续
        it++;

        // Step5：更新两两节点间的信息素，为下一次迭代的概率选择下一访问节点作准备
        // ①全部更新：累加所有蚂蚁，所有路径中，涉及到相同的两两节点间的信息素增量
        for (int i = 0; i < Ants; i++)
        {
            for (int j = 0; j < C - 1; j++)
            {
                // （禁忌表从1开始，而DeltaTau[][]从0开始存储，所以要减一）
                DeltaTau[Tabu[i][j] - 1][Tabu[i][j + 1] - 1] += Q / L[i];
            }
            // 蚁周算法，使用全局距离作更新
            DeltaTau[Tabu[i][C - 1] - 1][Tabu[i][0] - 1] += Q / L[i];
        }
        // ②基于以上两两节点间的信息素增量DeltaTau[][]，对Tau[][]作更新
        for (int i = 0; i < C; i++)
        {
            for (int j = 0; j < C; j++)
            {
                // 考虑信息素挥发+信息素增量，更新信息素
                Tau[i][j] = (1 - Rho) * Tau[i][j] + DeltaTau[i][j];
            }
        }
        // ③禁忌表清零,进入下一次迭代!
        for (int i = 0; i < Ants; i++)
        {
            for (int j = 0; j < C; j++)
            {
                Tabu[i][j] = 0;
            }
        }
    }

    // Step6：展示最终所有迭代中最好的结果
    double min_L = L_best[0]; // 所有迭代中最短距离
    int min_L_index = 0;      // 所有迭代中最优路径的迭代下标
    int Shortest_Route[C];    // 所有迭代中的最优路径
    for (int i = 0; i < it; i++)
    {
        if (L_best[i] < min_L)
        {
            min_L = L_best[i];
            min_L_index = i;
        }
    }
    cout << endl << endl;
    cout << "The length of the shortest route is :  " << min_L << endl;
    cout << "The number of iteration is :  " << min_L_index << endl;
    cout << "The Shortest route is： " << endl << "[start]";

    for (int i = 0; i < C; i++) // 所有迭代中的最优路径
    {
        Shortest_Route[i] = R_best[min_L_index][i];
        cout << " -> " << Shortest_Route[i];
    }
    cout << endl;

    system("pause");
    return 0;
}