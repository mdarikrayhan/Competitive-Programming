#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
#define int long long
const int MAXN = 1e5 + 5, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
vector<ll> pre_pow1, pre_pow2;
ll prime1, prime2;
vector<vector<ll>> updates1(10),updates2(10);
struct node {
    int h1 = 0, h2 = 0;

    node() {};

    node(int h1, int h2) : h1(h1), h2(h2) {}
};

void init() {
    prime1 = 31,prime2 = 51;
    pre_pow1.resize(MAXN + 1);
    pre_pow2.resize(MAXN + 1);
    pre_pow1[0] = pre_pow2[0] = 1;
    ll sum1 = 0 , sum2 = 0;
    updates1.emplace_back(),updates2.emplace_back();
    for (int i = 1; i <= MAXN; i++) {
        pre_pow1[i] = prime1 * 1ll * pre_pow1[i-1] % mod1;
        pre_pow2[i] = prime2 * 1ll * pre_pow2[i-1] % mod2;
        for (int j = 1;j<=10;j++){
            updates1[j].push_back((j) *pre_pow1[i]%mod1);
            updates2[j].push_back(((j)*pre_pow2[i])%mod2);
            if(i - 2 > -1) (updates1[j][i - 1]+=updates1[j][i - 2])%=mod1;
            if(i - 2 > -1) (updates2[j][i - 1]+=updates2[j][i - 2])%=mod2;

        }
    }
}

node get(int u , int i , int j){
    ll sum1 = ((updates1[u][j] - (i-1 > -1 ? updates1[u][i-1] : 0) + mod1)%mod1);
    ll sum2 = ((updates2[u][j]- (i-1 > -1 ? updates2[u][i-1] : 0) + mod2)%mod2);
    return {sum1,sum2};
}
struct segtree {

    int n, N;
    vector<node> st;
    vector<int> lazy;

    int l(int p) { return p << 1; }

    int r(int p) { return p << 1 | 1; }

    node unit = node(0,0);

    segtree() {}

    segtree(int sz) : n(sz), N(1 << bit_width(unsigned(sz))),
                      st(2 * N), lazy(vector<int>(2 * N, -1)) {}

    node conq(node a, node b) {
        return node((a.h1 + b.h1 )%mod1, (a.h2 + b.h2)%mod2);
    }
    void propagate(int p, int L, int R) {
        if (lazy[p] != -1) {
            st[p] = get(lazy[p] ,L , R);
            if (L != R) {
                lazy[l(p)] = lazy[p];
                lazy[r(p)] = lazy[p];
            }
            lazy[p] = -1;
        }
    }

    node query(int p, int L, int R, int i, int j) {
        propagate(p, L, R);
        if (j < L || i > R) return unit;
        if ((L >= i) && (R <= j)) return st[p];
        int m = (L + R) / 2;
        return conq(query(l(p), L, m, i, j), query(r(p), m + 1, R, i, j));
    }

    void update(int p, int L, int R, int i, int j, int val) {
        propagate(p, L, R);
        if (j < L || i > R) return;
        if (L >= i && R <= j) {
            lazy[p] = val;
            propagate(p, L, R);
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, j, val);
            update(r(p), m + 1, R, i, j, val);
            st[p] = conq(st[l(p)], st[r(p)]);
        }
    }

    void update(int i, int j, ll val) {
        update(1, 0, n - 1, i, j, val + 1);
    }

    node query(int i, int j) {
        auto x = query(1, 0, n - 1, i, j);
        (x.h1*=pre_pow1[MAXN - 1 - i] % mod1)%=mod1;
        (x.h2*=pre_pow2[MAXN - 1 - i] % mod2)%=mod2;
        return x;
    }

};
void solve(){
    int n , m , k , q;
    cin >> n >> m >> k;
    q = m + k;
    string s;
    cin >> s;
    segtree st(n);
    for (int i = 0;i<n;i++) st.update(i , i , s[i] - '0');
    while(q--){
        int ty ,l  , r , c;
        cin >> ty >> l >> r >> c,l--,r--;
        if (ty == 1){
            st.update(l,r,c);
        }else{
            auto x = st.query(l + c,r),y = st.query(l ,r -  c) ;
            cout << (x.h1 == y.h1 && x.h2 == y.h2  ?"YES\n" : "NO\n");
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >>t;
    init();
    while(t--)
    solve();
}
