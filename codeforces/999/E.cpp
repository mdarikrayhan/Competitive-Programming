#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// #define MAXN 10000001
const int mod = 1e9 + 7;

int binpow(int a, int b, int m)
{
  int res = 1;
  a = a % m;
  while (b != 0)
  {
    if (b & 1)
    {
      res = (res * a) % m;
    }
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}




void solve()
{
   int n,m,s;
    // ... read n ...
   cin>>n>>m>>s;
    s--;

   adj.resize(n);
   adj_rev.resize(n);

    for (int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        // ... read next directed edge (a,b) ...
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++){
        if (!used[i]){
            dfs1(i);
        }
    }
    used.assign(n, false);
    reverse(order.begin(), order.end());

vector<int> roots(n, 0);
vector<int> root_nodes;
vector<vector<int>> adj_scc(n);
int tot = 0;
   //cout<<1<<endl;

for (auto v : order){
    if (!used[v]) {
       // comp++;
        dfs2(v);

        //int root = component.front();
        for (auto u : component) roots[u] = tot;
        
        tot++;

        component.clear();
    }

}


vector<int> indeg(tot,0);

for (int v = 0; v < n; v++){
    for (auto u : adj[v]) {
        int root_v = roots[v],
            root_u = roots[u];

        if (root_u != root_v){
            adj_scc[root_v].push_back(root_u);
            indeg[root_u]++;
            //cout<<root_u<<" "<<root_v<<endl;
        }
    }
}

int ans = 0;

for(int i=0;i<tot;i++){
   if(indeg[i]==0){
     ans++;
   }
}

//cout<<ans<<endl;
cout<<ans - (indeg[roots[s]]==0)<<endl;

//cout<<1<<endl;
  return;
}

signed main()
{
 ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  //cin >> t;

  while (t-- != 0)
  {

    solve();
  }
  return 0;
}