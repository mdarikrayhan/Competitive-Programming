/*
Problem: 1338D
Date: 24-05-2024 08:33 PM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, a, b;
vector<int> adj[N], child[N], m0[N], m1[N];
bool vis[N];
int dp0[N], dp1[N];

void dfs(int x) {
    vis[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
            child[x].push_back(y);
            m0[x].push_back(dp0[y]);
            m1[x].push_back(dp1[y]);
        }
    }
    sort(m0[x].begin(), m0[x].end());
    sort(m1[x].begin(), m1[x].end());
    if(child[x].empty()) {
        dp0[x] = 0;
        dp1[x] = 1;
    }else {
        dp0[x] = m1[x].back() + child[x].size() - 1;
        dp1[x] = max(dp0[x], m0[x].back() + 1);
    }
}
void dfs2(int x) {
    for(int y : child[x]) {
        // find fake dp0[x] and dp1[x] if root from y
        // assume at this point they take into account parent of x
        int newm0 = m0[x].back(), newm1 = m1[x].back();
        if(dp0[y] == newm0) {
            newm0 = (m0[x].size() >= 2 ? m0[x][(int) m0[x].size() - 2] : 0);
        }
        if(dp1[y] == newm1) {
            newm1 = (m1[x].size() >= 2 ? m1[x][(int) m1[x].size() - 2] : 0);
        }
        int fake0 = newm1 + child[x].size() - 1 + (x == 1 ? -1 : 0);
        int fake1 = max(fake0, newm0 + 1);
        m0[y].push_back(fake0);
        m1[y].push_back(fake1);
        sort(m0[y].begin(), m0[y].end());
        sort(m1[y].begin(), m1[y].end());
        dp0[y] = m1[y].back() + child[y].size();
        dp1[y] = max(dp0[y], m0[x].back() + 1);
        dfs2(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    dfs2(1);
    int ans = *max_element(dp1 + 1, dp1 + n + 1);
    cout << ans << '\n';
}