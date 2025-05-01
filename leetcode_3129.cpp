#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int solve(int, int, int);

int main()
{
    int zero, one, limit;
    cin >> zero >> one >> limit;
    cout << solve(zero, one, limit) << endl;
}

int solve(int zero, int one, int limit)
{
    const int mod = 1e9 + 7;
    int **sto = new int *[zero + 1];
    sto[0] = new int[(zero + 1) * (one + 1)]();
    for (auto i = 1; i <= zero; i++)
    {
        sto[i] = sto[i - 1] + one + 1;
    }
    // int base0 = min(limit, zero);
    // int base1 = min(limit, one);
    for (int i = 0; i <= zero; i++)
    {
        sto[i][0] = (i > limit) ? 0 : 1;
    }
    for (int j = 0; j <= one; j++)
    {
        sto[0][j] = (j > limit) ? 0 : 1;
    }
    for (int i = 1; i <= zero; i++)
    {
        for (int j = 1; j <= one; j++)
        {
            // cout << sto[i][j - 1] << endl;
            // cout << sto[i - 1][j] << endl;
            sto[i][j] += sto[i][j - 1];
            sto[i][j] += sto[i - 1][j];
            sto[i][j] %= mod;
            // if (i > limit)
            // {
            //     sto[i][j] -= sto[i - limit - 1][j - 1];
            // }
            // if (j > limit)
            // {
            //     sto[i][j] -= sto[i - 1][j - limit -1];
            // }
            if (i > limit)
            {
                int zero_tmp = i - 1;
                int one_tmp = j;
                int flag = -1;
                do
                {
                    if (flag == -1)
                    {
                        zero_tmp -= limit;
                        one_tmp--;
                    }
                    else
                    {
                        zero_tmp--;
                        one_tmp -= limit;
                    }
                    if (zero_tmp >= 0 && one_tmp >= 0)
                    {
                        sto[i][j] += flag * (sto[zero_tmp][one_tmp]);
                        sto[i][j] %= mod;
                    }
                    flag = -flag;
                } while (zero_tmp > 0 && one_tmp > 0);
                if ((zero_tmp == 0 && one_tmp == limit) || (zero_tmp == limit && one_tmp == 0))
                {
                    sto[i][j] += flag;
                }
            }
            if (j > limit)
            {
                int zero_tmp = i;
                int one_tmp = j - 1;
                int flag = -1;
                do
                {
                    if (flag == -1)
                    {
                        one_tmp -= limit;
                        zero_tmp--;
                    }
                    else
                    {
                        one_tmp--;
                        zero_tmp -= limit;
                    }
                    if (zero_tmp >= 0 && one_tmp >= 0)
                    {
                        sto[i][j] += flag * (sto[zero_tmp][one_tmp]);
                        sto[i][j] %= mod;
                    }
                    flag = -flag;
                } while (zero_tmp > 0 && one_tmp > 0);
                if ((zero_tmp == 0 && one_tmp == limit) || (zero_tmp == limit && one_tmp == 0))
                {
                    sto[i][j] += flag;
                }
                
            }
            sto[i][j] %= mod;
            // cout << i << ' ' << j << ' ' << sto[i][j] << endl;
        }
    }
    int res = sto[zero][one];
    delete[] sto[0];
    delete[] sto;
    return res;
    // return sto[zero][one];
}