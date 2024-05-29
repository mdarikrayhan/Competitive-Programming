#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<array>
#include<numeric>
#include<functional>
#include<algorithm>
using namespace std;
using LL = long long;

struct Info {
    int mx = 0;
};

Info operator+(const Info &a, const Info &b){
    return {max(a.mx, b.mx)};
}

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

    void modify(int p, int l, int r, int x){
        if (l == r){
            info[p].mx += 1;
            return;
        }
        int m = (l + r) / 2;
        if (x <= m){
            modify(2 * p, l, m, x);
        } 
        else{
            modify(2 * p + 1, m + 1, r, x);
        }
        pull(p);
    }

    void modify(int p){
        modify(1, 1, n, p);
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
};


int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<vector<int> > g(n + 1);
    vector<int> ans(n + 1, 1);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        ans[1] = max(ans[1], int(g[i].size()) + 1);
    }

    vector<int> down(n + 1), up(n + 1), fa(n + 1);
    vector<array<int, 4> > event;

    vector<int> in(n + 1);
    int ts = 0;

    auto bfs = [&](){
        vector<bool> v(n + 1);
        queue<int> q;
        q.push(1);
        v[1] = true;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            in[t] = ++ts;
            for(auto j : g[t]){
                if (!v[j]){
                    v[j] = true;
                    q.push(j);
                }
            }
        }
    };

    bfs();

    vector<int> l(n + 1), r(n + 1);

    auto dfs1 = [&](auto &&dfs1, int u) -> void {
        for(auto it = g[u].begin(); it != g[u].end(); it++){
            if (*it == fa[u]){
                g[u].erase(it);
                break;
            }
        }
        l[u] = n + 1, r[u] = 0;
        for(auto j : g[u]){
            if (j == fa[u]) continue;
            fa[j] = u;
            dfs1(dfs1, j);
            down[u] = max(down[u], down[j] + 1);
            l[u] = min(l[u], in[j]);
            r[u] = max(r[u], in[j]);
        }
    };

    dfs1(dfs1, 1);

    vector<array<int, 4> > add;
    add.reserve(2 * n);

    auto dfs2 = [&](auto &&dfs2, int u, int pre) -> void {
        vector<array<int, 3> > v;
        if (pre != 0){
            v.push_back({pre, u, -1});
        }
        int mx1 = pre, mx2 = 0;
        for(int i = 0; i < g[u].size(); i++){
            int j = g[u][i];
            int t = down[j] + 1;
            v.push_back({t, u, i});
            if (t >= mx1){
                mx2 = mx1;
                mx1 = t;
            }
            else if (t > mx2){
                mx2 = t;
            }
        }
        sort(v.begin(), v.end(), greater<>());
        for(int i = 0; i < v.size(); i++){
            auto [val, p, q] = v[i];
            if (i > 0){
                ans[2 * val] = max(ans[2 * val], i + 1);
            }
            if (i > 0 && v[i - 1][0] > val){
                ans[2 * val + 1] = max(ans[2 * val + 1], i + 1);
            }
            add.push_back({val, p, q, i});
        }
        for(auto j : g[u]){
            int t = down[j] + 1;
            if (t == mx1){
                dfs2(dfs2, j, mx2 + 1);
            }
            else{
                dfs2(dfs2, j, mx1 + 1);
            }
        }
    };

    dfs2(dfs2, 1, 0);
    for(int i = n - 1; i >= 1; i--){
        ans[i] = max(ans[i], ans[i + 1]);
    }
    sort(add.begin(), add.end(), greater<>());
    SegmentTree<Info> seg(n);
    vector<int> cnt(n + 1);
    for(auto [val, p, q, rk] : add){
        cnt[p] += 1;
        seg.modify(in[p]);
        int mx = seg.query(l[p], r[p]).mx;
        if (fa[p]) mx = max(mx, cnt[fa[p]]);
        if (cnt[p] > 1 && mx > 1) ans[val * 2] = max(ans[val * 2], mx + cnt[p] - 2);
    }
    for(int i = n - 2; i >= 1; i--){
        ans[i] = max(ans[i], ans[i + 2]);
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " \n"[i == n];
    }

}