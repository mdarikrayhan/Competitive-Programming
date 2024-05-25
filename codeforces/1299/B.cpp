// LUOGU_RID: 160035061
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,x[100010],y[100010];
signed main(){
  cin>>n;for(int i=1;i<=n;++i)cin>>x[i]>>y[i];
  if(n%2){cout<<"NO";return 0;}
  for(int i=1;i<n/2;++i)if(x[i+1]-x[i]!=x[i+n/2]-x[i+n/2+1]||y[i+1]-y[i]!=y[i+n/2]-y[i+n/2+1]){
    cout<<"NO";return 0;
  }cout<<"YES";
  return 0;
}