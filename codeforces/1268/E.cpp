// LUOGU_RID: 159719884
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,pl[N],pr[N],h[N],H[N],al[N],ar[N],ex[N],ey[N],f[N],g[N],fa[N],p[N];
int dfn[N],low[N],st[N],tp;
vector<pair<int,int> >e[N];
int gf(int x){
	return fa[x]==x?fa[x]:fa[x]=gf(fa[x]);
}
void tarjan(int x,int y){
	st[++tp]=x,dfn[x]=low[x]=++dfn[0];
	for(auto [v,w]:e[x]){
		if(!dfn[v]){
			h[v]=w;
			tarjan(v,x);
			low[x]=min(low[x],low[v]);
			if(low[v]>=dfn[x]){
				vector<int>tmp;
				do{
					tmp.emplace_back(st[tp--]);
				}while(st[tp+1]!=v);
				int sz=tmp.size();
				if(sz==1)continue;
				tmp.emplace_back(x),++sz;
				for(int i=0;i<sz;++i)ar[tmp[i]]=tmp[(i+1)%sz],al[tmp[i]]=tmp[(i+sz-1)%sz];
				swap(h[x],H[x]);
				int mx=x,mn=h[x];
				for(auto u:tmp){
					if(h[u]>h[mx])mx=u;
					mn=min(mn,h[u]);
				}
				pr[mx]=ar[mx],pl[ar[mx]]=mx;
				for(int i=al[mx];i!=mx;i=al[i]){
					if(h[i]<h[ar[i]])pr[i]=pr[ar[i]];
					else pr[i]=ar[i];
				}
				for(int i=ar[mx];i!=mx;i=ar[i]){
					if(h[al[i]]>h[i])pl[ar[i]]=pl[i];
					else pl[ar[i]]=i;
				}
				for(auto u:tmp)if(pl[u]==mx&&pr[u]==ar[mx])p[mn]=h[mx];
				swap(h[x],H[x]);
			}
		}else if(v!=y)H[v]=w,low[x]=min(low[x],dfn[v]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		e[x].emplace_back(y,i),e[y].emplace_back(x,i);
		ex[i]=x,ey[i]=y;
	}
	tarjan(1,0);
	for(int i=1;i<=n;++i)f[i]=1,fa[i]=i;
	for(int i=m;i;--i){
		int x=ex[i],y=ey[i],u=f[x],v=f[y];
		g[i]=u+v;
		if(gf(x)==gf(y))u-=g[p[i]],v-=g[p[i]];
		f[x]+=v,f[y]+=u;
		fa[gf(x)]=gf(y);
	}
	for(int i=1;i<=n;++i)printf("%d%c",f[i]-1," \n"[i==n]);
	return 0;
}