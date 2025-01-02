#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define pb push_back
#define ff first
#define ss second
#define ins insert
const int mod = 1e9 + 7;
const int base = 47;

vector<int> pw;

struct ST{
    struct node{
        node *l, *r;
        int h, len;
        node(bool t){
            l = r = 0;
            h = (t + 1);
            len = 1;
        }
        node(node *left, node *right){
            l = left;
            r = right;
            len = l -> len + r -> len;
            h = (l -> h + 1LL * pw[l -> len] * (r -> h)) % mod;
        }
    };
    vector<node*> root;
    int n, cnt, q;
    node* build(int tl, int tr){
        if (tl == tr) return new node(0);
        int tm = (tl + tr) / 2;
        return new node(build(tl, tm), build(tm + 1, tr));
    }
    ST(int ns, int qs){
        n = ns; q = qs;
        root.resize(q + 1);
        root[0] = build(1, n);
        cnt = 0;
    }
    node* upd(node* v, int tl, int tr, int& p, bool& k){
        if (tl == tr) return new node(k);
        int tm = (tl + tr) / 2;
        if (p <= tm) return new node(upd(v -> l, tl, tm, p, k), v -> r);
        return new node(v -> l, upd(v -> r, tm + 1, tr, p, k));
    }
    void upd(int p, bool k){
        cnt++;
        root[cnt] = upd(root[cnt - 1], 1, n, p, k);
    }
    int solve(node* u, node* v, int tl, int tr){
        if (tl == tr){
            if (u -> h == v -> h) return 0;
            return tl;
        }
        int tm = (tl + tr) / 2;
        if (u -> l -> h != v -> l -> h){
            return solve(u -> l, v -> l, tl, tm);
        }
        return solve(u -> r, v -> r, tm + 1, tr);
    }
    int solve(int l, int r){
        return solve(root[l - 1], root[r], 1, n);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin>>n;
    pw.resize(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++){
        pw[i] = (1LL * pw[i - 1] * base) % mod;
    }
    
    vector<int> a(n + 1), all;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        all.pb(a[i]);
    }
    sort(all.begin(), all.end());
    int i = 0, cnt = 0;
    map<int, int> mp;
    vector<int> x(n + 1);
    while (i < all.size()){
        int j = i;
        while (j < all.size() && all[i] == all[j]){
            j++;
        }
        mp[all[i]] = ++cnt;
        x[cnt] = all[i];
        i = j;
    }
    for (int i = 1; i <= n; i++){
        a[i] = mp[a[i]];
    }
    
    ST T(cnt, n);
    vector<bool> t(n + 1);
    for (int i = 1; i <= n; i++){
        T.upd(a[i], !t[a[i]]);
        t[a[i]] = !t[a[i]];
    }

    int q; cin>>q;
    int out = 0;
    while (q--){
        int a, b; cin>>a>>b;
        int l = a ^ out, r = b ^ out;
        out = x[T.solve(l, r)];
        cout<<out<<"\n";
    }
}