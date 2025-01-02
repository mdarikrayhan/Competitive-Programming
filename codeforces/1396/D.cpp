// Problem: D. Rainbow Rectangles
// Contest: Codeforces - Codeforces Round 666 (Div. 1)
// URL: https://codeforces.com/contest/1396/problem/D
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Author: nullptr_qwq
// 
// Powered by CP Editor (https://cpeditor.org)

// 私は猫です

#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define inf 1000000000
#define infll 1000000000000000000ll
#define pii pair<int,int>
#define F(i,a,b) for(int i=a;i<=(b);i++)
#define dF(i,a,b) for(int i=a;i>=(b);i--)
#define wh(lzm) while(lzm--)
#define cmh(sjy) while(sjy--)
#define lowbit(x) (x&(-x))
#define HH printf("\n")
#define eb emplace_back
using namespace std;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int mod=1e9+7,maxn=2005;
int qpow(int x,ll y){
	int rt=1;
	for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) rt=1ll*rt*x%mod;
	return rt;
}
void inc(int &x,int y){ x=(x+y>=mod)?(x+y-mod):(x+y); }
void dec(int &x,int y){ x=(x>=y)?(x-y):(x+mod-y); }
void mul(int &x,int y){ x=1ll*x*y%mod; }
int add(int x,int y){ return (x+y>=mod)?(x+y-mod):(x+y); }
int sub(int x,int y){ return (x>=y)?(x-y):(x+mod-y); }
int prod(int x,int y){ return 1ll*x*y%mod; }
void chkmax(int &x,int y){ x=max(x,y); }
void chkmin(int &x,int y){ x=min(x,y); }
vector<int>vx[maxn],vy[maxn];
multiset<int>s[maxn];
int n,m,L,a[maxn],b[maxn],c[maxn],lshx[maxn],lshy[maxn],tx,ty,cx[maxn],cy[maxn];
namespace seg{
	#define ls (o<<1)
	#define rs (o<<1|1)
	int t[maxn<<2],lz[maxn<<2],mx[maxn<<2],sum[maxn<<2];
	void build(int o,int l,int r){
		if(l==r)return sum[o]=cy[l],void();
		int mid=(l+r)>>1; build(ls,l,mid),build(rs,mid+1,r),sum[o]=add(sum[ls],sum[rs]);
	}
	void maketag(int o,int val){ t[o]=1ll*sum[o]*val%mod,lz[o]=mx[o]=val; }
	void pushdown(int o){ if(lz[o]) maketag(ls,lz[o]),maketag(rs,lz[o]),lz[o]=0; }
	void update(int o,int l,int r,int ql,int qr,int val){
		if(ql>qr) return;
		if(ql<=l&&qr>=r) return maketag(o,val),void();
		int mid=(l+r)>>1; pushdown(o);
		if(ql<=mid)update(ls,l,mid,ql,qr,val);
		if(qr>mid) update(rs,mid+1,r,ql,qr,val);
		t[o]=add(t[ls],t[rs]),mx[o]=max(mx[ls],mx[rs]);
	}
	int find(int o,int l,int r,int x){
		if(l==r) return mx[o]>x?l:l+1;
		int mid=(l+r)>>1; pushdown(o);
		return (mx[ls]>x)?find(ls,l,mid,x):find(rs,mid+1,r,x);
	}
	void gmx(int l,int r,int val){
		if(l>r) return;
		update(1,1,ty,l,min(r,find(1,1,ty,val)-1),val);
	}
}
int nxt[maxn];
void ERR(multiset<int>&s,int x){ s.erase(s.find(x)); }
signed main(){
	n=read(),m=read(),L=read()+1;
	F(i,1,n) a[i]=read()+1,b[i]=read()+1,c[i]=read();
	F(i,1,n) lshx[++tx]=a[i],lshy[++ty]=b[i];
	sort(lshx+1,lshx+tx+1),tx=unique(lshx+1,lshx+tx+1)-lshx-1;
	sort(lshy+1,lshy+ty+1),ty=unique(lshy+1,lshy+ty+1)-lshy-1;
	lshx[tx+1]=lshy[ty+1]=L;
	F(i,1,n) a[i]=lower_bound(lshx+1,lshx+tx+1,a[i])-lshx;
	F(i,1,n) b[i]=lower_bound(lshy+1,lshy+ty+1,b[i])-lshy;
	F(i,1,tx+1) cx[i]=lshx[i]-lshx[i-1];
	F(i,1,ty+1) cy[i]=lshy[i]-lshy[i-1];
	F(i,1,n) vx[a[i]].push_back(i),vy[b[i]].push_back(i);
	F(i,1,m) s[i].insert(0),s[i].insert(ty+1);
	seg::build(1,1,ty);
	int ans=0;
	F(i,1,tx){
		multiset<int>st;
		F(j,1,m) st.insert(nxt[j]=ty+1);
		dF(j,ty,1){
			for(int x:vy[j]) if(a[x]>=i){
				ERR(st,nxt[c[x]]);
				st.insert(nxt[c[x]]=j);
				s[c[x]].insert(j);
			}
			seg::update(1,1,ty,j,j,lshy[*--st.end()]);
		}
		dF(j,tx,i){
			inc(ans,1ll*cx[i]*cx[j+1]%mod*sub(1ll*lshy[ty]*L%mod,seg::t[1])%mod);
			for(int x:vx[j]) {
				ERR(s[c[x]],b[x]);
				auto it=s[c[x]].upper_bound(b[x]);
				seg::gmx(*prev(it)+1,b[x],lshy[*it]);
			}
		}
	}
	printf("%d",ans);
}