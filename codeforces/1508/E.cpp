/*
code copied from editorial

solved but my code has some bug, dont want to debug
*/



#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, u, v, bor, a[N], par[N], pos[N];
int cnt_in = 0, in[N], ex[N];
int cnt_out = 0, out[N];
int cnt_in_oth = 0, in_oth[N];
long long ans = 0;
vector<int> adj[N];

void DFS(int u, int h = 0) {
    in[u] = ++cnt_in;
    if (a[u] >= bor) {
        in_oth[u] = ++cnt_in_oth + bor - 1;
    }
    sort(adj[u].begin(), adj[u].end(), [](const int &u, const int &v) {
        return a[u] < a[v];
    });
    for (int v : adj[u]) {
        DFS(v, h + 1);
    }
    out[u] = ++cnt_out;
    if (a[u] < bor) {
        ans += h;
    }
    ex[u] = cnt_in;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        par[v] = u;
    }
    bor = max(1, a[1] - 1);
    int cur_node = pos[bor];
    for (int u = cur_node; u != 1; u = par[u]) {
        swap(pos[a[u]], pos[a[par[u]]]);
        swap(a[u], a[par[u]]);
        ans++;
    }
    DFS(1);
    for (int i = 1; i <= n; i++) {
        if (a[i] < bor && a[i] != out[i]) {
            return cout << "NO\n", 0;
        } else if (a[i] >= bor && a[i] != in_oth[i]) {
            return cout << "NO\n", 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (out[i] == bor && !(in[i] >= in[cur_node] && ex[i] <= ex[cur_node])) {
            return cout << "NO\n", 0;
        }
    }
    cout << "YES\n";
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        cout << in[i] << " \n"[i == n];
    }
}