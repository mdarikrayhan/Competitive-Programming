// LUOGU_RID: 160507472
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=3e6+5,mod=1e9+7,Inv=(mod+1)/3;
int n,q;
ll jc[N],inv[N],f[3][N],res[N];
ll ksm(ll x,int y)
{
	ll s=1,t=x;
	while(y)
	{
		if(y&1)s=s*t%mod;
		t=t*t%mod,y/=2;
	}
	return s;
}
ll C(int x,int y)
{
	return jc[x]*inv[y]%mod*inv[x-y]%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q,jc[0]=1;
	for(int i=1;i<=3*n+1;i++)jc[i]=jc[i-1]*i%mod;
	inv[3*n+1]=ksm(jc[3*n+1],mod-2);
	for(int i=3*n+1;i;i--)inv[i-1]=inv[i]*i%mod;
	f[0][0]=n+1,f[1][0]=f[2][0]=n;
	for(int i=1;i<=3*n;i++)
	{
		ll y=(f[0][i-1]-C(3*n+1,i))%mod,z=f[1][i-1];
		f[0][i]=(C(3*n+1,i+1)-z-2*y)%mod*Inv%mod;
		f[1][i]=(f[0][i]+y)%mod;
		f[2][i]=(f[1][i]+z)%mod;
	}
	while(q--)
	{
		int x;
		cin>>x,cout<<(f[0][x]+mod)%mod<<'\n';
	}
	return 0;
}
