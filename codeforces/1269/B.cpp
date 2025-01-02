#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;


void solve() {
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
    vector<int> b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    vector<int> diff;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
    	if (b[i] <= a[0]) diff.push_back((m-a[0])+b[i]);
    	if (b[i] >= a[0]) diff.push_back(b[i] - a[0]);
    }	
    map<int, int> mp;
    for(auto &x : b) mp[x]++;
    sort(diff.begin(), diff.end());
    for (int i = 0; i < diff.size(); i++) {
    	int tar = diff[i];
    	bool ok = true;
    	map<int, int> tmp = mp;
    	for (int i = 0; i < n; i++) {
    		int ele = (a[i]+tar) % m;
    		if (tmp[ele] == 0) {
    			ok = false;
    			break;
    		}
    		tmp[ele]--;
    	}

    	if (ok) {
    		cout << tar << "\n";
    		return;
    	}
    }
    cout << -1 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}