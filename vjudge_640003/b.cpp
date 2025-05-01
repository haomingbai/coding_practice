/*************************************************************************
    > File Name: b.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月11日 星期四 13时17分40秒
 ************************************************************************/

#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

long long square_list[] = {1073741824, 536870912, 268435456, 134217728, 67108864, 33554432, 16777216, 8388608,
                           4194304,    2097152,   1048576,   524288,    262144,   131072,   65536,    32768,
                           16384,      8192,      4096,      2048,      1024,     512,      256,      128,
                           64,         32,        16,        8,         4,        2,        1};

int32_t main()
{
    long long T, sum = 0, r = 0;
    cin >> T;
    for (long long i = 0, tmp; i < T; i++)
    {
        cin >> tmp;
        sum += tmp;
    }
    for (auto i : square_list)
    {
        if (sum > ((i - 1) * T))
        {
            r += i;
            sum -= i * min(sum / i, T);
        }
    }
    cout << r << '\n';
}
