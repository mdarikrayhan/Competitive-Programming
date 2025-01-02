#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define endl '\n'
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// go down to child -> maximum dist from other subtrees increases by one
// maximum dist in child subtree decreases by one
// cost = max(those) * k + c * dep
void solve() {
  int n,k,c;cin>>n>>k>>c;
  vector<vector<int>> adj(n);
  for(int i=0;i<n-1;i++){
    int u,v;cin>>u>>v;
    u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> dep(n),hit(n);
  auto dfs1=[&](int u,int p,auto&& dfs1)->void{
    for(auto v:adj[u]){
      if(v==p)continue;
      dep[v]=dep[u]+1;
      dfs1(v,u,dfs1);
      ckmax(hit[u],hit[v]+1);
    }
  };
  dfs1(0,0,dfs1);
  int ans=-1e18;
  auto dfs2=[&](int u,int p,int above,auto&& dfs2)->void{
    int h=above;
    vector<pi> hs{{above+1,1e18}};
    for(auto v:adj[u]){
      if(v==p)continue;
      ckmax(h,hit[v]+1);
      hs.push_back({hit[v]+2,v});
    }
    sort(all(hs),greater<pi>());
    ckmax(ans,h*k-dep[u]*c);
    for(auto v:adj[u]){
      if(v==p)continue;
      int nxt=hs[0].first;
      if(hs[0].second==v)nxt=hs[1].first;
      dfs2(v,u,nxt,dfs2);
    }
  };
  dfs2(0,0,0,dfs2);
  cout<<ans<<endl;
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t = 1;
  cin >> t;
  while(t--) solve();
}
