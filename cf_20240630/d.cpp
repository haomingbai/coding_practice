/*************************************************************************
	> File Name: d.cpp
	> Author: Haoming Bai
	> Mail: haomingbai@hotmail.com
	> Created Time: 2024年07月01日 星期一 01时21分41秒
 ************************************************************************/

#include <algorithm>
#include <ios>
#include <iostream>
int main()
{
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int t, n;
	std::cin >> t;
	int *dat, *pros, *r = new int[t]();
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		dat = new int[n]();
		for (int j = 0; j < n; j++)
		{
			std::cin >> dat[j];
		}
		std::sort(dat, dat + n);
		int cnt = 1;
		pros = new int[n]();
		for (int j = 0, value = dat[0]; j < n; j++)
		{
			if (value != dat[j])
			{
				pros[cnt] = 1;
				cnt++;
				value=dat[j];
			} else
			{
				pros[cnt - 1]++;
			}
		}
		int alice = 0, bob = cnt - 1;
		// bool finish =0;
		while (1)
		{
			// Alice
			if (alice <= cnt)
			{
				while (pros[alice] == 0&&alice!=cnt)
					alice++;
				alice++;
			}
			if(alice<=cnt)
			{
				r[i]++;
				//std::cout<<alice<<"\n";
			}
			else
				break;
			if(bob!=0)
			{
				while(pros[bob]==0&&bob)
				{
					bob--;
				}
				pros[bob]--;
			}
			if(bob<=alice)
				break;
		}
		delete[] dat,delete[] pros;
	}
	for (int i = 0; i < t; i++)
		std::cout<<r[i]<<"\n";
}
