// LUOGU_RID: 160271985
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
#define il inline
#define pii pair<int,int>
#define x first
#define y second
#define gc getchar()
#define rd read()
#define debug() puts("------------")
namespace yzqwq{
	il int read(){
		int x=0,f=1;char ch=gc;
		while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=gc;}
		while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gc;
		return x*f;
	}
	il int qmi(int a,int b,int p){
		int ans=1;
		while(b){
			if(b&1) ans=ans*a%p;
			a=a*a%p,b>>=1;
		}
		return ans;
	}
	il auto max(auto a,auto b){return (a>b?a:b);}
	il auto min(auto a,auto b){return (a<b?a:b);}
	il int gcd(int a,int b){
		if(!b) return a;
		return gcd(b,a%b);
	}
	il int lcm(int a,int b){
		return a/gcd(a,b)*b;
	}
	il void exgcd(int a,int b,int &x,int &y){
		if(!b) return x=1,y=0,void(0);
		exgcd(b,a%b,x,y);
		int t=x;
		x=y,y=t-a/b*x;
		return ;
	}
	mt19937 rnd(time(0));
}
using namespace yzqwq;
const int N=1e5+10;
int n,k;
struct node{
	int l,r;
	il bool operator<(const node&b)const{
		if(r!=b.r) return r<b.r;
		return l>b.l;
	}
}a[N];
int f[105][N];
int qu[N],hh,tt;
il void solve(){
	n=rd,k=rd;int Min=1e18;
	for(re int i=1;i<=k;++i) a[i].l=rd,a[i].r=rd;
	sort(a+1,a+k+1);
	memset(f,0x3f,sizeof(f)),f[0][0]=0;
	for(re int i=1;i<=k;++i){
		hh=1,tt=0;
		for(re int j=0;j<=n;++j) f[i][j]=f[i-1][j];
		for(re int j=0;j<=min(n,a[i].r);++j){
			while(hh<=tt&&j-qu[hh]>a[i].r-a[i].l) ++hh;
			while(hh<=tt&&f[i-1][j]<=f[i-1][qu[tt]]) --tt;
			qu[++tt]=j;
			f[i][j]=min(f[i][j],f[i-1][qu[hh]]+2);
		}
		hh=1,tt=0;
		for(re int j=a[i].r;j>=0;--j){
			while(hh<=tt&&j+qu[hh]<a[i].l) ++hh;
			while(hh<=tt&&f[i-1][a[i].r-j]<=f[i-1][qu[tt]]) --tt;
			qu[++tt]=a[i].r-j;
			f[i][j]=min(f[i][j],f[i-1][qu[hh]]+1);
		}
		Min=min(Min,f[i][n]);
	}
	if(Min<1e18) printf("Full\n%lld\n",Min);
	else printf("Hungry");
	return ;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int t=1;while(t--)
	solve();
	return 0;
}//