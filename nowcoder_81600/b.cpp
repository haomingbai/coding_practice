/*************************************************************************
    > File Name: a.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月30日 星期二 12时06分07秒
 ************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int T;
	cin >> T;
    while (T--)
    {
        long long n, m, a, b;
        cin >> n >> m >> a >> b;
        if (a && b)
        {
            if (n % 2 == 0 || m % 2 == 0)
            {
                goto yes;
            }
            else
            {
                goto no;
            }
        }
		if (a == 0 && b == 0)
		{
			if ((m == 1 && n == 2) || (m == 2 && n == 1))
			{
				goto yes;
			}
			goto no;
		}
		if (a)
		{
			if ((m == 1 && n % 2 == 0) || (m % 2 == 0 && n == 1))
			{
				goto yes;
			}
			goto no;
		}
		if (b)
		{
			if ((m % 3 == 0 && n % 2 == 0) || (m % 2 == 0 && n % 3 == 0))
			{
				goto yes;
			}
			if (m % 2 == 0 && n % 2 == 0)
			{
				goto yes;
			}
			if (m == 2 || n == 2)
			{
				goto yes;
			}
			if ((m % 2 == 0 && n >= 3) || (m >= 3 && n % 2 == 0))
			{
				goto yes;
			}
			goto no;
		}
    yes:
        cout << "Yes\n";
        continue;
    no:
        cout << "No\n";
    }
}
