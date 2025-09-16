#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const int MOD = 998244353;
static const int MAXF = 2000005;

ll f[MAXF], invf[MAXF];
ll modexp(ll a, ll e) {
  ll res = 1 % MOD;
  while (e) {
    if (e & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    e >>= 1;
  }
  return res;
}
ll binom(int n, int k) {
  if (k < 0 || k > n) return 0;
  return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  f[0] = 1;
  for (int i = 1; i < MAXF; i++) f[i] = f[i - 1] * i % MOD;
  invf[MAXF - 1] = modexp(f[MAXF - 1], MOD - 2);
  for (int i = MAXF - 1; i > 0; i--) invf[i - 1] = invf[i] * i % MOD;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }

    vector<int> pa(n, -1), leftc(n, -1), rightc(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
      int last = -1;
      while (!st.empty() && p[st.top()] > p[i]) {
        last = st.top();
        st.pop();
      }
      if (!st.empty()) {
        pa[i] = st.top();
        rightc[st.top()] = i;
      }
      if (last != -1) {
        pa[last] = i;
        leftc[i] = last;
      }
      st.push(i);
    }
    int root = st.top();
    while (pa[root] != -1) root = pa[root];

    vector<int> sz(n, 0);
    function<int(int)> d_sz = [&](int u) {
      if (u < 0) return 0;
      int ls = d_sz(leftc[u]);
      int rs = d_sz(rightc[u]);
      sz[u] = ls + rs + 1;
      return sz[u];
    };
    d_sz(root);

    ll ans = 1;
    stack<tuple<int, int, int>> d_st;
    d_st.push({root, 0, 1});
    while (!d_st.empty()) {
      int u, cfixed, depth;
      tie(u, cfixed, depth) = d_st.top();
      d_st.pop();
      int K = n - cfixed;
      if (K >= 1) {
        ll ways = binom(K + depth - 1, depth);
        ans = (ans + ways) % MOD;
      }
      if (leftc[u] != -1) {
        int c2 = cfixed + ((rightc[u] != -1) ? sz[rightc[u]] : 0) + 1;
        d_st.push({leftc[u], c2, depth + 1});
      }
      if (rightc[u] != -1) {
        int c2 = cfixed + ((leftc[u] != -1) ? sz[leftc[u]] : 0) + 1;
        d_st.push({rightc[u], c2, depth + 1});
      }
    }

    cout << ans % MOD << "\n";
  }
  return 0;
}
