/*************************************************************************
    > File Name: h.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: Tue Aug  6 12:02:47 2024
 ************************************************************************/

#include <algorithm>
#include <cstdlib>
#include<iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		long long l, x, y, pivot;
		cin >> l >> x >> y;
		if (x > l / 2)
		{
			pivot = l;
			long long need_square = (x - pivot) * (x - pivot) + y * y;
			if (need_square > l * l) {
				cout << "No\n";
			} else {
				cout << "Yes\n" << pivot << '\n';
			}
		} else {
			pivot = 0;
			long long need_square  = x * x + y * y;
			if (need_square > l * l) {
				cout << "No\n";
			} else {
				cout << "Yes\n" << pivot << '\n';
			}
		}	
	}
}
