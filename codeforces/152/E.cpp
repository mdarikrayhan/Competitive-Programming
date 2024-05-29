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
int a[1005];
vector<int> mp[N];
int na[205][1<<7];
PII f1[205][1<<7],f2[205][1<<7];
int get(int i,int j){
	return (i-1)*m+j;
}
PII huan(int i){
	return mk((i+m-1)/m,(i%m==0?m:i%m));
}
int xy[4][2]={0,1,1,0,0,-1,-1,0};
ll f[205][1<<7];
int vis[1005];
char ans[105][105];
void dfs(int u,int msk){
	if(!u)return ;
	PII wei=huan(u);
	ans[wei.x][wei.y]='X';
	dfs(f1[u][msk].x,f1[u][msk].y);
	dfs(f2[u][msk].x,f2[u][msk].y);
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int w;
			cin>>w;
			a[get(i,j)]=w;
			for(int w=0;w<4;++w){
				int xx=i+xy[w][0],yy=j+xy[w][1];
				if(xx<1||yy<1||xx>n||yy>m)continue;
				mp[get(i,j)].push_back(get(xx,yy));
			}
		}
	}	
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=k;++i){
		int x,y;
		cin>>x>>y;
		f[get(x,y)][1<<(i-1)]=a[get(x,y)];
	}
	ll zhi=0x3f3f3f3f3f3f3f3f;
	for(int msk=0;msk<(1<<k);++msk){
		priority_queue<PLI> l;
		for(int u=1;u<=n*m;++u){
			for(int s=msk&(msk-1);s;s=(s-1)&msk){
				if(f[u][msk]>f[u][s]+f[u][msk-s]-a[u]){
					na[u][msk]=1;
					f1[u][msk]=mk(u,s);
					f2[u][msk]=mk(u,msk-s);
				}
				f[u][msk]=min(f[u][msk],f[u][s]+f[u][msk-s]-a[u]);
			}
			if(f[u][msk]!=zhi)l.push(mk(-f[u][msk],u));
		}
		memset(vis,0,sizeof(vis));
		while(!l.empty()){
			int u=l.top().y;
			l.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(int v:mp[u]){
				if(f[v][msk]>f[u][msk]+a[v]){
					f[v][msk]=f[u][msk]+a[v];
					na[v][msk]=0;
					f1[v][msk]=mk(u,msk);f2[v][msk]=mk(0,0);
					l.push(mk(-f[v][msk],v));
				}
			}
		}
	}
	ll anss=1e18;
	int wei=-1;
	for(int i=1;i<=n*m;++i){
		if(anss>f[i][(1<<k)-1]){
			anss=f[i][(1<<k)-1];
			wei=i;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			ans[i][j]='.';
		}
	}
	dfs(wei,(1<<k)-1);
	cout<<anss<<'\n';
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cout<<ans[i][j];
		}
		cout<<'\n';
	}
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

 		  		 				   		 		 	 	