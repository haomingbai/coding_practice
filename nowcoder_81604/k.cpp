#include <ios>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    multiset<ll> dat;
    for (ll i = 0, tmp; i < n; i++)
    {
        cin >> tmp;
        // cout << "finish " << i << endl;
        dat.insert(tmp);
    }
    // cout << "finish" << endl;
    ll cnt = 0;
    while (*prev(dat.end()) >= max(*prev(dat.end()) / 2, *prev(prev(dat.end()))) + 1)
    {
        int t = *prev(dat.end());
        dat.erase(prev(dat.end()));
        t /= k;
        dat.insert(t);
        cnt++;
    }
    cnt += *prev(dat.end());
    cout << cnt << '\n';
}