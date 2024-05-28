#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define pb push_back
#define ff first
#define ss second
#define ins insert

struct ST{
    vector<int> t, p;
    int n;
    ST(int ns){
        n = ns;
        t.resize(4 * n);
        p.resize(4 * n);
    }
    void push(int& v, int& vv){
        if (!p[v]) return;
        t[vv] += p[v]; t[vv + 1] += p[v];
        p[vv] += p[v]; p[vv + 1] += p[v];
        p[v] = 0;
    }
    void upd(int v, int tl, int tr, int& l, int& r, int& x){
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r){
            t[v] += x;
            p[v] += x;
            return;
        }
        int tm = (tl + tr) / 2, vv = 2 * v;
        push(v, vv);
        upd(vv, tl, tm, l, r, x);
        upd(vv + 1, tm + 1, tr, l, r, x);
        t[v] = max(t[vv], t[vv + 1]);
    }
    void upd(int l, int r, int x){
        if (l > r) return;
        upd(1, 1, n, l, r, x);
    }
    int get(int v, int tl, int tr, int& l, int& r){
        if (l > tr || r < tl) return 0;
        if (l <= tl && tr <= r) return t[v];
        int tm = (tl + tr) / 2, vv = 2 * v;
        push(v, vv);
        return max(get(vv, tl, tm, l, r), get(vv + 1, tm + 1, tr, l, r));
    }
    int get(int l, int r){
        if (l > r) return 0;
        return get(1, 1, n, l, r);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q; cin>>n>>q;
    vector<int> g[n + 1];
    for (int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    vector<int> tin(n + 1), tout(n + 1);
    int timer = 0;
    function<void(int, int)> fill = [&](int v, int pr){
        tin[v] = ++timer;
        for (int i: g[v]){
            if (i == pr) continue;
            fill(i, v);
        }
        tout[v] = timer;
    };
    fill(1, 0);
    
    auto check = [&](int x, int y){
        return (tin[x] <= tin[y] && tout[x] >= tout[y]);
    };
    
    ST T(n);
    for (int i = 1; i <= n; i++) T.upd(tin[i], tout[i], 1);
    
    vector<pair<int, vector<int>>> qs[n + 1];
    for (int tt = 1; tt <= q; tt++){
        int x, k; cin>>x>>k;
        vector<int> a;
        while (k--){
            int p; cin>>p;
            a.pb(p);
        }
        qs[x].pb({tt, a});
    }
    
    vector<int> out(q + 1), nt(n + 1);
    function<void(int, int)> solve = [&](int v, int pr){
        for (auto &[tt, a]: qs[v]){
            vector<pii> bad;
            for (int x: a){
                if (check(x, v)){
                    bad.pb({1, tin[nt[x]] - 1});
                    bad.pb({tout[nt[x]] + 1, n});
                }
                else {
                    bad.pb({tin[x], tout[x]});
                }
            }
            sort(bad.begin(), bad.end());
            int pre = 1;
            for (auto &[l, r]: bad){
                out[tt] = max(out[tt], T.get(pre, l - 1));
                pre = max(pre, r + 1);
            }
            out[tt] = max(out[tt], T.get(pre, n));
        }
        T.upd(1, n, 1);
        for (int i: g[v]){
            if (i == pr) continue;
            nt[v] = i;
            T.upd(tin[i], tout[i], -2);
            solve(i, v);
            T.upd(tin[i], tout[i], 2);
        }
        T.upd(1, n, -1);
    };
    solve(1, 0);
    
    for (int i = 1; i <= q; i++){
        cout<<--out[i]<<"\n";
    }
}