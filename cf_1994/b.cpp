/*************************************************************************
    > File Name: b.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月18日 星期四 23时01分03秒
 ************************************************************************/

#include <algorithm>
#include<iostream>

using namespace std;

signed main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int first_1 = -1, first_to0 = -1, first_to1 = -1, n;
		string s, t;
		cin >> n >> s >> t;
		if (s[0] == '0' && t[0] == '1')
		{
			cout << "NO" << '\n';
			continue;
		}
		else if (s[0] == '1')
		{
			cout << "YES" << '\n';
			continue;
		}
		for (int i = 0; i <= n; i++)
		{
			if (i == n)
			{
				cout << "YES" << '\n';
				break;
			}
			if (s[i] != t[i])
			{
				if (i >= find(s.begin(), s.end(), '1') - s.begin())
				{
					cout << "YES" << '\n';
				}
				else 
				{
					cout << "NO" << '\n'; 
				}
				break;
			}
		}
	}
}
