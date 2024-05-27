/*
Problem: 1344C
Date: 28-05-2024 03:49 AM
*/


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int N = 2e5 + 5;
int n, m, u[N], v[N], t[N], dp1[N], dp2[N];
vector<int> adj[N], adjr[N];
vector<int> topo;
bool vis[N];

void dfs(int x) {
    vis[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
        }
    }
    t[x] = (int) topo.size();
    topo.push_back(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    // Read input as a directed graph of inequalities
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        adj[u[i]].push_back(v[i]);
        adjr[v[i]].push_back(u[i]);
    }
    // Find a topological order, or detect a cycle.
    // A cycle indicates the formula is contradictory, so no solution exists.
    // Otherwise, we at least know the statement is true with all existentials.
    for(int x = 1; x <= n; x++) {
        if(!vis[x]) {
            dfs(x);
        }
    }
    for(int i = 0; i < m; i++) {
        // it is guaranteed u[i] != v[i], so we can safely ignore the equal case.
        if(t[u[i]] < t[v[i]]) {
            cout << "-1\n";
            return 0;
        }
    }
    // A variable can only be universal if it is compared with variables that appear later.
    // Use DP on the topo sort in both directions to determine the minimum reachable node.
    fill(dp1, dp1 + N, N);
    fill(dp2, dp2 + N, N);
    for(int i = 0; i < n; i++) {
        int x = topo[i];
        dp1[i] = min(dp1[i], x);
        assert(t[x] == i);
        for(int y : adjr[x]) {
            assert(t[x] < t[y]);
            dp1[t[y]] = min(dp1[t[y]], dp1[i]);
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        int x = topo[i];
        dp2[i] = min(dp2[i], x);
        assert(t[x] == i);
        for(int y : adj[x]) {
            assert(t[x] > t[y]);
            dp2[t[y]] = min(dp2[t[y]], dp2[i]);
        }
    }
    int k = 0;
    string ans = "";
    for(int x = 1; x <= n; x++) {
        if(min(dp1[t[x]], dp2[t[x]]) == x) {
            ans += 'A';
            k++;
        }else {
            ans += 'E';
        }
    }
    cout << k << '\n' << ans << '\n';
}