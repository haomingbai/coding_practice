/*************************************************************************
	> File Name: c.cpp
	> Author: Haoming Bai
	> Mail: haomingbai@hotmail.com
	> Created Time: 2024年07月02日 星期二 15时01分53秒
 ************************************************************************/

#include <ios>
#include <iostream>

using namespace std;

unsigned long long dat[100000], calc[100001], res[50], n, m, *pt;
unsigned long long pros(unsigned long long* pt, unsigned long long len);

int main()
{
	ios::sync_with_stdio(false), cin.tie(), cout.tie();
	unsigned long long T;
	cin >> T;
	for (unsigned long long i = 0; i < T; i++) {
		cin >> n >> m;
		pt = dat;
		for (unsigned long long j = 0, flag = 1; j <= n; j++) {
			// cout << "loop\n";
			if (j < n)
				cin >> dat[j];
			if (j == 0 && dat[j] >= m) {
				flag = 0;
			}
			if ((j == n) && flag == 1) {
				flag = 0;
				res[i] += pros(pt, dat + j - pt);
			} else if ((dat[j] >= m) && flag == 1) {
				flag = 0;
				res[i] += pros(pt, dat + j - pt);
			} else if (dat[j] < m && flag == 0) {
				flag = 1;
				pt = dat + j;
			}
		}
	}
	for (unsigned long long i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": " << res[i] << '\n';
	}
}

unsigned long long func(unsigned long long* pt, unsigned long long i, unsigned long long j)
{
	unsigned long long r = 0;
	for (unsigned long long x = i; x <= j; x++) {
		r |= pt[x];
	}
	return r;
}

unsigned long long pros(unsigned long long* pt, unsigned long long len)
{
	unsigned long long r = len;
	for (unsigned long long i = 0; i < len - 1; i++) {
		for (unsigned long long j = i + 1; j < len; j++) {
			if (func(pt, i, j) >= m) {
				break;
			}
			r++;
		}
	}
	return r;
}
