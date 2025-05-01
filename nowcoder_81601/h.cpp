/*************************************************************************
    > File Name: h.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年08月01日 星期四 12时02分49秒
 ************************************************************************/

#include<iostream>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string dat;
		dat.reserve(1000000);
		cin >> dat;
		bool five_promotional = 0;
		int last_five = -1, cnt_three = 0;
		for (int i = 0; i < dat.length(); i++)
		{
			char it = dat[i];
			switch (it)
			{
				case '3':
					cnt_three++;
					if (cnt_three >= 10)
					{
						goto invalid;
					}
					if (i - last_five >= 90)
					{
						goto invalid;
					}
					break;
				case '4':
					cnt_three = 0;
					if (i - last_five >= 90)
					{
						goto invalid;
					}
					break;
				case '5':
					cnt_three = 0;
					// cout << last_five << endl;
					if (last_five == -1)
					{
						last_five = i;
						break;
					}
					if (dat[last_five] == '5')
					{
						goto invalid;
					}
					last_five = i;
					break;
				case 'U':
					cnt_three = 0;
					last_five = i;
					break;
			}
		}
valid:
		cout << "valid\n";
		continue;
invalid:
		cout << "invalid\n";
	}
}
