#include<bits/stdc++.h>     ///  2-Sat  -  Binary Search  -  Segment Tree
#define _ ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
using namespace std;
const int N = 2e6 + 5;
int t, n, m, x, y, tmr, in[N], low[N], vis[N], cid[N], cmps, ch[N], l, r, md, ans;
vector<int> g[N], stk, nds, tmp;  vector<pair<int, int> > edgs;

void dfs(int v){
    in[v] = low[v] = ++tmr;
    stk.push_back(v), vis[v] = 1;
    for (int u : g[v]){
        if (!in[u]) dfs(u);
        if (vis[u]) low[v] = min(low[v], low[u]);
    }
    if (in[v] == low[v]){
        ch[cmps] = v;
        while (1){
            int u = stk.back();  stk.pop_back();
            vis[u] = 0, cid[u] = cmps;
            if (u == v) break;
        }
        cmps++;
    }
}

int Not(int x) { return (x <= 4 * n ? x + 4 * n : x - 4 * n); }

void add(int i, int j) { g[Not(i)].push_back(j), g[Not(j)].push_back(i); }

void build(int p, int l, int r){
    nds.push_back(p);
    if (l == r) return;
    int md = (l + r) / 2;
    build(p * 2, l, md);
    build(p * 2 + 1, md + 1, r);
    g[p].push_back(p * 2);
    g[p].push_back(p * 2 + 1);
    g[Not(p)].push_back(Not(p * 2));         /// !!!!
    g[Not(p)].push_back(Not(p * 2 + 1));     /// !!!!
}

void get(int p, int l, int r, int a, int b){
    if (a <= l && r <= b) { tmp.push_back(p);  return; }
    if (a > r || l > b) return;
    int md = (l + r) / 2;
    get(p * 2, l, md, a, b);
    get(p * 2 + 1, md + 1, r, a, b);
}

void clr(){
    for (x = tmr = cmps = 0; x <= 8 * n; x++)
        in[x] = vis[x] = low[x] = cid[x] = ch[x] = 0, g[x].clear();
    stk.clear(), nds.clear();
}

bool ok(int md){
    for (auto p : edgs) add(p.first, p.second);
    for (x = 1; x <= n; x++){
        tmp.clear(), get(1, 1, n, x, x), y = tmp.back();
        if (x > 1){
            tmp.clear();
            get(1, 1, n, max(1, x - md + 1), x - 1);
            for (int z : tmp) add(Not(y), Not(z));
        }
        if (x < n){
            tmp.clear();
            get(1, 1, n, x + 1, min(n, x + md - 1));
            for (int z : tmp) add(Not(y), Not(z));
        }
    }
    for (int x : nds){
        if (!in[x]) dfs(x);
        if (!in[Not(x)]) dfs(Not(x));
    }
    for (int x : nds) if (cid[x] == cid[Not(x)]) return 0;
    return 1;
}

int main()
{_
    cin >> t;
    while (t--){
        cin >> n >> m;  edgs.clear();
        while (m--){
            cin >> x >> y;
            tmp.clear(), get(1, 1, n, x, x), x = tmp.back();
            tmp.clear(), get(1, 1, n, y, y), y = tmp.back();
            edgs.push_back({x, y});
        }
        l = ans = 1, r = n;
        while (l <= r){
            md = (l + r) / 2, clr(), build(1, 1, n);
            if (ok(md)) ans = md, l = md + 1;
            else r = md - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
