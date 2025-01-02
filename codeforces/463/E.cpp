#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define double long double
// #define int long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    const int N = 2e6 + 5;
    vector<vector<int>> divs(N + 5);
    for(int i = 2; i < N; i++)
        if(!divs[i].size())
            for(int j = i; j < N; j += i)
                divs[j].push_back(i);

    int n, qq;
    cin >> n >> qq;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> adj[n];
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> par(n, -1);
    vector<int> dist(n);
    queue<int> q;
    q.push(0);
    par[0] = 0;
    while(!q.empty()) {
        auto e = q.front();
        q.pop();
        for(auto f : adj[e]) {
            if(f != par[e]) {
                par[f] = e;
                dist[f] = dist[e] + 1;
                q.push(f);
            }
        }
    }

    vector<int> ans(n, -2), d2(n, -2);
    vector<vector<int>> cur(N, vector<int>());
    function<void(int)> dfs = [&] (int u) {
        for(auto divisor : divs[a[u]]) {
            if(cur[divisor].size() && dist[cur[divisor].back()] > d2[u]) {
                ans[u] = cur[divisor].back();
                d2[u] = dist[cur[divisor].back()];
            }
            cur[divisor].push_back(u);
        }
        for(auto e : adj[u]) {
            if(e != par[u]) {
                dfs(e);
            }
        }
        for(auto divisor : divs[a[u]]) {
            cur[divisor].pop_back();
        }
    };

    dfs(0);

    for(int i = 0; i < qq; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int v;
            cin >> v;
            v--;
            cout << ans[v] + 1 << endl;
        } else {
            int v, w;
            cin >> v >> w;
            ans = vector<int>(n, -2);
            d2 = vector<int>(n, -2);
            cur = vector<vector<int>>(N, vector<int>());
            v--;
            a[v] = w;
            dfs(0);
        }
    }

    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cerr << "Time elapsed: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms" << endl;
}