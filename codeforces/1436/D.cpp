// LUOGU_RID: 159825549
#include<bits/stdc++.h>
#define int long long
#define said(...)
#define pb push_back
#define em emplace_back
#define F(i,x,y) for(int i=x;i<=y;++i)
#define G(i,x,y) for(int i=x;i>=y;--i)
#define W(G,i,x) for(auto&i:G[x])
#define W_(G,i,j,x) for(auto&[i,j]:G[x])
#define add(x,y) z[x].em(y)
#define add_(x,y) add(x,y),add(y,x)
#define Add(x,y,d) z[x].em(y,d)
#define Add_(x,y,z) Add(x,y,z),Add(y,x,z);
#ifdef int
#define inf (761125761137835809/2)
#else
#define inf 1011011011
#endif
using namespace std;
const int N = 1000100;
const int mod = 998244353;

namespace yhb {

void flower() {
}
int son[N], f[N], g[N], sz[N], a[N];
vector<int> z[N];
void dfs(int u) {
    if (!son[u]) {
        f[u] = 1;
    }
    sz[u] = a[u];
    W(z, j, u) {
        dfs(j);
        g[u] = max(g[u], g[j]);
        sz[u] += sz[j], f[u] += f[j];
    }
    g[u] = max(g[u], (int)ceil(1. * sz[u] / f[u]));
}
void rua() {
    int n;
    cin >> n;
    F(i, 2, n) {
        int x;
        cin >> x;
        add(x, i);
        son[x] = i;
    }
    F(i, 1, n) {
        cin >> a[i];
    }
    dfs(1);
    cout << g[1] << '\n';
}
}
auto main() [[O3]] -> signed {
    int T;
    // cin >> T;
    T = 1;
    yhb::flower();
    while (T--) {
        yhb::rua();
    }
}