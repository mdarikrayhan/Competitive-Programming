#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...) 
#endif

#define MOD 1000000007
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long

vector<vector<int>> dist;

void solve() {
    int n;
    cin >> n;

    dist.clear(); dist.resize(n + 1, vector<int>(n + 1, INF));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }

    vector<int> rem(n), ans;
    for(auto &x: rem)
        cin >> x;

    vector<int> curr;
    reverse(all(rem));
    for(auto &k: rem) {
        curr.pb(k);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
        // for(int i = 0; i < sz(curr); i++) {
        //     for(int j = 0; j < sz(curr); j++) {
        //         dist[curr[i]][curr[j]] = min(dist[curr[i]][curr[j]], dist[curr[i]][k] + dist[k][curr[j]]);
        //     }
        // }

        int sum = 0;
        for(int i = 0; i < sz(curr); i++) {
            for(int j = 0; j < sz(curr); j++) {
                if(i == j)
                    continue;
                sum += dist[curr[i]][curr[j]];
            }
        }

        ans.pb(sum);
    }

    reverse(all(ans));

    for(auto &x: ans)
        cout << x << " ";
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();       
    }
    return 0;
}