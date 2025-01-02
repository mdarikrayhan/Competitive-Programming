#include<bits/stdc++.h>
#define For(i,a,b) for( int i=(a);i<=(b);++i)
#define Rep(i,a,b) for( int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
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

#define maxn 1000005
#define inf 0x3f3f3f3f
#define ull unsigned long long

int n,m,q,res,aa,bb,cc,dd,mx1,mx2,mxid1,mxid2;
void upd(int x,int a,int b,int c,int d){
	//cout<<"upd "<<x<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	if(x>res)res=x,aa=a,bb=b,cc=c,dd=d;}
void add12(int x,int id){
	if(x>mx1)mx2=mx1,mxid2=mxid1,mx1=x,mxid1=id;
	else if(x>mx2)mx2=x,mxid2=id;
}

struct edge{
	int to,nxt;
}e[maxn<<1];
int tot=1,head[maxn];
void adde(int u,int v){
	e[++tot]=(edge){v,head[u]};
	head[u]=tot;
}

mt19937_64 rnd(19890604);
int dfn[maxn],low[maxn],bel[maxn],idx,st[maxn],tp,cnt,out[maxn];
int fa[maxn][19],dep[maxn],fe[maxn];
ull val[maxn],s[maxn];
map<ull,int>mpe;
void tar(int u,int lste)
{
	dfn[u]=low[u]=++idx,st[++tp]=u;
	For(i,1,18)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if((i^1)==lste)continue;
		if(!dfn[v]) fa[v][0]=u,dep[v]=dep[u]+1,tar(v,i),low[u]=min(low[u],low[v]),fe[v]=i;
		else{
			low[u]=min(low[u],dfn[v]);
			if(dep[u]>dep[v]) val[i]=rnd(),mpe[val[i]]=i,s[u]^=val[i],s[v]^=val[i];
		}
	}
	if(dfn[u]==low[u]){
		int v; ++cnt;
		do v=st[tp--],bel[v]=cnt;while(v!=u);
	}out[u]=idx;
}

bool insub(int u,int v){return dfn[u]>=dfn[v]&&dfn[u]<=out[v];}

int cov[maxn];
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	Rep(i,18,0)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return u;
	Rep(i,18,0)if(fa[u][i]^fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int jump(int u,int v){
	Rep(i,18,0)if(dep[fa[u][i]]>dep[v])u=fa[u][i];
	return u;
}

map<ull,int>up;
int dw[maxn];
void dfs(int u){
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(fe[v]!=i)continue;
		dfs(v),cov[u]+=cov[v],s[u]^=s[v];
	}
	if(u>1&&!s[u]) add12(cov[u],u);
	if(u>1&&s[u]){
		dw[u]=up[s[u]];
		up[s[u]]=u;
	}
	if(mpe.count(s[u])) upd(cov[u],u,fa[u][0],e[mpe[s[u]]].to,e[mpe[s[u]]^1].to);
}

namespace T{
	#define N 20000005
	int rt[maxn],t[N],ls[N],rs[N],cnt;
	int copy(int p){
		int u=++cnt;
		t[u]=t[p],ls[u]=ls[p],rs[u]=rs[p];
		return u;
	}
	void upd(int&p,int l,int r,int x){
		p=copy(p),++t[p];
		if(l==r)return;
		int mid=l+r>>1;
		x<=mid?upd(ls[p],l,mid,x):upd(rs[p],mid+1,r,x);
	}
	int ask(int p,int l,int r,int ql,int qr){
		if(!p||(l>=ql&&r<=qr))return t[p];
		int res=0,mid=l+r>>1;
		if(ql<=mid)res+=ask(ls[p],l,mid,ql,qr);
		if(qr>mid)res+=ask(rs[p],mid+1,r,ql,qr);
		return res;
	}
}

vi vec[maxn];
void addq(int u,int v){vec[dfn[u]].pb(dep[v]);}

int t[maxn],len;
void upde(int u,int v,int w){
	upd(w,u,fa[u][0],v,fa[v][0]);
}
int both(int u,int v){
	if(dep[u]>=dep[v]){puts("wa2");exit(0);}
	int res=T::ask(T::rt[out[v]],1,n,1,dep[u])-T::ask(T::rt[dfn[v]-1],1,n,1,dep[u]);
	return res;
}
int calc(int u,int v){
	int res=cov[u]+cov[v]-2*both(u,v);
	return res; 
}
void divide(int l,int r,int ql,int qr){
	if(l>r||ql>qr)return;
	int mid=l+r>>1,p=ql,mx=-inf;
	For(i,ql,qr){
		if(i<=mid)continue;
		int tmp=calc(t[mid],t[i]);
		if(tmp>mx)mx=tmp,p=i;
	}
	if(mx>0)upde(t[mid],t[p],mx);
	divide(l,mid-1,ql,p);
	divide(mid+1,r,p,qr);
}

void work()
{
	n=read(),m=read();
	tot=1,res=mx1=mx2=mxid1=mxid2=-1,idx=cnt=0; mpe.clear(),up.clear();
	s[0]=-1; T::cnt=0;
	For(i,1,n){
		head[i]=dfn[i]=bel[i]=low[i]=cov[i]=val[i]=s[i]=fe[i]=dw[i]=0;
		T::rt[i]=0; vec[i].clear();
	}
	
	For(i,1,m){
		int u=read(),v=read();
		adde(u,v),adde(v,u);
	}
	dep[1]=1,tar(1,0);
	
	q=read();
	For(i,1,q){
		int u=read(),v=read(),l=lca(u,v);
		++cov[u],++cov[v],cov[l]-=2;
		if(u^l) addq(u,jump(u,l));
		if(v^l) addq(v,jump(v,l));
	}
	dfs(1);
	For(i,1,n){
		T::rt[i]=T::rt[i-1];
		for(auto it:vec[i]) T::upd(T::rt[i],1,n,it);
	}
	
//	For(i,1,n)cout<<fa[i][0]<<" \n"[i==n];
//	For(i,1,n)cout<<cov[i]<<" \n"[i==n];
	
	for(auto it:up){
		int u=it.se; len=0;
		while(u)t[++len]=u,u=dw[u];
		divide(1,len-1,2,len);
	}
	
	int flag=0;
	if(mx1+max(mx2,0)>res){
		cout<<mx1+max(mx2,0)<<'\n';
		cout<<mxid1<<" "<<fa[mxid1][0]<<"\n";
		if(mxid2>0)cout<<mxid2<<" "<<fa[mxid2][0]<<'\n';
		else{
			For(u,1,n){
				for(int i=head[u];i&&!flag;i=e[i].nxt){
					int v=e[i].to;
					if(fa[u][0]!=v&&fa[v][0]!=u) cout<<u<<" "<<v<<'\n',flag=1;
				}
			}
		}
		return;
	}
	if(res!=-1){
		cout<<res<<'\n';
		cout<<aa<<" "<<bb<<"\n";
		cout<<cc<<" "<<dd<<"\n"; 
		return;
	}
	puts("0");
	For(u,1,n){
		for(int i=head[u];i&&flag<2;i=e[i].nxt){
			int v=e[i].to;
			if(u<v)cout<<u<<" "<<v<<"\n",++flag;
		}
	}
}

signed main(){
	int T=read();
	while(T--)work();
	return 0;
}
