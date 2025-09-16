#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,q,a[N],b[N],ans[N],cha[N],base;
signed main(void)
{
  int t;
  cin>>t;
  while(t--){
    base=0;
    memset(cha,0,sizeof(cha));
    cin>>n>>q;
    for(int i=1;i<=q;i++){
      cin>>a[i]>>b[i];
      b[i]++;
      int x=a[i]/n,y=a[i]%n;
      base+=x;
      cha[b[i]-1]++,cha[b[i]+y-1]--;
    }
    ans[1]=base;
    cout<<
    for(int i=2;i<=n;i++){
      ans[i]=ans[i-1]+cha[i-1];
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
  }
  return 0;
}