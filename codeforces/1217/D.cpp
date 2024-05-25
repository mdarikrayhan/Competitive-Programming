/*
Problem: 1217D
Date: 25-05-2024 03:36 PM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5005;
int n, m, u[N], v[N];
vector<int> adj[N];
vector<int> topsort;
int pos[N];
bool visited[N];

void dfs(int u) {
    if(visited[u]) return;
    visited[u] = true;
    for(int v : adj[u]) {
        dfs(v);
    }
    topsort.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        adj[u[i]].push_back(v[i]);
    }
    for(int i = 1; i <= n; i++) {
        dfs(i);
    }
    for(int i = 0; i < n; i++) {
        pos[topsort[i]] = i;
    }
    bool cycle = false;
    for(int i = 0; i < m; i++) {
        if(pos[u[i]] < pos[v[i]]) {
            cycle = true;
        }
    }
    if(!cycle) {
        cout << 1 << endl;
        for(int i = 0; i < m; i++) {
            cout << 1 << " ";
        }
        cout << endl;
    }else {
        cout << 2 << endl;
        for(int i = 0; i < m; i++) {
            cout << (u[i] < v[i] ? 1 : 2) << " ";
        }
        cout << endl;
    }
}