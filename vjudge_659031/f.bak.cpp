#include <ios>
#include <iostream>
#include <cstddef>
#include <cstdint>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <class a, class b>
struct mypair
{
    a first;
    b second;
    mypair (a mya, b myb): first(mya), second(myb){};
};

#define pair mypair

inline bool operator<(const pair<ull, ull> &a, const pair<ull, ull> &b)
{
    return (a.second - a.first) > (b.second - b.first);
}
inline bool operator<=(const pair<ull, ull> &a, const pair<ull, ull> &b)
{
    return (a.second - a.first) >= (b.second - b.first);
}
inline bool operator>(const pair<ull, ull> &a, const pair<ull, ull> &b)
{
    return (a.second - a.first) < (b.second - b.first);
}
inline bool operator>=(const pair<ull, ull> &a, const pair<ull, ull> &b)
{
    return (a.second - a.first) <= (b.second - b.first);
}

int main()
{
    size_t t;
    cin >> t;
    while (t--)
    {
        size_t n, m;
        cin >> n >> m;
        // vector<pair<size_t, size_t>> sto(2 * m);
        set<pair<ull, ull>> sto;
        for (size_t i = 0; i < 2 * m; i++)
        {
            ull testa, testb;
            cin >> testa >> testb;
            testa--, testb--;
            sto.emplace(move(testa), move(testb));
        }
        vector<ull> arr(n, 0);
        ull cnt(0), val(1);
        for (auto &it : sto)
        {
            /*
            if (cnt == m)
            {
                break;
            }
            if (arr[it.first] == arr[it.second])
            {
                goto fail;
            }
            if (arr[it.first] && arr[it.second])
            {
                continue;
            }
            cnt++;
            if (arr[it.first] != 0)
            {
                arr[it.second] = arr[it.first];
                continue;
            }
            else if (arr[it.second] != 0)
            {
                arr[it.first] = arr[it.second];
                continue;
            }
            arr[it.first] = val;
            arr[it.second] = val;
            val++;
        */
            cout << it.first << it.second << endl;
        }
        cnt++;
        for (auto &it : arr)
        {
            if (!it)
            {
                it = cnt;
                cnt++;
            }
            cout << it << ' ';
        }
        cout << '\n';
        continue;
        ;
    fail:
        cout << "-1\n";
    }
}