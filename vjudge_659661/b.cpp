#pragma GCC optimize(3)
#include <iostream>
#include <cstddef>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <ios>

using namespace std;

typedef unsigned long long int ull;

ull n2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int z;
    cin >> z;
    while (z--)
    {
        size_t n;
        cin >> n;
        map<ull, ull> a;
        for (size_t i = 0; i < n; i++)
        {
            long long tmp;
            cin >> tmp;
            a[tmp]++;
            // cout << i << '\n';
        }
        cout << "finish input" << endl;
        // sort(a.begin(), a.end());
        ull cnt(0);
        vector<pair<ull, ull>> b;
        b.reserve(n);
        for (auto &&i : a)
        {
            b.emplace_back(i.first, i.second);
        }
        cout << "finish process" << endl;
        for (auto &i : b)
        {
        }
        cout << cnt << '\n';
    }
}