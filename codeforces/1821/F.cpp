#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=998244353;
int n,T,k,m;
int jc[300005],inv[300005],jcinv[300005],p2[300005];
int C(int n,int m)
{
	if(m>n||n<0)return 0;
	return jc[n]*jcinv[m]%M*jcinv[n-m]%M;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=(M-M/i)*inv[M%i]%M;
	jc[0]=jcinv[0]=p2[0]=1;
	for(int i=1;i<=n;i++)
		jc[i]=i*jc[i-1]%M,jcinv[i]=inv[i]*jcinv[i-1]%M,p2[i]=2*p2[i-1]%M;
	int ans=0;
	for(int i=0,t=1;i<=m/*&&k*m+i*m<=n*/;i++)
	{
		ans=(ans+t*C(n-k*m-k*i,m)%M*C(m,i)%M*p2[m-i])%M;
		t=t*(M-1)%M;
	}
	cout<<ans;
}