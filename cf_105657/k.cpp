#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
void solve()
{
  int n,m,k;
  cin>>n>>m>>k;
  vector<int> v(N,0);
  int l=n*m;
  vector<int> p(l),a(l);
  for(auto &x:p) cin>>x;
  for(int i=0;i<l;i++){
    int x=p[i],y=(x-1)/m;
    v[y]++;
    a[i]=v[y];
  }
  int ans;
  for(int i=0;i<l;i++){
    // cout<<a[i]<<" ";
    if(m-a[i]<=k&&i>=m-1){
      ans=i+1;
      break;
    }
  }
  cout<<ans<<"\n";
  // cout<<"\n";
}
int main()
{
  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
