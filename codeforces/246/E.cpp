#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define x first
#define y second
#define len(x) x.size()
#define int long long

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const int maxn = 2e5 + 7;
const ll inf = 1e18 + 7;
const int mod = 1e9 + 7;
const int K = 1e3 + 7;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

ll binpow(int a, int n) {
    if (n == 0) return 1;
    else if (n & 1) {
        return binpow(a, n - 1) * a;
    } else {
        ll c = binpow(a, n / 2);
        return c * c;
    }
}

int n, q;
string s[maxn];
int p[maxn], dep[maxn], sz[maxn], ver[maxn];
int tin[maxn], tout[maxn], timer, ans[maxn];
vector <int> g[maxn];
set <string> cnt[maxn];
vector <pair <int, int>> query[maxn];

void calc(int v, int p = -1) {
    tin[v] = ++timer; sz[v] = 1;
    ver[timer] = v;
    for (auto to : g[v]) {
        if (to != p) {
            dep[to] = dep[v] + 1;
            calc(to, v);
            sz[v] += sz[to];
        }
    }
    tout[v] = timer;
}

void dfs(int v, int p = -1, bool keep = 1) {
    int bch = -1;
    for (auto to : g[v]) {
        if (to != p) {
            if (bch == -1 || sz[bch] < sz[to]) {
                bch = to;
            }
        }
    }
    for (auto to : g[v]) {
        if (to != p && to != bch) {
            dfs(to, v, 0);
        }
    }
    if (bch != -1) {
        dfs(bch, v, 1);
    }
    for (auto to : g[v]) {
        if (to != p && to != bch) {
            for (int x = tin[to]; x <= tout[to]; x++) {
                cnt[dep[ver[x]]].insert(s[ver[x]]);
            }
        }
    }
    cnt[dep[v]].insert(s[v]);
    for (auto [k, pos] : query[v]) {
        int need_dep = dep[v] + k;
        ans[pos] = cnt[need_dep].size();
    }
    if (keep == 0) {
        for (int x = tin[v]; x <= tout[v]; x++) {
            cnt[dep[ver[x]]].erase(s[ver[x]]);
        }
    }
}

void cl(int v, int p = 0) {
    tin[v] = tout[v] = sz[v] = 0;
    for (auto to : g[v]) {
        if (to != p) {
            cl(to, v);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> p[i];
        if (p[i] != 0) {
            g[i].pb(p[i]);
            g[p[i]].pb(i);
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int v, k;
        cin >> v >> k;
        query[v].pb({k, i});
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] == 0) {
            timer = 0;
            dep[i] = 1;
            calc(i);
            dfs(i);
            cl(i);
            for (int j = 1; j <= timer; j++) {
                ver[j] = 0;
                cnt[j].clear();
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt = 1;
//    cin >> tt;
    while (tt--) {
        solve();
    }
}
