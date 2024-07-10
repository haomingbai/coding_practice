/*************************************************************************
    > File Name: b.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月09日 星期二 12时39分48秒
 ************************************************************************/

#include <cstddef>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    long long power;
    long long assistance;
    // Make sure that the power of assistant is from beginning to end greater than zero such that we do not need to
    // process the input data.
    vector<size_t> requirement;
    // The requirement of a power plant.
    bool masked = 0;
    // True value of mask means that is has been entered the assistant mode.
};

Node dat[300000];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n;
    for (int i = 0; i < 3 * n; i++)
    {
        cin >> dat[i].power;
    }
    for (int i = 0; i < 3 * n; i++)
    {
        cin >> dat[i].assistance;
    }
    cin >> m;
    for (int i = 0, a, b; i < m; i++)
    {
        cin >> a >> b;
        a--, b--;
        dat[a].requirement.push_back(b);
    }
    long long res = 0;
    for (int i = 2 * n; i < 3 * n; i++)
	{
		if (dat[i].assistance == 0)
		{
			res += dat[i].power;
			dat[i].masked = 1;
		}
	}
    for (int i = 0; i < n; i++)
    {
        long long actual = dat[i].power;
        for (auto it : dat[i].requirement)
        {
            if (!dat[it].masked)
            {
                actual -= dat[it].assistance;
                actual -= dat[it].power;
                for (auto iter : dat[it].requirement)
                {
                    actual += dat[iter].power;
                    actual += dat[iter].assistance;
                }
            }
        }
        if (actual)
        {
            res += dat[i].power;
            for (auto it : dat[i].requirement)
            {
                dat[it].masked = 1;
            }
        }
    }
    for (int i = n; i < 2 * n; i++)
    {
        if (dat[i].masked)
        {
            res -= dat[i].assistance;
            continue;
        }
        long long actual = dat[i].power, give_up = 0;
        for (auto it : dat[i].requirement)
        {
            if (!dat[it].masked)
            {
                actual -= dat[it].assistance;
                give_up += dat[it].power;
            }
        }
        if (actual > give_up)
        {
            res += dat[i].power;
            for (auto it : dat[i].requirement)
            {
                dat[it].masked = 1;
            }
        }
    }
    for (int i = 2 * n; i < 3 * n; i++)
    {
        if (dat[i].masked)
        {
            res -= dat[i].assistance;
            continue;
        }
        res += dat[i].power;
    }
    cout << res << '\n';
}
