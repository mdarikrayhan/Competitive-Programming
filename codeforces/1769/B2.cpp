#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll find(ll x, ll y){
	return (y * x + 99) / 100;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n;
	vector <ll> v(n), vv(n + 1);
	
	for(int i = 0 ; i < n ; i++){
		cin >> v[i];
		vv[i + 1] = vv[i] + v[i];
	}
	for(int i = 0 ; i < 101 ; i++){
		ll l = find(vv[n], i), r = min(find(vv[n], i + 1) - 1, vv[n]);
		for(int j = 0 ; j < n ; j++){
			ll tl = vv[j] + find(v[j], i), tr = vv[j] + min(find(v[j], i + 1) - 1, v[j]);
			if (l <= r && tl <= tr && !(tr < l || r < tl)) {
				cout << i << endl;
				break;
			}
		}
	}
	
	return 0;
}