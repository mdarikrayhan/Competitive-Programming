#include <bits/stdc++.h>
#define ll long long
#define pii pair <ll, ll>
using namespace std;
const int N = 2e5 + 10;
ll r[N], id[N];
ll scnt, dcnt;
ll low[N], dfn[N];
vector <ll> G[N], G2[N];
vector <ll> path;
ll s[N][2];
bool vis[N];
inline void dfs1(ll u) {
    vis[u] = true;
    for (auto v : G[u])
        if (!vis[v]) dfs1(v);
    path.push_back(u);
}
inline void dfs2(ll u) {
    id[u] = scnt;
    for (auto v : G2[u])
        if (!id[v]) dfs2(v);
}
inline void init(ll n) {
    scnt = dcnt = 0;
    path.clear();
    for (int i = 0; i <= n; ++i) {
        G[i].clear();
        G2[i].clear();
        vis[i] = 0;
        s[i][0] = s[i][1] = 0;
        low[i] = dfn[i] = 0;
    }
}
inline void addedge(ll u, ll nu, ll v, ll nv) {
    u = (u * 2) ^ nu;
    v = (v * 2) ^ nv;
    ll uu = u ^ 1;
    ll vv = v ^ 1;
    G[uu].push_back(v);
    G[vv].push_back(u);
    G2[u].push_back(vv);
    G2[v].push_back(uu);
}
int main() {
    ll n, m; scanf("%lld%lld", &n, &m);
    init(n * 2);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &r[i]);
    for (int i = 1; i <= m; ++i) {
        ll q; scanf("%lld", &q);
        for (int j = 1; j <= q; ++j) {
            ll x; scanf("%lld", &x);
            if (!s[x][0]) s[x][0] = i;
            else s[x][1] = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        ll u = s[i][0], v = s[i][1];
        if (r[i]) {
            addedge(u, 1, v, 0);
            addedge(u, 0, v, 1);
        } else {
            addedge(u, 1, v, 1);
            addedge(u, 0, v, 0);
        }
    }
    for (int i = 1; i <= 2 * m; ++i)
        if (!vis[i]) dfs1(i);
    for (int i = m * 2 - 1; i >= 0; --i) {
        if (!id[path[i]]) {
            scnt ++;
            dfs2(path[i]);
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (id[i * 2 + 1] == id[i * 2]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
	 					 				     	  				   	