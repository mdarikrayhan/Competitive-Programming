// LUOGU_RID: 159754187
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 5;
const ll maxv = 2e5;
const ll B = 450;
ll n, q;
vector<ll> adj[maxn];
int f[maxn][B + 2];
vector<pair<pair<ll, ll>, ll>> op[2];
ll num[maxn];
void dfs1(ll now, ll fa){
    // ll num = (int)(adj[now].size()) - (now != 1);
    for(auto t : adj[now]){
        if(t == fa) continue;
        dfs1(t, now);
        for(int j = 0;j <= B;j++){
            f[now][j] = max(f[now][j] + 1, f[now][j] - j + f[t][j]);
        }
    }
    return ;
}
ll sz[maxn];
int g[B + 5];
void dfs2(ll now, ll fa){
    memset(f[now], -0x3f, sizeof(f[now]));
    memset(g, -0x3f, sizeof(g));
    sz[now] = 1;
    f[now][0] = 0;
    for(auto t : adj[now]){
        if(t == fa) continue;
        dfs2(t, now);
        for(int i = 0;i <= sz[now] && i <= B;i++){
            for(int j = 0;j <= sz[t] && j + i <= B;j++){
                g[i + j] = max(g[i + j], f[now][i] + 1);
                g[i + j + 1] = max(g[i + j + 1], f[now][i] + f[t][j]);
            }
        }
        sz[now] += sz[t];
        for(int i = 0;i <= sz[now] && i <= B;i++){
            f[now][i] = g[i]; g[i] = -0x3f3f3f3f;
        }
    }
    return ;
}
ll ans[maxn];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++){
        ll ux, vx; cin >> ux >> vx; adj[ux].push_back(vx);
        adj[vx].push_back(ux);
    }
    cin >> q;
    for(int i = 1;i <= q;i++){
        ll ux, kx; cin >> ux >> kx;
        if(kx > B) op[1].emplace_back(make_pair(ux, kx), i);
        else op[0].emplace_back(make_pair(ux, kx), i);
    }
    dfs1(1, 0);
    for(auto fr : op[0]){
        ll t = fr.first.first, vv = fr.first.second;
        ll id = fr.second;
        ans[id] = f[t][vv];
    }
    dfs2(1, 0);
    for(auto fr : op[1]){
        ll t = fr.first.first, vv = fr.first.second;
        ll id = fr.second;
        for(int j = 0;j <= B;j++){
            // cout << f[t][j] - vv * j << " \n"[j == B];
            ans[id] = max(ans[id], (ll)f[t][j] - vv * j);
        }
        // cout << id << " " << ans[id] << endl;
    }
    for(int i = 1;i <= q;i++) cout << ans[i] << "\n";
    cout.flush(); return 0;
}