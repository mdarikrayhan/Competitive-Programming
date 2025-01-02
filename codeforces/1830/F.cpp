#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int t, n, m;
int p[N] = {0};
vector<int> v[N];
struct node{
    int a, b;
};
bool operator < (node a, node b){
    if(a.b == b.b)
    return a.a < b.a;
    return a.b < b.b;
}
int inter(node x, node y){
    int da = x.a - y.a, db = y.b - x.b;
    if(da >= 0 && db <= 0 || da <= 0 && db >= 0)
    return LONG_LONG_MAX;
    return (da > 0 ? (da + db - 1) / da : (-da - db + 1) / (-da));
}
struct ktt{
    int lz[N << 2], intr[N << 2];
    node s[N << 2];
    void build(int x = 1, int nl = 1, int nr = m){
        lz[x] = 0;
        s[x] = {LONG_LONG_MIN, LONG_LONG_MIN};
        intr[x] = LONG_LONG_MAX;
        if(nl == nr)
        return;
        int mid = nl + nr >> 1;
        build(x << 1, nl, mid);
        build(x << 1 | 1, mid + 1, nr);
        return;
    }
    void pushdown(int x){
        for(int y : {x << 1, x << 1 | 1}){
            lz[y] += lz[x];
            s[y].b += lz[x] * s[y].a;
            intr[y] -= lz[x];
        }
        lz[x] = 0;
        return;
    }
    void pushup(int x){
        s[x] = (s[x << 1] < s[x << 1 | 1] ? s[x << 1 | 1] : s[x << 1]);
        intr[x] = min({intr[x << 1], intr[x << 1 | 1], inter(s[x << 1], s[x << 1 | 1])});
        return;
    }
    void rebuild(int x){
        if(intr[x] > 0)
        return;
        pushdown(x);
        rebuild(x << 1);
        rebuild(x << 1 | 1);
        pushup(x);
        return;
    }
    void add(int l, int r, int k, int x = 1, int nl = 1, int nr = m){
        if(nl >= l && nr <= r){
            s[x].b += s[x].a * k;
            intr[x] -= k;
            lz[x] += k;
            rebuild(x);
            return;
        }
        pushdown(x);
        int mid = nl + nr >> 1;
        if(mid >= l)
        add(l, r, k, x << 1, nl, mid);
        if(mid + 1 <= r)
        add(l, r, k, x << 1 | 1, mid + 1, nr);
        pushup(x);
        return;
    }
    void revise(int p, node k, int x = 1, int nl = 1, int nr = m){
        if(nl == nr){
            s[x] = k;
            return;
        }
        pushdown(x);
        int mid = nl + nr >> 1;
        if(mid >= p)
        revise(p, k, x << 1, nl, mid);
        else
        revise(p, k, x << 1 | 1, mid + 1, nr);
        pushup(x);
        return;
    }
    int query(int l, int r, int x = 1, int nl = 1, int nr = m){
        if(nl >= l && nr <= r)
        return s[x].b;
        pushdown(x);
        int mid = nl + nr >> 1;
        int ans = 0;
        if(mid >= l)
        ans = max(ans, query(l, r, x << 1, nl, mid));
        if(mid + 1 <= r)
        ans = max(ans, query(l, r, x << 1 | 1, mid + 1, nr));
        pushup(x);
        return ans;
    }
}T;
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; i ++)
    v[i].clear();
    for(int i = 1; i <= n; i ++){
        int l, r;
        cin >> l >> r;
        v[r].push_back(l);
    } 
    for(int i = 1; i <= m;i ++)
    cin >> p[i];
    T.build();
    for(int i = 1; i <= m;i ++){
        int ans = (i == 1 ? 0:T.query(1, i - 1));
        T.revise(i, {p[i], ans});
        for(int j : v[i])
        T.add(j, i, 1);
    }
    cout << T.query(1, m) << "\n";
    return;
}
signed main(){
	ios::sync_with_stdio(false);
    cin >> t;
    while(t --)
    solve();
    return 0;
}