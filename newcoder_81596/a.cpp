/*************************************************************************
    > File Name: a.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月16日 星期二 15时28分44秒
 ************************************************************************/

#include <iostream>

#define int long long

using namespace std;

inline int fastpow(int base, int index, int mod)
{
	if (index == 0)
	{
		return 1;
	}
    int r = base, sto = 1;
    r %= mod;
    while (index > 1)
    {
        int tmp = r;
        r *= r;
        r %= mod;
        if (index & 1)
        {
			sto *= tmp;
			sto %= mod;
        }
        index >>= 1;
    }
    return (r * sto) % mod;
}

signed main()
{
    int n, m, q;
    cin >> n >> m >> q;
    // Create a C
    auto C = new int *[n + 5];
    C[0] = new int[(n + 5) * (n + 5)]();
    for (auto i = 1; i <= n + 4; i++)
    {
        C[i] = C[i - 1] + (n + 5);
    }
    for (int i = 1; i <= n; i++)
    {
        C[i][0] = 1;
		C[i][1] = i;
        C[i][i] = 1;
        for (int j = 2; j <= i; j++)
        {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= q;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
		res += C[n][i] % q * fastpow((fastpow(2, i, q) - 1), m - 1, q) % q * fastpow(2, (n - i) * (m - 1), q) % q;
		res %= q;
    }
	cout << res << endl;
}
