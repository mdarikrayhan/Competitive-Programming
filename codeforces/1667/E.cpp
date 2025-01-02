// LUOGU_RID: 160429664
#include<bits/stdc++.h>
using namespace std;
const int N=200200,mod=998244353;
typedef long long ll;
ll n,fac[N],ifac[N],inv[N],f[N],g[N],sum=0;
ll C(int n,int m)
{
	if(m<n) return 0; return fac[m]*ifac[n]%mod*ifac[m-n]%mod;
}
void init()
{
	fac[0]=ifac[0]=1,inv[1]=1;
	for(int i=2;i<N;i++)
	{
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=1;i<N;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		ifac[i]=ifac[i-1]*inv[i]%mod;
	}
}
//分析：恰好为重心不好算，考虑容斥根为i的子树大小大于等于(n+1)/2的方案数
//前i个点有(i-1)!种取法，任取j-1个标号构成子树有C(j-1,n-i)种取法
//子树有(j-1)!种取法，剩余的节点有(i-1)*i*...*(n-j-1)种取法 
//所以fi=Σ(i-1)!*(n-i)!*(n-j-1)! / (n-i-j+1)!*(i-2)!((n+1)/2<=j<=n-i+1) 
//=(i-1)!*(n-i)!*ΣC(i-2,n-j)=(i-1)!*(n-i)!*C(i-1,(n-1)/2)
//以一个点j为根计算时，它的父亲落在[1,j]的概率均等，它父亲的父亲同样满足这一点 
//所以某个点的祖先包含i的概率恰好是1/i,容斥：gi=fi-Σgj / i。 
int main()
{
	cin>>n; init();
	for(int i=1;i<=n;i++) f[i]=fac[i-1]*fac[n-i]%mod*C(i-1,(n-1)/2)%mod;
	for(int i=n;i>=1;i--)
	{
		g[i]=(f[i]-sum*inv[i]%mod+mod)%mod; sum=(sum+g[i])%mod;
	}
	for(int i=1;i<=n;i++) cout<<g[i]<<" ";
	return 0;
}