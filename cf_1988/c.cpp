/*************************************************************************
    > File Name: c.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月16日 星期二 00时10分45秒
 ************************************************************************/

#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long n, bak;
		cin >> n;
		bak = n;
		int len = 0, cnt = 0;
		bool *flag = new bool[64]();
		while (n)
		{
			flag[len] = n % 2;
			if (flag[len])
				cnt++;
			n >>= 1;
			len++;
		}
		if (cnt == 1)
		{
			cout << "1\n" << bak << '\n';
		}
		else
		{
			cout << cnt + 1 << '\n';
			cout << (bak - (1 << (len - 1)));
			int tmp = (1 << (len - 1));
			for (auto i = len - 2, flg = 0; i >= 0; i--)
			{
				if (flag[i] && flg == 0)
				{
					flg = 1;
				}
				else if (flag[i])
				{
					tmp += (1 << i);
				}
			}
			cout << ' ' << tmp;
			tmp = (1 << (len - 1));
			for (auto i = len - 2; i >= 0; i--)
			{
				if (flag[i])
				{
					tmp += (1 << i);
					cout << ' ' << tmp;
				}
			}
			cout << '\n';
		}
	}
}
