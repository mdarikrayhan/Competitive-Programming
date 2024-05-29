// LUOGU_RID: 158444450
#include<bits/stdc++.h>
using namespace std;
namespace IO{
    template<typename T> inline void write(T x){
        if(x<0) putchar('-'),x=-x;
        if(x==0){
            putchar('0'); return ;
        }
        if(x>9) write(x/10);
        putchar(x%10+'0');
        return ;
    }
    template<typename T> inline void read(T &x){
        x=0; int w=1; char ch=getchar();
        while(!isdigit(ch)){
            if(ch=='-') w=-1; ch=getchar();
        }
        while(isdigit(ch))
            x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
        x*=w; return ;
    }
}
using namespace IO;
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),putchar('\n')
#define inf 0x3f3f3f3f
#define mod 1000000007
#define N 500010
#define pb emplace_back
//#define int long long
#define szi sizeof(int)
#define il inline
int T,n,fa[N],hd[N],tot=0,dfn[N],p[N],sz[N],son[N],cnt,dep[N];
int sum[N],t[N],nwd,mnd[N],sg[N],ans;
struct edge{int v,nxt;}eg[N];
il void add(int x,int y){
	eg[++tot].v=y,eg[tot].nxt=hd[x],hd[x]=tot;
	return ;
}
struct BIT{
	int sz,s[N],c[N];
	il void init(int n){
		sz=n+1,memset(s,0,szi*(sz+1)),memset(c,0,szi*sz);
		return ; 
	}
	il void add(int x){
		++c[x]; if(c[x]>1) return ;
		++x; while(x<=sz) ++s[x],x+=(x&-x);
		return ;
	}
	il void del(int x){
		--c[x]; if(c[x]) return ;
		++x; while(x<=sz) --s[x],x+=(x&-x);
		return ;
	}
	il int qry(){
		int res=0,sum=0,tmp;
		for(int i=20;i>=0;--i){
			if((tmp=res+(1<<i))>sz) continue;
			if(sum+s[tmp]==tmp) res=tmp,sum+=s[tmp];
		}
		return res;
	}
}c;
il void pre(int x){
	sz[x]=1,dfn[x]=++cnt,p[cnt]=x;
	mnd[x]=inf,son[x]=0;
	if(!hd[x]) return mnd[x]=dep[x],void();
	for(int i=hd[x];i;i=eg[i].nxt){
		int y=eg[i].v;
		dep[y]=dep[x]+1,pre(y),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]]) son[x]=y;
		mnd[x]=min(mnd[x],mnd[y]);
	}
	return ;
}
il void upd(int x,int fl){
	int td=0;
	for(int i=dfn[x]+fl;i<dfn[x]+sz[x];++i)
		if(dep[p[i]]<=nwd)
			t[dep[p[i]]]^=sg[p[i]],td=max(td,dep[p[i]]);
	for(int i=dep[x]+fl;i<=td;++i){
		if(!t[i]) continue;
		c.del(sum[i]),sum[i]^=t[i],c.add(sum[i]),t[i]=0;
	}
	return ;
}
il void del(int d){
	while(nwd>d) c.del(sum[nwd]),sum[nwd--]=0;
	return ;
}
il void dfs(int x,int op){
	for(int i=hd[x];i;i=eg[i].nxt)
		if(eg[i].v!=son[x]) dfs(eg[i].v,0);
	if(son[x]) dfs(son[x],1);
	if(mnd[x]==dep[x]) nwd=dep[x]+1,c.add(0);
	while(nwd>mnd[x]+1) c.del(sum[nwd]),sum[nwd--]=0;
	if(son[x]) sum[dep[x]+1]=sg[son[x]],c.add(sg[son[x]]);
	for(int i=hd[x];i;i=eg[i].nxt)
		if(eg[i].v!=son[x]) upd(eg[i].v,0);
	sg[x]=c.qry(); if(!op) del(dep[x]);
	return ;
}
il void solve(){
	read(n),ans=tot=cnt=0,c.init(n);
	for(int i=1;i<=n+1;++i) hd[i]=sum[i]=0;
	for(int i=1;i<=n;++i){
		read(fa[i]); if(fa[i]) add(fa[i],i);
	}
	for(int i=1;i<=n;++i) if(!fa[i]) dep[i]=1,pre(i);
	int ct=0;
	for(int i=1;i<=n;++i){
		if(fa[i]) continue; nwd=-1,dfs(i,0),ans^=sg[i];
	}
	puts(ans?"YES":"NO");
	return ;
}
signed main(){
//    freopen("a.in","r",stdin);
//    freopen(".out","w",stdout);
    read(T);
    while(T--) solve();
    return 0;
}
/*
很容易转化成 multi-SG 的模型，问题在于快速算出 SG 函数
每个点的 SG 函数与所有<=它的秩的深度的所有点有关，可以启发式合并
但是代码细节非常多，特别要注意空状态的影响
*/