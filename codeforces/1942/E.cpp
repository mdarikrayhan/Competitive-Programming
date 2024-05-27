#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
ll T,l,n,fact[1000005];
ll add(ll x,ll y){
	if(x+y>=mod)return x+y-mod;
	return x+y;
}
ll sub(ll x,ll y){
	if(x-y<0)return x-y+mod;
	return x-y;
}
ll mult(ll x,ll y){
	return x*y%mod;
}
ll pot(ll a,ll b){
	if(b==0)return 1;
	ll c=pot(a,b/2);
	if(b%2==1)return mult(c,mult(c,a));
	return mult(c,c);
}
ll dv(ll x,ll y){
	return mult(x,pot(y,mod-2));
}
ll povrh(ll x,ll y){
	if(x<0)return 0;
	if(x<y)return 0;
	return dv(fact[x],mult(fact[y],fact[x-y]));
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	fact[0]=1;
	for(int i=1;i<=1000004;i++)fact[i]=mult(fact[i-1],i);
	while(T--){
		cin>>l>>n;
		ll ans=mult(2,povrh(l,2*n));
		ll rem=0;
		for(int M=0;M<=l;M+=2)rem=add(rem,mult(povrh(M/2+n-1,n-1),povrh(l-M-n,n)));
		rem=mult(rem,2);
		ans=sub(ans,rem);
		cout<<ans<<'\n';
	}
	return 0;
}
