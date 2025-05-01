/*************************************************************************
	> File Name: a.cpp
	> Author: Haoming Bai
	> Mail: haomingbai@hotmail.com
	> Created Time: 2024年06月30日 星期日 22时38分14秒
 ************************************************************************/

#include <cstdio>
#include <iostream>

using namespace std;

int t, n[10000], k[10000], r[10000];

int main()
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", n + i, k + i);
		r[i] = (n[i] - 1) * k[i] + 1;
	}
	for(int i=0;i<t;i++)
	{
		printf("%d\n",r[i]);
	}
}
