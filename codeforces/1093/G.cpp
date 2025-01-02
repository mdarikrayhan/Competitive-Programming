// LUOGU_RID: 160062406
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5 + 10;
const int MAXK = 33;

int n, k, q;
struct node{
    int l, r;
    int v[MAXK];
    node(){ for(int i = 0; i < MAXK; ++i) v[i] = 0; }
};
node tree[MAXN << 2];
int a[MAXN][6];

void push_up(int p){
    for(int i = 0; i < (1 << k); ++i) tree[p].v[i] = max(tree[p << 1].v[i], tree[p << 1 | 1].v[i]);
}

void build(int p, int l, int r){
    tree[p].l = l; tree[p].r = r;
    if(l == r){
        for(int i = 0; i < (1 << k); ++i){
            for(int j = 0; j < k; ++j){
                if(i & (1 << j)) tree[p].v[i] += a[l][j + 1];
                else tree[p].v[i] -= a[l][j + 1];
            }
        }
        return ;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}

void update(int p, int x){
    if(tree[p].l == tree[p].r){
        for(int i = 0; i < (1 << k); ++i){
            tree[p].v[i] = 0;
            for(int j = 0; j < k; ++j){
                if(i & (1 << j)) tree[p].v[i] += a[x][j + 1];
                else tree[p].v[i] -= a[x][j + 1];
            }
        }
        return ;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if(x <= mid) update(p << 1, x);
    else update(p << 1 | 1, x);
    push_up(p);
}

node Max(node x, node y){
    node z;
    for(int i = 0; i < (1 << k); ++i) z.v[i] = max(x.v[i], y.v[i]);
    return z;
}

node query(int p, int l, int r){
    if(l <= tree[p].l && tree[p].r <= r) return tree[p];
    int mid = (tree[p].l + tree[p].r) >> 1;
    node res;
    for(int i = 0; i < (1 << k); ++i) res.v[i] = -1e9;
    if(l <= mid) res = Max(res, query(p << 1, l, r));
    if(mid < r) res = Max(res, query(p << 1 | 1, l, r));
//    cout << p << " " << tree[p].l << " " << tree[p].r << '\n';
//    for(int i = 0; i < (1 << k); ++i) cout << res.v[i] << " ";
//    cout << '\n';
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            cin >> a[i][j];
        }
    }
    build(1, 1, n);
    cin >> q;
    int state = (1 << k);
    
    while(q--){
        int opt;
        cin >> opt;
        if(opt == 1){
            int t;
            cin >> t;
            for(int i = 1; i <= k; ++i) cin >> a[t][i];
            update(1, t);
        }
        else{
            int l, r, ans = 0;
            cin >> l >> r;
            node res = query(1, l, r);
            for(int i = 0; i < (1 << k); ++i) ans = max(ans, res.v[i] + res.v[i ^ (state - 1)]);
            cout << ans << '\n';
        }
    }

    return 0;
}
