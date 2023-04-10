#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define MOD 998244353
const int up=1e6;
int n,o,ans,inv[N],fail[N],z[N];char a[N];
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int calc(int n)
{
	for(int i=2,j=0;i<=n;++i)
	{
		while(j && a[i]!=a[j+1]) j=fail[j];
		if(a[i]==a[j+1]) ++j;fail[i]=j;
	}
	for(int i=fail[n];i;i=fail[i])
		if(!(n%(n-i))) return n-i;return n;
}
void upd(int x,int vl)
{
	for(int i=2;i<=x;++i) while(!(x%i))
	{
		x/=i;z[i]+=vl;
		if(z[i]<0) z[i]=0,o=1ll*o*i%MOD,ans=1ll*ans*i%MOD;
	}
}
int main()
{
	scanf("%d",&n);o=ans=1;
	for(int i=1;i<=up;++i)
		inv[i]=i>1?1ll*inv[MOD%i]*(MOD-MOD/i)%MOD:1;
	for(int i=1,t,x;i<=n;++i)
	{
		bool s=0;scanf("%s",a+1);t=calc(strlen(a+1));x=0;
		for(int j=1;j<=t;++j) s^=a[j]=='0',x+=(!s);
		if(s&1) x=t,t*=2;upd(x,-1);upd(t-x,1);
		if(t==x) break;o=1ll*o*(t-x)%MOD*inv[x]%MOD;W(ans,o);
	}W(ans,ans);printf("%d\n",ans);return 0;
}