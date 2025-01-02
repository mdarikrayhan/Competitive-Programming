// LUOGU_RID: 159176495
//File uses UTF-8 encoding.
//By: Luogu@tzl_Dedicatus545(UID:308854) Yuanshen@tzl_Dedicatus(UID:273152640)
//Ayaka bless me!
#include <bits/stdc++.h>
#define ll long long
#define rep(i,x,y,z) for(int i=(x);i<=(y);i+=(z))
#define per(i,x,y,z) for(int i=(x);i>=(y);i-=(z))
#define pb push_back
#define pii pair<int,int>
#define i128 __int128
#define _1 first
#define _2 second
#define ld long double
#define cint const int
#define pcnt __builtin_popcountll
#define vint vector<int>
#define vpii vector<pair<int,int> >
using namespace std;

const int inf=(sizeof(int)==4?0x3f3f3f3f:0x3f3f3f3f3f3f3f3f);
const int mod=998244353;
const long double EPS=1e-7;
const int maxn=32769;
int gcd(int a,int b){
	unsigned az=__builtin_ctz(a),bz=__builtin_ctz(b);unsigned z=min(az,bz);b>>=bz;
	while(a){	a>>=az;int d=a-b;az=__builtin_ctz(d),b=min(a,b),a=(d<0?-d:d);}
	return b<<z;
}
int read()
{
	int ch = getchar(), t = 1, n = 0;
	while (ch < '0' || ch > '9') { if (ch == '-') t = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { n = n * 10 + ch - '0', ch = getchar(); }
	return n * t;
}void chkmin(int &x,int y){	x=min(x,y);}void chkmax(int &x,int y){	x=max(x,y);}
bool Mbe;
pii operator+(const pii &x,const pii &y){return {x._1+y._1,x._2+y._2};}
pii operator%(const pii &x,const int &y){return {x._1%y,x._2%y};};
pii operator*(const pii &x,const int &y){return {x._1*y,x._2*y};};
int fac[maxn],finv[maxn];
ll fpow(ll x,int y){
	ll rt=1;
	for(;y;y>>=1,x=x*x%mod) if(y&1) rt=rt*x%mod;
	return rt;
}int inv(int x){	return fpow(x,mod-2);}
void init(int n){
	fac[0]=fac[1]=1;finv[0]=finv[1]=1;
	rep(i,2,n,1){
		fac[i]=fac[i-1]*i%mod;
	}finv[n]=inv(fac[n]);
	per(i,n-1,1,1){
		finv[i]=finv[i+1]*(i+1)%mod;
	}
}int C(int n,int m){
	if(n<m || n<0 || m<0)	return 0;
	return fac[n]*finv[m]%mod*finv[n-m]%mod;
}
int su[maxn];
int a[16];
int f[20][20][maxn];
int fr[20][20][maxn];
int g[20][20][maxn];
int frg[20][20][maxn];
int cc2[20];
vint vec[20][maxn];

inline int lowbit(int x){return x&(-x);}
inline int lb(unsigned x){return __builtin_ctz(x);}

bool Med;
signed main()
{ios::sync_with_stdio(0);cin.tie(0);cerr<<fixed<<setprecision(3)<<(&Mbe-&Med)/1048576.0<<"MiB"<<endl;
	int T;cin>>T;
	while(T--){
		int n;cin>>n;bool flg=0;
		auto beg=clock();
		rep(i,0,n-1,1)	cin>>a[i];
		rep(i,0,n-2,1)	if(a[i]>=a[i+1])	flg=1;
		if(!flg){
			cout<<0<<endl;continue ;
		}
		int m=(1<<n)-1;
		// rep(i,0,n,1)	rep(j,0,m,1)	vec[i][j].clear();
		// rep(j,0,m,1)	for(int k=j;k;k=(k-1)&j){
			// vec[pcnt(j^k)][j].pb(k);
		// }
		rep(i,1,m,1)	su[i]=su[i^lowbit(i)]+a[__builtin_ctz(i)];
		rep(i,0,n,1)	rep(j,0,m,1)	g[0][i][j]=f[0][i][j]=g[i][0][j]=f[i][0][j]=inf;
		f[0][0][0]=0;
		rep(k,0,n,1)	g[0][k][0]=0,cc2[k]=0;
		rep(i,1,n,1){
			rep(j,0,m,1){
				if(pcnt(j)<i)	continue ;
				rep(l,1,n,1)	f[i][l][j]=inf;
				for(int k=j;k;k=(k-1)&j){
					if(pcnt(j^k)<i-1 || g[i-1][n-1][j^k]>=su[k])	continue ;
					rep(l,1,n,1){
						if(f[i][l][j]<=su[k])	continue ;
						if(k&(1<<(l-1))){
							if(f[i][l][j]>(g[i-1][l-1][j^k]<su[k]?su[k]:inf)){
								f[i][l][j]=(g[i-1][l-1][j^k]<su[k]?su[k]:inf);
								fr[i][l][j]=k;
							}
							if((j^k)<(1<<(l-1)))	break ;
						}
					}
				}
			}
			rep(j,0,m,1){
				g[i][0][j]=inf;
				rep(l,1,n,1){
					g[i][l][j]=min(g[i][l-1][j],f[i][l][j]);
					frg[i][l][j]=(g[i][l-1][j]<f[i][l][j]?frg[i][l-1][j]:l);
				}
			}
		}int ans=-1;
		per(i,n,1,1)	if(g[i][n][m]!=inf){	ans=n-i;break ;}
		cout<<ans<<"\n";
		vpii ops;
		int u=m,cc=n-ans,tl=n;
		while(cc){
			int l=frg[cc][tl][u];
			int se=fr[cc][l][u];
			rep(i,1,n,1)	if((se&(1<<(i-1))) && i!=l)	ops.pb({i,l});
			u^=se;cc--;tl=l;
		}
		for(auto [l,r]:ops){
			cout<<l-cc2[l]<<" "<<r-cc2[r]<<"\n";
			rep(i,l+1,n,1)	cc2[i]++;

		}
		#ifdef TZL_MEOW
		cerr<<(clock()-beg)*1.0/CLOCKS_PER_SEC<<endl;
		#endif
	}
	return 0;
}
