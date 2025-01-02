//AshrafSustS19


#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int n, k;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int dijkstra(int s, int e){
    vector<int> mndis(n, INT_MAX), prevInd(n, -1);

    mndis[s] = 0;
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, s});
    while (!pq.empty()){
        auto [wt, u] = pq.top();
        wt = -wt;
        pq.pop();
        if (mndis[u] < wt){
            continue;
        }
        for (int v: adj[u]){
            int cw = (capacity[u][v] == 0);
            if (mndis[v] > wt + cw){
                prevInd[v] = u;
                mndis[v] = cw + wt;
                pq.push({-(cw + wt), v});
            }

        }
    }
    int mn = mndis[e];
    int v = e;
    while (prevInd[v] != -1){
        int u = prevInd[v];
        if (mndis[u] < mndis[v]){
            capacity[v][u]++;
        }
        else {
            capacity[u][v]--;
            capacity[v][u]++;
        }
        v = u;
    }
    return mn;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(){
    cin >> n >> k;
    capacity.resize(n, vector<int> (n, 0));
    adj.resize(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> capacity[i][j];
            if (capacity[i][j] != 0){
                adj[i].push_back(j);
            }
        }
    }
    int tot = maxflow(0, n - 1);
    while (k > 0){
        int res = dijkstra(0, n - 1);
        k -= res;
        
        if (k >= 0){
            tot++;
        }
    }
    cout << tot << "\n";
}