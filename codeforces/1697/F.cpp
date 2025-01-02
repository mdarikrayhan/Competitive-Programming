#include <bits/stdc++.h>

#define N 400005
#define ps(x,y,z) (((x)-1)*(m-1)*2+((y)-1)*2+(z)+1)

using namespace std;

int m,en,tp,cnt,col,c[N],q[N],in[N],id[N],st[N],dfn[N],low[N],head[N],ans[N];
struct edge{int u,v,nxt;}e[N*12];
void adde(int u,int v){e[++en]={u,v,head[u]};head[u]=en;}

void dfs(int);
void adde(int u,int x,int fx,int v,int y,int fy)
{
	if((x>=m&&fx==0)||(x<=0&&fx==1)||(y>=m&&fy==0)||(y<=0&&fy==1))return;
	if((x<=0&&fx==0)||(x>=m&&fx==1))adde(ps(v,y,fy^1),ps(v,y,fy));
	else if((y<=0&&fy==0)||(y>=m&&fy==1))adde(ps(u,x,fx^1),ps(u,x,fx));
	else
	{
		adde(ps(u,x,fx^1),ps(v,y,fy));
		adde(ps(v,y,fy^1),ps(u,x,fx));
	}
}

int main()
{
	int i,j,k,n,Q,T,ty,x,u,v;
	scanf("%d",&T);
	while(T--)
	{
		en=cnt=col=0;
		scanf("%d %d %d",&n,&Q,&m);
		for(i=0;i<=n*(m-1)*2;++i)c[i]=dfn[i]=head[i]=0;
		for(i=1;i<=n;++i)
			for(k=1;k<m-1;++k)
			{
				adde(ps(i,k,0),ps(i,k+1,0));
				adde(ps(i,k+1,1),ps(i,k,1));
			}
		for(i=1;i<n;++i)
			for(k=1;k<m;++k)
			{
				adde(ps(i,k,1),ps(i+1,k,1));
				adde(ps(i+1,k,0),ps(i,k,0));
			}
		while(Q--)
		{
			scanf("%d",&ty);
			if(ty==1)
			{
				scanf("%d %d",&i,&x);
				adde(i,x-1,0,i,x,1);
			}
			else if(ty==2)
			{
				scanf("%d %d %d",&i,&j,&x);
				for(k=0;k<=m;++k)adde(i,k,0,j,x-k-1,0);
			}
			else
			{
				scanf("%d %d %d",&i,&j,&x);
				for(k=0;k<=m;++k)adde(i,k,1,j,x-k-1,1);
			}
		}
		int fl=0;
		for(i=1;i<=n*(m-1)*2;++i)if(!dfn[i])dfs(i);
		for(i=1;i<=n*(m-1)*2;i+=2)if(c[i]==c[i+1])fl=1;
		if(fl){puts("-1");continue;}

		int tmp=en;en=0;for(i=0;i<=n*(m-1)*2;++i)head[i]=in[i]=0;
		for(i=1;i<=tmp;++i)if(c[e[i].u]!=c[e[i].v]){++in[c[e[i].v]];adde(c[e[i].u],c[e[i].v]);}
		int hd=1,tl=0;for(i=1;i<=col;++i)if(!in[i])q[++tl]=i;
		while(hd<=tl)
		{
			id[u=q[hd]]=hd;++hd;
			for(i=head[u];i;i=e[i].nxt)
				if(!--in[v=e[i].v])
					q[++tl]=v;
		}
		for(i=1;i<=n;++i)
		{
			ans[i]=m;
			for(k=m-1;k;--k)
				if(id[c[ps(i,k,0)]]>id[c[ps(i,k,1)]])
					ans[i]=k;
		}
		for(i=1;i<=n;++i)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}
void dfs(int u)
{
	int i,v;
	dfn[u]=low[u]=++cnt;st[++tp]=u;
	for(i=head[u];i;i=e[i].nxt)
		if(!dfn[v=e[i].v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!c[v])
			low[u]=min(low[u],dfn[v]);
	if(dfn[u]==low[u])
	{
		c[u]=++col;
		while(st[tp]!=u)
			c[st[tp--]]=col;
		--tp;
	}
}
