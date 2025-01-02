// LUOGU_RID: 160261021
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
typedef long long ll;

struct edge {
    int v, next, w;
} e[MAXN];

int eid, p[MAXN];

void init() {
    eid = 0;
    memset(p, -1, sizeof(p));
}

void insert(int u, int v, int w) {
    e[eid] = {v, p[u], w};
    p[u] = eid++;
}

int n, m;
ll dis[MAXN];
set<pair<ll, int>> st;

void dij() {
    for (int i = 2; i <= 2 * n; i++) {
        dis[i] = 1e18;
    }
    dis[1] = 0;
    st.insert({0, 1});
    while (!st.empty()) {
        int u = st.begin()->second;
        st.erase(st.begin());
        for (int i = p[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (dis[v] > dis[u] + e[i].w) {
                st.erase({dis[v], v});
                dis[v] = dis[u] + e[i].w;
                st.insert({dis[v], v});
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1, u, v, w; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        insert(u, v, w);
        insert(v + n, u + n, w);
    }
    for (int i = 1; i <= n; i++) {
        insert(i, i + n, 0);
    }
    dij();
    for (int i = 2; i <= n; i++) {
        if (dis[i + n] >= (ll)1e18) printf("-1 ");
        else printf("%lld ", dis[i + n]);
    }
}