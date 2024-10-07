#include <iostream>
#include <algorithm>
#include <vector>
#include <cstddef>
#include <cstdint>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int main()
{
    int t; 
    cin >> t;
    while (t--)
    {
        ull n, q;
        cin >> n >> q;
        vector <ull> dat, query;
        dat.resize(n);
        query.resize(q);
        for (auto &it : dat)
        {
            cin >> it;
        }
        for (auto &it : query)
        {
            cin >> it;
            ull cnt(0);
            for (size_t i = 0; i < n; i++)
            {
                if ((i + 1) * (n - i) == it + 1)
                {
                    cnt++;
                }
                if (i != 0 && i * (n - i) == it)
                {
                    cnt += (dat[i] - dat[i - 1] - 1);
                }
            }
            cout << cnt << ' ';
        }
        cout << '\n';
    }
}