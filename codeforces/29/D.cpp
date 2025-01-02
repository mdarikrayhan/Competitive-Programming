#include <bits/stdc++.h>
using namespace std;

int n;
int adj[310][310], degree[310], leaves[310];

vector <int> dfs(int v, int goal, int par) {
    if (v == goal) {
        vector <int> tmp;
        tmp.push_back(v);
        return tmp;
    }
    for (int u = 1; u <= n; u++) {
        if (adj[u][v] != 0 && u != par) {
            adj[u][v]--;
            adj[v][u]--;
            vector <int> tmp = dfs(u, goal, v);
            if (tmp.size() != 0) {
                tmp.insert(tmp.begin(), u);
                return tmp;
            }
            adj[u][v]++;
            adj[v][u]++;
        }
    }

    vector <int> tmp;
    return tmp;
}


int main() {
    cin >> n;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        adj[u][v] = 2;
        adj[v][u] = 2;
        degree[u]++;
        degree[v]++;
    }

    int k = 0;
    for (int i = 2; i <= n; i++) 
        if (degree[i] == 1)
            k++;
    
    for (int i = 0; i < k; i++)
        cin >> leaves[i];
    
    int start = 1;
    leaves[k] = 1;

    vector<int> ans;

    for (int i = 0; i <= k; i++) {
        int goal = leaves[i];
        vector <int> tmp = dfs(start, goal, -1);
        if (tmp.size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        tmp.pop_back();
        tmp.insert(tmp.begin(), start);


        for (int j = 0; j < tmp.size(); j++) {
            if (i != 0 && j == 0)
                continue;
            ans.push_back(tmp[j]);
        }
        start = goal;
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}