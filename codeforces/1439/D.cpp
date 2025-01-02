// Problem: INOI Final Contests
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1439D
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// Author: nullptr_qwq
// 
// Powered by CP Editor (https://cpeditor.org)

// 私は猫です

/*
 *                                                     __----~~~~~~~~~~~------___
 *                                    .  .   ~~//====......          __--~ ~~
 *                    -.            \_|//     |||\\  ~~~~~~::::... /~
 *                 ___-==_       _-~o~  \/    |||  \\            _/~~-
 *         __---~~~.==~||\=_    -_--~/_-~|-   |\\   \\        _/~
 *     _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \      /
 *   .~       .~       |   \\ -_    /  /-   /   ||      \   /
 *  /  ____  /         |     \\ ~-_/  /|- _/   .||       \ /
 *  |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
 *           '         ~-|      /|    |-~\~~       __--~~
 *                       |-~~-_/ |    |   ~\_   _-~            /\
 *                            /  \     \__   \/~                \__
 *                        _--~ _/ | .-~~____--~-/                  ~~==.
 *                       ((->/~   '.|||' -_|    ~~-/ ,              . _||
 *                                  -_     ~\      ~~---l__i__i__i--~~_/
 *                                  _-~-__   ~)  \--______________--~~
 *                                //.-~~~-~_--~- |-------~~~~~~~~
 *                                       //.-~~~--\
 *                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               神兽保佑            永无BUG
 */

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
const int maxn=500005;
int n,m,mod;
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
// void chkmax(ll &x,ll y){ x=max(x,y); }
// void chkmin(ll &x,ll y){ x=min(x,y); }
int mypow(int x,int y,int Mod){
	x%=Mod; int rt=1;
	for(;y;y>>=1,x=(1ll*x*x)%Mod) if(y&1) rt=(1ll*rt*x)%Mod;
	return rt;
}
mt19937 rng(time(0));
int rd(int l,int r){ return rng()%(r-l+1)+l; }
// mt19937 eng(std::chrono::steady_clock::now().time_since_epoch().count());
// int rd(int l,int r) { return std::uniform_int_distribution<int>(l,r)(eng); }
namespace combi{
	int fac[maxn],inv[maxn];
	void init(int N){
		fac[0]=inv[0]=1;
		F(i,1,N) fac[i]=1ll*fac[i-1]*i%mod;
		inv[N]=qpow(fac[N],mod-2);
		dF(i,N-1,1) inv[i]=1ll*inv[i+1]*(i+1)%mod;
	}
	int C(int n,int m){
		if(m>n||n<0||m<0) return 0;
		return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
	}
}
using namespace combi;
int dp[505],val[505],f[505][505],g[505][505];
signed main(){
	n=read(),m=read(),mod=read(),init(505),dp[0]=1;
	F(i,1,n){
		F(j,1,i) inc(dp[i],1ll*dp[j-1]*dp[i-j]%mod*C(i-1,j-1)%mod);
		mul(dp[i],i+1);
		F(j,1,i){
			inc(val[i],1ll*val[j-1]*dp[i-j]%mod*(i+1)%mod*C(i-1,j-1)%mod);
			inc(val[i],1ll*dp[j-1]*val[i-j]%mod*(i+1)%mod*C(i-1,j-1)%mod);
			inc(val[i],1ll*dp[j-1]*dp[i-j]%mod*add(C(j,2),C(i-j+1,2))%mod*C(i-1,j-1)%mod);
		}
	}
	f[0][0]=1;
	F(i,1,n){
		f[i][0]=1,f[i][i]=dp[i],g[i][i]=val[i];
		F(j,1,i-1) F(k,0,j){
			inc(f[i][j],1ll*dp[k]*f[i-k-1][j-k]%mod*C(j,k)%mod);
			inc(g[i][j],1ll*dp[k]*g[i-k-1][j-k]%mod*C(j,k)%mod);
			inc(g[i][j],1ll*val[k]*f[i-k-1][j-k]%mod*C(j,k)%mod);
		}
	}
	printf("%d ",g[n][m]);
}