#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

using uint = unsigned int;
using ull = unsigned long long;

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

vi dsupar;

int find_par(int x) {
    if(dsupar[x] == x) {
        return x;
    }
    return dsupar[x] = find_par(dsupar[x]);
}

bool merge(int x, int y) {
    int a = find_par(x);
    int b = find_par(y);

    if(a == b) {
        return false;
    }
    dsupar[a] = b;
    return true;
}

const int B = 20;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, pii>> edges;
    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--;y--;
        edges.push_back({w, {x, y}});
    }

    sort(edges.begin(), edges.end());
    dsupar.resize(n);
    iota(dsupar.begin(), dsupar.end(), 0);
    
    ll totw = 0;
    vector<vpii> adj(n);
    for(auto p : edges) {
        int w;
        pii e;
        tie(w, e) = p;
        int x, y;
        tie(x, y) = e;
        
        if(merge(x, y)) {
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
            totw += w;
        }
    }

    int cc = 0;
    for(int i = 0; i < n; i++) {
        if(dsupar[i] == i) {
            cc++;
        }
    }

    debug("1");

    vb vis(n);
    vi par(n);
    vi wei(n, 0);
    vi dep(n);
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;

        queue<int> q;
        vis[i] = true;
        q.push(i);
        dep[i] = 0;
        par[i] = i;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(pii e : adj[u]) {
                int v, w;
                tie(v, w) = e;
                if(vis[v]) {
                    continue;
                }
                vis[v] = true;
                dep[v] = dep[u] + 1;
                par[v] = u;
                wei[v] = w;
                q.push(v);
            }
        }
    }

    debug("2");

    vvi lift(B, vi(n));
    vvi maxw(B, vi(n));
    for(int i = 0; i < n; i++) {
        lift[0][i] = par[i];
        maxw[0][i] = wei[i];
    }
    for(int b = 1; b < B; b++) {
        for(int i = 0; i < n; i++) {
            lift[b][i] = lift[b-1][lift[b-1][i]];
            maxw[b][i] = max(maxw[b-1][i], maxw[b-1][lift[b-1][i]]);
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        x--;y--;
        if(cc > 2) {
            cout << -1 << endl;
            continue;
        }
        if(cc == 2) {
            if(find_par(x) == find_par(y)) {
                cout << -1 << endl;
            } else {
                cout << totw << endl;
            }
            continue;
        }

        if(dep[x] < dep[y]) swap(x, y);
        int mx = 0;
        for(int b = B-1; b >= 0; b--) {
            if(dep[x] - (1<<b) >= dep[y]) {
                mx = max(mx, maxw[b][x]);
                x = lift[b][x];
            }
        }

        for(int b = B-1; b >= 0; b--) {
            if(lift[b][x] != lift[b][y]) {
                mx = max(mx, maxw[b][x]);
                x = lift[b][x];
                mx = max(mx, maxw[b][y]);
                y = lift[b][y];
            }
        }
        while(x != y) {
            mx = max(mx, maxw[0][x]);
            x = lift[0][x];
            mx = max(mx, maxw[0][y]);
            y = lift[0][y];
        }

        cout << totw - mx << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
