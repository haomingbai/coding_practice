/*************************************************************************
    > File Name: d.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月05日 星期五 14时01分57秒
 ************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    long long n, r = 1;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        r *= 2;
        r %= 998244353;
    }
    cout << r << endl;
}
