#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll n, b, c, k, rem;
        cin >> n >> b >> c;

        if (b == 0)
        {
            if (c >= n)
            {
                cout << n << endl;
            }
            else if (c == n - 1)
            {
                cout << n - 1 << endl;
            }
            else if (c == n - 2)
            {
                cout << n - 1 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
            continue;
        }

        if (c >= n)
        {
            k = -1, rem = n;
        }
        else
        {
            k = (n - 1 - c) / b;
            rem = n - k - 1;
        }
        cout << rem << endl;
    }
}