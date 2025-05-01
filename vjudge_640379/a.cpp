/*************************************************************************
    > File Name: a.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月13日 星期六 18时58分27秒
 ************************************************************************/

#include <ios>
#include <iostream>

typedef long long ll;

using namespace std;

ll arr[2000000], ori[4][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    ll **mat = new ll *[n];
    for (int i = 0; i < n; i++)
    {
        mat[i] = arr + n * i;
    }
    /*
    for (int i = 0; i < n; i++)
    {
        bool flag0 = (i & 1), flag1 = !(i & 1);
        for (int j = 0; j < n; j++) // j * n + k is the position of mat[j][k]
        {
            for (int k = 0; k < n; k++)
            {
                switch (mat[i][j] & 1)
                {
                case 1:
                    mat[j][k] <<= 1;
                    mat[j][k] += flag0;
                    flag0 = !flag0;
                    break;
                case 0:
                    mat[j][k] <<= 1;
                    mat[j][k] += flag1;
                    flag1 = !flag1;
                    break;
                }
            }
        }
    }
    */
	ll odd = 1, even = 0;
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
			mat[j][k] = (j & 1) ? (odd) : (even);
			(j & 1) ? (odd += 2) : (even += 2);
            // mat[j][k] = (j + 1) * (k + 1) - 1;
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            cout << mat[j][k] << ' ';
        }
        cout << '\n';
    }
}
