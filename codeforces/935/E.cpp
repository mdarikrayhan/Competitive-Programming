#include <bits/stdc++.h>
#define N 1000005
#define ll long long
#define mk make_pair
#define x first
#define y second
#define bas 20200721
#define lowbit(x) (x&(-x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PIL pair<int,ll>
#define PLI pair<ll,int>
//#define eps 
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
string s,ss;
int len,n,m;
int zuo[N],you[N]; 
int qian[N];
int tot;
PII f[20005][105];
int get(int l,int r){
	return qian[r]-qian[l-1];
}
int solve1(int l,int r){//x最大y最小 
	int u=++tot;
	for(int j=0;j<=n;++j)f[u][j]=mk(-1e9,1e9);
	if(l==r){
		f[u][0]=mk(s[l]-'0',s[l]-'0');
		return u;
	}
	int www=solve1(l+1,you[l]-1);
	for(int j=0;j<=n;++j){
		f[u][j]=f[www][j];
	}
	for(int i=you[l]+2;i<=r;++i){
		int p=you[i];
		int tmp[2][105];
		memset(tmp[0],-0x3f,sizeof(tmp[0]));
		memset(tmp[1],0x3f,sizeof(tmp[1]));
		int son=solve1(i+1,p-1);
		for(int j=0;j<=n;++j){
			for(int k=0;k+j<=n;++k){
				//减号 
				tmp[0][j+k]=max(tmp[0][j+k],f[u][j].x-f[son][k].y);
				tmp[1][j+k]=min(tmp[1][j+k],f[u][j].y-f[son][k].x);
				//加号
				tmp[0][j+k+1]=max(tmp[0][j+k+1],f[u][j].x+f[son][k].x);
				tmp[1][j+k+1]=min(tmp[1][j+k+1],f[u][j].y+f[son][k].y); 
			}
		}
		for(int j=0;j<=n;++j)f[u][j]=mk(tmp[0][j],tmp[1][j]);
		i=p+1;
	}
	return u;
}
int solve2(int l,int r){//x最大y最小 
	int u=++tot;
//	cout<<l<<' '<<r<<"d\n";
	for(int j=0;j<=m;++j)f[u][j]=mk(-1e9,1e9);
	if(l==r){
		f[u][0]=mk(s[l]-'0',s[l]-'0');
		return u;
	}
	int www=solve2(l+1,you[l]-1);
	for(int j=0;j<=m;++j){
		f[u][j]=f[www][j];
	}
	for(int i=you[l]+2;i<=r;++i){
		int p=you[i];
		int tmp[2][105];
		memset(tmp[0],-0x3f,sizeof(tmp[0]));
		memset(tmp[1],0x3f,sizeof(tmp[1]));
		int son=solve2(i+1,p-1);
		for(int j=0;j<=m;++j){
			for(int k=0;k+j<=m;++k){
				//减号 
				tmp[0][j+k+1]=max(tmp[0][j+k+1],f[u][j].x-f[son][k].y);
				tmp[1][j+k+1]=min(tmp[1][j+k+1],f[u][j].y-f[son][k].x);
				//加号
				tmp[0][j+k]=max(tmp[0][j+k],f[u][j].x+f[son][k].x);
				tmp[1][j+k]=min(tmp[1][j+k],f[u][j].y+f[son][k].y); 
			}
		}
		for(int j=0;j<=m;++j)f[u][j]=mk(tmp[0][j],tmp[1][j]);
		i=p+1;
	}
	return u;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;len=s.size();
	s=" "+s;
	for(int i=1;i<=len;++i){
		if(s[i]>='0'&&s[i]<='9'){
			ss+="(";ss+=s[i];ss+=")";
		}
		else
			ss+=s[i];
	}
	swap(s,ss);
	len=s.size();
	s=" "+s;
//	cout<<s<<' '<<len<<"\n";
	stack<int> l;
	for(int i=1;i<=len;++i){
		if(s[i]=='(')l.push(i);
		if(s[i]==')'){
			int u=l.top();
			you[u]=i;
			zuo[i]=u;
			l.pop();
		}
	}
//	for(int i=1;i<=len;++i){
//		cout<<you[i]<<' ';
//	}
	cin>>n>>m;
	for(int i=1;i<=len;++i){
		qian[i]=qian[i-1];
		if(s[i]=='?')++qian[i];
	}
	if(n<=m){
		cout<<f[solve1(1,len)][n].x;
		return 0;
	}
//	cout<<"d";
	cout<<f[solve2(1,len)][m].x;
	return 0;
}
/*
liitleskin


*/
	 			    	           	   	 	 	