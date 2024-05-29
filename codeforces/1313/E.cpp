// LUOGU_RID: 160230866
//File uses UTF-8 encoding.
//By: Luogu@tzl_Dedicatus545(UID:308854) Yuanshen@tzl_Dedicatus(UID:273152640)
//Ayaka bless me!
#include <bits/stdc++.h>
#define int long long
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
const int maxn=1.02e6;
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
//18:17

int has0[maxn],has1[maxn],hat[maxn],pw[maxn];
bool sm(int*ha0,int *ha1,int l1,int r1,int l2,int r2){
	return (ha0[r1]-ha0[l1-1]*pw[r1-l1+1]%mod+mod)%mod==(ha1[r2]-ha1[l2-1]*pw[r2-l2+1]%mod+mod)%mod;
}
int a[maxn],b[maxn];
struct BIT{
	int num[maxn],n;
	inline int lowbit(const int &x){	return x&-x;}
	void padd(int Pos,const int &Val){Pos++;while(Pos<=n)		{	num[Pos]+=Val;Pos+=lowbit(Pos);}}
	int qsum(int x){	x++;int ans=0;while(x>0){	ans+=num[x];		x-=lowbit(x);}	return ans;}
}b1,b2;
bool Med;
signed main()
{ios::sync_with_stdio(0);cin.tie(0);cerr<<fixed<<setprecision(3)<<(&Mbe-&Med)/1048576.0<<"MiB"<<endl;
	int n,m;cin>>n>>m;b1.n=b2.n=max(n,m)+10;
	string s0,s1,t;cin>>s0>>s1>>t;s0="%"+s0,s1="%"+s1,t="%"+t;
	pw[0]=1;rep(i,1,max(n,m),1)	pw[i]=pw[i-1]*131%mod;
	rep(i,1,n,1)	has0[i]=has0[i-1]*131%mod+s0[i]-'a';
	rep(i,1,n,1)	has1[i]=has1[i-1]*131%mod+s1[i]-'a';
	rep(i,1,m,1)	hat[i]=hat[i-1]*131%mod+t[i]-'a';
	rep(i,1,n,1){
		int l=1,r=min(m,n-i+1),ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(sm(has0,hat,i,i+mid-1,1,mid))	ans=mid,l=mid+1;
			else								r=mid-1;
		}a[i]=min(i+ans-1,m+i-2);
	}
	rep(i,1,n,1){
		int l=1,r=min(m,i),ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(sm(has1,hat,i-mid+1,i,m-mid+1,m))	ans=mid,l=mid+1;
			else									r=mid-1;
		}
		ans=i-ans+1;
		b[i]=max(0ll,ans-i-2+m);
	}int tr=min(m,n+1);
	rep(i,1,tr-1,1){
		b1.padd(b[i],b[i]);b2.padd(b[i],1);
	}int ans=0;
	rep(l,1,n,1){
		ans+=b2.qsum(a[l]-l)*(a[l]-l+1)-b1.qsum(a[l]-l);
		b1.padd(b[l],-b[l]);b2.padd(b[l],-1);
		if(tr<=n){
			b1.padd(b[tr],b[tr]);b2.padd(b[tr],1);
			tr++;
		}
	}cout<<ans<<endl;
	return 0;
}
