/*************************************************************************
    > File Name: a.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com
    > Created Time: 2024年07月09日 星期二 12时08分15秒
 ************************************************************************/

#include <cmath>
#include <iostream>

using namespace std;

inline unsigned long long process(unsigned long long x)
{
    unsigned long long root = sqrt(x);
    return root * root;
}

int main()
{
    unsigned long long x, k, res(0);
    cin >> x >> k;
    if (x == 1)
    {
        cout << 1 << '\n';
        return 0;
    }
    res = k + 1;
    for (unsigned long long i = 0; i < k; i++)
    {
        if (process(x) != x && process(x) != 1)
        {
            res += k - 1 - i;
        }
        x = sqrt(x);
		// cout << res << endl;
        res++;
        if (x == 1)
        {
            break;
        }
    }
    cout << res << '\n';
    return 0;
}
