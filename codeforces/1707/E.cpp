// Problem: E. Replace
// Contest: Codeforces - Codeforces Round 808 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1707/E
// Memory Limit: 1024 MB
// Time Limit: 1500 ms
// Author: nullptr_qwq
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
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
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int mod=998244353,maxn=100005;
int n,sjy,a[maxn];
pii f[20][maxn][20];
pii U(pii x,pii y){ return make_pair(min(x.fi,y.fi),max(x.se,y.se)); }
pii query(int x,int l,int r){
	--r;
	if(l>r) return make_pair(n+1,0);
	int t=__lg(r-l+1);
	return U(f[x][l][t],f[x][r-(1<<t)+1][t]);
}
int query(int l,int r){
	if(l==1&&r==n) return 0;
	pii tmp=query(19,l,r);
	if(tmp.fi!=1||tmp.se!=n) return -1;
	int ans=1;
	dF(i,18,0){
		tmp=query(i,l,r);
		if(tmp.fi!=1||tmp.se!=n) l=tmp.fi,r=tmp.se,ans+=(1<<i);
	}
	return ans;
}
signed main(){
	n=read(),sjy=read();
	F(i,1,n) a[i]=read();
	F(i,1,n-1) f[0][i][0]=make_pair(min(a[i],a[i+1]),max(a[i],a[i+1]));
	F(j,1,19) F(i,1,n-(1<<j)) f[0][i][j]=U(f[0][i][j-1],f[0][i+(1<<(j-1))][j-1]);
	F(i,1,19){
		F(j,1,n-1) f[i][j][0]=query(i-1,f[i-1][j][0].fi,f[i-1][j][0].se);
		F(k,1,19) F(j,1,n-(1<<k)) f[i][j][k]=U(f[i][j][k-1],f[i][j+(1<<(k-1))][k-1]);
	}
	cmh(sjy){
		int l=read(),r=read();
		printf("%d\n",query(l,r));
	}
}