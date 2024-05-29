#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const long long inf=0x3f3f3f3f3f3f3f3f;
int T,n,q,dep[N],Size[N],dfn[N],top[N],son[N],tot,fa[N],len[N];
long long a[N],b[N],c[N],Sum[N],sum[N][3];
vector <int> nex[N];
struct matrix
{
	long long num[3][3];
};
matrix seg[N<<2];
matrix operator * (const matrix x,const matrix y)
{
	matrix ret;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			ret.num[i][j]=inf;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				ret.num[i][j]=min(ret.num[i][j],x.num[i][k]+y.num[k][j]);
	return ret;
}
int read()
{
	char ch=getchar();
	int ret=0;
	while(!isdigit(ch))
		ch=getchar();
	while(isdigit(ch))
		ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar();
	return ret;
}
void dfs(int x)
{
	Size[x]=1,son[x]=0;
	for(int y:nex[x])
		dep[y]=dep[x]+1,dfs(y),Size[x]+=Size[y],son[x]=(Size[y]>Size[son[x]] ? y : son[x]);
}
void Dfs(int x)
{
	dfn[x]=++tot,Sum[x]-=b[x];
	if(son[x])
		top[son[x]]=top[x],++len[top[x]],Dfs(son[x]),Sum[x]+=Sum[son[x]];
	for(int y:nex[x])
		if(y!=son[x])
			top[y]=y,Dfs(y),Sum[x]+=Sum[y];
	sum[x][0]=sum[x][1]=sum[x][2]=Sum[x]+b[x]-Sum[son[x]];
}
void change(int p,int l,int r,int id)
{
	if(l==r)
		return seg[p]=(matrix){min(a[id]-b[id]+sum[id][0],a[id]+sum[id][2]),inf,inf,a[id]-b[id]-c[id]+sum[id][1],a[id]-b[id]-c[id]+sum[id][1],inf,a[id]+sum[id][2],inf,0},void();
	int mid=(l+r)>>1;
	(dfn[id]<=mid ? change(p*2,l,mid,id) : change(p*2+1,mid+1,r,id));
	seg[p]=seg[p*2+1]*seg[p*2];
}
matrix query(int p,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)
		return seg[p];
	int mid=(l+r)>>1;
	if(R<=mid)
		return query(p*2,l,mid,L,R);
	if(L>=mid+1)
		return query(p*2+1,mid+1,r,L,R);
	return query(p*2+1,mid+1,r,L,R)*query(p*2,l,mid,L,R);
}
int main()
{
	T=read();
	while(T--)
	{
		n=read(),q=read();
		for(int i=1;i<=n;i++)
			nex[i].clear(),sum[i][0]=sum[i][1]=sum[i][2]=Sum[i]=len[i]=0;
		for(int i=2;i<=n;i++)
			fa[i]=read(),nex[fa[i]].push_back(i);
		for(int i=1;i<=n;i++)
			a[i]=c[i]=0,b[i]=read();
		dep[1]=1,dfs(1),tot=0,top[1]=1,Dfs(1);
		for(int i=1;i<=n;i++)
			change(1,1,n,i);
		sum[0][0]=sum[0][1]=sum[0][2]=Sum[1];
		for(int i=1;i<=q;i++)
		{
			int op=read(),x=read(),y=read();
			(op==1 ? a[x] : c[x])+=y;
			while(x)
			{
				matrix ret=query(1,1,n,dfn[top[x]],dfn[top[x]]+len[top[x]]);
				change(1,1,n,x);
				matrix Ret=query(1,1,n,dfn[top[x]],dfn[top[x]]+len[top[x]]);
				long long dp[2]={inf,inf},DP[2]={inf,inf};
				for(int i=0;i<=1;i++)
					for(int j=0;j<=2;j++)
						dp[i]=min(dp[i],ret.num[j][i]),DP[i]=min(DP[i],Ret.num[j][i]);
				sum[fa[top[x]]][0]+=DP[0]-dp[0],sum[fa[top[x]]][1]+=DP[1]-dp[1],sum[fa[top[x]]][2]+=min(DP[0],0ll)-min(dp[0],0ll);
				x=fa[top[x]];
			}
			printf("%s\n",(sum[0][0]>=0 ? "YES" : "NO"));
		}
	}
} 