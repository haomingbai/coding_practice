#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll n, m, v;
        cin >> n >> m >> v;
        auto a = new ll[n];
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int pos = 0, least = n;
        for (int i = 0, vol = 0, tmpl = 0; i < n; i++)
        {
            tmpl++;
            vol += a[i];
            if (vol >= v)
            {
                least = min(least, tmpl);
                pos = i - tmpl + 1;
                vol = 0;
                tmpl = 0;
            }
        }
        
        delete[] a;
    }
}