#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<map<int, int>> adj;
vector<bool> vis;

void dfs(int v) {
    vis[v] = true;
    for (auto &[u, weight] : adj[v]) {
        if (!vis[u]) {
            dfs(u);
            if (weight == 1) {
                weight = 2; // Update the weight to 2
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    adj.resize(n);
    vis.resize(n);

    vector<pair<int, int>> un_edge;
    for (int i = 0; i < m; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        a--;
        b--;
        if (t == 1) {
            adj[a][b] = 0; // Edge from 'a' to 'b' with weight 0
        } else if (t == 2) {
            un_edge.push_back({a, b});
        }
    }
    
    dfs(s);

    string s2 = "";
    int ans2 = 0;
    for (auto &[a, b] : un_edge) {
        if (!vis[a] && vis[b]) {
            s2 += '+';
        } else {
            s2 += '-';
        }
    }
    for (bool v : vis) {
        if (v) {
            ans2++;
        }
    }

    vis.assign(n, false);
    int ans1 = 0;
    string s1 = "";
    for (auto &[a, b] : un_edge) {
        adj[a][b] = 1; // Add the un_edge as a two-way edge
        adj[b][a] = 1;
    }
    dfs(s);
    for (bool v : vis) {
        if (v) {
            ans1++;
        }
    }
    for (auto &[a, b] : un_edge) {
        if (adj[a][b] == 2) {
            s1 += '+';
        } else {
            s1 += '-';
        }
    }
    cout << ans1 << endl;
    cout << s1 << endl;
    cout << ans2 << endl;
    cout << s2 << endl;
    cout.flush();
    return 0;
}
