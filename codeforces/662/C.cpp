// LUOGU_RID: 160415791
#include <bits/stdc++.h>
#define N 1000005
#define M 20000005
#define ll long long
#define ull unsigned long long
#define mk make_pair
#define x first
#define y second
#define bas 20200721
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define lowbit(x) (x&(-x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PIL pair<int,ll>
#define PLI pair<ll,int>
#define eps (1e-7)
#define mod 1000000007
//#define int long long
using namespace std;
//int mod;
struct mint {
	int x;
	mint() : x(0) {}
	mint(long long y, bool flag = 0) {
		if (flag) x = (int)(y);
		else x = (int)((y % mod + mod) % mod);
	}
	friend const mint ksm(mint a, long long b);
	const mint inv() {return ksm(*this, mod - 2);}
};
bool operator == (const mint a, const mint b) {return a.x == b.x;}
bool operator != (const mint a, const mint b) {return a.x != b.x;}
bool operator <(const mint a,const mint b){return a.x<b.x;}
bool operator >(const mint a,const mint b){return a.x>b.x;}
int operator ! (const mint a) {return !a.x;}
const mint operator + (const mint a, const mint b) {
	mint res(a.x + b.x, 1);
	if (res.x >= mod) res.x -= mod;
	return res;
}
mint& operator += (mint &a, const mint b) {
	a.x += b.x;
	if (a.x >= mod) a.x -= mod;
	return a;
}
const mint operator - (const mint a, const mint b) {
	mint res(a.x - b.x, 1);
	if (res.x < 0) res.x += mod;
	return res;
}
mint& operator -= (mint &a, const mint b) {
	a.x -= b.x;
	if (a.x < 0) a.x += mod;
	return a;
}
const mint operator * (const mint a, const mint b) {
	return mint((long long)a.x * b.x % mod, 1);
}
mint& operator *= (mint &a, const mint b) {
	a.x = (int)((long long)a.x * b.x % mod);
	return a;
}
const mint poww(mint a, long long b) {
	mint res(1, 1);
	for (; b; a *= a, b >>= 1)
		if (b & 1) res *= a;
	return res;
}
const mint operator / (const mint a, const mint b) {
	return a * poww(b, mod - 2);
}
mint& operator /= (mint &a, const mint b) {
	a = a * poww(b, mod - 2);
	return a;
}
ostream& operator << (ostream &out, const mint a) {
	return out << a.x;
}
istream& operator >> (istream &in, mint &a) {
	long long y;
	in >> y, a = mint(y);
	return in;
}
void chkmx(int &x,int y){
	x=max(x,y);
}
void chkmn(int &x,int y){
	x=min(x,y);
}
int tt;
int n,m,k,q,d,t,r,h,x,y;
int a[N],b[N],c[N];
string s;
int f[21][1<<20],ww[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			char c;
			cin>>c;
			ww[j]|=(c=='1')*(1<<(i-1));
		}
	}
	for(int i=1;i<=m;++i)f[0][ww[i]]++;
	for(int j=0;j<n;++j){
		for(int i=n;i>=1;--i){
			for(int msk=0;msk<(1<<n);++msk){
				f[i][msk]+=f[i-1][msk^(1<<j)];
			}
		}
	}
//	for(int i=0;i<(1<<n);++i){
//		for(int j=0;j<=(n);++j){
//			cout<<i<<' '<<j<<" "<<f[j][i]<<'\n';
//		}
//	}
	int ans=1e9;
	for(int i=0;i<(1<<n);++i){
		int sum=0;
		for(int j=0;j<=n;++j)sum+=min(j,n-j)*f[j][i];
		ans=min(ans,sum);
//		cout<<i<<" "<<sum<<'\n';
	}
	cout<<ans<<'\n';
}

signed main(){
//	freopen(".in","r",stdin);	
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
//	cin>>tt;
//	while(tt--){
		solve();
		
//	}
	return 0;
}
/*
-dep[u]+qian[u]  

-2*qian[u]+ziji +(2*dep[u]-1)


*/
					   	     			 	    		  		