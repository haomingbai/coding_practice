/*************************************************************************
    > File Name: c.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月19日 星期五 00时01分21秒
 ************************************************************************/

#include<iostream>
#define int long long

using namespace std;

signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, x, res;
		cin >> n >> x;
		auto dat = new int[n + 1](), err = new int[n + 1]();
		for (int i = 0; i < n; i++)
		{
			cin >> dat[i];
		}
		auto dp = new int *[n];
		dp[0] = new int[n * n];
		dp[0][0] = dat[0];
		for (int i = 1; i < n; i++)
		{
			dp[0][i] = dp[0][i - 1] + dat[i];
		}
		cout << res << '\n';
	}
}
