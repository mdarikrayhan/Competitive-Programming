#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	auto solve  = [&](){
		int c,d;
		cin >> c >> d;
		if(abs(c - d)%2==1){
			cout << -1 << "\n";
			return;
		}
		if(c==d && c==0) cout << 0 << "\n";
		else if(c==d){
			cout << 1 << "\n";
		}
		else cout << 2 << "\n";


	};
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}