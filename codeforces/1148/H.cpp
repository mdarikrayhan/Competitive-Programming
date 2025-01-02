// LUOGU_RID: 158940358
#include<bits/stdc++.h>
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fd(i,r,l) for(int i=r;i>=l;--i)
#define ll long long
#define V inline void
#define I inline int
#define B inline bool
#define L inline ll
#define vi vector<int>
#define pi pair<int,int>
#define Pi pair<ll,ll>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
using namespace std;
const int N=2e5+10;
I read() {
	int x=0,y=1;char c=getchar();
	while(c<48||c>57){if(c==45)y=-1;c=getchar();}
	while(c>=48&&c<=57)x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*y;
}
char St;
int n,las[N];
struct Tree1 {
	#define ls x<<1
	#define rs x<<1|1
	int tr[N<<2];
	V add(int x,int l,int r,int px,int py) {
		if(l==r) return tr[x]=py,void();
		int mid=l+r>>1;
		if(px<=mid) add(ls,l,mid,px,py);
		else add(rs,mid+1,r,px,py);
		tr[x]=min(tr[ls],tr[rs]);
	}
	I ques(int x,int l,int r,int pl,int pr) {
		if(l>pr||r<pl) return 1e9;
		if(l>=pl&&r<=pr) return tr[x];
		int mid=l+r>>1;
		return min(ques(ls,l,mid,pl,pr),ques(rs,mid+1,r,pl,pr));
	}
	I askmex(int x,int l,int r,int k) {
		if(l==r) return l+(tr[x]>=k);
		int mid=l+r>>1;
		if(k<=tr[ls]) return askmex(rs,mid+1,r,k);
		else return askmex(ls,l,mid,k);
	}
	#undef ls
	#undef rs 
}T;
Pi operator +(Pi x,Pi y) {return mk(x.fi+y.fi,x.se+y.se);}
struct Tree2 {
	ll s1[N<<7],t1[N<<7],t2[N<<7];
	int s2[N<<7],ls[N<<7],rs[N<<7],cnt;
	I nw(int x) {
		++cnt;s1[cnt]=s1[x];s2[cnt]=s2[x];t1[cnt]=t1[x];t2[cnt]=t2[x];ls[cnt]=ls[x];rs[cnt]=rs[x];return cnt;
	}
	V add(int &x,int l,int r,int pl,int pr,ll p1,ll p2) {
		x=nw(x);
		if(l>=pl&&r<=pr) return t1[x]+=(r-l+1)*p1,t2[x]+=(r-l+1)*p2,s1[x]+=p1,s2[x]+=p2,void();
		int mid=l+r>>1;
		t1[x]+=p1*(min(r,pr)-max(l,pl)+1);t2[x]+=p2*(min(r,pr)-max(l,pl)+1);
		if(pl<=mid) add(ls[x],l,mid,pl,pr,p1,p2);
		if(pr>mid) add(rs[x],mid+1,r,pl,pr,p1,p2);
	} 
	Pi ques(int x,int l,int r,int pl,int pr) {
		if(l>pr||r<pl||!x) return mk(0,0);
		if(l>=pl&&r<=pr) return mk(t1[x],t2[x]);
		int mid=l+r>>1;Pi s=mk(s1[x]*(min(r,pr)-max(l,pl)+1),s2[x]*(min(r,pr)-max(l,pl)+1));
		if(pl<=mid) s=s+ques(ls[x],l,mid,pl,pr);
		if(pr>mid) s=s+ques(rs[x],mid+1,r,pl,pr);
		return s;
	}
}T2;
set<pi> rt[N];
V Add(int val,int l,int r,int t,ll op) {
	pi Rt=*rt[val].rbegin();int w=Rt.se;
	T2.add(w,1,n,l,r,op*t,-op);
	if(Rt.fi==t) rt[val].erase(rt[val].find(Rt));
	Rt.fi=t;Rt.se=w;rt[val].insert(Rt);
}
L query(int tm,int l,int r,int k) {
	auto t=rt[k].upper_bound(mk(tm,10000000));
	if(t==rt[k].begin()) return 0;
	t--;
	Pi s=T2.ques((*t).se,1,n,l,r);
	return s.fi+tm*s.se;
}
char Ed;
int main() {
	cerr<<(&St-&Ed)/1024.0<<endl;
	n=read();
	fo(i,0,n) rt[i].insert(mk(0,0));
	ll ans=0;
	fo(i,1,n) {
		int a=(read()+ans)%(n+1),l=(read()+ans)%i+1,r=(read()+ans)%i+1,k=(read()+ans)%(n+1);
		if(l>r) swap(l,r);
		int mex=T.askmex(1,0,n,las[a]+1);T.add(1,0,n,a,i);
		if(mex==a) {
			int p,st=las[a]+1,ed=i-1;
			while(st<i&&(p=T.askmex(1,0,n,st))>a) {
				ed=min(T.ques(1,0,n,0,p-1),i-1);
				if(st<=ed) Add(a,st,ed,i-1,1),Add(p,st,ed,i-1,-1);
				st=ed+1;
			}
		}
		las[a]=i;Add(!a,i,i,i-1,-1);
		printf("%lld\n",ans=query(r,l,r,k)-query(l-1,l,r,k));
	}
	return 0;
}

