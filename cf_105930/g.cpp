#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  string s;
  cin>>s;
  int n=s.size();
  if(n&1){
    for(int i=1;i<n;i++) cout<<"9";
    cout<<"\n";
    return;
  }else if(n==2){
    if(s[0]<=s[1]) cout<<s[0]<<s[0];
    else cout<<char(s[0]-1)<<char(s[0]-1);
    cout<<"\n";
    return;
  }
  stack<char> st;
  st.push('#');
  int site=-1;
  for(int i=0;i<n;i++){
    char c=s[i];
    if(st.top()==c){
      st.pop();
      if(st.size()==1){
        site=i;
      }
    }else st.push(c);
  }
  if(site==n-1){
    cout<<s<<"\n";
    return;
  }
  int l=(n+site)/2,r=l+1;
  int ll=l,rr=r;
  while((ll>site+1)&&(rr<n-1)&&s[ll]==s[rr]){
    ll--;rr++;
  }
  if(ll!=site+1){
    if(s[rr]>s[ll]){
      for(int i=0;i<rr;i++) cout<<s[i];
      for(int i=ll;i>=site+1;i--) cout<<s[i];
      cout<<"\n";
      return;
    }
    else{
      int k=l;
      while(k>site+1&&s[k]=='0') k--;
      s[k]=char(s[k]-1);
      for(int i=0;i<=k;i++) cout<<s[i];
      for(int i=k+1;i<l+r-k;i++) cout<<"9";
      for(int i=k;i>=site+1;i--) cout<<s[i];
      cout<<"\n";
      return;
    }
  }else{
    if(s[rr]>s[ll]){
      for(int i=0;i<rr;i++) cout<<s[i];
      for(int i=ll;i>=site+1;i--) cout<<s[i];
      cout<<"\n";
      return;
    }else{
      if(s[ll]=='1'){
        if(site==-1){
          for(int i=0;i<n-2;i++) cout<<"9";
          cout<<"\n";
          return;
        }else{
          for(int i=0;i<=site;i++) cout<<s[i];
          for(int i=site+1;i<n;i++) cout<<"0";
          cout<<"\n";
          return;
        }
      }else{
        int k=ll;
         s[k]=char(s[k]-1);
        for(int i=0;i<=k;i++) cout<<s[i];
        for(int i=k+1;i<l+r-k;i++) cout<<"9";
        for(int i=k;i>=site+1;i--) cout<<s[i];
        cout<<"\n";
        return;
      }
    }
  }

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