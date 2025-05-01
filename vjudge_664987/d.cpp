#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int withdraw(int a)
{
    if (a)
    {
        return max(a % 10, withdraw(a / 10));
    }
    else
    {
        return 0;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll la, ra, lb, rb;
        cin >> la >> ra >> lb >> rb;
        if (ra + rb - (la + lb) >= 9)
        {
            cout << 9 << endl;
        }
        else
        {
            int x = la + lb, r = 0;
            r = withdraw(x);
            for (size_t i = 0; i < rb - lb; i++)
            {
                x++;
                r = max(r, withdraw(x));
            }
            for (size_t i = 0; i < ra - la; i++)
            {
                x++;
                r = max(r, withdraw(x));
            }
            cout << r << endl;
        }
        
    }
    
}