#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
const int N=2e5+5;
vector<int>e[N];
int h[N];

int dfs(int x,int fa){
  int mx1=0,mx2=0;
  for(auto v:e[x]){
    if(v!=fa){
      int p=dfs(v,x);
      if(p>mx1)mx2=mx1,mx1=p;
      else if(p>mx2) mx2=p;
    }
  }
  if(fa){
    ans+=max(0,h[x]-mx1);
    mx1=max(h[x],mx1);
  }
  else{
    ans+=max(0,h[x]-mx1);
    ans+=max(0,h[x]-mx2);
  }
  return mx1;
}

void slove(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>h[i];
  }
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  int rt=1;
  for(int i=1;i<=n;i++){
    if(h[i]>h[rt])rt=i;
  }
  ans=0;
  dfs(rt,0);
  cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

        slove();

    return 0;
}
