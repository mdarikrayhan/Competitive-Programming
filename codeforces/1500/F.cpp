// Problem: F. Cupboards Jumps
// Contest: Codeforces - Codeforces Round 707 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/problemset/problem/1500/F
// Memory Limit: 512 MB
// Time Limit: 6000 ms
// Author: nullptr_qwq
// 
// Powered by CP Editor (https://cpeditor.org)

// 私は猫です

#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define int long long
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
void chkmin(int &x,int y){ x=min(x,y); }
void chkmax(int &x,int y){ x=max(x,y); }
const int mod=998244353,maxn=1000005;
int sgn,D,n,m,a[maxn],lst[maxn],b[maxn],ans[maxn];
int trans(int x){ return sgn?(D-x):(D+x); }
int invtr(int x){ return sgn?(D-x):(x-D); }
signed main(){
	n=read(),m=read();
	F(i,1,n-2) a[i]=read();
	int l=0,r=m;
	set<int>s;
	F(i,1,n-2){
		const int val=a[i];
		int L=invtr(0),R=invtr(val);
		if(L>R) swap(L,R);
		chkmax(l,L),chkmin(r,R);
		for(;!s.empty()&&(*s.begin())<L;s.erase(s.begin()));
		for(;!s.empty()&&(*(--s.end())>R);s.erase(--s.end()));
		if(l>r&&s.empty()) return puts("NO"),0;
		int rev=invtr(val);
		if(s.count(rev)||(l<=rev&&rev<=r)){
			s.clear(),l=0,r=lst[i]=val,D=sgn=0;
			continue;
		}
		lst[i]=(l<=r)?trans(l):trans(*s.begin());
		sgn^=1,D=val-D,s.insert(invtr(val));
	}
	b[n-1]=(l<=r)?trans(l):trans(*s.begin());
	dF(i,n-2,1){
		if(lst[i]==a[i]) b[i]=a[i];
		else if(b[i+1]==a[i]) b[i]=lst[i];
		else b[i]=a[i]-b[i+1];
	}
	int fl=1,mn=infll;
	dF(i,n-2,1){
		if(abs(b[i])+abs(b[i+1])!=a[i]) fl=-fl;
		b[i]=fl*b[i];
	}
	F(i,1,n) ans[i]=ans[i-1]+b[i-1],chkmin(mn,ans[i]);
	F(i,1,n) ans[i]-=mn;
	puts("YES");
	F(i,1,n) printf("%lld ",ans[i]);
}