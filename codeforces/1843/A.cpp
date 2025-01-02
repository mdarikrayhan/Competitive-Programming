/*
    author:    hex
    created:   16.05.2024 10:17:11
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	int a[n];
	for(auto &x:a) cin >> x;
	sort(a,a+n);
	int ans = 0;
	for(int i = 0 ;i < n ; ++i){
		ans+=abs(a[i]-a[n-1-i]);			 
	}
	cout << ans / 2 << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);    
 	int t ;cin >> t;
 	while(t--){
 		solve();
    }
    return 0;
}



