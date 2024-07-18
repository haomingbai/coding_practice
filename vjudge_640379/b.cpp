/*************************************************************************
    > File Name: b.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月13日 星期六 21时43分59秒
 ************************************************************************/

#include <iostream>
#define int long long

using namespace std;

signed main()
{
    int n, m;
    cin >> n >> m;
    // get the length of the num
	auto digit = new int[18]();
	auto len = 0;
	while (n)
	{
		digit[len] = n % 10;
		n /= 10;
		len++;
	}
	int **res = new int*[1 << len];
	// allocate memory
	res[0] = new int[(1 << len) * m]();
	for (auto i = 1; i < (1 << len); i++)
	{
		res[i] = res[i - 1] + m;
	}
	// dp
	res[0][0] = 1;
	for (auto i = 0; i < (1 << len); i++)
	{
		for (auto j = 0; j < m; j++)
		{
			auto vis = new bool[10]();
			for (auto k = 0; k < len; k++)
			{
				int x = digit[k];
				if (i & (1 << k)) continue;
				if (i == 0 && x == 0) continue;
				if (vis[x]) continue;
				vis[x] = 1;
				res[i | (1 << k)][(j * 10 + x) % m] += res[i][j];
			}
		}
	}
	cout << res[(1 << len) - 1][0] << endl;;
}
