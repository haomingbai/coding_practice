/*************************************************************************
    > File Name: g.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月11日 星期四 12时11分24秒
 ************************************************************************/

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <numeric>

using namespace std;

#define int long long

int32_t main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, a, b, k;
        cin >> n >> m >> a >> b >> k;
        int g = gcd(a, b);
        if (k % g)
        {
            cout << n + m << '\n';
            continue;
        }
        k /= g, a /= g, b /= g;
        int t = n + m;
        for (int i = 0, j, num; i <= k / a;)
        { // i obj A and j obj B
            j = (k - i * a) / b;
            if ((i * a + j * b) == k)
            {
                num = min(i ? n / i : 1000000000, j ? m / j : 1000000000);
                t = min(n - num * i + m - num * j, t);
                i += b;
                if (abs(i / j - n / m) > 1)
                {
					break;
                }
            }
            else
            {
                if (j == 0)
                {
                    i++;
                    continue;
                }
                if (abs(i / j - n / m) > 1)
                {
					i += b;
                }
                else
                {
                    i++;
                }
            }
        }
        cout << t << '\n';
    }
}
