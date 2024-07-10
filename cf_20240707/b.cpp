/*************************************************************************
    > File Name: b.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月07日 星期日 22时46分27秒
 ************************************************************************/

#include <cstdio>
#include <iostream>

using namespace std;

bool res[10000];

int main()
{
    int t;
    cin >> t;
    for (int i = 0, m, n, **dat, tmp; i < t; i++)
    {
        cin >> m >> n;
        dat = new int *[m];
        *dat = new int[m * n];
        for (int j = 1; j < m; j++)
        {
            dat[j] = dat[j - 1] + n;
        }
		getchar();
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
				dat[j][k] = getchar() - '0';
            }
			getchar();
        }
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
				tmp = getchar() - '0';
                dat[j][k] = dat[j][k] < tmp ? dat[j][k] - tmp : dat[j][k] - tmp + 3;
            }
			getchar();
        }
        for (int j = 0; j < m; j++)
        {
            for (int k = 0, indexa = -1, indexb = -1; k < n; k++)
            {
                if (dat[j][k] == 0)
                {
                    continue;
                }
                else
                {
                    if (indexa == -1 && indexb == -1)
                    {
                        indexa = i, indexb = j;
                    }
                    else
                    {
                        if (dat[indexa][indexb] != dat[j][k])
                        {
                            continue;
                        }
                        else if (dat[indexa][k] != dat[j][indexb])
                        {
                            goto retrieve_memory;
                        }
						else
						{
							dat[indexa][indexb] = 0;
							dat[indexa][k] = 0;
							dat[j][indexb] = 0;
							dat[j][j] = 0;
							indexa = indexb = -1;
						}
                    }
                }
            }
        }
        res[i] = 1;
    retrieve_memory:
        delete[] dat[0];
        delete[] dat;
    }
    for (int i = 0; i < t; i++)
    {
        cout << (res[i] ? "YES" : "NO") << '\n';
    }
}
/*
 */
