#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cassert>
#include<set>
#include<random>
#include<chrono>
#include<bitset>
#include<map>
#include<queue>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#define eb emplace_back

using namespace std;
const int maxn=2e5+10, mxsz=(1<<18)+10, inf=1e9+10;//, P=998244353;
const double eps=1e-10, pi=acos(-1.0);
typedef long long LL;
typedef unsigned long long ULL;
const LL INF=4e18;
typedef pair<LL, int> pli;
typedef pair<int, int> pii;
typedef pair<int, LL> pil;
typedef pair<LL, LL> pll;
inline int read() {
	int x=0, f=1; char c=getchar();
	for(; c<'0'||c>'9'; c=getchar()) if(c=='-') f=0;
	for(; c>='0'&&c<='9'; c=getchar()) x=x*10+c-'0';
	return f?x:-x;
}
int P;
mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
inline int ksm(int x, int y) {
	int s=1;
	for(; y; y>>=1, x=1LL*x*x%P)
		if(y&1) s=1LL*s*x%P;
	return s;
}
inline int add(int x, int y) {x+=y; return x>=P?x-P:x;}
inline int del(int x, int y) {x-=y; return x<0?x+P:x;}
inline int abs_(int x) {return x>0?x:-x;}
int gcd(int x, int y) {return y?gcd(y, x%y):x;}

int l[maxn], r[maxn];

inline LL calc(int x) {return 1ll*(x+1)*x*(x+1)/2-1ll*x*(x+1)*(2*x+1)/6;}

vector<int> b[maxn];

struct pj{
	int mx[2], mxt[2], tag[2];
	LL sum[2];
};
struct tg{
	int mx, mxt; LL sum;
};
inline tg merge(tg x, tg y) {
	if(y.mx>x.mx) return y;
	if(y.mx<x.mx) return x;
	return (tg){x.mx, x.mxt+y.mxt, x.sum+y.sum};
}
struct segt{
	pj tr[maxn<<2];
	inline void update(int u) {
		tr[u].mx[0]=max(tr[u<<1].mx[0], tr[u<<1|1].mx[0]); tr[u].mxt[0]=tr[u].sum[0]=0;
		if(tr[u<<1].mx[0]==tr[u].mx[0]) tr[u].mxt[0]+=tr[u<<1].mxt[0], tr[u].sum[0]+=tr[u<<1].sum[0];
		if(tr[u<<1|1].mx[0]==tr[u].mx[0]) tr[u].mxt[0]+=tr[u<<1|1].mxt[0], tr[u].sum[0]+=tr[u<<1|1].sum[0];
		
		tr[u].mx[1]=max(tr[u<<1].mx[1], tr[u<<1|1].mx[1]); tr[u].mxt[1]=tr[u].sum[1]=0;
		if(tr[u<<1].mx[1]==tr[u].mx[1]) tr[u].mxt[1]+=tr[u<<1].mxt[1], tr[u].sum[1]+=tr[u<<1].sum[1];
		if(tr[u<<1|1].mx[1]==tr[u].mx[1]) tr[u].mxt[1]+=tr[u<<1|1].mxt[1], tr[u].sum[1]+=tr[u<<1|1].sum[1];;
	}
	inline void pushdown(int u, int l, int r) {
		if(tr[u].tag[0]==0&&tr[u].tag[1]==0) return;
		int mid=(l+r)>>1;
		
		if(l<mid||(l&1)==0) {
			tr[u<<1].mx[0]+=tr[u].tag[0];
			tr[u<<1].tag[0]+=tr[u].tag[0];
		}
		if(l<mid||(l&1)==1) {
			tr[u<<1].mx[1]+=tr[u].tag[1];
			tr[u<<1].tag[1]+=tr[u].tag[1];
		}

		if(mid+1<r||(r&1)==0) {
			tr[u<<1|1].mx[0]+=tr[u].tag[0];
			tr[u<<1|1].tag[0]+=tr[u].tag[0];
		}
		if(mid+1<r||(r&1)==1) {
			tr[u<<1|1].mx[1]+=tr[u].tag[1];
			tr[u<<1|1].tag[1]+=tr[u].tag[1];
		}
		
		tr[u].tag[0]=tr[u].tag[1]=0;
	}
	void build(int u, int l, int r) {
		if(l==r) {
			tr[u].mx[0]=tr[u].mx[1]=0;
			tr[u].mxt[l&1]=1;
			tr[u].mxt[l&1^1]=0;
			tr[u].sum[l&1]=l;
			tr[u].sum[l&1^1]=0;
			return;
		}
		int mid=(l+r)>>1;
		build(u<<1, l, mid); build(u<<1|1, mid+1, r);
		update(u);
	}
	void modify(int u, int l, int r, int l0, int r0, int ty, int x) {
		if(l0<=l&&r<=r0) {
			if(l<r||ty==(l&1)) tr[u].mx[ty]+=x, tr[u].tag[ty]+=x;
			return;
		}
		int mid=(l+r)>>1; pushdown(u, l, r);
		if(l0<=mid) modify(u<<1, l, mid, l0, r0, ty, x);
		if(r0>mid) modify(u<<1|1, mid+1, r, l0, r0, ty, x);
		update(u);
	}
	tg query(int u, int l, int r, int l0, int r0) {
		if(l0<=l&&r<=r0) {
			return merge((tg){tr[u].mx[0], tr[u].mxt[0], tr[u].sum[0]}, (tg){tr[u].mx[1], tr[u].mxt[1], tr[u].sum[1]});
		}
		int mid=(l+r)>>1; pushdown(u, l, r);
		tg ret; ret=(tg){0, 0, 0};
		if(l0<=mid) ret=merge(ret, query(u<<1, l, mid, l0, r0));
		if(r0>mid) ret=merge(ret, query(u<<1|1, mid+1, r, l0, r0));
		return ret;
	}
	void print(int u, int l, int r) {
		if(l==r) printf("%d[%d, %d] mx=%d %d mxt=%d %d\n", u, l, r, tr[u].mx[0], tr[u].mx[1], tr[u].mxt[0], tr[u].mxt[1]);
		if(l==r) return;
		int mid=(l+r)>>1; pushdown(u, l, r);
		print(u<<1, l, mid); print(u<<1|1, mid+1, r);
	}
} T[2];
int n, m;

