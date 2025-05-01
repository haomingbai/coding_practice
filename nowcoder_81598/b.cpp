/*************************************************************************
    > File Name: b.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月23日 星期二 12时19分56秒
 ************************************************************************/

#include <algorithm>
#include <cstdlib>
#include <ios>
#include<iostream>
#include <numeric>
#define int long long

using namespace std;

signed main()
{
	// ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int n, D, res, g;
	cin >> n >> D;
	auto h = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
		if (!i)
		{
			g = h[i];
		}
		else
		{
			g = gcd(h[i], g);
		}
		if (h[i] == 1)
		{
			res = 0;
		}
	}
	if (n == 1)
	{
		res = min(D % h[0], abs(D - (D / h[0] + 1) * h[0]));
	}
	else if (res != 0 && g == 1)
	{
		res = 0;
	}
	else 
	{
		res  = min(D % g, abs(D - (D / g + 1) * g));
	}
	cout << res << '\n';
}
