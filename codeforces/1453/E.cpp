#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5;

int ans;
int f[N];
vector<int>e[N];

void dfs(int u,int fa){
  int mx=0,semx=0,tot=0;
  for(auto v:e[u]){
    if(v==fa)continue;
    dfs(v,u);
    tot++;
    f[u]=min(f[u],f[v]+1);
    if(f[v]+1>mx)semx=mx,mx=f[v]+1;
    else if(f[v]+1>semx)semx=f[v]+1;
  }
  if(tot==0){
    f[u]=0;
    return;
  }
  if(u==1){
    if(tot==1)ans=max(ans,mx);
    else ans=max(ans,max(semx+1,mx));
  }
  else if(tot>=2) ans=max(ans,mx+1);
}


void slove(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    e[i].clear();
    f[i]=1e9;
  }
  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
   ans=0;
  dfs(1,0);
  cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        slove();
    }
    return 0;
}
