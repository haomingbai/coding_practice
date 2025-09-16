#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n,q;
  cin>>n>>q;
  vector<ll>v(n+10);
  for(int i=0;i<q;i++){
    int x,y;
    cin>>x>>y;
    int a=x/n,b=x%n;
    v[0]+=a;
    if(y+b>n){
      v[0]++;
      v[y+1]++;
      v[y+b-n+1]--;
    }else{
      v[y+1]++;
      v[y+b+1]--;
    }
  }
  ll ans=v[0];
  for(int i=1;i<=n;i++){
    ans+=v[i];
    cout<<ans<<" ";
  }
  cout<<"\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
/*
2   
7 3
10 0
4 2
21 1
1 2
200 0
100 0
*/