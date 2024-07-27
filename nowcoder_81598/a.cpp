/*************************************************************************
    > File Name: a.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月23日 星期二 19时21分35秒
 ************************************************************************/

#include <algorithm>
#include <cmath>
#include<iostream>
#define int long long
#define up_div(n,m) (((n)%(m))?(((n)/(m))+1):((n)))

using namespace std;

signed main()
{
	int n, L, R;
	cin >> n >> L >> R;
	// int come_back = ceil((n - R) * 1.0 / (R - L));
	int come_back = up_div(n - R, R - L);
	int sum(0);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		tmp--;
		tmp /= 2;
		tmp = min(tmp, come_back);
		sum += tmp;
	}
	cout << (sum >= come_back * L ? "Yes\n": "No\n");
}
