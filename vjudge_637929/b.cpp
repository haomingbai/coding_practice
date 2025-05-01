/*************************************************************************
    > File Name: b.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月03日 星期三 20时25分05秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        auto src = new double[N - 1];
        auto path = new double[M];
        auto path_idx = new int[M][2];
        double *total_efficient = new double[N - 1]();
        for (int i = 0; i < N + 1; i++)
            cin >> src[i];
        for (int i = 0; i < M; i++)
        {
            cin >> path_idx[i][0] >> path_idx[i][1] >> path[i];
            path[i] = 1.0 - path[i]; // Convert to efficiency.
        }
    }
}
