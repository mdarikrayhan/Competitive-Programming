/*
Problem: 1238F
Date: 28-05-2024 03:17 AM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 5;
int q, n, x, y;
vector<int> adj[N];
vector<int> children[N];
// dp3 = root is a leaf of the backbone
// dp4 = root MUST be a member of backbone
int dp1[N], dp2[N], dp3[N], dp4[N];
bool visited[N];

void dfs(int x) {
    visited[x] = true;
    for(int y : adj[x]) {
        if(!visited[y]) {
            dfs(y);
            children[x].push_back(y);
        }
    }
}

void answerdp(int x) {
    int nchild = children[x].size();
    int M1 = 0, M2 = 0, M21 = 0, M4 = 0;
    for(int y : children[x]) {
        answerdp(y);
        M1 = max(M1, dp1[y]);
        M4 = max(M4, dp4[y]);
        if(dp2[y] > M2) {
            M21 = M2;
            M2 = dp2[y];
        }else if(dp2[y] > M21) {
            M21 = dp2[y];
        }
    }
    dp1[x] = nchild == 0 ? 1 : nchild == 1 ? 1 + M2 : nchild - 1 + M2 + M21;
    dp2[x] = nchild == 0 ? 1 : nchild + M2;
    dp3[x] = nchild = 0 ? 1 : M1 + 1;
    dp4[x] = max(max(dp1[x], dp2[x]), max(dp3[x], M4));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        fill(visited, visited + n, false);
        fill(dp1, dp1 + n, 0);
        fill(dp2, dp2 + n, 0);
        for(int i = 0; i < n; i++) {
            adj[i].clear();
            children[i].clear();
        }
        for(int i = 0; i < n - 1; i++) {
            cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        // 0 is the root
        dfs(0);
        answerdp(0);
        cout << dp4[0] << endl;
    }
}