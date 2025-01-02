#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) static_cast<int>((x).size())
#define all(x) begin(x), end(x)
const int mod = 1e9 + 7;


void solve(){

    int n; cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<int>> g(n), r(n);
    for (int i = 0; i < n; ++i){
        if (i - a[i] >= 0){
            g[i].push_back(i - a[i]);
            r[i - a[i]].push_back(i);
        }
        if (i + a[i] < n){
            g[i].push_back(i + a[i]);
            r[i + a[i]].push_back(i);
        }
    }

    vector<int> d(n, -1);

    auto solve = [&](int par){
        vector<int> dist(n, -1);
        for (int i = 0; i < n; ++i){
            if ((a[i] & 1) == par){
                for (auto &v : g[i]){
                    dist[i] = ((a[v] & 1) != par) ? 1 : dist[i];
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < n; ++i){
            if (dist[i] != -1){
                q.push(i);
            }
        }
        while (!q.empty()){
            auto u = q.front(); q.pop();
            for (auto &v : r[u]){
                if (dist[v] == -1 || dist[v] > dist[u] + 1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < n; ++i){
            if ((a[i] & 1) == par){
                d[i] = dist[i];
            }
        }
    };

    for (int i = 0; i < 2; ++i){
        solve(i);
    }

    for (auto &x : d){
        cout << x << ' ';
    }

}


signed main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}