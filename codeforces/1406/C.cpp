#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    std::vector<int> siz(n);
    auto dfs = [&](auto self, int x, int px) -> int {
        int sum = 1;
        for (auto y : adj[x]) {
            if (y == px) {
                continue;
            }
            int t = self(self, y, x);
            siz[x] = std::max(siz[x], t);
            sum += t;
        }
        siz[x] = std::max(siz[x], n - sum);
        return sum;
    };
    dfs(dfs, 0, -1);
    int min = *std::min_element(siz.begin(), siz.end());
    
    std::vector<int> g;
    for (int i = 0; i < n; i++) {
        if (siz[i] == min) {
            g.push_back(i);
        }
    }
    if (g.size() == 1) {
        std::cout << 1 << " " << adj[0].back() + 1 << "\n";
        std::cout << 1 << " " << adj[0].back() + 1 << "\n";   
    } else {
        int x = g[0];
        int px = -1;
        while (adj[x].size() != 1 || adj[x].back() != px) {
            for (auto y : adj[x]) {
                if (y == px || y == g[1]) {
                    continue;
                }
                px = x;
                x = y;
                break;
            }
        }
        std::cout << x + 1 << " " << adj[x].back() + 1 << "\n";
        std::cout << x + 1 << " " << g[1] + 1 << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
	  	 				 		   	 		 		 	 		 	 	