inline void modify(int cur, int i, int ty, int x) {//ty=0 normal ty=1 rev
	if(1<=l[i]-1&&ty==0) {
		T[cur].modify(1, 1, m, 1, l[i]-1, 0, x);
		T[cur].modify(1, 1, m, 1, l[i]-1, 1, x);
	}
	T[cur].modify(1, 1, m, l[i], r[i], (l[i]&1)^ty, x);
	if(r[i]+1<=m&&(((r[i]-l[i]+1)&1)^ty)) {
		T[cur].modify(1, 1, m, r[i]+1, m, 0, x);
		T[cur].modify(1, 1, m, r[i]+1, m, 1, x);
	}
}
int c[maxn];
int main() {
	n=read(), m=read();
	for(int i=1; i<=n; ++i) 
		l[i]=read(), r[i]=read(), ++c[l[i]], --c[r[i]+1];
	
	LL ans=0, t=0;
	for(int i=1; i<=m; ++i) {
		c[i]+=c[i-1];
		if(c[i]>0) ans-=calc(t), t=0;
			else ++t;
	}
	ans-=calc(t);

	for(int i=1; i<=n; ++i) if(l[i]<r[i]) {
		b[l[i]].eb(i);
		b[r[i]].eb(-i);
	}

	int cur=0;
	T[0].build(1, 1, m); T[1].build(1, 1, m);
	for(int i=1; i<=n; ++i) 
		for(int ty:{0, 1})
			modify(ty, i, 0, 1);
	
	//T[0].print(1, 1, m);
	for(int i=1; i<=m; ++i) {
		cur^=1;
		//T[cur].print(1, 1, m);
		for(auto pp:b[i]) {
			int p;
			if(pp>0) {
				p=pp;
				modify(cur^1, p, 0, -1);
				modify(cur^1, p, 1, 1);
			} else {
				p=-pp;
				if((r[p]-l[p]+1)&1) {
					modify(cur^1, p, 1, -1);
					modify(cur^1, p, 0, 1);
				} else {
					modify(cur^1, p, 0, -1);
					modify(cur^1, p, 1, 1);
				}
			}
		} 
		tg tmp=T[cur].query(1, 1, m, 1, i);
	//	printf("i=%d (%d, %d, %lld)\n", i, tmp.mx, tmp.mxt, tmp.sum);
		if(tmp.mx==n) ans+=1ll*tmp.mxt*(i+1)-tmp.sum;
	}
	printf("%lld", ans);
    return 0;
}
	 	  	   	 		 		      	 	 	 			