#include<bits/stdc++.h>
#define il inline
#define ui unsigned int
#define ll long long
#define ull unsigned ll
#define lll __int128
#define db double
#define ldb long db
#define pii pair<int,int>
#define vi vector<int>
#define fir first
#define sec second
#define gc getchar
#define pc putchar
#define mst(arr,val) memset(arr,val,sizeof arr)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pct __builtin_popcount
using namespace std;
const int N=3e5+10,INF=0x3f3f3f3f;
const ll INFll=0x3f3f3f3f3f3f3f3f;
il int rd() {int x=0,f=1; char ch=gc(); while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=gc();} while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc(); return x*f;}
il ll rdll() {ll x=0; int f=1; char ch=gc(); while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=gc();} while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc(); return x*f;}
il void wr(int x) {if(x<-2147483647) return (void)printf("-2147483648"); if(x<0) {pc('-'),wr(-x); return;} if(x<10) {pc(x+'0'); return;} wr(x/10),pc(x%10+'0');}
il void wrll(ll x) {if(x<-9223372036854775807) return (void)printf("-9223372036854775808"); if(x<0) return pc('-'),wrll(-x); if(x<10) return (void)pc(x+'0'); wrll(x/10),pc(x%10+'0');}
il void wr(int x,char *s) {wr(x),printf("%s",s);}
il void wrll(ll x,char *s) {wrll(x),printf("%s",s);}
int n,m,cnt,pos,ans[N];
struct edg {int x,y,z,id;}e[N];
bool cmp(edg s,edg t) {return s.z<t.z;}
struct DSU {
	int top,fa[N],siz[N];
	struct nd {int x,y,t;}st[N];
	void init() {for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
	int fd(int x) {return x==fa[x]?x:fd(fa[x]);}
	void mg(int x,int y) {
		x=fd(x),y=fd(y); if(x==y) return;
		if(siz[x]>siz[y]) swap(x,y); int t=(siz[x]&siz[y]&1)<<1;
		st[++top]={x,y,t},cnt-=t,fa[x]=y,siz[y]+=siz[x];
	}
	void pp() {int x=st[top].x,y=st[top].y,t=st[top--].t; fa[x]=x,siz[y]-=siz[x],cnt+=t;}
}D;
struct SGT {
	#define ls (id<<1)
	#define rs (id<<1|1)
	#define mid (l+r>>1)
	vi tr[N<<2];
	void upd(int id,int l,int r,int L,int R,int k) {
		if(L>R) return; if(L<=l&&r<=R) return tr[id].pb(k);
		L<=mid?upd(ls,l,mid,L,R,k):(void)0,R>mid?upd(rs,mid+1,r,L,R,k):(void)0;
	}
	void sol(int id,int l,int r) {
		int lst=D.top; for(int i:tr[id]) D.mg(e[i].x,e[i].y);
		if(l==r) {
			while(1) {
				if(pos==m||!cnt) break; pos++;
				if(e[pos].id<=l) D.mg(e[pos].x,e[pos].y),upd(1,1,m,e[pos].id,l-1,pos);
			}
			ans[l]=cnt?-1:e[pos].z;
		} else sol(rs,mid+1,r),sol(ls,l,mid);
		while(D.top>lst) D.pp();
	}
}T;
void QwQ() {
	n=cnt=rd(),m=rd(),D.init();
	for(int i=1;i<=m;i++) e[i]={rd(),rd(),rd(),i};
	sort(e+1,e+1+m,cmp),T.sol(1,1,m);
	for(int i=1;i<=m;i++) wr(ans[i],"\n");
}
signed main() {
	int T=1; while(T--) QwQ();
}

 	  		 	 		 				 	  	  		 			