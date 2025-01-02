#include <bits/stdc++.h>
#define N 1000005
#define M 20000005
#define ll long long
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
#define mod 998244353
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
int tt;
int n,m,k,q,d,t,r,h,x;
int a[N];
string s;
int f[100005][25][2],g[100005][25][2];
int w[100005][25][2];
vector<int> mp[N];
void dfs1(int u,int fa){
	f[u][0][0]=a[u];
	for(int v:mp[u]){
		if(v==fa)continue;
		dfs1(v,u);
		for(int j=1;j<k;++j){
			f[u][j][0]^=f[v][j-1][0];
			f[u][j][1]^=f[v][j-1][1];
		}
		f[u][0][0]^=f[v][k-1][1];
		f[u][0][1]^=f[v][k-1][0];
	}
}
int tmp[25][2],yuan[25][2];
void dfs2(int u,int fa){
	memset(tmp,0,sizeof(tmp));
	if(k>=2){
		tmp[1][0]=a[u];
	}
	else
		tmp[0][1]=a[u];
	for(int i=1;i<k;++i){
		tmp[i][0]^=g[u][i-1][0];
		tmp[i][1]^=g[u][i-1][1];
	}
	tmp[0][0]^=g[u][k-1][1],tmp[0][1]^=g[u][k-1][0];
	for(int v:mp[u]){
		if(v==fa)continue;
		for(int j=1;j<k;++j){
			w[v][j][0]=f[v][j-1][0],w[v][j][1]=f[v][j-1][1];
		}
		w[v][0][0]=f[v][k-1][1],w[v][0][1]=f[v][k-1][0];
		for(int j=0;j<k;++j)yuan[j][0]=w[v][j][0],yuan[j][1]=w[v][j][1];
		for(int j=1;j<k;++j){
			w[v][j][0]=yuan[j-1][0],w[v][j][1]=yuan[j-1][1];
		}
		w[v][0][0]=yuan[k-1][1],w[v][0][1]=yuan[k-1][0];
		for(int j=0;j<k;++j){
			tmp[j][0]^=w[v][j][0],tmp[j][1]^=w[v][j][1];
		}
	}
	for(int v:mp[u]){
		if(v==fa)continue;
		for(int j=0;j<k;++j){
			g[v][j][0]=tmp[j][0]^w[v][j][0];
			g[v][j][1]=tmp[j][1]^w[v][j][1];
//			co
		}
	}
	for(int v:mp[u]){
		if(v==fa)continue;
		dfs2(v,u);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
	}	
	for(int i=1;i<=n;++i)cin>>a[i];
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i){
		int ans=0;
		for(int j=0;j<k;++j){
			ans^=f[i][j][1];ans^=g[i][j][1];
//			cout<<i<<' '<<j<<" "<<f[i][j][1]<<" "<<g[i][j][1]<<'\n';
		}
		if(ans)cout<<"1 ";
		else cout<<"0 ";
	}
	cout<<'\n';
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
x1+x2<=10^
i*x-qian>=0

*/

      	   	 	   		 	   	  	