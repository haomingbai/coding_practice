/*************************************************************************
	> File Name: a.cpp
	> Author: Haoming Bai
	> Mail: haomingbai@hotmail.com
	> Created Time: 2024年07月01日 星期一 16时33分33秒
 ************************************************************************/

#include <cmath>
#include <ios>
#include <iostream>

using namespace std;
unsigned long long M, a, b, c, T, k, y, sto[500000];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> M >> a >> b >> c;
	cin >> T;
	auto calc = [=](unsigned long long x) -> unsigned long long {
		unsigned long long remainx = x % M, remaina = a % M, remainb = b % M, remainc = c % M;
		unsigned long long res = (remaina * remainx * remainx + remainb * remainx + remainc) % M + x / 2;
		return res;
	};
	auto dp = new unsigned long long*[61];
	for (unsigned long long i = 0; i < 61; i++) {
		dp[i] = new unsigned long long[2 * M - 1];
	}
	for (unsigned long long i = 0; i < 2 * M - 1; i++) {
		dp[0][i] = calc(i);
	}
	for (unsigned long long i = 1; i < 61; i++) {
		for (unsigned long long j = 0; j < 2 * M - 1; j++) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
	for (unsigned long long i = 0, tmp; i < T; i++) {
		cin >> k >> y;
		while (k > 2 * M - 2 && y > 0) {
			y--;
			k = calc(k);
		}
		if (y == 0) {
			sto[i] = k;
			continue;
		}
		tmp = 0;
		while (y != 0) {
			// cout << k << ' ' << y << '\n';
			if (y % 2) {
				k = dp[tmp][k];
			}
			tmp++;
			y >>= 1;
		}
		sto[i] = k;
	}
	for (unsigned long long i = 0; i < T; i++) {
		cout << sto[i] << '\n';
	}
}
