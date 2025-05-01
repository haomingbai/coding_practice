/*************************************************************************
    > File Name: a.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月18日 星期四 22时39分27秒
 ************************************************************************/

#include <cstddef>
#include <ios>
#include <iostream>

#define int long long

signed main()
{
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--)
    {
        // std::cout << T << std::endl;
        size_t n, m;
        std::cin >> n >> m;
        if (n == 1 && m == 1)
        {
            for (int i = 0; i < n; i++)
            {
				int tmp;
                for (int j = 0; j < m; j++)
                {
                    std::cin >> tmp;
                }
            }
            std::cout << -1 << '\n';
            continue;
        }
        auto dat = new int *[n];
        for (int i = 0; i < n; i++)
        {
            dat[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                std::cin >> dat[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                std::cout << dat[i % n][j % m] << ' ';
            }
            delete[] dat[i % n];
            std::cout << '\n';
        }
        delete[] dat;
    }
}
