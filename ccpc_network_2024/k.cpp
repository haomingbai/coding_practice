#include<bits/stdc++.h>
using namespace std;
void solve()
{
  int n;
  cin>>n;
  vector<int> v(n);
  int a=0,b=0;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a^=x;
    v[i]^=x;
  }
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    b^=x;
    v[i]^=x;
  }
  sort(v.begin(),v.end(),[](int x,int y){
    return x>y;
  });
  vector<pair<int,int>> p(n+1);
  p[0].first=a,p[0].second=b;
  for(int i=0;i<n;i++){
    pair<int,int> c;
    c.first=p[i].first^v[i],c.second=p[i].second^v[i];
    if(max(c.first,c.second)<max(p[i].first,p[i].second)){
      p[i+1]=c;
    }else{
      p[i+1]=p[i];
    }
    }
 cout<<max(p[n].first,p[n].second)<<"\n";
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);
  int t;
  cin>>t;
  while(t--) solve();
}