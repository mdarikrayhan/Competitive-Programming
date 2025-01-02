#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define ld long double
#define int long long
#define endl "\n"
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define pb push_back
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int MOD = 1e9 + 7;
//const int MOD = 998244353  ;
const int N = 1e5 + 5;
const ll INF = 1e18;
const ll MIN = -1e18;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;


map<pair<ll, ll>, ll> mp;
vector<ll> adj[105];
ll vis1[105];
ll vis2[105];
ll ans1 = 0;
ll ans2 = 0;

void dfs(ll pos = 1) {
    vis1[pos] = 1;
    ll tst = 0;
    for (int i = 0; i < 2; i++) {
        if (vis1[adj[pos][i]] == 0) {
            ans1 += mp[{pos, adj[pos][i]}];
            dfs(adj[pos][i]);
            tst = 1;
        }
    }
    if (tst == 0) {
        ans1 += mp[{pos, 1}];
    }
}

void dfs2(ll pos = 1) {
    vis2[pos] = 1;
    ll tst = 0;
    for (int i = 1; i >= 0; i--) {
        if (vis2[adj[pos][i]] == 0) {
            ans2 += mp[{pos, adj[pos][i]}];
            dfs2(adj[pos][i]);
            tst = 1;
        }
    }
    if (tst == 0) {
        ans2 += mp[{pos, 1}];
    }
}

void solve() {
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        mp[{b, a}] = c;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    dfs();
    dfs2();

    //cout << endl;
    cout << min(ans1, ans2) << endl;
}

signed main() {
    FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t = 1;
    //cin>>t;
    while (t--) solve();
}


