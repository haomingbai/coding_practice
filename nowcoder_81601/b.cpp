/*************************************************************************
    > File Name: b.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年08月01日 星期四 12时28分51秒
 ************************************************************************/

#include<iostream>

typedef long long ll;

using namespace std;

int main()
{
	ll n, k;
	cin >> n >> k;
	if (k > n / 2)
	{
		k = n - k;
	}
	if (k == n / 2 && n % 2 == 0)
	{
		cout << n << '\n';
		return 0;
	}
	cout << n * k + 1 << endl;
}
