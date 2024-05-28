#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef ONLINE_JUDGE
#include "db/debug.h"
#else
#define debug(...)
#endif

#define ndl '\n'
#define int long long

void solve(ll tc) {
    int n, h, m, k; cin >> n >> h >> m >> k;
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++) {
        int hi, mi; cin >> hi >> mi;
        v[i].first = (hi * m + mi) % (m / 2);
        v[i].second = i;
    }
    auto w = v;
    sort(w.begin(), w.end());
    debug(w);
    int rem = n + 1, idx = 0;
    for(int i=0; i<n; i++) {
        auto j = upper_bound(w.begin(), w.end(), make_pair(w[i].first + k, -1LL)) - w.begin();
        if(rem > j - i - 1) {
            rem = j - i - 1;
            idx = w[i].second;
        }
        w.push_back({w[i].first + (m / 2), w[i].second});
    }
    debug(idx);
    cout << rem << " " << (v[idx].first + k) % (m / 2) << ndl;
    for(int i=0; i<n; i++) {
        if(w[i].second == idx) {
            for(int j=0; j<rem; j++) {
                cout << w[i+j+1].second + 1 << " ";
            }
        }
    }
    cout << ndl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T=1;
    // cin>>T;
    for (ll tc = 1; tc <=T; tc++) solve(tc);
    return 0;
}

/*
10 24 60 8
10 59
21 56
0 42
21 27
5 24
5 53
16 5
5 22
10 11
10 46
*/