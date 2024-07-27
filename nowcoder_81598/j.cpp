/*************************************************************************
    > File Name: j.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月23日 星期二 15时49分48秒
 ************************************************************************/

#include<iostream>
#define int long long
#define pros(n,m) ((n)%(m))

using namespace std;

signed main()
{
	int n, a, b;
	cin >> n >> a >> b;
	char *dat = new char[n + 1];
	bool *chain = new bool[n];
	cin >> dat;
	for (int i = 0; i < n; i++)
	{
		chain[i] = dat[i] - '0';
		// cout << chain[i] << endl;
	}
	int B = 0, *A = new int[n]();
	for (int  i = 0; i < 2 * b - 1; i++)
	{
		for (int j = 0; j < 2 * a - 1; j++)
		{
			A[i] += chain[pros(j + i * (2 * a - 1), n)] ? 1 : -1;
		}
		// cout << A[i] << endl;
		B += (A[i] > 0) ? 1 : -1;
	}
	// cout << B << endl;
	if (B > 0)
	{
		cout << 1;
	}
	else 
	{
		cout << 0;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < b * 2 - 1; j++)
		{
			int tmp = A[j];
			tmp -= chain[pros(i - 1 + j * (2 * a - 1), n)] ? 1 : -1;
			tmp += chain[pros(i - 1 + (j + 1) * (2 * a - 1), n)] ? 1 : -1;
			if (tmp * A[j] < 0)
			{
				B += (tmp > 0) ? 2 : -2;
			}
			A[j] = tmp;
		}
		if (B > 0)
		{
			cout << 1;
		}
		else 
		{
			cout << 0;
		}
	}
}
