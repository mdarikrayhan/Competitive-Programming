#include <bits/stdc++.h>
using namespace std;
bool visited[10005];
vector<int> graph[10005];
int cnt = 0;
int dfs (int n) {
    visited[n] = true;
    int childcnt=0;
    for (auto adj:graph[n]) if (!visited[adj]) {
        int k = dfs(adj);
        childcnt++;
        cnt += k;
    }
    cnt += childcnt * (childcnt - 1) / 2;
    return childcnt;
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    cout << cnt;
}

// DFS from root, then solve from its subtree