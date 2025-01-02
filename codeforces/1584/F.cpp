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
string s[11];
int get(char c){
	if(c>='a'&&c<='z')return c-'a';
	return c-'A'+26;
}
char fan(int c){
	if(c<26)return c+'a';
	return c-26+'A';
}
int wei[11][60][3];
vector<PII> mp[60][1<<10];
int ru[60][1<<10];
int f[60][1<<10];
PII lst[60][1<<10];
void dfs(PII u){
	if(u.x==-1)return ;
	dfs(lst[u.x][u.y]);
	cout<<(char)(fan(u.x));
}
void solve(){
	cin>>n;
	memset(wei,-1,sizeof(wei));
	memset(ru,0,sizeof(ru));
	memset(f,0,sizeof(f));
	for(int i=0;i<n;++i){
		cin>>s[i];
		for(int j=0;j<s[i].size();++j){
			int c=get(s[i][j]);
			if(wei[i][c][0]!=-1)wei[i][c][1]=j;
			else wei[i][c][0]=j;
		}
	}
	for(int i=0;i<52;++i){
		for(int j=0;j<(1<<n);++j){
			mp[i][j].clear();
			bool flgg=1;
			for(int w=0;w<n;++w){
				if(wei[w][i][(j>>w)&1]==-1)flgg=0;
			}
			if(!flgg)continue;
			for(int xia=0;xia<52;++xia){
				int msk=0;bool flg=1;
				for(int w=0;w<n;++w){
					if(wei[w][xia][0]>wei[w][i][(j>>w)&1]);
					else{
						if(wei[w][xia][1]>wei[w][i][(j>>w)&1])msk|=(1<<w);
						else flg=0;
					}
				}
				if(!flg)continue;
				mp[i][j].push_back(mk(xia,msk));
				++ru[xia][msk];
			}
		}
	}
	queue<PII> l;
	for(int i=0;i<52;++i){
		for(int j=0;j<(1<<n);++j){
			bool flgg=1;
			for(int w=0;w<n;++w){
				if(wei[w][i][(j>>w)&1]==-1)flgg=0;
			}
			if(!flgg)continue;
			if(!ru[i][j])l.push(mk(i,j)),f[i][j]=1,lst[i][j]=mk(-1,-1);
		}
	}
	int maxn=0;
	PII wei(-1,-1);
	while(!l.empty()){
		PII u=l.front();
		l.pop();
		if(maxn<f[u.x][u.y]){
			maxn=f[u.x][u.y];
			wei=u;
		}
		for(PII v:mp[u.x][u.y]){
			--ru[v.x][v.y];
			if(f[v.x][v.y]<f[u.x][u.y]+1){
				f[v.x][v.y]=f[u.x][u.y]+1;
				lst[v.x][v.y]=mk(u.x,u.y);
			}
			if(!ru[v.x][v.y])l.push(v);
		}
	}
	cout<<maxn<<'\n';
	dfs(wei);
	cout<<'\n';
}

signed main(){
//	freopen(".in","r",stdin);	
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>tt;
	while(tt--){
		solve();
		
	}
	return 0;
}
/*
-dep[u]+qian[u]  

-2*qian[u]+ziji +(2*dep[u]-1)


*/

 					 	  	  		 					     	