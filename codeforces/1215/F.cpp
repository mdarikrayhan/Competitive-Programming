#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#define lowbit(x) x & -x
//#define int long long
typedef long long ll;
typedef unsigned long long ULL;
#define PII pair<int,int>
#define PIII pair<int,PII>
#define endl '\n'
#define x first
#define y second
#define rep(i,a,b) for(int i = a;i <= b;i++)
#define per(i,a,b) for(int i = a;i >= b;i--)
#define debug(a) for(int i:(a)) cout<<i<<'|';cout<<endl
#define all(n) (n).begin() + 1,(n).end()
const int mod = 998244353;
const int N = 5e6 + 5, M = 5e6 + 5;
int n, m, scc_cnt;
int h[N], e[M], ne[M], idx, id[N];
int dfn[N], low[N], stk[N], instk[N], top, timestamp;
void add(int a, int b) {
    ne[idx] = h[a], e[idx] = b, h[a] = idx++;
}
void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    instk[u] = 1;
    for (int j = h[u]; ~j; j = ne[j]) {
        int ver = e[j];
        if (!dfn[ver]) {
            tarjan(ver);
            low[u] = min(low[u], low[ver]);
        }
        else if (instk[ver]) low[u] = min(low[u], dfn[ver]);
    }
    if (dfn[u] == low[u]) {
        ++scc_cnt;
        int y;
        do {
            y = stk[top--];
            instk[y] = 0;
            id[y] = scc_cnt;
        } while (y != u);
    }
}
void solve()
{
    memset(h, -1, sizeof h);
    int n, p, M, m; cin >> n >> p >> M >> m;
    rep(i, 1, n) {
        int x, y; cin >> x >> y;
        add(x + p, y);
        add(y + p, x);
    }
    // 4e5 * ( 2 + 4 + 2)
    vector<PII> edge(p + 1);
    rep(i, 1, p) {
        int l, r; cin >> l >> r;
        edge[i].x = l;
        edge[i].y = r;
        // 选 x 则 必选 x - 1
        add(i, 2 * p + l);
        add(2 * p + M + l, i + p);
        add(i, 2 * p + M + r + 1);
        add(2 * p + r + 1, i + p);
    }
    rep(i, 2, M) add(2 * p + i, 2 * p + i - 1), add(2 * p + i - 1 + M, 2 * p + i + M);
    rep(i, 1, m) {
        int x, y; cin >> x >> y;
        add(x, y + p);
        add(y, x + p);
    }
    vector<int> ans;
    rep(i, 1, 2 * p) if (!dfn[i]) tarjan(i);
    //cout << "--" << id[2 * p + 1] << ' ' << id[2 * p + m + 1] << endl;
    rep(i, 1, p) {
        if (id[i] == id[i + p]) return void(cout << "-1" << endl);
        if (id[i] < id[i + p]) ans.push_back(i);
    }
    int l = 0;
    for (int i : ans) {
        if (l < edge[i].x) l = edge[i].x;
    }
    cout << ans.size() << ' ' << l << endl;
    for (int i : ans) cout << i << ' ';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _ = 1; //cin >> _;
    while (_--) solve();
}