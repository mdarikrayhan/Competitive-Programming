// Problem: G. Count Voting
// Contest: Codeforces - Codeforces Round 854 by cybercats (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1799/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Author: nullptr_qwq
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define ll long long
#define pb push_back
#define fi first
#define se second
#define inf 1e9
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
const int mod=998244353,maxn=5005;
int qpow(int x,int y){
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
int mypow(int x,int y,int Mod){
	x%=Mod; int rt=1;
	for(;y;y>>=1,x=(1ll*x*x)%Mod) if(y&1) rt=(1ll*rt*x)%Mod;
	return rt;
}
mt19937 rng(time(0));
int rd(int l,int r){ return rng()%(r-l+1)+l; }
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
int n,bel[232],a[232];
vector<int>vec[232];
int cnt[232],sum[232],f[232][232],dp[232][232],lstdp[4309],tmpdp[4309];
signed main(){
	init(4309);
	n=read();
	F(i,1,n) a[i]=read();
	F(i,1,n) vec[bel[i]=read()].push_back(a[i]);
	F(i,1,n) cnt[bel[i]]++;
	F(i,1,n) for(int j:vec[i]) sum[i]+=j;
	dp[0][0]=1;
	F(i,1,n){
		memset(lstdp,0,sizeof lstdp),memset(tmpdp,0,sizeof tmpdp);
		tmpdp[0]=lstdp[0]=1;
		for(int j:vec[i]){
			F(k,0,n) tmpdp[k]=0;
			F(p,0,n) F(q,0,min(j,n-p)) inc(tmpdp[p+q],1ll*lstdp[p]*inv[q]%mod*inv[j-q]%mod); 
			F(k,0,n) lstdp[k]=tmpdp[k];
		}
		F(k,0,n) mul(tmpdp[k],1ll*C(cnt[i],k)*fac[k]%mod);
		F(p,0,n) F(q,0,n-p) inc(dp[i][p+q],1ll*dp[i-1][q]*tmpdp[p]%mod);
	}
	int ans=0;
	F(i,0,n){
		int val=1ll*dp[n][i]*fac[n-i]%mod;
		if(i&1) dec(ans,val);
		else inc(ans,val);
	}
	cout<<ans;
}