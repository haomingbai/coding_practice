/*************************************************************************
    > File Name: e.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月09日 星期二 13时34分01秒
 ************************************************************************/

#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

struct lst
{
    long long dat[20] = {};
    long long sum[20] = {};
    constexpr lst()
    {
        dat[0] = 1;
        sum[0] = 1;
        for (long long i = 1; i < 20; i++)
        {
            dat[i] = dat[i - 1] * 2 + 1;
            sum[i] = sum[i - 1] + dat[i];
        }
    }
};

int st(int n)
{
    int cnt = 0;
    while (n != 0)
    {
        if (n % 2 != 0)
        {
            cnt++;
        }
        n /= 2;
    }
    return cnt;
}

char str[100001], sto[21];

int main()
{
    long long T;
    cin >> T;
    while (T--)
    {
        long long n, k, m = 0;
        cin >> n >> k >> str;
        for (long long i = 0; i < n; i++)
        {
            m += str[i] - '0';
        }
        long long s = -1;
        for (long long i = 0; i < k; i++)
        {
            long long tmpm = (m + i);
            tmpm %= (long long)(pow(2, k));
            if (i == st(tmpm))
            {
                s = tmpm;
                break;
            }
        }
        if (s == -1)
        {
            cout << "None" << endl;
        }
        else
        {
            sto[k] = 0;
            for (int i = k - 1; i >= 0; i--)
            {
                sto[i] = (s % 2) ? '1' : '0';
                s /= 2;
            }
            cout << sto << endl;
        }
    }
}
