#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
const int mod = 998244353;
int n, k, p[N], pos, num, cnt, ans;
signed main(void) {
  int t;
  cin >> t;
  while (t--) {
    num=0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      if (p[i]) num++;
    }
    sort(p + 1ll, p + n + 1ll);
    if (num<k) {
      cout << p[n]%mod << endl;
      continue;
    }
    num=(num-1)/(k-1)*(k-1)+1;
    ans=1;
    for(int i=n;i>=n-num+1;i--) ans=(ans*p[i])%mod;
    cout<<ans%mod<<endl;
  }
  return 0;
}