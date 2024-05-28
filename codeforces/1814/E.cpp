#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
using namespace std;

#define pb push_back

int mod = (int)1e9 + 7;
ll INF = (ll)1e18;

template<typename T>
T chmax(T a, T b) {
    return a > b ? a : b;
}

template<typename T>
T chmin(T a, T b) {
    return a > b ? b : a;
}

template<class Operation, class Mark>
struct SegTree{
    const int n;
    vector<Operation> op;
    vector<Mark> mrk;
 
    SegTree(int n) : n(n), op(4 << __lg(n)), mrk(4 << __lg(n)) {
        function<void(int, int, int)> build = [&](int u, int l, int r){
            op[u] = Operation();
            if(l == r) return;
            int mid = l + r >> 1;
            build(u << 1, l, mid);
            build(u << 1 | 1, mid + 1, r);
            pushup(u);
        };
 
        build(1, 1, n);
    }
 
    void pushup(int u){
        op[u] = op[u << 1] + op[u << 1 | 1];
    }
 
    void modify(int u, const Mark &mk){
        op[u].modify(mk);
        mrk[u].modify(mk);
    }
 
    void pushdown(int u) {
        modify(u << 1, mrk[u]);
        modify(u << 1 | 1, mrk[u]);
        mrk[u] = Mark();
    }
 
    void update(int u, int l, int r, int x, const Operation &v) {
        if(l == r){
            op[u] = v;
            return;
        }
        int m = (l + r) >> 1;
        pushdown(u);
 
        if(x <= m){
            update(u << 1, l, m, x, v);
        } 
        else{
            update(u << 1 | 1, m + 1, r, x, v);
        }
        pushup(u);
    }
 
    void update(int u, const Operation &v) {
        update(1, 1, n, u, v);
    }
 
    Operation query(int u, int l, int r, int x, int y) {
        if(x <= l && r <= y) {
            return op[u];
        }
        
        int m = (l + r) >> 1;
        Operation cur;
        pushdown(u);
        if(x <= m){
            cur = query(u << 1, l, m, x, y);
        }
        if(y > m){
            cur = cur + query(u << 1 | 1, m + 1, r, x, y);
        }
        return cur;
    }
 
    Operation query(int l, int r) {
        return query(1, 1, n, l, r);
    }
 
    void range_update(int u, int l, int r, int x, int y, const Mark &v) {
        if(l >= x && r <= y){
            modify(u, v);
            return;
        }
 
        int m = (l + r) >> 1;
        pushdown(u);
        if(x <= m){
            range_update(u << 1, l, m, x, y, v);
        }
        if(y > m){
            range_update(u << 1 | 1, m + 1, r, x, y, v);
        }
        pushup(u);
    }
 
    void range_update(int l, int r, const Mark &v) {
        return range_update(1, 1, n, l, r, v);
    }
};
 
struct Mark{
    int add;
    
    void modify(const Mark &v){

    }
};
 
struct Operation {
    ll a[2][2];
    
    Operation() : a{} {
        a[0][1] = a[1][0] = INF;
    }

    Operation(ll p){
        a[0][0] = INF;
        a[1][1] = p;
        a[1][0] = p;
        a[0][1] = 0;
    }

    void modify(const Mark &v){

    }
};
 
Operation operator+(Operation a, Operation b) {
    Operation c;
    c.a[0][0] = c.a[1][1] = INF;
 
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                c.a[i][j] = chmin(c.a[i][j], a.a[i][k] + b.a[k][j]);
            }
        }
    }
    return c;
}

void solve(){
    int n;
    cin >> n;

    SegTree<Operation, Mark> tr(n + 1);

    for(int i = 1; i < n; i++){
        int u;
        cin >> u;

        tr.update(i, {u});
    }

    int q;
    cin >> q;

    while(q--){
        int u, v;
        cin >> u >> v;
        tr.update(u, {v});
        cout << tr.query(1, n).a[1][0] * 2 << endl;
    }
}   

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }
    return 0;
}