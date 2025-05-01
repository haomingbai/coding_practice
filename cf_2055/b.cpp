#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        size_t n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (auto &i : a)
        {
            cin >> i;
        }
        for (auto &i : b)
        {
            cin >> i;
        }

        ll cnt = 0, m = 1e15;
        size_t pos;
        for (size_t i = 0; i < n; i++)
        {
            if (a[i] < b[i])
            {
                cnt++;
                pos = i;
            }
            else
            {
                m = min(m, a[i] - b[i]);
            }
        }

        // cout << cnt << m << endl;
        switch (cnt)
        {
        case 0:
            cout << "YES\n";
            break;

        case 1:
            if (m >= (b[pos] - a[pos]))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            break;

        default:
            cout << "NO\n";
            break;
        }
    }
}