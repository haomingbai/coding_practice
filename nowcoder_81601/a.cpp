/*************************************************************************
    > File Name: a.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年08月01日 星期四 12时56分24秒
 ************************************************************************/

#include<iostream>
#include <utility>
#include <vector>

typedef long long ll;

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<pair<int,bool>> *a = new vector<pair<int, bool>> [n];
		for (int i = 0; i < n - 1; i++)
		{
			int x, y, k;
			cin >> x >> y >> k;
			x--, y--;
			(a + x)->push_back({y, k});
		}
	}
}
