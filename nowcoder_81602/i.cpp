/*************************************************************************
    > File Name: i.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: Tue Aug  6 12:33:20 2024
 ************************************************************************/

#include<iostream>

using namespace std;

template <typename T1, typename T2> inline auto up_div(T1 x, T2 y) -> decltype(T1{} / T2{})
{
	return x % y ? (x / y + 1) : (x / y);
}
template <typename T1, typename T2> inline auto new_div(T1 x, T2 y) -> decltype(T1{} / T2{})
{
	return x % y ? (x / y) : (x / y + 1);
}


int main() {
	int T;
	cin >> T;
	while (T--)
	{
		long long m, k, h, x;
		cin >> m >> k >> h;
		if (k == m) {
			cout << m << endl;
			continue;
		} else if (m - k == 1) {
			x = h / (k + 2);
		} else {
			x = h / (2 + (k / (m - k - 1)));
		}
		while (x + k * ((x - m) / (m - k) + 1) < h) {
			x++;
		}
		cout << x << endl;
	}
}
