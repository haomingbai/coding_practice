/*************************************************************************
    > File Name: b.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月16日 星期二 00时00分16秒
 ************************************************************************/

#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		char *dat = new char[n + 1];
		cin >> dat;
		int cnt1 = 0, cnt0_seg = 0, flag = 1;
		for (int i = 0; i < n; i++)
		{
			if (flag == 1 && dat[i] == '0')
			{
				flag = 0;
				cnt0_seg++;
			}
			else if (flag == 0 && dat[i] == '1')
			{
				flag = 1;
			}
			if (dat[i] == '1')
			{
				cnt1++;
			}
		}
		if (cnt1 > cnt0_seg)
		{
			cout << "Yes" << '\n';
		}
		else
		{
			cout << "No" << '\n';
		}
		delete[] dat;
	}
}
