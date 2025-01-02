#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9; 

int main(){
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector< pair<int, int> > a;

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.push_back({x, inf});
	}

	for(int i = 0; i < m; i++){
		int x, t;
		cin >> x >> t;
		a.push_back({x-t, x+t});
	}

	sort(a.begin(), a.end());

	multiset<int> r;
	int ans = 0;
	for(int i = 0; i < n+m; i++){
		int _r = a[i].second,
			x = a[i].first;
		if(_r == inf){
			while(!r.empty() && *(r.begin()) < x)
				r.erase(r.begin());
			if(!r.empty()){
				ans++;
				r.erase(r.begin());
			}
		}
		else
			r.insert(_r);
	}

	cout << ans;

	return 0;
}