#include <cstdio>
#include <set>
#include <vector>
typedef unsigned int UI;
const int k=1e6,inf=1e9,N=2e5+10,M=1e6+10;
int n,x;std::multiset<int> set;
template<typename T>T lb(T x){return x&(-x);}
template<typename T>T rv(T x){return x>T()?x:-x;}
template<typename T>T min(T x,T y){return x<y?x:y;}
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
namespace RD{UI s=1;UI rd(){s^=s<<13,s^=s>>17,s^=s<<5;return s;}}using RD::rd;
namespace IO{
	int lt,nw,res,dig[20];char c;
	int read(){
		res=0;for(;c<'0'||c>'9';c=getchar());
		for(;!(c<'0'||c>'9');c=getchar())res=(res<<1)+(res<<3)+(c^48);
		return res;
	}
	void write(int x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
	}
}using IO::read;using IO::write;
struct rg{
	int l,r;rg(){};
	rg(int l,int r):l(l),r(r){};
};std::vector<rg> ins[M],del[M];
namespace BIT{
	int a[M];void fm(int x,int d){while(x<=k)a[x]+=d,x+=lb(x);}
	int fq(int x){int res=0;cmax(x,0);while(x)res+=a[x],x-=lb(x);return res;}
}
namespace TP{
	int rt,tnt;
	struct node{
		int l,r,w,x,tx,mx,tmx;UI p;node():l(0),r(0),w(0),x(0),tx(0),mx(0),tmx(0),p(0){};
		node(int l,int r,int w,int x,int tx,int mx,int tmx,UI p):l(l),r(r),w(w),x(x),tx(tx),mx(mx),tmx(tmx),p(p){};
	}t[N<<2];
	int nd(int x,int w){t[++tnt]=node(0,0,w,x,0,inf+1,inf,rd());return tnt;}
	void pushtag(int x,int tx,int tmx){
		if(tmx!=inf)t[x].mx=t[x].tmx=tmx;
		t[x].tx+=tx;int nx=min(t[x].x+tx,t[x].mx);
		t[x].w+=t[x].x+tx-nx,t[x].x=nx;
	}
	void pushdown(int x){
		int l=t[x].l,r=t[x].r;
		pushtag(l,t[x].tx,t[x].tmx);
		pushtag(r,t[x].tx,t[x].tmx);
		t[x].tx=0,t[x].tmx=inf;
	}
	void split(int u,int k,int &x,int &y){
		if(!u){x=y=0;return;}pushdown(u);
		if(t[u].x<=k)x=u,split(t[x].r,k,t[x].r,y);
		else y=u,split(t[y].l,k,x,t[y].l);
	}
	void splitl(int u,int k,int &x,int &y){
		if(!u){x=y=0;return;}pushdown(u);
		if(!t[u].l&&k)x=u,splitl(t[x].r,0,t[x].r,y);
		else y=u,splitl(t[y].l,k,x,t[y].l);
	}
	void splitr(int u,int k,int &x,int &y){
		if(!u){x=y=0;return;}pushdown(u);
		if(!t[u].r&&k)y=u,splitr(t[y].l,0,x,t[y].l);
		else x=u,splitr(t[x].r,k,t[x].r,y);
	}
	int merge(int x,int y){
		if(!x||!y)return x|y;
		int u;pushdown(x),pushdown(y);
		if(t[x].p<t[y].p)u=x,t[x].r=merge(t[x].r,y);
		else u=y,t[y].l=merge(x,t[y].l);
		return u;
	}
	void init(){
		set.insert(-inf-1),set.insert(inf+1);
		rt=merge(nd(-inf,inf/2),merge(nd(x,0),nd(inf,inf/2)));
	}
	void extend(){pushtag(rt,1,inf);}
	int dfs(int u){
		int res=t[u].w;pushdown(u);
		if(t[u].l)cmin(res,dfs(t[u].l));
		if(t[u].r)cmin(res,dfs(t[u].r));
		return res;
	}
	int calc(){return dfs(rt);}
	int fir(int x){while(t[x].l)pushdown(x),x=t[x].l;return x;}
	int las(int x){while(t[x].r)pushdown(x),x=t[x].r;return x;}
	int get(int x){
		if(BIT::fq(x))return inf;
		int a,b,c,d,res=inf;
		auto it=set.lower_bound(x);
		int nx=*it,ls=*(--it);split(rt,x,b,c);
		split(b,ls,a,b),split(c,nx,c,d);int u=las(b),v=fir(c);
		if(b)cmin(res,t[u].w+rv(t[u].x-x));
		if(c)cmin(res,t[v].w+rv(t[v].x-x));
		rt=merge(merge(a,b),merge(c,d));return res;
	}
	void remove(rg g){
		int a,b,c,l=g.l,r=g.r,p=get(l),q=get(r);
		split(rt,l,a,b),split(b,r-1,b,c);
		if(p<inf){
			int u=las(a);auto it=set.lower_bound(l);int ls=*(--it);
			//while(t[u].x>ls&&p+l-t[u].x<t[u].w)splitr(a,1,a,b),u=las(a);
			if(t[u].x<=ls||t[u].w+l-t[u].x>p){int v=nd(l,p);pushtag(v,0,l),a=merge(a,v);}
		}
		if(q<inf){
			int u=fir(c),nx=*set.lower_bound(r);
			//while(t[u].x<=nx&&q+t[u].x-r<t[u].w)splitl(c,1,b,c),u=fir(c);
			if(t[u].x>nx||t[u].w+t[u].x-r>q){int v=nd(r,q);pushtag(v,0,nx),c=merge(v,c);}
		}
		auto it=set.lower_bound(l);int ls=*(--it);
		split(a,ls,a,b),pushtag(b,0,l),a=merge(a,b);
		rt=merge(a,c),set.insert(l),BIT::fm(l+1,1),BIT::fm(r,-1);
	}
	void insert(rg g){
		int a,b,c,d,e=0,l=g.l,r=g.r;
		set.erase(set.find(l));auto it=set.lower_bound(l);
		int nx=*it,ls=*(--it);split(rt,l,b,c);
		while(b&&t[las(b)].x==l)splitr(b,1,b,e);
		int p=las(b);if(t[p].x<=ls||t[p].w+l-t[p].x>t[e].w)b=merge(b,e);
		split(b,ls,a,b),split(c,nx,c,d);
		pushtag(b,0,nx);int u=las(b),v=fir(c);
		while(b&&c&&t[v].x-t[u].x<=rv(t[v].w-t[u].w)){
			if(t[u].w>=inf||t[v].w>=inf)break;
			if(t[v].w>t[u].w)splitl(c,1,e,c);
			else splitr(b,1,b,e);
			u=las(b),v=fir(c);
		}
		BIT::fm(l+1,-1),BIT::fm(r,1);
		rt=merge(merge(a,b),merge(c,d));
	}
	void debug(int x=rt){
		printf("Point %d\n",x);
		printf("x=%d,w=%d,mx=%d,l=%d,r=%d\n",t[x].x,t[x].w,t[x].mx,t[x].l,t[x].r);
		pushdown(x);
		if(t[x].l)debug(t[x].l);if(t[x].r)debug(t[x].r);
	}
}
void ndebug(){return;puts("Now the tree is:"),TP::debug(),putchar('\n');}
int main(){
	n=read(),x=read();
	for(int tl,tr,l,r,i=1;i<=n;++i){
		tl=read()-1,tr=read()+1,l=read()-1,r=read()+1;
		ins[tl].push_back(rg(l,r)),del[tr].push_back(rg(l,r));
	}
	TP::init();
	for(int i=0;i<=k;++i){
		for(rg j:del[i])TP::insert(j),ndebug();
		for(rg j:ins[i])TP::remove(j),ndebug();
		//if(i<=10)printf("After %d sec\n",i);
		TP::extend();
	}
	write(TP::calc());return 0;
}
/*
3 2
3 10 5 6
4 6 10 10
1 3 8 9
*/