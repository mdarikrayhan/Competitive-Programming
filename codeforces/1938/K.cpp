#include<iostream>
#include<cstring>
#include<vector>
#include<numeric>
#include<functional>
#include<array>
#include<cassert>
using namespace std;
using LL = long long;

using Info = LL;

template<class Info>
struct SegmentTree{
    int n;
    vector<Info> info;

    SegmentTree() {}

    SegmentTree(int n, Info _init = Info()){
        init(vector<Info>(n, _init));
    }

    SegmentTree(const vector<Info> &_init){
        init(_init);
    }

    void init(const vector<Info> &_init){
        n = (int)_init.size();
        info.assign((n << 2) + 1, Info());
        function<void(int, int, int)> build = [&](int p, int l, int r){
            if (l == r){
                info[p] = _init[l - 1];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m + 1, r);
            pull(p);
        };
        build(1, 1, n);
    }

    void pull(int p){
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void modify(int p, int l, int r, int x, const Info &v){
        if (l == r){
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x <= m){
            modify(2 * p, l, m, x, v);
        } 
        else{
            modify(2 * p + 1, m + 1, r, x, v);
        }
        pull(p);
    }

    void modify(int p, const Info &v){
        modify(1, 1, n, p, v);
    }

    Info query(int p, int l, int r, int x, int y){
        if (l > y || r < x){
            return Info();
        }
        if (l >= x && r <= y){
            return info[p];
        }
        int m = (l + r) / 2;
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m + 1, r, x, y);
    }

    Info query(int l, int r){
        return query(1, 1, n, l, r);
    }

    int find_first(int p, int l, int r, int L, int R, const function<bool(const Info&)> &f, Info &pre){
        if (l > R || r < L){
            return r + 1;
        }
        if (l >= L && r <= R){
            if (!f(pre + info[p])){
                pre = pre + info[p];
                return r + 1;
            }
            if (l == r) return r;
            int m = (l + r) / 2;
            int res;
            if (f(pre + info[2 * p])){
                res = find_first(2 * p, l, m, L, R, f, pre);
            }
            else{
                pre = pre + info[2 * p];
                res = find_first(2 * p + 1, m + 1, r, L, R, f, pre);
            }
            return res;
        }
        int m = (l + r) / 2;
        int res = m + 1;
        if (L <= m){
            res = find_first(2 * p, l, m, L, R, f, pre);
        }
        if (R > m && res == m + 1){
            res = find_first(2 * p + 1, m + 1, r, L, R, f, pre);
        }
        return res;
    }

    int find_first(int l, int r, const function<bool(const Info&)> &f){
        Info pre = Info();
        return find_first(1, 1, n, l, r, f, pre);
    }

    int find_last(int p, int l, int r, int L, int R, const function<bool(const Info&)> &f, Info &suf){
        if (l > R || r < L){
            return l - 1;
        }
        if (l >= L && r <= R){
            if (!f(info[p] + suf)){
                suf = info[p] + suf;
                return l - 1;
            }
            if (l == r) return r;
            int m = (l + r) / 2;
            int res;
            if (f(info[2 * p + 1] + suf)){
                res = find_last(2 * p + 1, m + 1, r, L, R, f, suf);
            }
            else{
                suf = info[2 * p + 1] + suf;
                res = find_last(2 * p, l, m, L, R, f, suf);
            }
            return res;
        }
        int m = (l + r) / 2;
        int res = m;
        if (R > m){
            res = find_last(2 * p + 1, m + 1, r, L, R, f, suf);
        }
        if (L <= m && res == m){
            res = find_last(2 * p, l, m, L, R, f, suf);
        }
        return res;        
    }

    int find_last(int l, int r, const function<bool(const Info&)> &f){
        Info suf = Info();
        return find_last(1, 1, n, l, r, f, suf);
    }
};

const int maxn = 1e5 + 5;
int tr[maxn * 32], ls[maxn * 32], rs[maxn * 32];
int root[maxn];
int idx;

