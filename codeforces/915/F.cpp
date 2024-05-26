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
const int N = 300010, M = N * 30;
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

struct DSU{
    vector<int> fa, sz;
    DSU(int n) : fa(n + 1), sz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x){
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    bool same(int x, int y) { 
        return find(x) == find(y); 
    }

    bool merge(int x, int y){
        x = find(x), y = find(y);
        if (x == y) return false;
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
};

void solve(){
    int n;
    cin >> n;
    
    auto a = readVector(n);
    
    ll ans = 0;
    vector<array<int, 2>> edges;
    for (int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        edges.push_back({u, v});
    }
    
    {
        vector<array<int, 3>> e;
        for (auto& [u, v]: edges) {
            e.push_back({min(a[u], a[v]), u, v});
        }
        sort(all(e), greater<>());
        
        DSU d(n);
        for (auto& [w, u, v]: e) {
            u = d.find(u), v = d.find(v);
            ans -= (ll)w * d.sz[v] * d.sz[u];
            d.sz[u] += d.sz[v];
            d.fa[v] = u;
        }
    }
    
    {
        vector<array<int, 3>> e;
        for (auto& [u, v]: edges) {
            e.push_back({max(a[u], a[v]), u, v});
        }
        sort(all(e));
        
        DSU d(n);
        for (auto& [w, u, v]: e) {
            u = d.find(u), v = d.find(v);
            ans += (ll)w * d.sz[v] * d.sz[u];
            d.sz[u] += d.sz[v];
            d.fa[v] = u;
        }
    }
    
    cout << ans;
}

int main() {
	ios
	int t = 1; //cin >> t;
	while(t --) solve();

	return 0;
}