// LUOGU_RID: 160342754
//File uses UTF-8 encoding.
//By: Luogu@tzl_Dedicatus545(UID:308854) Yuanshen@tzl_Dedicatus(UID:273152640)
//Ayaka bless me!
#pragma GCC optimize(3)
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
const int maxn=1.02e5;
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
void inc(int &x,int y){	x=(x+y>mod?x+y-mod:x+y);}
void dec(int &x,int y){	x=(x-y<0?x-y+mod:x-y);}
int mul(vint vec){int ans=1;for(auto x:vec)	ans*=x,ans%=mod;return ans;}

int phi[maxn],p[maxn];ll su[maxn];int cc=0;
bool isp[maxn];

void init(int n){
	phi[1]=1;su[1]=1;
	rep(i,2,n,1){
		if(!isp[i]){	p[++cc]=i,phi[i]=i-1;}
		for(int j=1;j<=cc && p[j]*i<=n;j++){
			isp[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];break ;
			}phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
	rep(i,2,n,1)	su[i]=su[i-1]+phi[i];
}
ll w(int l,int n){
	int tl=l;ll ans=0;int tr;
	while(tl<=n){
		tr=n/(n/tl);
		ans+=su[n/tl]*(tr-tl+1);
		tl=tr+1;
	}return ans;
}
ll f[maxn][20];

void dodp(int l,int r,int zl,int zr,int id){
	if(l>r)	return ;
	int mid=(l+r)/2,bst=zl;
	rep(i,zl,min(mid-1,zr),1){
		if(w(i+1,mid)+f[i][id-1]<f[mid][id]){
			f[mid][id]=w(i+1,mid)+f[i][id-1];
			bst=i;
		}
	}
	dodp(l,mid-1,zl,bst,id);dodp(mid+1,r,bst,zr,id);
}

bool Med;
signed main()
{ios::sync_with_stdio(0);cin.tie(0);init(maxn-1);cerr<<fixed<<setprecision(3)<<(&Mbe-&Med)/1048576.0<<"MiB"<<endl;
	int T;cin>>T;
	int N=1e5;
	memset(f,0x3f,sizeof(f));
	rep(i,1,N,1)	f[i][1]=w(1,i);
	rep(i,2,19,1){
		dodp(1,N,1,N,i);
	}
	while(T--){
		int n,k;cin>>n>>k;
		if(k>=19)	{ cout<<n<<"\n";continue ;}
		cout<<f[n][k]<<"\n";
	}
	return 0;
}
