/*************************************************************************
    > File Name: h.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月06日 星期六 11时27分41秒
 ************************************************************************/

#include <cstdlib>
#include <ios>
#include <iostream>

using namespace std;

long long I[10001][1001], K[1001][1001], V[1001][1001], T, R[1001][1001];
// Use matrix V to store the original data with signs.

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k, l, p, q;
    cin >> n >> m >> k >> l;
    p = n - k + 1, q = m - l + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> I[i][j];
            if (j < q)
            {
                R[i][0] += I[i][j];
            }
            else
            {
                R[i][j + 1 - q] = R[i][j - q];
                R[i][j + 1 - q] += I[i][j];
                R[i][j + 1 - q] -= I[i][j - q];
            }
        }
        if (i < p)
        {
            for (int j = 0; j < l; j++)
            {
                V[0][j] += R[i][j];
            }
        }
        else
        {
            for (int j = 0; j < l; j++)
            {
                V[i + 1 - p][j] = V[i - p][j];
                V[i + 1 - p][j] += R[i][j];
                V[i + 1 - p][j] -= R[i - p][j];
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            T += abs(V[i][j]);
        }
    }
    cout << T << '\n';
}
