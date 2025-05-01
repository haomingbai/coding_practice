/*************************************************************************
    > File Name: a.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月15日 星期一 22时37分01秒
 ************************************************************************/

#include <algorithm>
#include<iostream>

#define up_div(x,y) (((x) % (y)) ? (((x) / (y)) + 1) : ((x)/(y))) // 整除，向上取整

using namespace std;

//template <typename T> T up_div(T x, T y)
//{
//	return (x % y) ? x / y + 1 : x / y;
//}

long long solve(int n, int k)
{
	if (n <= 1)
	{
		return 0;
	}
	if (n <= k)
	{
		return 1; 
	}
	if (n <= k * k)
	{
		return n / k + solve(n % k, k) + 1;
	}
	long long res = 0;
	int basis = n / k, mod = n % k;
	res = min((k - mod) * solve(basis, k) + mod * solve(basis + 1, k), (k - 1) * solve(basis, k) + solve(basis + mod, k));
	return res + 1;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		cout << solve(n, k) <<'\n';
	}
}
