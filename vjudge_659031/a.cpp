#include <ios>
#include <iostream>
#include <cstddef>
#include <cstdint>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        size_t n, m;
        cin >> n >> m;
        vector<ull> a(n), l(m), r(m), c(m);
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (size_t i = 0; i < m; i++)
        {
            cin >> l[i] >> r[i] >> c[i];
        }
    }
}