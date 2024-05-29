#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, a; cin >> n >> a;
	vector<pair<pair<int, int>, int>> v(n);
	for(int i = 0; i < n; ++i){
		int x, y; cin >> x >> y;
		y += x;
		v[i] = {{x, y}, i};
	}
	sort(v.begin(), v.end(), [&](auto &x, auto &y){ return x.first.second < y.first.second; });
	int l = 1, r = a - 1, bes = a;
	while(l <= r){
		int m = (l + r) >> 1;
		multiset<int> in;
		int cu = 0;
		for(int i = 0; i < n; ++i){
			auto z = in.upper_bound(v[i].first.first);
			if(z != in.begin())in.erase(prev(z));
			if((int)in.size() < m){
				in.insert(v[i].first.second);
				cu++;
			}
		}
		if(cu >= a){
			bes = m;
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	cout << bes << '\n';
	vector<int> ans;
	multiset<int> in;
	for(int i = 0; i < n; ++i){
		auto z = in.upper_bound(v[i].first.first);
		if(z != in.begin())in.erase(prev(z));
		if((int)in.size() < bes){
			in.insert(v[i].first.second);
			ans.push_back(v[i].second);
		}
	}
	for(int i = 0; i < a; ++i)cout << ans[i] + 1 << ' ';
	cout << '\n';
}