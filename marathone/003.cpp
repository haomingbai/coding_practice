#include <iostream>
#include <algorithm>

using namespace std;

long long calc(long long n, long long m)
{
    long long res(0);
    auto mi = min(n, m);
    for (long long i = 1; i <= mi; i++)
    {
        auto remain_n = n - i, remain_m = m - i;
        res += (remain_m + 1) * (remain_n + 1);
    }
    return res;
}

int main()
{
    long long n, m;
    cin >> n >> m;
    auto res = calc(n, m);
    auto total = 0ll;
    total += (n + 1) * n / 2;
    total *= (m + 1) * m / 2;
    cout << res << ' ' << total - res << endl;
}