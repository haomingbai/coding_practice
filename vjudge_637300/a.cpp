/*************************************************************************
	> File Name: a.cpp
	> Author: Haoming Bai
	> Mail: haomingbai@hotmail.com
	> Created Time: 2024年07月02日 星期二 10时06分01秒
 ************************************************************************/

#include <cstring>
#include <ios>
#include <iostream>

using namespace std;

#define numberlize(n) ((n) - 'a')

unsigned long long N, k, len, sto[10];
char S[1000001];
int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> N;
	for (unsigned long long i = 0, *calc, first_found, number_of_distinct; i < N; i++) {
		cin >> S >> k;
		len = strlen(S);
		if (k > len) {
			sto[i] = 0;
			continue;
		}
		first_found = 0;
		number_of_distinct = 0;
		calc = new unsigned long long[26]();
		for (unsigned long long j = 0, pt = 0; j < len - k + 1; j++) {
			if (j != 0) {
				calc[numberlize(S[j - 1])]--;
				if (calc[numberlize(S[j - 1])] == 0)
					number_of_distinct--;
			}
			while (number_of_distinct < k && pt < len) {
				if (!calc[numberlize(S[pt])]) {
					number_of_distinct++;
				}
				calc[numberlize(S[pt++])]++;
			}
			if (number_of_distinct == k) {
				sto[i] += len - pt + 1;
			}
		}
	}
	for (unsigned long long i = 0; i < N; i++) {
		cout << sto[i] << '\n';
	}
}
