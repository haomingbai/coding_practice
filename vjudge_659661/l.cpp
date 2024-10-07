#include <iostream>
#include <cstddef>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

constexpr ull g = 1;

int main()
{
    size_t z;
    cin >> z;
    while (z--)
    {
        ull k, n; // g indicates golden
        cin >> n >> k;
        vector<ull> t(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> t[i];
        } 
        sort(t.begin(), t.end());
        ull t1(t.back()), t2(0);
        for (size_t i = 0; i < n - k; i++)
        {
            t2 += t[i];
        }
        cout << max(t1, t2) << '\n';
    }
    
}