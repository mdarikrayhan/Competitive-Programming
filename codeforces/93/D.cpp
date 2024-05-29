// LUOGU_RID: 158157315
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll mywsm(ll x,ll y){
	ll ss=1;
	while(y){
		if(y&1ll)ss=ss*x%mod;
		x=x*x%mod;y>>=1;
	}return ss;
}
struct node{
	ll a[9][9];
	void init(){
		memset(a,0,sizeof(a));
		for(int i=0;i<9;i++)
		a[i][i]=1;
	}
	node operator *(const node x)const{
		node ans;memset(ans.a,0,sizeof(ans.a));
		for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		for(int z=0;z<9;z++)
		ans.a[i][j]=(ans.a[i][j]+a[i][z]*x.a[z][j])%mod;
		return ans;
	}
}mul;
node qpow(node x,ll y){
	node ss;ss.init();
	while(y){
		if(y&1ll)ss=ss*x;
		x=x*x;y>>=1ll;
	}return ss;
}
ll l,r,inv;
ll cc[9][9]={
	{0,0,1,1,0,mod-1,0,0,0},
	{0,0,1,1,mod-1,0,0,0,0},
	{1,1,0,0,0,0,0,0,0},
	{1,1,0,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,0,0},
	{1,1,1,1,0,0,0,0,1}	
};
ll f(ll x){
	node ss;ll ans=0;
	ss=qpow(mul,x);
	for(int i=0;i<4;i++)
	ans=(ans+ss.a[8][i])%mod;
	return ans;
}
ll calc(ll x){
	return inv*(f(x)+f((x+1)/2))%mod;
}
int main(){
	cin>>l>>r;inv=mywsm(2ll,mod-2);
	for(int i=0;i<9;i++)
	for(int j=0;j<9;j++)
	mul.a[i][j]=cc[i][j];
	printf("%lld\n",(calc(r)-calc(l-1)+mod)%mod);
	return 0;
} 