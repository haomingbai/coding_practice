/*************************************************************************
	> File Name: b.cpp
	> Author: Haoming Bai
	> Mail: haomingbai@hotmail.com
	> Created Time: 2024年07月01日 星期一 11时45分31秒
 ************************************************************************/

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

char mem[40000], *str = mem;
int T, max_dis, res[101];

int solve(char* str, int m, int len, int already);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> max_dis;
		cin >> str;
		res[i] = solve(str, max_dis, strlen(str), 0);
		str += strlen(str);
	}
	for (int i = 0; i < T; i++) {
		cout << res[i] << '\n';
	}
}

inline int solve1(char* str, int m, int len, int already);
inline int solve2(char* str, int m, int len, int already);
inline int solve(char* str, int m, int len, int already)
{
	auto pt = str;
	int c = 0, l = 0;
	for (int i = 0; i < len / 2; i++) {
		c += abs(str[i] - str[len - 1 - i]);
		l++;
		if (c >= m) {
			break;
		}
	}
	/*
	if (len <= 2 * (c / 26)||len<=2*l)
		return l;
	return max({ l,already, solve(str, m, len - 1,l), solve(str + 1, m, len - 1,l) });
	*/
	for (int i = 0; i < len / 2 - 2 * l; i++) {
		c -= abs(str[i] - str[len - 1 - i]);
		c += abs(str[i + l] - str[len - 1 - (i + l)]);
		if (c >= m)
			continue;
		while (c < m) {
			c += abs(str[i + l + 1] - str[len - 1 - (i + l + 1)]);
			if (c < m)
				l++;
		}
	}
	if (len <= 2 * (c / 26) || len <= 2 * l)
		return l;
	return max({ l, already, solve2(str, m, len - 1, l), solve1(str + 1, m, len - 1, max(l,already)) });
}
inline int solve2(char* str, int m, int len, int already)
{
	auto pt = str;
	int c = 0, l = 0;
	for (int i = 0; i < len / 2; i++) {
		c += abs(str[i] - str[len - 1 - i]);
		l++;
		if (c >= m) {
			break;
		}
	}
	/*
	if (len <= 2 * (c / 26)||len<=2*l)
		return l;
	return max({ l,already, solve(str, m, len - 1,l), solve(str + 1, m, len - 1,l) });
	*/
	for (int i = 0; i < len / 2 - 2 * l; i++) {
		c -= abs(str[i] - str[len - 1 - i]);
		c += abs(str[i + l] - str[len - 1 - (i + l)]);
		if (c >= m)
			continue;
		while (c < m) {
			c += abs(str[i + l + 1] - str[len - 1 - (i + l + 1)]);
			if (c < m)
				l++;
		}
	}
	if (len <= 2 * (c / 26) || len <= 2 * l)
		return l;
	return max({ l, already, solve2(str, m, len - 1, max(l,already)) });
}
inline int solve1(char* str, int m, int len, int already)
{
	auto pt = str;
	int c = 0, l = 0;
	for (int i = 0; i < len / 2; i++) {
		c += abs(str[i] - str[len - 1 - i]);
		l++;
		if (c >= m) {
			break;
		}
	}
	/*
	if (len <= 2 * (c / 26)||len<=2*l)
		return l;
	return max({ l,already, solve(str, m, len - 1,l), solve(str + 1, m, len - 1,l) });
	*/
	for (int i = 0; i < len / 2 - 2 * l; i++) {
		c -= abs(str[i] - str[len - 1 - i]);
		c += abs(str[i + l] - str[len - 1 - (i + l)]);
		if (c >= m)
			continue;
		while (c < m) {
			c += abs(str[i + l + 1] - str[len - 1 - (i + l + 1)]);
			if (c < m)
				l++;
		}
	}
	if (len <= 2 * (c / 26) || len <= 2 * l)
		return l;
	return max({ l, already, solve1(str + 1, m, len - 1, max(l,already)) });
}
