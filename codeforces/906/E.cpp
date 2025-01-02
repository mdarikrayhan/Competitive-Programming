// becoder Submission #undefined @ 1716215793349
#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define iter vector<Node>::iterator
using namespace std;
const int N=1e6+5,Mod=1e9+7;
int n,tot=1,f[N],g[N][2],rf[N],rg[N][2];
char a1[N],a2[N],a[N];
struct PAM{int fail,son[26],len,del,slink;}T[N];
int Get(int x,int i)
{
	while(a[i-T[x].len-1]!=a[i])x=T[x].fail;
	return x;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	
	memset(f,63,sizeof(f));
	f[0]=0;
	T[0].fail=1,T[1].len=-1;
	scanf("%s%s",a1+1,a2+1),n=strlen(a1+1);
	for(int i=1;i<=n;i++)a[i*2-1]=a1[i],a[i*2]=a2[i];
	n<<=1;
	// for(int i=1;i<=n;i++)printf("%c",a[i]);puts("");
	for(int i=1,now=1;i<=n;i++)
	{
		int ch=a[i]-'a';
		now=Get(now,i);
		if(!T[now].son[ch])
		{
			T[++tot].fail=T[Get(T[now].fail,i)].son[ch];
			T[now].son[ch]=tot;
			T[tot].len=T[now].len+2;
			T[tot].del=T[tot].len-T[T[tot].fail].len;
			T[tot].slink=T[tot].del==T[T[tot].fail].del?T[T[tot].fail].slink:tot;
		}
		now=T[now].son[ch];
		int x=now;
		while(x>1)
		{
			g[x][0]=g[x][1]=1e9;
			g[x][T[T[x].slink].len&1]=f[i-T[T[x].slink].len],rg[x][T[T[x].slink].len&1]=i-T[T[x].slink].len;
			if(T[x].slink!=x)for(int k=0;k<2;k++)if(g[x][k]>g[T[x].fail][k^(T[x].del&1)])
				g[x][k]=g[T[x].fail][k^(T[x].del&1)],rg[x][k]=rg[T[x].fail][k^(T[x].del&1)];
			if(f[i]>g[x][0]+1)f[i]=g[x][0]+1,rf[i]=rg[x][0];
			x=T[T[x].slink].fail;
		}
		if(a[i]==a[i-1]&&f[i]>f[i-2])f[i]=f[i-2],rf[i]=i-2;
		// printf("%d %d\n",i,f[i]);
	}
	if(f[n]>1e9)return puts("-1"),0;
	printf("%d\n",f[n]);
	int x=n;
	while(x)
	{
		if(f[x]!=f[rf[x]])printf("%d %d\n",rf[x]/2+1,x/2);
		x=rf[x];
	}
}