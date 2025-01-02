#include<bits/stdc++.h>
#define For(i,a,b) for( int i=(a);i<=(b);++i)
#define Rep(i,a,b) for( int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;
 
#define maxn 300005
#define inf 0x3f3f3f3f

int n,m;
vi e[maxn];
int dfn[maxn],low[maxn],bel[maxn],idx,scc;
int stk[maxn],top;
vi g[maxn];
vector<pii>E[maxn];
void tar(int u,int pa)
{
	dfn[u]=low[u]=++idx,stk[++top]=u;
	for(auto v:e[u]){
		if(v==pa)continue;
		if(!dfn[v]){
			tar(v,u),low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				++scc,g[scc]={u},E[scc].clear();
				while(g[scc].back()!=v)
					bel[stk[top]]=scc,g[scc].pb(stk[top--]);
			}
		}else low[u]=min(low[u],dfn[v]);
	}
}

set<int>s[maxn];
vi out[maxn];

pii edg[maxn];
int uu[maxn];

int L[maxn],R[maxn],id[maxn];

int fir;
bool cmp(int x,int y){
	return ((fir<id[x])==(fir<id[y]))?(id[x]<id[y]):(fir<id[x]);
}

bool work()
{
	n=read(),m=read();
	scc=idx=0;
	For(i,1,n)e[i].clear(),out[i].clear(),dfn[i]=low[i]=bel[i]=0;
	For(i,1,m){
		int u=read()+1,v=read()+1;
		e[u].pb(v),e[v].pb(u);
	}
	For(i,1,n)if(!dfn[i])tar(i,0);
	For(i,1,n)for(auto j:e[i])if(dfn[i]>dfn[j])E[bel[i]].pb(mkp(i,j));
	For(t,1,scc){
		for(auto u:g[t]) e[u].clear(),s[u].clear();
		for(auto o:E[t]) {
			int u=o.fi,v=o.se;
			e[u].pb(v),e[v].pb(u),s[u].insert(v),s[v].insert(u); 
		}
		queue<int>q;
		for(auto u:g[t]) if(s[u].size()==2) q.push(u);
		int len=0;
		while(q.size()){
			int u=q.front();q.pop();
			if(s[u].size()!=2)continue;
			int x=*s[u].begin(),y=*s[u].rbegin();
			uu[++len]=u;
			edg[len]=mkp(x,y);
			s[u].clear();
			s[x].erase(u),s[y].erase(u),s[x].insert(y),s[y].insert(x);
			if(s[x].size()==2)q.push(x);
			if(s[y].size()==2)q.push(y);
		}
		if(len+2!=g[t].size())return 0;
		int x=0,y=0;
		for(auto u:g[t]){
			R[u]=u;
			if(s[u].size()==1){
				if(!x)x=u;
				else y=u;
			}
		}
		R[x]=y,R[y]=x;
		Rep(i,len,1){
			int u=uu[i],x=edg[i].fi,y=edg[i].se;
			if(R[x]!=y)swap(x,y);
			if(R[x]!=y)return 0;
			R[x]=u,R[u]=y;
		}
		For(i,0,(int)g[t].size()-1)
			id[x]=i,x=R[x];
		for(auto u:g[t]){
			fir=id[u];
			sort(e[u].begin(),e[u].end(),cmp);
			for(auto v:e[u])out[u].pb(v);
		}
	}
	puts("YES");
	For(i,1,n)for(auto j:out[i])cout<<j-1<<" \n"[j==out[i].back()];
	return 1;
}

signed main()
{
	int T=read();
	while(T--)if(!work())puts("NO");
	return 0;
}
