#include<bits/stdc++.h>
#define ll long long
#define pii pair<long long,long long>
using namespace std;
const int B = (int)1e6;
vector dd(B,vector<ll>());
void solve()
{
	int n;cin>>n;
	map<ll,ll>cnt;
	for(int i=1;i<=n;i++) {
		int x;cin>>x;
		cnt[x]++;
	}
	ll ans=0;
	for(auto [x,num]:cnt) {
		if(num>2) ans+=num*(num-1)*(num-2);
		if(x<B) {
			for(auto d:dd[x])
				if(cnt.count(x/d) and cnt.count(x*d))
				ans+=num*cnt[x/d]*cnt[x*d];
		} else {
			for(int j=2;x*j<=(int)1e9;j++)
				if(x%j==0 and cnt.count(x/j) and cnt.count(x*j)) {
					ans+=num*cnt[x/j]*cnt[x*j];
				}
		}
	}
	cout<<ans<<'\n';
 } 
 main()
 {
 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	int _  = 1;cin>>_;
 	for(int i=2;i<(int)1e6;i++) {
 		dd[i].push_back(i);
 		for(int j=2;1LL*j*j<=i;j++)
 			if(i%j==0) {
 				dd[i].push_back(j);
 				if(1LL*j*j!=i) dd[i].push_back(i/j); 
			 }
	 }
	for(int i=2;i<=(int)100;i++) {
		for(auto d:dd[i])
			cerr<<d<<' ';
		cerr<<'\n';
	}
 	while(_--) solve();
 }