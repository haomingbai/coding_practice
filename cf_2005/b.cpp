#include <iostream>
#include <algorithm>
#include <cstdint>
#include <ios>

using namespace std;

void solve(uint64_t n, uint64_t m, uint64_t *pos);

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        uint64_t n, m, q;
        cin >> n >> m >> q;
        uint64_t pos[m];
        for (size_t i = 0; i < m; i++)
        {
            cin >> pos[i];
        }
        sort(pos, pos + m);
        while (q--)
        {
            solve(n, m, pos);
        }
        
    }
}


void solve(uint64_t n, uint64_t m, uint64_t *pos)
{
    uint64_t q;
    cin >> q;
    if (q < pos[0])
    {
        cout << pos[0] - 1 << '\n';
        return;
    }
    else if (q > pos[m - 1])
    {
        cout << n - pos[m - 1] << '\n';
        return;
    }
    size_t left(0), right(m - 1), i((m - 1) / 2);

begin_find:
    if (pos[i] < q && pos[i + 1] > q)
    {
        goto next_step;
    }
    if (pos[i] > q)
    {
        right = i;
        i /= 2;
        goto begin_find;
    }
    if (pos[i + 1] < q)
    {
        left = i;
        i = (left + right) / 2;
        goto begin_find;
    }

next_step:
    uint64_t l = pos[i], r = pos[i + 1];
    cout << (r - l) / 2 << '\n';
}