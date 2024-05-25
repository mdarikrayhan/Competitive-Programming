#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
const ll mod = 1e9 + 7,inf = 1e18;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n = 3005;
bool found = false;
set<int> cycle;
vi vis(n),par(n);
vvi adj(n);
void dfs(int i,int p)
{
    vis[i] = 1;
    if (found)return;
    par[i] = p;
    for (int c:adj[i]){
        if (vis[c] && c != p){
            par[c] = i;
            while (!cycle.count(i) && i != -1){
                cycle.insert(i);
                i = par[i];
            }
            found = true;
        }
        else if (c != p)dfs(c,i);
    }
}
int main()
{
    cin>>n;
    for (int i = 1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v),adj[v].pb(u);
    }
    dfs(1,-1);

    queue<int>q;
    vi ans(n + 1,1e9);

    for (int start:cycle){
        q.push(start);
        vi cur_dist(n + 1,1e9);
        cur_dist[start] = 0;

        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (int x:adj[cur]){
                if (cur_dist[x] <= cur_dist[cur] + 1)continue;
                cur_dist[x] = cur_dist[cur] + 1;
                q.push(x);
            }
        }

        for (int i = 1;i<=n;i++)ans[i] = min(ans[i],cur_dist[i]);
    }

    for (int i = 1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}