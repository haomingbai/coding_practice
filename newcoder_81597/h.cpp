/*************************************************************************
    > File Name: h.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月18日 星期四 18时47分09秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define int long long

template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &a, const pair<T1, T2> &b)
{
    pair<T1, T2> res;
    res.first = a.first + b.first;
    res.second = a.second + b.second;
    return res;
}

map<pair<int, int>, vector<int>> mp;

signed main()
{
    int n, x, y;
    string str;
    cin >> n >> x >> y >> str;
    pair<int, int> current;
    if (x == 0 && y == 0)
    {
        cout << (n * n + n) / 2 << endl;
		return 0;
    }
    for (int i = 0; i < n; i++)
    {
        switch (str[i])
        {
        case 'W':
            current.second++;
            break;
        case 'S':
            current.second--;
            break;
        case 'A':
            current.first--;
            break;
        case 'D':
            current.first++;
            break;
        }
        mp[current].push_back(i + 1);
    }
    current = {0, 0};
    int res(0);
    for (int i = 0; i < n; i++)
    {
        // int tmp = mp[current + make_pair(x, y)];
        if (!mp[current + make_pair(x, y)].empty())
        {
            int tmp = -1;
            for (auto it : mp[current + make_pair(x, y)])
            {
                if (it > i)
                {
                    tmp = it;
                    break;
                }
            }
            if (tmp != -1)
                res += n - tmp + 1;
            // cout << n - tmp + 1 << endl;
            // cout << (current).first << ' ' << (current).second << endl;
        }
        switch (str[i])
        {
        case 'W':
            current.second++;
            break;
        case 'S':
            current.second--;
            break;
        case 'A':
            current.first--;
            break;
        case 'D':
            current.first++;
            break;
        }
    }
    cout << res << endl;
    return 0;
}