void modify(int &now, int pre, int l, int r, int x, int v){
    tr[now = ++idx] = tr[pre];
    ls[now] = ls[pre];
    rs[now] = rs[pre];
    if (l == r){
        tr[now] += v;
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid) modify(ls[now], ls[pre], l, mid, x, v);
    else modify(rs[now], rs[pre], mid + 1, r, x, v);
    tr[now] = tr[ls[now]] + tr[rs[now]];
}

int find(int root1, int root2, int root3, int root4, int l, int r, int k){
    if (l == r) return r;
    int sl = tr[ls[root1]] + tr[ls[root2]] - tr[ls[root3]] - tr[ls[root4]];
    int mid = (l + r) / 2;
    if (sl >= k){
        return find(ls[root1], ls[root2], ls[root3], ls[root4], l, mid, k);
    }
    return find(rs[root1], rs[root2], rs[root3], rs[root4], mid + 1, r, k - sl);
}

int sum(int root1, int root2, int l, int r, int L, int R){
    if (l > R || r < L) return 0;
    if (l >= L && r <= R) return tr[root2] - tr[root1];
    int mid = (l + r) / 2;
    return sum(ls[root1], ls[root2], l, mid, L, R)
         + sum(rs[root1], rs[root2], mid + 1, r, L, R);
}

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<vector<int> > g(n + 1);
    int r = -1;
    vector<array<int, 20> > fa(n + 1);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x == 0) r = i;
        fa[i][0] = x;
        g[x].push_back(i);
    }
    for(int i = 1; i <= 19; i++){
        for(int j = 1; j <= n; j++){
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
        }
    }

    vector<int> sz(n + 1), in(n + 1), out(n + 1), seq(n + 1), dep(n + 1);
    int ts = 0;

    auto dfs1 = [&](auto &&dfs1, int u) -> void {
        in[u] = ++ts;
        seq[ts] = u;
        sz[u] = 1;
        for(auto j : g[u]){
            dep[j] = dep[u] + 1;
            dfs1(dfs1, j);
            sz[u] += sz[j];
        }
        out[u] = ts;
    };

    dep[r] = 1;
    dfs1(dfs1, r);

    for(int i = 1; i <= n; i++){
        modify(root[i], root[i - 1], 1, n, seq[i], 1);
    }

    vector<vector<pair<LL, int> > > query(n + 1);
    vector<LL> ans(q);
    for(int i = 0; i < q; i++){
        LL x;
        cin >> x;
        x--;
        auto [d, r] = div(x, 1LL * n);
        ans[i] += 1LL * d * n * n;
        query[d + 1].push_back({r, i});
    }

    SegmentTree<Info> seg(n);

    auto jump = [&](int x, int k){
        for(int i = 19; i >= 0; i--){
            if (k >> i & 1){
                x = fa[x][i];
            }
        }
        return x;
    };

    auto dfs2 = [&](auto &&dfs2, int u) -> void {
        seg.modify(u, sz[u]);
        for(auto [d, id] : query[u]){
            d += 1;
            
            auto f = [&](const Info &info){
                return info >= d;
            };

            int anc = seg.find_first(1, n, f);
            
            ans[id] += 1LL * (anc - 1) * n;
            int k = d - seg.query(1, anc - 1);
            int t = -1;
            if (anc == u){
                t = find(root[out[u]], 0, root[in[u] - 1], 0, 1, n, k);
            }
            else{
                int son = jump(u, dep[u] - dep[anc] - 1);
                t = find(root[out[anc]], root[in[son] - 1], root[out[son]], root[in[anc] - 1], 1, n, k);
            }
            ans[id] += t - 1;
        }

        for(auto j : g[u]){
            seg.modify(u, sz[u] - sz[j]);
            dfs2(dfs2, j);
        }
        seg.modify(u, 0);
    };

    dfs2(dfs2, r);
    for(auto x : ans) cout << x << '\n';

}