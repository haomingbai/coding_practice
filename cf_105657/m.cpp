#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 100;
const int mod = 1e9 + 7;
void solve() {
  ll n;
  ll k;
  cin >> n >> k;
  set<ll> s;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    s.insert(x);
  }
  if (s.size() == 1) {
    cout << k << " " << k * (k + 1) / 2 << "\n";
    return;
  }
  ll la;
  int f = 0;
  set<ll> ans;
  for (ll x : s) {
    if (f == 0) {
      la = x;
      f++;
      continue;
    } else if (f == 1) {
      ll y = x - la;
      for (ll j = 1; j <= (ll)sqrt(y); j++) {
        if (y % j == 0) {
          if (la < j && la + k >= j) {
            ans.insert(j - la);
          }
          ll l = y / j;
          if (la < l && la + k >= l) {
            ans.insert(l - la);
          }
        }
      }
      la = x;
      f++;
    } else {
      ll y = x - la;
      for (ll h : ans) {
        if (y % (la + h) != 0) {
          ans.erase(h);
        }
      }
      if (ans.size() == 0) break;
      la = x;
    }
  }
  ll sum = 0;
  for (ll x : ans) sum += x;
  cout << ans.size() << " " << sum << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}