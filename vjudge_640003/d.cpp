/*************************************************************************
    > File Name: d.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月11日 星期四 16时22分05秒
 ************************************************************************/

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;

#define int unsigned long long

int dat[15003], path_left[5001][10001], path_right[5001][10001], path[5001][10001], *a = dat + 5000;

int32_t main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // cout << a[i] << ' ';
    }
    for (int i = 1; i <= n; i++)
    {
        path[i][0] = path_left[i][0] = path_right[i][0] = a[i];
        for (int j = 1; j <= i - 1; j++)
        {
            path_left[i][j] = path_left[i][j - 1] + a[i - j];
        }
        for (int j = 1; j <= n - i; j++)
        {
            path_right[i][j] = path_right[i][j - 1] + a[i + j];
        }
        for (int j = i; j <= 2 * (i - 1); j++)
        {
            path_left[i][j] = path_left[i][j - 1];
        }
        for (int j = n - i + 1; j <= 2 * (n - i); j++)
        {
            path_right[i][j] = path_right[i][j - 1];
            // cout << path_right[i][j] << ' '<< i<<endl;
        }
        for (int j = 2 * i - 1; j <= 2 * (i - 1) + (n - i); j++)
        {
            path_left[i][j] = path_left[i][j - 1] + a[i + (j - 2 * (i - 1))];
        }
        for (int j = 2 * (n - i) + 1; j <= (i - 1) + 2 * (n - i); j++)
        {
            path_right[i][j] = path_right[i][j - 1] + a[i - (j - 2 * (n - i))];
        }
        for (int j = 2 * (i - 1) + (n - i) + 1; j <= 2 * n; j++)
        {
            path_left[i][j] = path_left[i][j - 1];
        }
        for (int j = (i - 1) + 2 * (n - i) + 1; j <= 2 * n; j++)
        {
            path_right[i][j] = path_right[i][j - 1];
        }
        for (int j = 1; j <= 2 * n; j++)
        {
            path[i][j] = max(path_left[i][j], path_right[i][j]);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= 2 * n; j++)
        {
            cout << setw(3) << path_right[i][j];
            tmp ^= (j * path[i][j]);
        }
        cout << endl;
        tmp += i;
        res ^= tmp;
    }
    cout << res << '\n';
}
