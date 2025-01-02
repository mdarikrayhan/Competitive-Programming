#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define inf 0x3F3F3F3F3F3F3F3F

const int MXN = 1e5 + 5;

struct DATA
{
    int p, s, res, z;
};

int f[MXN];

DATA combine(DATA a, DATA b)
{
    return {!a.z ? a.p + b.p : a.p, !b.z ? b.s + a.s : b.s, a.res + b.res + (a.s >= 1 && b.p >= 1 ? f[a.s + b.p] - f[a.s] - f[b.p] : 0), (a.z | b.z)};
}

struct SegTree
{
    int sz;
    vector<DATA> st;
    void init(int n)
    {
        sz = 1;
        while (sz < n) sz <<= 1;
        st.assign(sz << 1, {0, 0, 0, 1});
    }
    void make(int l, int r, int x, int ind)
    {
        if (l + 1 == r)
        {
            st[x] = {1, 1, f[1], 0};
            return;
        }
        int mid = (l + r) >> 1;
        if (ind < mid) make(l, mid, 2*x + 1, ind);
        else make(mid, r, 2*x + 2, ind);
        st[x] = combine(st[2*x + 1], st[2*x + 2]);
    }
    DATA get(int l, int r, int x, int lx, int rx)
    {
        if (lx >= rx) return {0, 0, 0, 0};
        if (l >= rx || r <= lx) return {0, 0, 0, 0};
        if (l >= lx && r <= rx) return st[x];
        int mid = (l + r) >> 1;
        return combine(get(l, mid, 2*x + 1, lx, rx), get(mid, r, 2*x + 2, lx, rx));
    }
};

int n, Q, SZ;
array<int, 3> q[MXN];
vector<int> o;
vector<array<int, 2>> adj[MXN];
vector<array<int, 2>> ed;
int eid[MXN], reid[MXN], ew[MXN];
int head[MXN], par[MXN], sz[MXN], dep[MXN];
int in[MXN], out[MXN], tim = -1;
int ANS[MXN];
SegTree st;

void _dfs(int a)
{
    sz[a] = 1;
    vector<array<int, 2>> nw;
    int mx = 0;
    for (array<int, 2> &v : adj[a])
    {
        if (v[0] == par[a]) continue;
        par[v[0]] = a;
        _dfs(v[0]);
        sz[a] += sz[v[0]];
        nw.push_back(v);
        if (sz[v[0]] > sz[nw[mx][0]]) mx = (int)nw.size() - 1;
    }
    if (!nw.empty()) swap(nw[mx], nw[0]);
    swap(adj[a], nw);
}
void dfs(int a)
{
    in[a] = ++tim;
    for (int i = 0; i < adj[a].size(); i++)
    {
        if (!i) head[adj[a][i][0]] = head[a];
        else head[adj[a][i][0]] = adj[a][i][0];
        eid[adj[a][i][0]] = adj[a][i][1];
        reid[adj[a][i][1]] = adj[a][i][0];
        dep[adj[a][i][0]] = dep[a] + 1;
        dfs(adj[a][i][0]);
    }
    out[a] = tim;
}
int getans(int u, int v)
{
    DATA resu = {0, 0, 0, 0}, resv = {0, 0, 0, 0};
    while (head[u] != head[v])
    {
        if (dep[head[u]] > dep[head[v]]) 
        {
            if (head[u] == u)
            {
                resu = combine(resu, (ew[eid[u]] ? DATA {1, 1, f[1], 0} : DATA {0, 0, 0, 1}));
                u = par[u];
            }
            else
            {
                DATA x = st.get(0, SZ, 0, in[head[u]] + 1, in[u] + 1);
                swap(x.p, x.s);
                resu = combine(resu, x);
                u = head[u];
            }
        }   
        else
        {
            if (head[v] == v)
            {
                resv = combine(resv, (ew[eid[v]] ? DATA {1, 1, f[1], 0} : DATA {0, 0, 0, 1}));
                v = par[v];
            }
            else
            {
                DATA x = st.get(0, SZ, 0, in[head[v]] + 1, in[v] + 1);
                swap(x.p, x.s);
                resv = combine(resv, x);
                v = head[v];
            }
        }
    }
    if (dep[u] > dep[v])
    {
        swap(resu.p, resu.s);
        resv = combine(resv, st.get(0, SZ, 0, in[v] + 1, in[u] + 1));
        resv = combine(resv, resu);
        return resv.res;
    }
    else
    {
        swap(resv.p, resv.s);
        resu = combine(resu, st.get(0, SZ, 0, in[u] + 1, in[v] + 1));
        resu = combine(resu, resv);
        return resu.res;
    }
}
void upd(int e)
{
    ew[e] = 1;
    int node = reid[e];
    if (head[node] != node) st.make(0, SZ, 0, in[node]);
}

signed main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> Q;
    for (int i = 1; i < n; i++) cin >> f[i];
    st.init(n);
    SZ = st.sz;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ed.push_back({w, i});
        ew[i] = 0;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    _dfs(1);
    head[1] = 1;
    dfs(1);
    o.resize(Q);
    iota(o.begin(), o.end(), 0);
    for (int i = 0; i < Q; i++) cin >> q[i][0] >> q[i][1] >> q[i][2];
    sort(o.begin(), o.end(), [&](const int &a, const int &b)
    {
        return q[a][2] > q[b][2];
    });
    sort(ed.rbegin(), ed.rend());
    int j = 0;
    for (int i : o)
    {
        while (j < ed.size() && ed[j][0] >= q[i][2]) 
        {
            upd(ed[j][1]);
            j++;
        }
        ANS[i] = getans(q[i][0], q[i][1]);
    }
    for (int i = 0; i < Q; i++) cout << ANS[i] << '\n';
}