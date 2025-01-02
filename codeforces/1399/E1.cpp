#include <bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
#define ll long long
//#define int long long
const ll oo = 1e18, nx = 2003, mod = 1e9 + 7, N = 1e5 + 7;
int n;
ll s;

vector<pair<int,int>>adj[N];
map<pair<int,int>, int>mp;
int dfs(int i, int par, int lstW){
    if(adj[i].size() == 1 && i != 1){
        return mp[{lstW, i}] = 1;
    }
    for(auto& j: adj[i]){
        if(j.first == par)
            continue;
        mp[{lstW, i}] += dfs(j.first, i, j.second);
    }
    return mp[{lstW, i}];
}
int calc(){
    priority_queue<pair<ll, pair<int,int>>> pq;
    ll cur{};
    int ret{};
    for(auto& i: mp)
        pq.emplace(1ll * i.first.first * i.second - 1ll * (i.first.first / 2) * i.second, make_pair(i.first.first, i.second)),
        cur += 1ll * i.first.first * i.second;
    while (cur > s){
        ++ret;
        auto p = pq.top();
        pq.pop();
        cur -= p.first;
        p.second.first /= 2;
        pq.emplace(1ll * p.second.first * p.second.second - 1ll * (p.second.first / 2) * p.second.second, p.second);
    }
    return ret;
}
void solve() {
    cin >> n >> s;
    for(int i{}; i <= n; ++i)
        adj[i].clear();
    mp.clear();
    for(int i{1}; i < n; ++i){
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs(1, 0, 0);
    cout << calc() << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
//    SPF();
//    preprocess();
//    sieve();
    int t{1};
    cin >> t;
    while (t--)
        solve();
}

   	 	   	 	  	 					  						 	