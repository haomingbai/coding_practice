#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ull n, k, x, p;
    cin >> n >> k >> x >> p;
    ull *time_left = new ull[k + 1], *speed = new ull[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> speed[i];
    }
    for (size_t i = 1; i <= k; i++)
    {
        cin >> time_left[i];
    }
    for (size_t i = 1; i <= k; i++)
    {
        ull t;
        cin >> t;
        p = max(p, t - time_left[i]);
    }
    
    ull cnt(0);
    
    for (size_t i = 0; i < n; i++)
    {
        if (p * speed[i] >= x)
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
}