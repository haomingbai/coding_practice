/*
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll fastpow(ll a, ll b, ll m);

int main()
{
    ll a, b, m;
    cin >> a >> b >> m;
    cout << fastpow(a, b, m) << endl;
}

ll fastpow(ll a, ll b, ll m)
{
    ll res(1);
    a %= m;
    while (b > 1)
    {
        if (b % 2)
        {
            res *= a;
            res %= m;
        }
        b /= 2;
        a *= a;
        a %= m;
    }
    res *= a;
    res %= m;
    return res;
}
*/

#include <stdio.h>

int main()
{
    unsigned long long a = 0,b = 0,m = 0;
    unsigned long long result = 1;
    scanf("%llu %llu %llu", &a ,&b, &m);
    a = a % m;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result = ((result % m) * (a % m)) % m;
        }
        b /=2;
        a = ((a % m) * (a % m)) % m;
    }
    printf("%llu\n",result);
    return 0;
}