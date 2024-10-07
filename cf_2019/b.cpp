#include <iostream>
#include <algorithm>
#include <vector>
#include <cstddef>
#include <cstdint>
#include <ios>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
    {
        ull n, q;
        cin >> n >> q;
        vector <ull> dat;
        dat.resize(n);
        for (auto &it : dat)
        {
            cin >> it;
        }
        ull it;
        for (size_t i = 0; i < q; i++)
        {
            cin >> it;
            ull cnt(0);
            for (size_t i = 0; i <= n / 2; i++)
            {
                // cout << i << endl;
                if ((i + 1) * (n - i) == it + 1)
                {
                    if (i == n / 2 || (!(n % 2) && i == n / 2 - 1))
                    {
                        cnt++;
                    }
                    else
                    {
                        cnt += 2;
                    }
                }
                if (i != 0 && i * (n - i) == it)
                {
                    if (!(n % 2) && i == n / 2)
                    {
                        cnt += (dat[i] - dat[i - 1] - 1);
                    }
                    else
                    {
                        cnt += (dat[i] - dat[i - 1] - 1) + (dat[n - i] - dat[n - i - 1] - 1);
                    }
                    break;
                }
            }
            cout << cnt << ' ';
        }
        cout << '\n';
    }
}