/*************************************************************************
    > File Name: a.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月23日 星期二 22时39分16秒
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
		int n, k, cnt = 0;
		cin >> n >> k;
		int len = n;
		if (k >= len)
		{
			k -= len;
			cnt++;
			len--;
		}
		else
		{
			cout << (k ? "1\n" : "0\n");
			continue;
		}
		while (k > 0)
		{
			// cout << cnt << endl;
			if (k >= len)
			{
				k -= len;
				cnt++;
			}
			if (k >= len)
			{
				k -= len;
				cnt++;
			}
			else
			{
				break;
			}
			len--;
		}
		if (k > 0)
		{
			cnt++;
		}
		cout << cnt << '\n';
	}
}
