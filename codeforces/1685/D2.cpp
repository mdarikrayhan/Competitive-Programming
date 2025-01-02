#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
namespace DSU
{
	int f[1005],ct;
	int find(int x)
	{
		if(f[x]==x) return x;
		return f[x]=find(f[x]);
	}
	void link(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y) return;
		f[x]=y;
		ct++;
	}
	void build(int n)
	{
		ct=0;
		for(int i=1;i<=n;i++)
			f[i]=i;
	}
}
int T,n,p[1005],visc[1005],c[1005],a[1005],ct,tans[1005],t;
int vist[1005],pre[1005],rp[1005],vis[1005],s[1005];
int check()
{
	memset(visc,0,sizeof(visc));
	memset(vis,0,sizeof(vis));
	memset(pre,0,sizeof(pre));
	int ans=0;
	for(int i=1;i<t;i++)
	{
		int x=tans[i],y=p[tans[i+1]];
		if(x<y)
		{
			ans+=y-x;
			for(int j=x;j<=y;j++)
			{
				if(j!=x&&!visc[c[j]]) pre[j]=j-1;
				visc[c[j]]=1;
			}
		}
		else
		{
			ans+=x-y;
			for(int j=x;j>=y;j--)
			{
				if(j!=x&&!visc[c[j]]) pre[j]=j+1;
				visc[c[j]]=1;
			}
		}
		if(ans>2*(ct-1)) return 0;
	}
	for(int i=1;i<=n;i++)
		if(vist[i]&&vist[rp[i]]) a[i]=1;
		else a[i]=0;
	int u=tans[t];
	while(1)
	{
		if(!vist[rp[u]]&&!vis[rp[u]])
		{
			vis[rp[u]]=1;
			u=rp[u];
		}
		else if(pre[u])
		{
			a[u]=0;
			u=pre[u],ans++;
		}
		else
		{
			a[u]=0;
			if(u!=p[1]) return 0;
			break;
		}
	}
	for(int i=1;i<=ct;i++)
		if(visc[i])
		{
			int u=s[i],fl=0;
			while(1)
			{
				if(fl&&u==s[i]) break;
				fl=1;
				if(!vis[u]&&!vist[u]) return 0;
				u=rp[u];
			}
		}
	DSU::build(ct);
	for(int i=1;i<=n;i++)
		if(pre[i])
			DSU::link(c[i],c[pre[i]]);
	if(ans+(ct-1-DSU::ct)*2>2*ct) return 0;
	for(int i=1;i<n;i++)
		if(!a[i]&&!a[i+1])
			DSU::link(c[i],c[i+1]);
	if(DSU::ct!=ct-1) return 0;
	return 1;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(vist,0,sizeof(vist));
		memset(c,0,sizeof(c));
		t=ct=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		for(int i=1;i<=n;i++)
			rp[p[i]]=i;
		for(int i=1;i<=n;i++)
			if(!c[i])
			{
				int u=i;
				ct++;
				s[ct]=i;
				while(!c[u])
				{
					c[u]=ct;
					u=p[u];
				}
			}
		tans[1]=1;
		vist[1]=1;
		t=1;
		for(int i=2;i<=n;i++){
			t++;
			for(int j=1;j<=n;j++)
				if(!vist[j])
				{
					vist[j]=1;
					tans[t]=j;
					if(check()) break;
					vist[j]=0;
				}
		}
		for(int i=1;i<=t;i++)
			printf("%d ",tans[i]);
		printf("\n");
	}
	return 0;
}