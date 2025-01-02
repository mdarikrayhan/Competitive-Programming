// LUOGU_RID: 159951443
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
#define inf 0x3f3f3f3f3f3f3f
#define mod 998244353
#define N 500010
#define pb emplace_back
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
#define szi sizeof(int)
#define il inline
int n,q,sum[3][N],dp[N],ans=-inf; vector<int> p[N];
struct itv{int l,r,v;}a[N];
il bool cmp(itv a,itv b){return (a.l!=b.l)?(a.l<b.l):(a.r<b.r);}
il void cmax(int &x,int y){x=(x>y)?x:y;return ;}
struct segt1{
	struct dat{
		int a,b,res;
		//线段树维护 f(x)+g(y) (x<=y),合并区间时 f,g 分别取 max，然后新区间答案为 max(原左右区间答案,左区间最大f+右区间最大g)
		dat operator +(const dat &x){
			return dat{max(a,x.a),max(b,x.b),max(max(res,x.res),a+x.b)};
		}
	}s[N<<2];
	il void init(int rt,int l,int r){
		s[rt].a=s[rt].res=-inf;
		if(l==r) return s[rt].b=sum[0][l]-sum[1][l-1],void();
		int mid=l+r>>1; init(ls,l,mid),init(rs,mid+1,r);
		return s[rt]=s[ls]+s[rs],void();
	}
	il void upd(int rt,int l,int r,int x,int y){
		if(l==r){
			cmax(s[rt].a,y),cmax(s[rt].res,s[rt].a+s[rt].b);
			return ;
		}
		int mid=l+r>>1;
		if(x<=mid) upd(ls,l,mid,x,y); else upd(rs,mid+1,r,x,y);
		return s[rt]=s[ls]+s[rs],void();
	}
	il dat qry(int rt,int l,int r,int x){
		if(r<=x) return s[rt];
		int mid=l+r>>1;
		return (x<=mid)?qry(ls,l,mid,x):(s[ls]+qry(rs,mid+1,r,x));
	}
}sg1;
struct segt2{
	int mx[N<<2],tg[N<<2];
	il void init(int rt,int l,int r){
		tg[rt]=-inf; if(l==r) return mx[rt]=dp[l],void();
		int mid=l+r>>1; init(ls,l,mid),init(rs,mid+1,r);
		return mx[rt]=max(mx[ls],mx[rs]),void();
	}
	il void upd(int rt,int l,int r,int x,int y,int z){
		if(x<=l&&r<=y) return cmax(mx[rt],z),cmax(tg[rt],z),void();
		int mid=l+r>>1;
		if(x<=mid) upd(ls,l,mid,x,y,z); if(y>mid) upd(rs,mid+1,r,x,y,z);
		return ;
	}
	il int qry(int rt,int l,int r,int x){
		if(l==r) return mx[rt];
		int mid=l+r>>1,res=tg[rt];
		cmax(res,(x<=mid)?qry(ls,l,mid,x):qry(rs,mid+1,r,x));
		return res;
	}
}sg2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n),read(q);
	for(int i=1;i<=n;++i) read(sum[0][i]),sum[0][i]+=sum[0][i-1];
	for(int i=1;i<=n;++i) read(sum[1][i]),sum[1][i]+=sum[1][i-1];
	for(int i=1;i<=n;++i) read(sum[2][i]);
	for(int i=n;i>=1;--i) sum[2][i]+=sum[2][i+1];
	for(int i=1;i<=q;++i)
		read(a[i].l),read(a[i].r),read(a[i].v),p[a[i].r].pb(i);
	sg1.init(1,1,n);
	for(int i=n;i>=1;--i){
		for(int j:p[i]) sg1.upd(1,1,n,a[j].l,-a[j].v);
		dp[i]=sg1.qry(1,1,n,i).res;
	}
	sg2.init(1,1,n),sort(a+1,a+q+1,cmp);
	for(int i=1;i<=q;++i)
		sg2.upd(1,1,n,a[i].l,a[i].r,sg2.qry(1,1,n,a[i].l-1)-a[i].v);
	for(int i=1;i<=n;++i)
		ans=max(ans,sg2.qry(1,1,n,i)+sum[1][i]+sum[2][i]);
	writeln(ans);
	return 0;
}
/*
直接 dp 答案比较困难，考虑设计 dp 状态 dp[i] 表示从 (1,1)->(2,i) 的最大收益
转移分为两种情况
一是只开这一个区间，从区间内且在这个点前面的任意一点拐入第 2 行
二是这个区间要与前面的一些区间合并
第二种情况按 l 排序之后线段树维护更新区间内的 dp 值，可以在第一种情况全部转移结束后转移
对于第一种情况，设拐点为 y，对于位置 x 要求 l[i]<=y<=x<=r[i]
稍微拆一下贡献，只需维护 s1[y]-s2[y-1] -v[i] 的最大值，考虑把 -v[i] 的贡献放到 l[i] 处，且为了保证 x<=r[i] 可以按 r 递减加入区间
然后问题就是 [1,x] 中，f(l)+g(y) (l<=y) 的最值，是线段树可以维护的经典问题
*/