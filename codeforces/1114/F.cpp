#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using pii = pair<int, int>;

#define F first
#define S second
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll get_rand(ll l, ll r) {
    assert(l <= r);
    return uniform_int_distribution<ll> (l, r)(rng);
}

const int N = 4e5 + 3;
const int A = 303;
const ll mod = 1e9 + 7;

ll mul(ll x, ll y){ x %= mod, y %= mod; return (x * y) % mod; }

ll binpow(ll a, ll b){
    if(b == 0) return 1;
    ll res = binpow(a, b >> 1);
    res = (res * res) % mod;
    if(b & 1)
        return (res * a) % mod;
    return res;
}

struct ST_prod{
    int n;
    vector<ll> st, lazy;

    void init(int _n){
        n = _n;
        st.resize(4 * n + 6, 1);
        lazy.resize(4 * n + 6, 1);
    }

    void down(int id, int l, int r){
        if(lazy[id] == 1)
            return;
        int mid = (l + r) >> 1;
        st[id << 1] = mul(st[id << 1], binpow(lazy[id], mid - l + 1));
        st[id << 1 | 1] = mul(st[id << 1 | 1], binpow(lazy[id], r - mid));
        lazy[id << 1] = mul(lazy[id << 1], lazy[id]);
        lazy[id << 1 | 1] = mul(lazy[id << 1 | 1], lazy[id]);
        lazy[id] = 1;
    }

    void _update(int id, int l, int r, int tl, int tr, ll val){
        if(l > tr or tl > r)
            return;
        if(tl <= l and r <= tr){
            st[id] = mul(st[id], binpow(val, r - l + 1));
            lazy[id] = mul(lazy[id], val);
            return;
        }
        int mid = (l + r) >> 1;
        down(id, l, r);
        _update(id << 1, l, mid, tl, tr, val);
        _update(id << 1 | 1, mid + 1, r, tl, tr, val);
        st[id] = mul(st[id << 1], st[id << 1 | 1]);
    }

    ll _get(int id, int l, int r, int tl, int tr){
        if(l > tr or tl > r)
            return 1;
        if(tl <= l and r <= tr)
            return st[id];
        int mid = (l + r) >> 1;
        down(id, l, r);
        return mul(_get(id << 1, l, mid, tl, tr), _get(id << 1 | 1, mid + 1, r, tl, tr));
    }

    void update(int l, int r, ll val){ _update(1, 1, n, l, r, val); }
    ll get(int l, int r){ return _get(1, 1, n, l, r); }
} st_prod;

struct ST_or{
    int n;
    vector<ll> st, lazy;

    void init(int _n){
        n = _n;
        st.resize(4 * n + 6, 0);
        lazy.resize(4 * n + 6, 0);
    }

    void down(int id){
        st[id << 1] |= lazy[id];
        st[id << 1 | 1] |= lazy[id];
        lazy[id << 1] |= lazy[id];
        lazy[id << 1 | 1] |= lazy[id];
        lazy[id] = 0;
    }

    void _update(int id, int l, int r, int tl, int tr, ll val){
        if(l > tr or tl > r)
            return;
        if(tl <= l and r <= tr){
            st[id] |= val;
            lazy[id] |= val;
            return;
        }
        int mid = (l + r) >> 1;
        down(id);
        _update(id << 1, l, mid, tl, tr, val);
        _update(id << 1 | 1, mid + 1, r, tl, tr, val);
        st[id] = st[id << 1] | st[id << 1 | 1];
    }

    ll _get(int id, int l, int r, int tl, int tr){
        if(l > tr or tl > r)
            return 0;
        if(tl <= l and r <= tr)
            return st[id];
        int mid = (l + r) >> 1;
        down(id);
        return _get(id << 1, l, mid, tl, tr) | _get(id << 1 | 1, mid + 1, r, tl, tr);
    }

    void update(int l, int r, ll val){ _update(1, 1, n, l, r, val); }
    ll get(int l, int r){ return _get(1, 1, n, l, r); }
} st_or;

int n, q;
ll a[N], mask[A], inv[A];
vector<ll> p;

bool is_prime(int x){
    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0) return 0;
    return 1;
}

void prep(){
    for(int i = 2; i < A; ++i){
        if(is_prime(i)){
            mask[i] = (1ll << sz(p));
            p.push_back(i);
            inv[i] = binpow(i, mod - 2);
        }
    }

    for(int i = 1; i < A; ++i)
        for(int pr : p)
            if(i % pr == 0)
                mask[i] |= mask[pr];
}

void solve(){
    prep();
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    st_prod.init(n);
    st_or.init(n);

    for(int i = 1; i <= n; ++i){
        st_prod.update(i, i, a[i]);
        st_or.update(i, i, mask[a[i]]);
    }

    while(q--){
        string opt;
        int l, r;
        cin >> opt >> l >> r;
        if(opt[0] == 'M'){
            ll x;
            cin >> x;
            st_prod.update(l, r, x);
            st_or.update(l, r, mask[x]);
        }
        else{
            ll x = st_prod.get(l, r);
            ll pmask = st_or.get(l, r);
            for(int i = 0; i < sz(p); ++i)
                if(pmask & (1ll << i))
                    x = mul(x, mul(p[i] - 1, inv[p[i]]));
            cout << x << '\n';
        }
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(0);
    #define task "troll"
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int test = 1;
//    cin >> test;
    for(int i = 1; i <= test; ++i){
//        cout << "Case #" << i << ": ";
        solve();
    }
    #ifdef LOCAL
        cerr << "\n[Time]: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
    #endif
    return 0;
}
