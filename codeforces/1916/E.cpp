#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MAXN = 3e5 + 10;
const int LG = 30;
const int MOD = 998244353;
const int64_t INF = 1e9;

vector<int> G[MAXN];
vector<int> st[MAXN];
vector<int> after[MAXN];
int c[MAXN], counter, tin[MAXN], tout[MAXN], N;
int64_t ans = 0;
struct Tree{
    int n;
    vector<int64_t>lazy;
    vector<int64_t>st;
    Tree(int _n, int64_t _v): n(_n), st(_n * 4 + 10, _v), lazy(_n * 4 + 10, _v){};
    void push(int id){
        int64_t add = lazy[id];
        lazy[id * 2] += add, st[id * 2] += add;
        lazy[id * 2 + 1] += add, st[id * 2 + 1] += add;
        lazy[id] = 0;
    }
    void update(int id, int l, int r, int u, int v, int64_t val){
        if (v < l || u > r) return;
        if (u <= l && r <= v) {
            st[id] += val;
            lazy[id] += val;
            return;
        }
        push(id);
        int mid = (l + r)/2;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }
    int64_t getMax(int id, int l, int r, int u, int v) {
        if (v < l || u > r) return 0;
        if (u <= l && r <= v) return st[id];
        push(id);
        int mid = (l + r)/2;
        return max(getMax(id * 2, l, mid, u, v), getMax(id * 2 + 1, mid + 1, r, u, v));
    }
};
void dfs(int u) {
    tin[u] = tout[u] = ++counter;
    if (!st[c[u]].empty()) {
        after[st[c[u]].back()].pb(u);
    }
    st[c[u]].pb(u);
    for (int v : G[u]) {
        dfs(v);
    }
    st[c[u]].pop_back();
    tout[u] = counter;
}
void dfs1(int u, Tree &T) {
    for (auto v : G[u]) {
        dfs1(v, T);
    }
    for (auto v : after[u]) {
        T.update(1, 1, N, tin[v], tout[v], -1);
    }
    T.update(1, 1, N, tin[u], tout[u], 1);
    pair<int64_t, int64_t> best = {1, 1};
    for (int v : G[u]) {
        int64_t x = T.getMax(1, 1, N, tin[v], tout[v]);
        if (x > best.first) {
            best.second = max(best.second, best.first);
            best.first = x;
        } else {
            best.second = max(best.second, x);
        }
    }
    // cout << u << " " << best.first << " " << best.second << "\n";
    ans = max(ans, best.first * best.second);
}
void Solve(void) {
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        G[i].clear();
        st[i].clear();
        after[i].clear();
        counter = 0;
    }
    for (int i = 2; i <= N; i ++) {
        int p; cin >> p;
        G[p].pb(i);
    } 
    for (int i = 1; i <= N; i ++) cin >> c[i];
    dfs(1);
    Tree T(N, 0);
    ans = 0;
    dfs1(1, T);
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int Tests = 1; cin >> Tests; 
    while (Tests --) {
        Solve();    
    }
}