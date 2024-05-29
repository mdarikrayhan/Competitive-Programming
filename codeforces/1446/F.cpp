// Problem: Line Distance
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1446F
// Memory Limit: 250 MB
// Time Limit: 7500 ms
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
#define inf 1e9
#define infll 1e18
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
const int mod=998244353,maxn=1000005;
ll k;
int n,t[maxn],tot;
double a[maxn],b[maxn];
void add(int x,int y=1){ for(;x<maxn-3;x+=lowbit(x)) t[x]+=y; }
int query(int x){ int R=0; for(;x;x^=lowbit(x)) R+=t[x]; return R; }
int query(int l,int r){ return query(r)-query(l-1); }
double lsh[maxn];
vector<pair<double,double>>vec;
double dist(int i){ return sqrt(a[i]*a[i]+b[i]*b[i]); }
const double Pi=acos(-1),eps=1e-9;
ll calc(double R){
	vec.clear(),tot=0;
	F(i,1,n) {
		if(a[i]*a[i]+b[i]*b[i]<=R*R) continue;
		double chk=atan2(b[i],a[i]),dt=acos(R/dist(i)),l=chk-dt,r=chk+dt;
		if(l<-Pi) l+=Pi*2;
		if(r>Pi) r-=Pi*2;
		if(l>r) swap(l,r);
		vec.push_back({l,r}),lsh[++tot]=l,lsh[++tot]=r;
	}
	sort(lsh+1,lsh+tot+1),tot=unique(lsh+1,lsh+tot+1)-lsh-1,sort(vec.begin(),vec.end());
	memset(t,0,sizeof t);
	ll ans=0;
	for(auto [x,y]:vec){
		int l=lower_bound(lsh+1,lsh+tot+1,x)-lsh,r=lower_bound(lsh+1,lsh+tot+1,y)-lsh;
		ans+=query(l,r),add(r);
	}
	return (1ll*n*(n-1)>>1)-ans;
}
signed main(){
	n=read(),k=read();
	F(i,1,n) a[i]=read(),b[i]=read();
	double l=0,r=15000;
	while(r-l>eps){
		double mid=(l+r)/2;
		if(calc(mid)<k) l=mid;
		else r=mid;
	}
	printf("%.12lf",l);
}