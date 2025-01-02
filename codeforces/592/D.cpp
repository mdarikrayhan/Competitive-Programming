/*
Problem: 592D
Date: 27-05-2024 02:30 AM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

// in compressed tree, find longest edge
// if ties, choose one with smallest vertex label.
// sort the m nodes by preorder

// farthest pair
// at a node, store pair (depth, -index) for the deepest attack node in subtree

const int N = 123460;
int n, m, u, v;
vector<int> adj[N];
int depth[N], tin[N], tout[N], a[N], p[N];
bool vis[N], b[N];
int t = 0;
pair<int, int> dp[N];
pair<int, int> ans = {-2, 0};

void dfs(int x) {
    vis[x] = true;
    tin[x] = t++;
    dp[x] = {-1, -1};
    vector<pair<int, int>> ve;
    if(b[x]) {
        dp[x] = {0, -x};
        ans = max(ans, dp[x]);
        ve.push_back(dp[x]);
    }
    for(int y : adj[x]) {
        if(!vis[y]) {
            p[y] = x;
            depth[y] = depth[x] + 1;
            dfs(y);
            if(dp[y].first != -1) {
                dp[x] = max(dp[x], {dp[y].first + 1, dp[y].second});
                ve.push_back({dp[y].first + 1, dp[y].second});
            }
        }
    }
    tout[x] = t++;
    if((int) ve.size() >= 2) {
        sort(ve.rbegin(), ve.rend());
        auto [d1, x1] = ve[0];
        auto [d2, x2] = ve[1];
        ans = max(ans, {d1 + d2, max(x1, x2)});
    }
}
bool anc(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        b[a[i]] = true;
    }
    p[a[0]] = a[0];
    dfs(a[0]);
    sort(a, a + m, [&](int x, int y) {
        return tin[x] < tin[y];
    });
    stack<int> st;
    st.push(a[0]);
    int dist = 0;
    for(int i = 0; i < m; i++) {
        while(!anc(st.top(), a[i])) {
            int x = st.top();
            st.pop();
            st.push(p[x]);
            dist++;
        }
        dist += depth[a[i]] - depth[st.top()];
        st.push(a[i]);
    }
    dist += depth[st.top()];
    cout << -ans.second << '\n' << dist - ans.first << '\n';
}