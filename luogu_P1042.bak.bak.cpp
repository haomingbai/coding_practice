/*************************************************************************
	> File Name: P1042.cpp
	> Author: Haoming Bai
	> Mail: haomingbai@hotmail.com
	> Created Time: 2024年01月28日 星期日 16时17分30秒
 ************************************************************************/

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ios>
#include <iostream>
#include <utility>
using namespace std;

char dat[2501 * 26];

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	char* tmp = dat;
	cin >> tmp;
	while (find(tmp, tmp + strlen(tmp), 'E') == tmp + strlen(tmp)) {
		tmp += strlen(tmp);
		cin >> tmp;
	}
	pair<long long, long long> sto { 0, 0 };
	tmp = dat;
	// cout << tmp << '\n';
	if (*tmp == 'E') {
		cout << "0:0\n\n0:0\n";
	}
	while (*tmp != 'E') {
		if (*(tmp) == 'W') {
			sto.first++;
		} else if (*tmp == 'L') {
			sto.second++;
		}
		tmp++;
		if ((sto.first >= 11 || sto.first >= 11) && (abs(sto.first - sto.second) >= 2)) {
			cout << sto.first << ':' << sto.second << '\n';
			sto.first = 0, sto.second = 0;
		}
	}
	if (sto.first || sto.second) {
		cout << sto.first << ':' << sto.second << '\n';
		sto.first = 0, sto.second = 0;
	}
	cout << '\n';
	tmp = dat;
	while (*tmp != 'E') {
		if (*(tmp) == 'W') {
			sto.first++;
		} else if (*tmp == 'L') {
			sto.second++;
		}
		tmp++;
		if ((sto.first >= 21 || sto.first >= 21) && (abs(sto.first - sto.second) >= 2)) {
			cout << sto.first << ':' << sto.second << '\n';
			sto.first = 0, sto.second = 0;
		}
	}
	if (sto.first || sto.second) {
		cout << sto.first << ':' << sto.second << '\n';
	}
}
