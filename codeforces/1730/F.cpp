// Problem: F. Almost Sorted
// Contest: Codeforces - Codeforces Round 823 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1730/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
void chkmax(int &x,int y){ x=max(x,y); }
void chkmin(int &x,int y){ x=min(x,y); }
const int maxn=5005;
int n,k,a[maxn],f[maxn][maxn],rev[maxn],vis[maxn][maxn];
signed main(){
	n=read(),k=read()+1;
	int mx=(1<<k)-1;
	F(i,1,n) rev[a[i]=read()]=i,vis[i][a[i]]++;
	dF(i,n,1) F(j,1,n) vis[i][j]+=vis[i+1][j]+vis[i][j-1]-vis[i+1][j-1];
	memset(f,0x3f,sizeof f),f[0][mx]=0;
	F(i,0,n-1) F(s,1,mx) if(s&1){
		int p=i+k-__builtin_popcount(s);
		const int val=f[i][s];
		if(val>=inf) continue;
		F(t,1,min(k,n-p)){
			if(!(s&(1<<(k-t)))) break;
			int cnt=0;
			if(p>k) cnt+=vis[rev[p+t]+1][p-k];
			F(q,0,min(p-1,k-1)) if((s&(1<<q))&&rev[p-q]>rev[p+t]) ++cnt;
			chkmin(f[i+1][((s<<t)|1)&mx],val+cnt);
		}
		F(t,0,min(k-1,p-1)) if(!(s&(1<<t))){
			int cnt=0;
			if(p>k) cnt+=vis[rev[p-t]+1][p-k];
			F(q,0,t-1) if((s&(1<<q))&&rev[p-q]>rev[p-t]) ++cnt;
			F(q,t+1,min(k-1,p-1)) if((s&(1<<q))&&rev[p-q]>rev[p-t]) ++cnt;
			chkmin(f[i+1][s^(1<<t)],val+cnt);
		}
	}
	printf("%d",f[n][mx]);
}