// LUOGU_RID: 156977339
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int maxn = 1000000 + 10;
constexpr int maxm = 1000000 + 10;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
struct edge
{
    int v; i64 f, c;
    edge(int _v=0, i64 _f=0, i64 _c=0) : v(_v), c(_c), f(_f) {}
} e[maxm << 1];
int cnt = 1;
vector<int> G[maxn];
void addedge(int u, int v, i64 f, i64 c)
{
    e[++cnt] = edge(v, f, c); G[u].emplace_back(cnt);
    e[++cnt] = edge(u, 0, -c); G[v].emplace_back(cnt);
}
int s, t;
i64 incf[maxn], dis[maxn];
int pre[maxn];
bool inq[maxn];
bool spfa()
{
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(s);
    dis[s] = incf[t] = 0; incf[s] = inf;
    while (q.size())
    {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for (int i : G[u])
        {
            int v = e[i].v; i64 c = e[i].c, f = e[i].f;
            if (!f || dis[v] <= dis[u] + c) continue;
            dis[v] = dis[u] + c; incf[v] = min(incf[u], f); pre[v] = i;
            if (!inq[v]) inq[v] = 1, q.push(v);
        }
    }
    return incf[t];
}
i64 mxf = 0, mnc = 0;
void ekcost()
{
    while (spfa())
    {
        mxf += incf[t];
        for (int u=t;u!=s;u=e[pre[u]^1].v)
        {
            e[pre[u]].f -= incf[t];
            e[pre[u] ^ 1].f += incf[t];
            mnc += e[pre[u]].c * incf[t];
        }
    }
}
constexpr int maxk = 100 + 5;
int p[maxk][maxk];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, c, d;
    cin >> n >> m >> k >> c >> d;
    int idx = 0;
    s = ++idx; t = ++idx;
    for (int i=1;i<=n;++i)
        for (int j=0;j<maxk;++j)
        {
            p[i][j] = ++idx;
            if (j) addedge(p[i][j - 1], p[i][j], inf, 0);
            if (i == 1) addedge(p[i][j], t, inf, c * j);
        }
    for (int i=1;i<=k;++i)
    {
        int x;
        cin >> x;
        addedge(s, p[x][0], 1, 0);
    }
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        for (int i=0;i+1<maxk;++i)
            for (int j=1;j<=k;++j)
                addedge(p[u][i], p[v][i + 1], 1, (j + j - 1) * d), addedge(p[v][i], p[u][i + 1], 1, (j + j - 1) * d);
    }
    ekcost();
    cout << mnc << '\n';
    return 0;
}