/*************************************************************************
    > File Name: a.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月07日 星期日 22时35分19秒
 ************************************************************************/

#include <ios>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0, n; i < t; i++)
    {
		cin >> n;
		for(int j = 1; j < n; j++)
		{
			cout << j << ' ';
		}
		cout << '\n';
    }
}
