/*************************************************************************
    > File Name: c.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: Wed Sep 18 22:50:12 2024
 ************************************************************************/

#include <cstdint>
#include <ios>
#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

constexpr auto narek = "narek";
constexpr int64_t inf = 223372036854775807;

int main()
{
    size_t t;
    cin >> t;
    while (t--)
    {
        size_t n, m;
        cin >> n >> m;
        int64_t dp[5]{0, -inf, -inf, -inf, -inf};


        string* dat = new string[n];
        for(auto i = 0; i < n; i++)
        {
            cin >> dat[i];
        }
        for(auto i = 0; i < n; i++)
        {
            for(auto j = 0; j < 5; j++)
            {
                if(dp[j] == -inf)
                {
                    continue;
                }
                int64_t score(0), next_value(j);
                auto dpj(dp[j]);
                for(int64_t k = 0; k < m; k++)
                {
                    int64_t pos = find(narek, narek+5, dat[i][k]) - narek;
                    if(pos == 5 || pos == -1)
                    {
                        continue;
                    }
                    if (next_value == pos)
                    {
                        next_value = (next_value + 1) % 5;
                        score++;
                        continue;
                    }
                    score--;
                }
                dp[next_value] = max(dp[next_value], dpj + score);
            }
        }
        int64_t ans(0);
        for (auto i = 0; i < 5; i++)
        {
            ans = max(ans, dp[i] - 2 * i);
        }
        cout << ans << '\n';
        delete[] dat;
    }
}