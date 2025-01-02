// LUOGU_RID: 160406924
#include <bits/stdc++.h>

using namespace std;

// #define int long long 
constexpr int MAXL=2e3+10, MAXN=4e6+10;
int n, m; char a[MAXL][MAXL]; int id[MAXL][MAXL], vtot;
vector<int> g[MAXN];
int deg[MAXN], dis[MAXN][2], cnt;

void add(int u, int v) {
    // swap(u,v);
    g[u].push_back(v); deg[v]++;
}

void topo() {
    queue<int> q;
    for (int i=1; i<=vtot; ++i) if (!deg[i]) q.push(i);
    while (q.size()) { 
        ++cnt;
        int u=q.front(); q.pop();
        for (auto v: g[u]) {
            if (dis[u][0]+1>=dis[v][0]) {
                dis[v][1]=dis[v][0];
                dis[v][0]=dis[u][0]+1;
            }
            else if (dis[u][0]+1>dis[v][1]) {
                dis[v][1]=dis[u][0]+1;
            }
            if (!--deg[v]) q.push(v);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) cin>>a[i][j], id[i][j]=++vtot;
    for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) if (a[i][j]!='#') {
        if (a[i][j]=='^') add(id[i][j],id[i-1][j]);
        if (a[i][j]=='v') add(id[i][j],id[i+1][j]);
        if (a[i][j]=='<') add(id[i][j],id[i][j-1]);
        if (a[i][j]=='>') add(id[i][j],id[i][j+1]);
    }
    topo();
    if (cnt!=vtot) return cout<<-1, 0;
    vector<int> v;
    for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j)
        if(a[i][j]=='#') v.push_back(dis[id[i][j]][0]), v.push_back(dis[id[i][j]][1]);
    sort(v.begin(),v.end()); reverse(v.begin(),v.end());
    int ans=0;
    if (v.size()==1) ans=v[0]*2-1;
    else {
        ans=max(v[0]+v[1],v[0]*2-1);
    }
    cout<<ans;
}