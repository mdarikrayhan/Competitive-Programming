#include <bits/stdc++.h>
using namespace std;
#define ll long
#define ff first
#define ss second
#define pb push_back
#define int long long
int rr,d,x,y,r,n;
bool ok(){
	int dis=x*x+y*y;
	return dis>=(r-d+rr)*(r-d+rr) and dis<=(r-rr)*(r-rr);
}
void solve() {
	cin>>r>>d>>n;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>x>>y>>rr;
		if(ok())ans++;
	}
	cout<<ans<<endl;
	
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin >> t;
	while (t--) {
		solve();
	}
}