#include<bits/stdc++.h>
using namespace std;
#define ii pair<long long,long long>
#define fi first
#define se second
ii mul(ii a,ii b,long long mod) { return {(a.fi*b.se+a.se*b.fi-a.fi*b.fi+mod*mod)%mod,(a.fi*b.fi+a.se*b.se)%mod}; }
long long mm(long long n,long long mod)
{
	ii ans=(ii){0,1};
	for(int i=60;i+1;i--)
	{
		ans=mul(ans,ans,mod);
		if((n>>i)&1) ans=mul(ans,(ii){1,1},mod);
	}
	return ans.se;
}
long long poww(long long n,long long m,long long mod)
{
	long long res=n,ans=1;
	while(m)
	{
		if(m&1) ans=ans*res%mod;
		res=res*res%mod,m/=2;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,k,l,mod,ans=1;
	cin>>n>>k>>l>>mod;
	if(l<=60&&(1LL<<l)-1<k) return cout<<0,0;
	ans%=mod;
	long long r1=mm(n+1,mod),r2=(poww(2,n,mod)-r1+mod)%mod;
	for(int i=l-1;i+1;i--) if((k>>i)&1) ans=ans*r2%mod;
	else ans=ans*r1%mod;
	cout<<ans;
}