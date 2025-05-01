/*************************************************************************
  > File Name: c.cpp
  > Author: Haoming Bai
  > Mail: haomingbai@hotmail.com
  > Created Time: 2024年06月30日 星期日 23时18分19秒
 ************************************************************************/

#include <algorithm>
#include <cstdio>

// long long int t, mem[200000], n, *h = mem, res[20000], time;

/*
 * int main()
{
	scanf("%lld", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%lld", &n);
		for (long long int j = 0; j < n - 1; j++)
		{
			scanf("%lld", h + j);
		}
		scanf("%lld", h + n - 1);
		// res[t] = *(h + n - 1);
		for (long long int j = 0, tmp = 0; j < n - 1; j++)
		{
			if (h[j] > h[j + 1] && tmp == 0)
			{
				res[i] += h[j];
				tmp = 1;
				// printf("%d %d\n", j,res[i]);
			} else if (h[j] < h[j + 1])
			{
				res[i] += h[j];
				tmp = 0;
				// printf("%d %d\n", j,res[i]);
			}
			if (j < n - 2)
			{
				if (h[j] == h[j + 1] && h[j + 1] <= h[j + 2])
				{
					res[i]++;
				}
			}
		}
		if (h[n - 1] >= h[n - 2])
		{
			res[i] += h[n - 1];
			// printf("%d\n", res[i]);
		}
		h += n;
	}
	for (int i = 0; i < t; i++)
	{
		printf("%lld\n", res[i]);
	}
}
*/

/*

long long int t, mem[200000], n, *h = mem, res[20000], time;

int main()
{
	scanf("%lld", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%lld", &n);
		for (int j = 0; j < n; j++)
		{
			scanf("%lld", h + j);
		}
		res[i] = h[n - 1];
		for (long long int j = 1, minh = 0, time = 0, maxh=0; j < n; j++)
		{
			// h[n-1-j] is the value of the j_th h from right to left.
			if (h[n - 1 - j] > h[n - j])
			{
				// res[i] += h[n - 1 - j] - h[n - j];
				if (h[n - 1 - j] - maxh >= time)
				{
					res[i] += h[n - 1 - j] - maxh - time;
				}
			} else
			{
				res[i] += (h[n - j] - h[n - j - 1] + 1);
				maxh = std::max(maxh,h[n-j]);
				time += h[n - j] - h[n - j - 1] + 1;
			}
		}
		// res[i]--;
		h += n;
	}
	for (int i = 0; i < t; i++)
	{
		printf("%lld\n", res[i]);
	}
}

*/

#include <ios>
#include <iostream>
#include <vector>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

void solve()
{
	int n;
	cin >> n;

	vector<int> h(n);
	for (auto &x : h)
		cin >> x;

	int ans = h[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		ans = max(ans + 1, h[i]);
	}

	cout << ans << nl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
