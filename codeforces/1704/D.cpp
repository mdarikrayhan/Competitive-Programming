//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
#define all(x) (x).begin(),(x).end()
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define per(i,j,k) for (int i=j;i>=k;--i)
#define Tim ((double)clock()/CLOCKS_PER_SEC)
int const N=3e5+10;
int n,m;
vector<int>a[N];
void solve(){
	cin>>n>>m;
	rep(i,1,n) a[i].clear(),a[i].resize(m+1);
	rep(i,1,n) rep(j,1,m) cin>>a[i][j];
	map<int,int>mp;
	int mi=1e18;
	rep(i,1,n){
		int sm=0;
		rep(j,1,m) sm+=j*a[i][j];
		++mp[sm],mi=min(mi,sm);
	}
	rep(i,1,n){
		int sm=0;
		rep(j,1,m) sm+=j*a[i][j];
		if (mp[sm]==1){
			cout<<i<<' '<<sm-mi<<'\n';
			return;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	cin>>t;
	while (t--) solve();
	return 0;
}