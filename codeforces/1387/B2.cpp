#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // precompute size from root=0
    std::vector<int> sz(n);
    std::function<void(int, int)> dfs = [&](int u, int par) {
        sz[u] = 1;
        for (int v: adj[u]) {
            if (v != par) {
                dfs(v, u);
                sz[u] += sz[v];
            }
        }
    };
    dfs(0, -1);

    // find centroid
    std::function<int(int, int)> find_centroid = [&](int u, int par) {
        for (int v: adj[u]) {
            if (v != par && sz[v] > n/2) {
                return find_centroid(v, u);
            }
        }
        return u;
    };
    int c = find_centroid(0, -1);

    // calculate the answer
    long long ans = 0;
    std::vector<std::vector<int>> nodes;
    std::function<void(int, int, int, int)> solve = [&](int u, int par, int head, int depth) {
        ans += depth;
        nodes[head].push_back(u);
        for (int v: adj[u]) {
            if (v == par) {
                continue;
            }
            solve(v, u, head, depth+1);
        }
    };
    nodes.push_back({c});
    int head = 1;
    for (int v: adj[c]) {
        nodes.push_back({});
        solve(v, c, head++, 1);
    }

    int mxpos = 1;
    for (int h = 1; h < head; h++) {
        if (nodes[mxpos].size() < nodes[h].size()) {
            mxpos = h;
        }
    }
    std::swap(nodes[0], nodes[mxpos]);

    // std::cerr << "groups:" << std::endl;
    // for (int h = 0; h < head; h++) {
    //     std::cerr << "h " << h << ":";
    //     for (int u: nodes[h]) {
    //         std::cerr << " " << u+1;
    //     }
    //     std::cerr << std::endl;
    // }

    // construct an output
    std::vector<int> move_to(n, -1);
    for (int h = 0, i = 1, j = 0; h < head; h++) {
        for (int u: nodes[h]) {
            move_to[nodes[i][j]] = u;
            j++;
            if (j == nodes[i].size()) {
                i++;
                if (i == head) {
                    i = 0;
                }
                j = 0;
            }
        }
    }

    std::cout << ans*2 << std::endl;
    for (int u = 0; u < n; u++) {
        std::cout << move_to[u]+1 << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
