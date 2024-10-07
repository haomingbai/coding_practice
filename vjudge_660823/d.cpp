#include <iostream>
#include <string>
#include <list>

typedef unsigned long long int ull;
typedef unsigned long long int ull;

using namespace std;

ull comb[3001][3001];
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
    ull sum(0);
    size_t t = n.size();
    for (size_t i = 0; i <= t; i++)
    {
        ull tmp = comb[t][i];
        tmp %= mod;
        tmp *= powc[i];
        tmp %= mod;
        sum += tmp;
        sum %= mod;
    }
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
        powc[i] = powc[i - 1] * c;
        powc[i] %= mod;
        comb[i][0] = 1;
        comb[i][i] = 1;
    }
    comb[0][0] = 1;
    for (size_t i = 2; i <= n_wait.length(); i++)
    {
        for (size_t j = 1; j < i; j++)
        {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            comb[i][j] %= mod;
        }
    }
    cout << calc(n, c) % mod << endl;
}