#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>

#define ll long long
#define pb push_back
#define ent '\n'
#define $ ' '
#define F first
#define S second
#define sz(x) x.size()
#define FOR(l,r,x) for(ll i=l;i<=r;i+=x)
#define For(l,r,x) for(ll i=l;i>=r;i-=x)
 
using namespace std;
 
//string ssss[2]={"Ciel","Hanako"};
 
//ll dx[4]={1,-1,0,0};
//ll dy[4]={0,0,-1,1};
 
const int N=5e5+5;
const int mod=1e9+7;
const ll INF=1e18;

/*
int phi(ll nn){
	ll result=n;
	for(ll i=2;i*i<=n;i++){
		if(n%i<1){
			while(n%i<1){
				n/=i;
			}
			result-=result/i;
		}
	}
	if(n>1){
		result-=result/n;
	}
	return result;
}
*/

void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	ll a,b;
	cin>>a>>b;
	ll a1=a/(m*k),b1=b/(m*k);
	if(a%(m*k)>0) a1++;
	if(b%(m*k)>0) b1++;
	ll a3=a%(m*k),b3=b%(m*k);
	if(a3<1) a3=k*m;
	if(b3<1) b3=m*k;
	ll a2=a3/k,b2=b3/k;
	if(a3%k>0) a2++;
	if(b3%k>0) b2++;
	if(a1==b1){
		ll cnt=min((max(b2,a2)-min(b2,a2))*5,(max(b2,a2)-min(b2,a2))+10);
		cout<<cnt;
		return;
	}
	ll ans=min(max(a1,b1)-min(a1,b1),(n-max(a1,b1))+min(a1,b1));
	ans*=15;
	ans+=min((a2-1)*5,a2+9);
	ans+=min((b2-1)*5,b2+9);
	cout<<ans;
}
//125 577 124
//7716799 6501425

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	//rand( time(0));
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ll u=1;
	//cin>>u;
	for(ll o=1;o<=u;o++){
		//cout<<"Case "<<i<<": ";
		solve();
		cout<<ent;
	}
}