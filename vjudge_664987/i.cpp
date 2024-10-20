#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int check(int* a, int n)
{
    for (size_t i = 1; i < n; i++)
    {
        if (a[i] > i)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        auto a = new int [n + 1];
        for (size_t i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        vector<pair<int, int>> opt;
        opt.reserve(n / 2);
        int start;
        while (start = check(a, n))
        {
            int stop = n;
            for (size_t i = start; i <= n; i++)
            {
                if (a[i] < a[start])
                {
                    stop = i;
                }
            }
            sort(a + start, a + stop + 1);
            opt.push_back({start, stop});
        }
        cout << opt.size() << '\n';
        for (auto &&i : opt)
        {
            cout << i.first << ' ' << i.second << '\n';
        }
    }
}