// LUOGU_RID: 160411803
#include <bits/stdc++.h>

using namespace std;

// #define int long long 
using db=double;
constexpr int MAXN=5e2+10;
int n, m;

int id(int x, int y) {
    return (x-1)*n+y;
}

db a[MAXN][MAXN], p[MAXN]; bool e[MAXN][MAXN];
int deg[MAXN];
int c, d;

void gauss(int n) {
    for (int i=1; i<=n; ++i) {
        int pos=i;
        for (int j=i+1; j<=n; ++j)
            if (fabs(a[j][i])>fabs(a[pos][i]))
                pos=j;
        if(pos!=i) swap(a[pos],a[i]);
        for (int j=1; j<=n; ++j) if (i!=j) {
            db d=a[j][i]/a[i][i];
            for (int k=i; k<=n+1; ++k)
                a[j][k]-=d*a[i][k];
        }
    }
    for (int i=1; i<=n; ++i) a[i][n+1]/=a[i][i];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>c>>d;
    for (int i=1,u,v; i<=m; ++i) {
        cin>>u>>v; e[u][v]=e[v][u]=1;
        deg[u]++; deg[v]++;
    }
    for (int i=1; i<=n; ++i) cin>>p[i];
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            a[id(i,j)][id(i,j)]--;
            if (i==c&&j==d) a[id(i,j)][n*n+1]=-1;
            if (i!=j) a[id(i,j)][id(i,j)]+=p[i]*p[j];
            // u!=i, v!=j
            for (int u=1; u<=n; ++u) if (e[u][i])
            for (int v=1; v<=n; ++v) if (e[v][j] && u!=v) {
                a[id(i,j)][id(u,v)]+=(1-p[u])/deg[u]*(1-p[v])/deg[v];
            }
            for (int u=1; u<=n; ++u) if (e[u][i] && u!=j) {
                a[id(i,j)][id(u,j)]+=(1-p[u])/deg[u]*p[j];
            }
            for (int v=1; v<=n; ++v) if (e[v][j] && v!=i) {
                a[id(i,j)][id(i,v)]+=(1-p[v])/deg[v]*p[i];
            }
        }
    }
    gauss(n*n);
    for (int i=1; i<=n; ++i)
        cout<<fixed<<setprecision(10)<<a[id(i,i)][n*n+1]<<' ';

    
}