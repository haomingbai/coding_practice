/*************************************************************************
    > File Name: d.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: Tue Aug  6 13:27:28 2024
 ************************************************************************/

#include<iostream>
#include <map>

using namespace std;

long long a[200000];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		map<int, int> cnt[n];
		long long res = 0;
		bool flag[n];
		for (int i = 0; i < n; i++)
		{
			cnt[i][a[i]]++;
			flag[i] = 1;
		}
		if (k == 1)
		{
			res += n;
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				cnt[j][a[i]]++;
				if (flag[j] && cnt[j][a[i]] == k)
				{
					bool test = 1;
					for (auto it : cnt[j])
					{
						if (it.second != k)
						{
							test = 0;
						   	break;	
						}
					}
					if (test)
					{
						res++;
					}
				} 
				else if (flag[j] && cnt[j][a[i]] == k + 1)
				{
					flag[j] = 0;
				}
			}
		}
		cout << res << '\n';
	}
}
