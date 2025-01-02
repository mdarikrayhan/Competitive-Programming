#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int> > g(n + 1);
    while(m--){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int idx = 0;
    vector<vector<int> > cycle;

    vector<int> id(n + 1, -1), fa(n + 1);
    vector<bool> v(n + 1), ins(n + 1);

    auto dfs = [&](auto &&dfs, int u) -> void {
        v[u] = true;
        ins[u] = true;
        for(auto j : g[u]){
            if (j == fa[u]) continue;
            if (!v[j]){
                fa[j] = u;
                dfs(dfs, j);
            }
            else if (ins[j]){
                int t = u;
                vector<int> v{u};
                while(t != j){
                    t = fa[t];
                    v.push_back(t);
                }
                for(auto x : v){
                    id[x] = idx;
                }
                cycle.push_back(v);
                idx += 1;
            }
        }
        ins[u] = false;
    };

    dfs(dfs, 1);
    for(int i = 1; i <= n; i++){
        if (id[i] == -1){
            id[i] = idx++;
            cycle.push_back({i});
        }
    }
    vector<int> len(cycle.size());
    for(int i = 0; i < cycle.size(); i++){
        len[i] = cycle[i].size();
    }
    vector<int> mx1(n + 1), mx2(n + 1);

    auto dis = [&](int a, int b, int len){
        if (a > b) swap(a, b);
        return min(b - a, len - b + a);
    };
    vector<int> f(n + 1), ans(n + 1);

    auto dfs1 = [&](auto &&dfs1, int u, int fa) -> void {
        int cid = id[u];
        int t = -1;
        for(int i = 0; i < cycle[cid].size(); i++){
            if (cycle[cid][i] == u){
                t = i;
                break;
            }
        }
        rotate(cycle[cid].begin(), cycle[cid].begin() + t, cycle[cid].end());
        for(auto x : cycle[cid]){
            for(auto j : g[x]){
                if (id[j] == cid || j == fa) continue;
                dfs1(dfs1, j, x);
                int t = max(f[j], mx1[j]) + 1;
                if (t >= mx1[x]){
                    mx2[x] = mx1[x];
                    mx1[x] = t;
                }
                else if (t + 1 > mx2[x]){
                    mx2[x] = t;
                }
            }
        }
        for(int i = 1; i < len[cid]; i++){
            f[u] = max(f[u], dis(0, i, len[cid]) + mx1[cycle[cid][i]]);
        }
    };

    auto dfs2 = [&](auto &&dfs2, int u, int fa, int pre) -> void {
        int cid = id[u];
        if (pre >= mx1[u]){
            mx2[u] = mx1[u];
            mx1[u] = pre;
        }
        else if (pre > mx2[u]){
            mx2[u] = pre;
        }
        // if (len[cid] == 1){
        //     ans[u] = max({mx1[u], f[u], pre});
        //     for(auto j : g[u]){
        //         if (j == fa) continue;
        //         int t = max(f[j], mx1[j] + 1);
        //         if (t + 1 == mx1[u]){
        //             dfs2(dfs2, j, u, mx2[u] + 1);
        //         }
        //         else{
        //             dfs2(dfs2, j, u, mx1[u] + 1);
        //         }
        //     }
        // }
        // else{
        auto bk = cycle[cid];
        bk.resize(2 * len[cid]);
        for(int i = 0; i < len[cid]; i++){
            bk[i + len[cid]] = bk[i];
        }
        int mx = len[cid] / 2;
        deque<int> q;

        auto get1 = [&](int t){
            return mx1[bk[t]] - t;
        };

        auto get2 = [&](int t){
            return mx1[bk[t]] + t;
        };

        for(int i = 0; i < 2 * len[cid]; i++){
            while(!q.empty() && i - q.front() > mx) q.pop_front();
            if (i >= len[cid] && !q.empty()){
                int x = bk[i];
                ans[x] = max(ans[x], i + get1(q.front()));
            }
            while(!q.empty() && get1(i) >= get1(q.back())) q.pop_back();
            q.push_back(i);
        }
        q.clear();
        for(int i = 2 * len[cid] - 1; i >= 0; i--){
            while(!q.empty() && q.front() - i > mx) q.pop_front();
            if (i < len[cid] && !q.empty()){
                int x = bk[i];
                ans[x] = max(ans[x], -i + get2(q.front()));
            }
            while(!q.empty() && get2(i) >= get2(q.back())) q.pop_back();
            q.push_back(i);
        }
        for(auto x : cycle[cid]){
            for(auto j : g[x]){
                if (id[j] == cid || j == fa) continue;
                int t = max(f[j], mx1[j]) + 1;
                if (t == mx1[x]){
                    dfs2(dfs2, j, x, max(mx2[x], ans[x]) + 1);
                }
                else{
                    dfs2(dfs2, j, x, max(mx1[x], ans[x]) + 1);
                }
            }
        }
        // }
    };

    dfs1(dfs1, 1, -1);
    dfs2(dfs2, 1, -1, 0);
    // for(int i = 1; i <= n; i++){
    //     cout << mx1[i] << " \n"[i == n];
    // }
    // for(int i = 1; i <= n; i++){
    //     cout << f[i] << " \n"[i == n];
    // }
    for(int i = 1; i <= n; i++){
        cout << max(ans[i], mx1[i]) << " \n"[i == n];
    }

}