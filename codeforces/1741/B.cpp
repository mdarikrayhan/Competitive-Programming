#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	if(n & 1 and n < 5) {
	    cout << "-1\n";
	    return;
	}
	cout << n << " " << n - 1 << " ";
	for(int i = 1; i <= n - 2; i++) cout << i << " ";
	cout << "\n";
	

}
int32_t main(){
	cin.tie(0) -> sync_with_stdio(0);
	int t; cin >> t;
	while(t--){
		solve();
	}
	
}