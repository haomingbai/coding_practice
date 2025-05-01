/*************************************************************************
    > File Name: g.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月05日 星期五 14时46分39秒
 ************************************************************************/

#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int a[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        long long sum = 0, n, a, b;
        char c;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> c;
            if (c == 'A')
                b = 0;
            else
                b = c - '0';
            sum += a * (b % 5);
            sum %= 5;
        }
            if (!sum)
        cout << "Yes" << '\n';
            else         cout << "No" << '\n';
    }
}
