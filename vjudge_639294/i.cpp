/*************************************************************************
    > File Name: i.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月10日 星期三 06时08分39秒
 ************************************************************************/

#include <iostream>

using namespace std;

const int mod = 998244353;
const int N = 1e5 + 10;
long long f[N], g[N], fac[N];

long long factorial_then_mod(long long n)
{
    long long value = 1;
    while (n)
    {
        value *= (n--);
        value %= 998244353;
    }
    return value;
}

int main()
{
	int n, k;
	cin >> n >> k;
	fac[0] = 1;
	for (int i = 1; i < N; i++)
	{
		fac[i] = fac[i-1] * i;
	}
}
