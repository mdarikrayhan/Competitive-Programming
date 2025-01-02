#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;


void solve() {
	int n,sx,sy;
	cin >> n >> sx >> sy;
	vector<pair<int,int>> vp(n);
	for (int i = 0; i < n; i++) {
		cin >> vp[i].first >> vp[i].second;
	}	

	int row[4] = {-1,1,0,0};
	int col[4] = {0,0,-1,1};

	vector<pair<int, int>> newone;
	for (int i = 0; i < 4; i++) {
		if (sx + row[i] >= 0 && sx + row[i] <= 1e9 && sy + col[i] >= 0 && sy + col[i] <= 1e9) {
			newone.push_back({sx + row[i], sy + col[i]});
		}
	}
	map<pair<int,int>, int> mp; 
	auto countfor = [&](int x, int y) {
		int mndis = 1e18;
		for (int i = 0; i < newone.size(); i++) {
			mndis = min(mndis, abs(x - newone[i].first) + abs(y - newone[i].second));
		}

		for (int i = 0; i < newone.size(); i++) {
			if (abs(x - newone[i].first) + abs(y - newone[i].second) == mndis) {
				mp[{newone[i].first, newone[i].second}]++;
			}
		}
	};




	for (int i = 0; i < n; i++) {
		countfor(vp[i].first, vp[i].second);
	}

	int mx = 0;
	for (auto &x : mp) {
		if (x.second > mx) {
			mx = x.second;
		}
	}

	for (auto &x : mp) {
		if (x.second == mx) {
			cout << mx << "\n";
			cout << x.first.first << " " << x.first.second << "\n";
			return;
		}
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}