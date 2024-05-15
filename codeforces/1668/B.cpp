#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define len(v) (int)v.size() 
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#ifdef Raptor
#include "debug.h"
#else
#define debug(...) 1
#define imie(...) 1;
#endif

void solve(){
	ll n,m; cin>>n>>m;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(rall(a));
	ll tot = accumulate(all(a),0ll) - a.back() + a[0] + n;
	if(tot<=m) cout<<"YES"<<"\n";
	else cout<<"NO"<<"\n";
	
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
}
