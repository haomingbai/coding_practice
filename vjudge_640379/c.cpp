/*************************************************************************
    > File Name: c.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月15日 星期一 16时58分57秒
 ************************************************************************/

#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

int fs(int from, int where, int (*path)[200000], int *cnt)
{
    if (cnt[where] == 1)
    {
		// cout << where << endl;
        return 1;
    }
    int res = 0;
    for (int i = 0; i < cnt[where]; i++)
    {
        if (path[where][i] != from)
        {
            res = max(res, fs(where, path[where][i], path, cnt));
        }
    }
	// cout << where << endl;
    res++;
    return res;
}

int main()
{
    int n;
    cin >> n;
    auto dat = new int[n][2]();       // 0 is the max length and 1 means the second longest
    auto path = new int[n][200000](); // record the dest of path
    auto path_cnt = new int[n];
    for (int i = 0; i < n - 1; i++)
    {
        int p, q;
        cin >> p >> q;
        p--, q--;
        path[p][path_cnt[p]] = q, path[q][path_cnt[q]] = p;
        path_cnt[p]++, path_cnt[q]++;
    }
    int start = 0, last = -1, cnt = 0;
    while (path_cnt[start] <= 1)
    {
        start = path[start][0];
        cnt++;
        // cout << last << endl;
    }
    vector<int> r;
	if (cnt)
	{
		r.push_back(cnt);
	}
    for (int i = 0; i < path_cnt[start]; i++)
    {
        if (path[start][i] != last)
        {
            r.push_back(fs(start, path[start][i], path, path_cnt));
        }
    }
	cout << r.size() << endl;
    sort(r.rbegin(), r.rend());
	// cout << r[0] << r[1] << cnt << endl;
    cout << r[0] + r[1] << '\n';
}
