/*
Problem: 1188A2
Date: 24-05-2024 11:49 PM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1005;
int n, u, v;
ll val;
vector<pair<int, ll> > adj[MAX_N];
// all descendent leaves of a node
vector<int> leaves[MAX_N];
ll moves[MAX_N][MAX_N];

void dfsleaves(int u, int p) {
    if(adj[u].size() == 1 && p >= 0) {
        leaves[u].push_back(u);
    }
    for(pair<int, ll> v : adj[u]) {
        if(v.first != p) {
            dfsleaves(v.first, u);
            leaves[u].push_back(leaves[v.first][0]);
        }
    }
}

void dfs(int u, int p, int g, ll w) {
    // analyze the edge (u, p)
    if(p >= 0) {
        if(adj[p].size() == 1) {
            if(adj[u].size() == 1) {
                moves[u][p] += w;
            }else {
                moves[p][leaves[u][0]] += w / 2;
                moves[p][leaves[u][1]] += w / 2;
                moves[leaves[u][0]][leaves[u][1]] -= w / 2;
            }
        }else {
            int l = leaves[p][0];
            int l2 = leaves[p][1];
            if(l2 == leaves[u][0]) {
                swap(l, l2);
            }
            if(l == leaves[u][0]) {
                if(g >= 0) {
                    l = leaves[g][0];
                    if(l == leaves[p][0]) {
                        if(leaves[g].size() == 1) {
                            l = g;
                        }else {
                            l = leaves[g][1];
                        }
                    }
                }else {
                    l = leaves[p][2];
                }
            }
            if(adj[u].size() == 1) {
                moves[l][u] += w / 2;
                moves[l2][u] += w / 2;
                moves[l][l2] -= w / 2;
            }else {
                moves[l][leaves[u][0]] += w / 2;
                moves[l2][leaves[u][1]] += w / 2;
                moves[l][l2] -= w / 2;
                moves[leaves[u][0]][leaves[u][1]] -= w / 2;
            }
        }
    }
    for(pair<int, ll> v : adj[u]) {
        if(v.first != p) {
            dfs(v.first, u, p, v.second);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v >> val;
        u--; v--;
        adj[u].push_back({v, val});
        adj[v].push_back({u, val});
    }
    for(int i = 0; i < n; i++) {
        if(adj[i].size() == 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    dfsleaves(0, -1);
    dfs(0, -1, -1, 0);
    vector<tuple<int, int, ll> > vec;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(moves[i][j] + moves[j][i] != 0) {
                vec.push_back({i, j, moves[i][j] + moves[j][i]});
            }
        }
    }
    cout << vec.size() << endl;
    for(auto t : vec) {
        cout << (get<0>(t) + 1) << " " << (get<1>(t) + 1) << " " << get<2>(t) << endl;
    }
}