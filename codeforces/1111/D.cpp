#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll dp[100010],bp[100010],a[60][60],v[100010],inv[100010],fac[100010],W;
char s[100010];
int get_pos(char c) 
{
	if (c>='A'&&c<='Z') return c-'A'+1;
	else return c-'a'+1+26;
}
ll quickpow(ll a,ll n) 
{
	ll res=1;
	while(n>0) 
	{
		if(n&1) res=res*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return res;
}

void get_w(int n) 
{
	fac[0]=1;
	int m=n/2;
	for(int i=1;i<=n;i++) fac[i]=i*fac[i-1]%mod;
	W=fac[m]*fac[m]%mod;
	for(int i=1;i<=52;i++) //费马小定理求逆元
	{
		if(v[i]==0) continue;
		inv[i]=quickpow(fac[v[i]],mod-2);
		W=W*inv[i]%mod;
	}
}
void init() 
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++) v[get_pos(s[i])]++;
	get_w(len);
	dp[0] = 1;
	int m=len/2;
	for(int i=1;i<=52;i++) 
	{
		if(v[i]==0) continue;
		for(int j=m;j>=v[i];j--) dp[j]=(dp[j]+dp[j-v[i]])%mod;
	}
	for(int i=1;i<=52;i++) 
	{
		if(v[i]==0) continue;
		for(int j=1;j<=52;j++) 
		{
			if(v[j]==0) continue;
			for(int k=0;k<=m;k++) bp[k]=dp[k];//背包中去掉i物品
			for (int k=v[i]; k<=m;k++) bp[k]=(bp[k]-bp[k-v[i]]+mod)%mod;//这里+mod的原因是减完可能为负，所以+mod使之为正
			if(i!=j) for(int k=v[j]; k<=m;k++) bp[k]=(bp[k]-bp[k-v[j]]+mod)%mod;
			a[i][j]=bp[m];
		}
	}
}
int main() 
{
	init();
	int q;
	scanf("%d",&q);
	while(q--) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int px=get_pos(s[x]),py=get_pos(s[y]);
		printf("%lld\n",a[px][py]*W*2%mod);
	}
	return 0;
}
		 	 			     		  	     				 		