#include <bits/stdc++.h>
using namespace std;
#define Dodo_elso8ayara_2 ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v(m);
    map<pair<int, int>, deque<pair<int, int>>> mp;
    for (int i = 0; i < m; ++i) cin >> v[i].first >> v[i].second, v[i].second ^= 1;

    vector<pair<int, int>> oth = v;
    sort(oth.begin(), oth.end());

    int curSz = 1;
    int l = 0, r = 3;
    for (int i = 0; i < m; ++i) {
        if (!oth[i].second) {
            mp[oth[i]].push_back({curSz, curSz + 1});
            curSz++;
        } else {
            if (curSz < 3) return void(cout << "-1\n");

            if (r - l > 2) l++;
            else if (r < curSz) r++, l = 1;
            else return void(cout << "-1\n");

            mp[oth[i]].push_back({l, r});
        }
    }

    for (auto &i : v) {
        cout << mp[i][0].first << " " << mp[i][0].second << "\n";
        mp[i].pop_front();
    }
    cout << "\n";
}

signed main() {
    Dodo_elso8ayara_2
    int tt = 1;
//    cin >> tt;
    while (tt--) solve();
    return 0;
}
		 		  				  	  		  	 		      	