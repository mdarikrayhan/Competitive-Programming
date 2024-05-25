#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void print() { cout << '\n'; }
template <typename T, typename...Args>
void print(T t, Args...args) { cout << t << ' '; print(args...); }
using P = pair<int, int>;
using ll = long long;
const int N = 300010;
// function

int dir[4][2] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

template <typename T> void chmax(T &x, T y) { x = max(x, y); }
template <typename T> void chmin(T &x, T y) { x = min(x, y); }

template <typename T = int>
vector<T> readVector(int n) {
    vector<T> a(n);
    for(T &x: a) cin >> x;
    return a;
} 

vector<pair<int, int>> g[N];
vector<int> h[N];
int dfn[N], low[N], id[N], clk, cnt, stk[N], top, ans;

void tarjan (int u, int from) {
    dfn[u] = low[u] = ++ clk;
    stk[++ top] = u;
    for (auto& [v, edge_id]: g[u]) {
        if (edge_id == from) {
            continue;
        }
        if (!dfn[v]) {
            tarjan(v, edge_id);
            chmin(low[u], low[v]);
        } else {
            chmin(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        cnt ++;
        while (true) {
            int v = stk[top --];
            id[v] = cnt;
            if (u == v) {
                break;
            }
        }
    }
}

int dfs (int u, int fa) {
    int d1 = 0, d2 = 0;
    for (int v: h[u]) {
        if (v == fa) {
            continue;
        }
        int d = dfs(v, u) + 1;
        if (d > d1) {
            d2 = d1;
            d1 = d;
        } else if (d > d2) {
            d2 = d;
        }
    }
    chmax(ans, d1 + d2);
    return d1;
}

void solve(){
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    
    tarjan(1, 0);
    
    for (int i = 1; i <= n; i ++) {
        for (auto& [j, _]: g[i]) {
            int u = id[i], v = id[j];
            if (u == v) continue;
            h[u].emplace_back(v);
        }
    }
    
    dfs(1, 0);
    
    cout << ans;
}

int main() {
	ios
	int t = 1; //cin >> t;
	while(t --) solve();

	return 0;
}