#include <iostream>
#include <list>

typedef unsigned long long int ull;
typedef unsigned long long int ull;

using namespace std;

ull powc[3001];
const ull mod = 1e9 + 7;

ull calc(list<bool> &n, ull c)
{
    if (n.empty())
    {
        return 1;
    }
    if (!n.front())
    {
        n.pop_front();
        return calc(n, c);
    }
    n.pop_front();
    size_t t = n.size();
    ull sum(powc[t]);
    return (sum + (c * (calc(n, c) % mod)) % mod) % mod;
}

int main()
{
    string n_wait;
    ull c;
    cin >> n_wait >> c;
    list<bool> n;
    for (auto &&i : n_wait)
    {
        n.push_back(i == '1');
    }
    powc[0] = 1;
    for (size_t i = 1; i <= n_wait.length(); i++)
    {
        powc[i] = powc[i - 1] * (c + 1);
        powc[i] %= mod;
    }
    cout << calc(n, c) % mod << endl;
}