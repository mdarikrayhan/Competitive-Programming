#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll N=2024;
ll n,m,k,p,a[N][N];
pii ans;
ll sum(ll l,ll L,ll r,ll R){
	return a[r][R]-a[r][L-1]-a[l-1][R]+a[l-1][L-1];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)cin>>a[i+j][i-j+m];
	for(ll i=1;i<=n+m;i++)
		for(ll j=1;j<=n+m;j++)
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	for(ll i=k;i<=n-k+1;i++)
		for(ll j=k;j<=m-k+1;j++){
			ll x=i+j,y=i-j+m,s=0;
			for(ll z=0;z<k;z++)
				s+=sum(x-z,y-z,x+z,y+z);
			if(p<=s)p=s,ans={i,j};
		}
	cout<<ans.fi<<' '<<ans.se;
	return 0;
}
    			 		  			  					 				 	 	