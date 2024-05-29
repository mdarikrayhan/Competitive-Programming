// LUOGU_RID: 157612592
#include<bits/stdc++.h>
using namespace std;
int n;
const int N=200005;
bool inque[N],f[N];
int dfn[N],low[N],cnt,ccnt;
int c[N];
int stk[N],tp;
long long w[2*N];
int hd[N],to[2*N],nxt[2*N],tot;
long long tt;
long long siz[N],ans[N];
void add(int x,int v,long long ww){
	nxt[++tot]=hd[x];
	w[tot]=ww;
	hd[x]=tot;
	to[tot]=v;
}
void tar(int x,int fa){
	dfn[x]=++cnt;
	low[x]=cnt;
	stk[++tp]=x;
	for(int i=hd[x];i;i=nxt[i]){
		if(!dfn[to[i]]){
			tar(to[i],x);
			low[x]=min(low[x],low[to[i]]);
		}
		else if(to[i]!=fa)low[x]=min(low[x],dfn[to[i]]);
	}
	if(low[x]==dfn[x]){
		if(stk[tp]==x){
			tp--;
			return;
		}
		while(stk[tp]!=x){
			c[++ccnt]=stk[tp];
			f[stk[tp]]=1;
			tp--;
		}
		c[++ccnt]=x;
		tp--;
		f[x]=1;
	}
}
void dfs(int x,int fa){
	siz[x]=1;
	for(int i=hd[x];i;i=nxt[i]){
		if(!f[to[i]]&&to[i]!=fa){
			dfs(to[i],x);
			siz[x]+=siz[to[i]];
			ans[x]+=ans[to[i]]+siz[to[i]]*w[i];
		}
	}
}
void dfs2(int u,int fa){
	for(int i=hd[u];i;i=nxt[i]){
		if(to[i]!=fa &&!f[to[i]]){
			int v=to[i];
			ans[v]=ans[u]+w[i]*(n-siz[v])-w[i]*siz[v];
			dfs2(v,u);
		}
	}
}
long long sums[2*N],sumw[2*N],sum[2*N],ww[2*N];
int main(){
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int u,v,ww;
		cin>>u>>v>>ww;
		add(u,v,ww);
		add(v,u,ww);
	}
	tar(1,0);
	for(int i=1;i<=n;i++){
		if(f[i])dfs(i,0),tt+=ans[i];
	}
	for(int i=1;i<=ccnt;i++){
		c[i+ccnt]=c[i];
		for(int j=hd[c[i]];j;j=nxt[j]){
			if(to[j]==c[i+1]){
				ww[i]=ww[ccnt+i]=w[j];
				break;
			}
		}
	}
	for(int i=1;i<=ccnt*2;i++){
		sums[i]=sums[i-1]+siz[c[i]];
		sumw[i]=sumw[i-1]+ww[i];
		sum[i]=sum[i-1]+ww[i]*sums[i];
	}
	for(int l=1,r=1;l<=ccnt;l++)
	{
		while(sumw[r]-sumw[l-1]<=(sumw[ccnt]>>1))r++;
		ans[c[l]]=tt+sums[r]*(sumw[r-1]-sumw[l-1])-(sum[r-1]-sum[l-1])+(sum[l+ccnt-1]-sum[r])-sums[r]*(sumw[l+ccnt-1]-sumw[r]);
		dfs2(c[l],0);
	}
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
}