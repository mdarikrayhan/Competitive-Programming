#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int maxn = 2e5 + 5;
pair<int, int> edge[maxn];
int pre1[maxn], pre2[maxn], nxt1[maxn], nxt2[maxn];
int ans[maxn];
bitset<1001> bs[maxn];

struct Query{
    int l, r, id;
};

void solve(int l, int r, vector<Query> query){
    if (query.empty()) return;
    if (l == r){
        for(auto [L, R, id] : query){
            ans[id] = 1;
        }
        return;
    }
    int mid = (l + r) / 2;
    vector<Query> ql, qr, cur;
    for(auto [L, R, id] : query){
        if (R <= mid){
            ql.push_back({L, R, id});
        }
        else if (L >= mid + 1){
            qr.push_back({L, R, id});
        }
        else{
            cur.push_back({L, R, id});
        }
    }
    solve(l, mid, ql);
    solve(mid + 1, r, qr);
    if (!cur.empty()){
        for(int i = mid; i >= l; i--){
            bs[i].reset();
            if (nxt1[i] <= mid){
                bs[i] |= bs[nxt1[i]];
            }
            if (nxt2[i] <= mid){
                bs[i] |= bs[nxt2[i]];
            }
            bs[i].set(edge[i].first);
            bs[i].set(edge[i].second);
        }
        for(int i = mid + 1; i <= r; i++){
            bs[i].reset();
            if (pre1[i] >= mid + 1){
                bs[i] |= bs[pre1[i]];
            }
            if (pre2[i] >= mid + 1){
                bs[i] |= bs[pre2[i]];
            }
            bs[i].set(edge[i].first);
            bs[i].set(edge[i].second);
        }
        for(auto [L, R, id] : cur){
            ans[id] = (bs[L] & bs[R]).any();
        }
    }
}

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int> > g(n + 1);
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(i);
        g[b].push_back(i);
        edge[i] = {a, b};
    }
    vector<int> last(n + 1, 0);
    for(int i = 1; i <= m; i++){
        auto [a, b] = edge[i];
        pre1[i] = last[a];
        pre2[i] = last[b];
        last[a] = last[b] = i;
    }
    last.assign(n + 1, m + 1);
    for(int i = m; i >= 1; i--){
        auto [a, b] = edge[i];
        nxt1[i] = last[a];
        nxt2[i] = last[b];
        last[a] = last[b] = i;
    }
    vector<Query> query;
    for(int i = 0; i < q; i++){
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        auto itl = lower_bound(g[a].begin(), g[a].end(), l);
        auto itr = upper_bound(g[b].begin(), g[b].end(), r);
        if (itl != g[a].end() && itr != g[b].begin()){
            int L = *itl, R = *prev(itr);
            if (L <= R){
                query.push_back({L, R, i});
            }
        }
    }
    solve(1, m, query);
    for(int i = 0; i < q; i++){
        cout << (ans[i] ? "Yes" : "No") << '\n';
    }

}