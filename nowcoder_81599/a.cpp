/*************************************************************************
    > File Name: a.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月25日 星期四 12时02分37秒
 ************************************************************************/

#include<iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<set<int>> dat(n);
	for (int i = 0, u, v; i < m; i++)
	{
		cin >> u >> v;
		u--, v--;
		dat[u].insert(v);
	}
	int* up = new int[n]();
	for (int i = 0; i < n; i++)
	{
		int ubound = i;
		for (auto it : dat[i])
		{
			if (it != ubound + 1)
			{
				break;
			}
			ubound++;
		}
		up[i] = ubound;
	}
	long long cnt = 0;
	for (int i = n - 1, lbound = n - 1; i >=0; i--)
	{
		for (int j = lbound; j >= 0 && up[j] >= i; j--)
		{
			lbound--;
		}
		cnt += i - lbound;
	}
	cout << cnt << endl;
}
