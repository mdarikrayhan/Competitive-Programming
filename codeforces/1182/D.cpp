//
// Created by codicon on 5/25/2024 at 10:52 PM.
//

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+1;

int n;
vector<int> adj[MAXN];

int check;
int sz[MAXN];
multiset<int> szs[MAXN];  // To handle star graph

void dfs(int c, int p) {
    sz[c] = 1;
    for (auto ne: adj[c]) {
        if (ne != p) {
            dfs(ne, c);
            sz[c] += sz[ne];
        }
    }

    if (c != 1) {
        szs[c].insert(n - sz[c]);
    }
    for (auto ne: adj[c]) {
        if (ne != p) {
            szs[c].insert(sz[ne]);
        }
    }

    if (size(adj[c]) > 1 and *szs[c].begin() == *szs[c].rbegin()) {
        check = c;  // Unique since centroid
    }
}

bool bad = false;
int deg[MAXN];

void dfs2(int c, int p, int d=0) {
    if (deg[d] == 0) deg[d] = size(adj[c]);

    if (size(adj[c]) != deg[d]) {
        bad = true;
    }

    for (auto ne: adj[c]) {
        if (ne != p) {
            dfs2(ne, c, d+1);
        }
    }
}

int chain;

bool dfs3(int c, int p, int d=0) {
    if (size(adj[c]) >= 3) {
        szs[c].extract(d);
        if (*szs[c].begin() == *szs[c].rbegin()) {
            check = c;
            chain = p;
        }
        szs[c].insert(d);

        return true;
    }

    for (auto ne: adj[c]) {
        if (ne != p) {
            if (dfs3(ne, c, d+1)) {
                return true;
            }
        }
    }

    return false;
}

void dfs4(int c, int p, int d=0) {
    if (deg[d] == 0) deg[d] = size(adj[c]);

    if (size(adj[c]) != deg[d]) {
        bad = true;
    }

    for (auto ne: adj[c]) {
        if (ne != p and ne != chain) {
            dfs4(ne, c, d+1);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1);

    int ans = -1;

    // Root non leaf
    if (check) {
        bad = false;
        dfs2(check, check);
        if (not bad) {
            ans = check;
        }
        else {
            check = 0;
        }
    }

    // Root leaf
    if (not check) {
        int leaf;
        for (int i = 1; i <= n; i++) {
            if (size(adj[i]) == 1) {
                if (not dfs3(i, i)) {
                    cout << i << '\n';
                    return 0;
                }

                if (check) {
                    leaf = i;
                    break;
                }
            }
        }

        if (check) {
            fill(deg, deg+n+1, 0);
            bad = false;
            dfs4(check, check);
            if (not bad) {
                ans = leaf;
            }
        }
    }

    cout << ans << '\n';
}
