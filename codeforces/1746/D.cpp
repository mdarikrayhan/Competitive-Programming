// LUOGU_RID: 160216146
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i ++ ) {
        int x;
        cin >> x;
        adj[x].emplace_back(i);
    }

    vector<int> s(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> s[i];
    }

    i64 ans = 0;
    auto dfs = [&](auto self, int u, int k) -> int {
        ans += 1ll * k * s[u];
        int son = adj[u].size(); 
        if (!son) {
            return s[u];
        }   
        priority_queue<int> heap;
        for (auto v : adj[u]) {
            int sum = self(self, v, k / son);
            heap.push(sum);
        }
        int d = k % son;
        while (d -- ) {
            ans += heap.top();
            heap.pop();
        }
        return heap.top() + s[u];
    };

    dfs(dfs, 1, k);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    
    while (t --) {
        solve();
    }
    
    return 0;
}