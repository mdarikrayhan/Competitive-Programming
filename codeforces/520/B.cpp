#include <bits/stdc++.h>
#include <cmath>
#define int long long
using namespace std;

int get_ans(int n, int m) {
    if (n >= m) return n - m;
    else {
        if (m % 2 == 0) {
            return get_ans(n, m / 2) + 1;
        } else {
            return get_ans(n, (m + 1) / 2) + 2;
        }
    }
}

int32_t main() {
    int n; cin >> n;
    int m; cin >> m;
    cout << get_ans(n, m);
    // if (n >= m) {
    //     cout << n - m;
    // } else {
    //     vector<vector<int>> adj(2 * m);
    //     for (int i = 1; i < 2 * m + 1; i++) {
    //         adj[i - 1].push_back(i - 1);
    //         if (2 * i - 1 < 2 * m) {
    //            adj[i - 1].push_back(2 * i - 1);
    //         }
    //     }
    //     // for (int i = 0; i < adj.size(); i++) {
    //     //     for (int j = 0; j < adj[i].size(); j++) {
    //     //         cout << adj[i][j] << ' ';
    //     //     }
    //     //     cout << '\n';
    //     // }

    //     queue<int> q;
    //     q.push(n - 1);
    //     vector<bool> used(2 * m);
    //     used[n - 1] = true;
    //     vector<int> dist(2 * m);
    //     while (!q.empty()) {
    //         int v = q.front();
    //         q.pop();
    //         for (int i = 0; i < adj[v].size(); i++) {
    //             int to = adj[v][i];
    //             if (!used[to]) {
    //                 used[to] = true;
    //                 q.push(to);
    //                 dist[to] = dist[v] + 1;
    //             }
    //         }
    //     }
    //     cout << dist[m - 1];
    //     // for (int i = 0; i < dist.size(); i++) {
    //     //     cout << dist[i] << ' ';
    //     // }
    //     // cout << '\n';
    // }
}



