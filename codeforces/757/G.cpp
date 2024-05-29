#include<bits/stdc++.h>
namespace IO{
	// #define ISIZE (1<<20)
	// char in[ISIZE],*p1=in,*p2=in;
	// std::streambuf *inbuf=std::cin.rdbuf();
	// #define getchar() (p1==p2&&(p2=(p1=in)+inbuf->sgetn(in,ISIZE),p1==p2)?EOF:*p1++)
	// std::streambuf *outbuf=std::cout.rdbuf();
	// #define putchar(ch) (outbuf->sputc(ch))
	template<class Tp> __forceinline void read(Tp &x){
		x=0; bool f=0; char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
		for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
		if(f) x=-x;
	}
	template<class Tp,class ...Args> __forceinline void read(Tp &x,Args &...args){ read(x),read(args...); }
	__forceinline void write(const char *x){ while(*x) putchar(*x++); }
	__forceinline void write(char *x){ while(*x) putchar(*x++); }
	template<class Tp> __forceinline void write(Tp x){
		static char stk[50],*top=stk;
		if(x<0) putchar('-'),x=-x;
		do *++top=x%10,x/=10; while(x);
		do putchar(*top--^48); while(top!=stk);
	}
	template<class Tp,class ...Args> __forceinline void write(Tp x,Args ...args){ write(x),write(args...); }
	#undef getchar
	#undef putchar
	#undef ISIZE
}
const int mod=1<<30;
const int N=2e5+5;
int tot,h[N];
struct edge{ int to,nex,val; }e[N*2];
__forceinline void add(int u,int v,int w){ e[++tot]=(edge){v,h[u],w},h[u]=tot; }
__forceinline void add_edge(int u,int v,int w){ add(u,v,w),add(v,u,w); }
int n,q,p[N];
long long pre_w[N],pre_dis[N],dis[N];
int fa[N],top[N],dfn[N],tt,rev[N],sz[N],son[N],w[N];
void dfs1(int u,int fa){
    ::fa[u]=fa,sz[u]=1;
    for(int i=h[u];i;i=e[i].nex){
        int v=e[i].to,w=e[i].val;
        if(v==fa) continue;
        ::w[v]=w,dis[v]=dis[u]+w;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int tp){
    top[u]=tp,dfn[u]=++tt,rev[tt]=u;
    if(son[u]) dfs2(son[u],tp);
    for(int i=h[u];i;i=e[i].nex){
        int v=e[i].to;
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int root[N],lim,siz;
const int FK=3.81e7;
int ls[FK],rs[FK],s1[FK]; long long s2[FK];
__forceinline void push_up(int rt,int l,int r){ s2[rt]=s2[ls[rt]]+s2[rs[rt]]+(pre_w[r]-pre_w[l-1])*s1[rt]; }
void insert(int &rt,int l,int r,int L,int R){
    if(rt<=lim) ls[++siz]=ls[rt],rs[siz]=rs[rt],s1[siz]=s1[rt],s2[siz]=s2[rt],rt=siz;//不要改本次新建的
    if(L<=l&&r<=R) return s1[rt]++,s2[rt]+=pre_w[r]-pre_w[l-1],void();
    int mid=(l+r)>>1;
    if(L<=mid) insert(ls[rt],l,mid,L,R);
    if(mid<R) insert(rs[rt],mid+1,r,L,R);
    push_up(rt,l,r);
}
long long query(int rt,int l,int r,int L,int R,int cnt){
    if(!rt) return (pre_w[std::min(r,R)]-pre_w[std::max(l-1,L-1)])*cnt;
    if(L<=l&&r<=R) return (pre_w[r]-pre_w[l-1])*cnt+s2[rt];
    int mid=(l+r)>>1; long long res=0;
    if(L<=mid) res+=query(ls[rt],l,mid,L,R,cnt+s1[rt]);
    if(mid<R) res+=query(rs[rt],mid+1,r,L,R,cnt+s1[rt]);
    return res;
}
__forceinline void insert(int id,int u){
    lim=siz;
    for(;u;u=fa[top[u]]) insert(root[id],1,n,dfn[top[u]],dfn[u]);
}
__forceinline long long query(int id,int u){
    long long ans=dis[u]*id+pre_dis[id];
    for(;u;u=fa[top[u]]) ans-=query(root[id],1,n,dfn[top[u]],dfn[u],0)*2;
    return ans;
}
int main(){
    IO::read(n,q);
    for(int i=1;i<=n;i++) IO::read(p[i]);
    for(int i=1;i<n;i++){
        int u,v,w; IO::read(u,v,w);
        add_edge(u,v,w);
    }
    dfs1(1,0),dfs2(1,1);
    for(int i=1;i<=n;i++) pre_dis[i]=pre_dis[i-1]+dis[p[i]],pre_w[i]=pre_w[i-1]+w[rev[i]];
    for(int i=1;i<=n;i++) root[i]=root[i-1],insert(i,p[i]);
    int cnt=0;
    long long lstans=0;
    while(q--){
        int op; IO::read(op);
        if(op==1){
            int l,r,x; IO::read(l,r,x);
            l^=lstans,r^=lstans,x^=lstans;
            IO::write(lstans=(query(r,x)-query(l-1,x)),"\n");
            lstans%=mod;
        }else{
            int x; IO::read(x);
            x^=lstans;
            std::swap(p[x],p[x+1]),pre_dis[x]=pre_dis[x-1]+dis[p[x]];
            if(++cnt==160000){//暴力重建卡空间
                cnt=0,siz=0;
                for(int i=1;i<=n;i++) root[i]=root[i-1],insert(i,p[i]);
            }else root[x]=root[x-1],insert(x,p[x]);
        }
    }
    return 0;
}
//////asdsad
			 	     		 		  	 	   	 	 		 	