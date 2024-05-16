#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int root;
        vector<vector<int>> adj(n);
        vector<int> parent(n);

        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;

            p--;

            if (p == i) {
                root = i;
            }
            else {
                adj[p].push_back(i);
                parent[i] = p;
            }
        }

        vector<vector<int>> paths;
        paths.push_back({});
        auto dfs = [&] (int node, int idx, auto &&dfs) -> void {
            paths[idx].push_back(node);
            bool flag = true;

            for (auto child : adj[node]) {
                if (flag) {
                    flag = false;
                    dfs(child, idx, dfs);
                }
                else {
                    int c = paths.size();
                    paths.push_back({});
                    dfs(child, c, dfs);
                }
            }
        };

        dfs(root, 0, dfs);

        cout << paths.size() << '\n';

        for (int i = 0; i < paths.size(); i++) {
            cout << paths[i].size() << '\n';
        
            for (int num : paths[i]) cout << num+1 << ' ';
            cout << '\n';
        }

        cout << '\n';

    }

    return 0;
}