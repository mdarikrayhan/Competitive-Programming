#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define pp pop_back
#define int long long 
const int INF = 1e18-5;
const int MOD = 1e9+7;

// do something, stay focused
// look for stupid bugs
// guess, slow, stress
// don't overgeneralize
// don't rush
 
// don't waste time on standings
 
// SOLVE THE PROBLEM OR DIE TRYING
// THE SOLUTION IS ALWAYS SIMPLE
// THE CODE IS ALWAYS SHORT

void solve() {
     int n;
	 cin >> n;
	 vector <int> v(n);
	 vector <int> prime(1e6+5,true);
	 prime[0] = prime[1] = false;
	 for(int i=2;i<n;i++) {
	 	if(prime[i]) {
	 		for(int j=i*2;j<=1e6+1;j+=i) {
	 			prime[j] = false;
			 }
		 }
	 }
	 for(int i=0;i<n;i++) {
	 	cin >> v[i];
	 }
	 sort(all(v));
	 int ans = v[0] * v[v.size()-1];
	 vector <int> b;
	 for(int i=2;i*i<=ans;i++) {
	 	if(ans%i==0) {
	 		if(ans/i!=i) {
	 			b.pb(i);
	 			b.pb(ans/i);
			 }
			 else {
			 	b.pb(i);
			 }
		 }
	 }
	 sort(all(b));
	 if(b==v) {
	 	cout << ans << "\n";
	 }
	 else {
	 	cout << -1 << "\n";
	 }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
    
    return 0;
}