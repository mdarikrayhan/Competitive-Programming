#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include<list>
using namespace std;
const int M = 105;
const int inf = 0x3f3f3f3f;
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int n,m,b[8][8],num[8],p[8],a[8];
//the part of dinic
namespace net{
    struct edge{
        int t,w,n;
    } G[20000];
    int ecnt=2,hd[105],cur[105];
    void ade(int s,int t,int w){
        G[ecnt]={t,w,hd[s]};
        hd[s]=ecnt++;
    }void lnk(int s,int t,int w){
        ade(s,t,w);
        ade(t,s,0);
    }
    int N,S,T,lvl[105];
    bool bfs(){
        std::queue<int,std::list<int> > q;
        memset(lvl+1,0,sizeof*lvl*N);
        memcpy(cur+1,hd+1,sizeof*hd*N);
        lvl[S]=1;
        q.push(S);
        while(q.size()){
            int u=q.front();
            q.pop();
            for(int e=hd[u];e;e=G[e].n) if(G[e].w&&!lvl[G[e].t]){
                lvl[G[e].t]=lvl[u]+1;
                q.push(G[e].t);
            }
        }
        return lvl[T];
    }int dfs(int x,int lim){
        int f=0,ff;
        if(x==T||!lim) return lim;
        for(int&e=cur[x];e;e=G[e].n){
            int const&t=G[e].t;
            if(lvl[t]==lvl[x]+1){
                ff=dfs(t,min(lim,G[e].w));
                if(ff){
                    f+=ff;
                    lim-=ff;
                    G[e].w-=ff;
                    G[e^1].w+=ff;
                    if(!lim) break;
                }
            }
        }
        return f;
    }int mxf(){
        int ans=0;
        while(bfs()) ans+=dfs(S,0x3f3f3f3f);
        return ans;
    }
}
//check the tree
void check()
{
    int cnt=0;
    net::ecnt=2;
    memset(net::hd,0,sizeof net::hd);
	//use prufer to build tree
	int q[8]={},c[8][8]={},d[8]={}
	,vis[8]={},id[8][8]={};
	a[m-1]=m;
	for(int i=1;i<m;i++) d[a[i]]++;
	for(int i=1;i<m;i++)
	{
		int p=0;
		for(int j=1;j<=m;j++)
			if(!vis[j] && !d[j])
				p=j;
		vis[p]=1;d[a[i]]--;
		c[min(p,a[i])][max(p,a[i])]++;
	}
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++)
			id[i][j]=++cnt;
    net::T=cnt+1+m;
    net::S=net::N=net::T+1;
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++)
		{
			if(c[i][j]>b[i][j]) return ;
            net::lnk(net::S,id[i][j],b[i][j]-c[i][j]);
            net::lnk(id[i][j],cnt+i,inf);
            net::lnk(id[i][j],cnt+j,inf);
		}
	for(int i=1;i<=m;i++)
		net::lnk(cnt+i,net::T,num[i]-1);
	if(net::mxf()<n-m) return ;
	for(int i=1;i<=m;i++) q[i]=p[i];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++) if(c[i][j])
			printf("%d %d\n",p[i],p[j]);
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++)
		{
			int u=id[i][j];
			for(int w=net::hd[u];w;w=net::G[w].n)
			{
				int v=net::G[w].t,c=net::G[w^1].w;
				if(v==net::S) continue;
				if(v-cnt==i) while(c--)
					printf("%d %d\n",++q[i],p[j]);
				else while(c--)
					printf("%d %d\n",++q[j],p[i]);
			}
		}
	exit(0);
}
//fuck all prufer
void zxy(int x)
{
	if(x==m-1)
	{
		check();
		return ;
	}
	for(int i=1;i<=m;i++)
	{
		a[x]=i;
		zxy(x+1);
	}
}
signed main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		char s[10],t[10];
		scanf("%s%s",s,t);
		int l1=strlen(s),l2=strlen(t);
		b[min(l1,l2)][max(l1,l2)]++;
	}
	for(int i=1;i<=n;i*=10) p[++m]=i;
	for(int i=1;i<m;i++) num[i]=p[i+1]-p[i];
	num[m]=n-p[m]+1;
	if(m==1)
	{
		if(b[1][1]!=n-1) puts("-1");
		else
		{
			for(int i=1;i<n;i++)
				printf("%d %d\n",i,i+1);
		}
		return 0;
	}
	zxy(1);
	puts("-1");
}
