/*************************************************************************
	> File Name: P1042.cpp
	> Author: Haoming Bai
	> Mail: haomingbai@hotmail.com
	> Created Time: 2024年01月28日 星期日 16时17分30秒
 ************************************************************************/

#include <cstdio>
#include <list>
#include <utility>
using namespace std;

int main()
{
	list<pair<long long, long long>> sto_11, sto_21;
	char fetch;
	fetch = getchar();
	if (fetch == 'E') {
		printf("0:0\n\n0:0\n");
		return 0;
	}
	sto_11.push_back({ 0, 0 });
	sto_21.push_back({ 0, 0 });
	if (fetch == 'W') {
		sto_11.back().first++;
		sto_21.back().first++;
	} else if (fetch == 'L') {
		sto_11.back().second++;
		sto_21.back().second++;
	}
	while (fetch != 'E') {
		fetch = getchar();
		if (fetch == 'W') {
			sto_11.back().first++;
			sto_21.back().first++;
			if ((sto_11.back().first >= 11) && (sto_11.back().first - sto_11.back().second >= 2)) {
				sto_11.push_back({ 0, 0 });
			}
			if ((sto_21.back().first >= 21) && (sto_21.back().first - sto_21.back().second >= 2)) {
				sto_21.push_back({ 0, 0 });
			}
		} else if (fetch == 'L') {
			sto_11.back().second++;
			sto_21.back().second++;
			if ((sto_11.back().second >= 11) && (sto_11.back().first - sto_11.back().second <= -2)) {
				sto_11.push_back({ 0, 0 });
			}
			if ((sto_21.back().second >= 21) && (sto_21.back().first - sto_21.back().second <= -2)) {
				sto_21.push_back({ 0, 0 });
			}
		}
	}
	for (auto it : sto_11) {
		printf("%lld:%lld\n", it.first, it.second);
	}
	printf("\n");
	for (auto it : sto_21) {
		printf("%lld:%lld\n", it.first, it.second);
	}
	return 0;
}
