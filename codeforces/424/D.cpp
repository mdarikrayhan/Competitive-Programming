#include <bits/stdc++.h>
#define N 1000005
#define M 20000005
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
//#define mod 1000000007
//#define int long long
using namespace std;
int mod;
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
int n,m,t,tp,tu,td;
int a[305][305];
int qian[4][305][305];
int qvan(int w1,int w2){
	if(w1==w2)return tp;
	if(w1<w2)return tu;
	return td;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>t;
	cin>>tp>>tu>>td;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			qian[0][i][j]=qian[0][i][j-1]+qvan(a[i][j-1],a[i][j]);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=m;j>=1;--j){
			qian[1][i][j]=qian[1][i][j+1]+qvan(a[i][j+1],a[i][j]);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			qian[2][i][j]=qian[2][i-1][j]+qvan(a[i-1][j],a[i][j]);
		}
	}
	for(int i=n;i>=1;--i){
		for(int j=1;j<=m;++j)qian[3][i][j]=qian[3][i+1][j]+qvan(a[i+1][j],a[i][j]);
	}
	ll ans=1e18;
	int w1,w2,w3,w4;
	for(int sh=1;sh<=n;++sh){
		for(int xia=sh+2;xia<=n;++xia){
			set<PII> s;
			for(int i=m;i>=1;--i){
				if(i+2<=m){
					s.insert(mk(qian[0][sh][i+2]-qian[1][xia][i+2]+qian[2][xia][i+2]-qian[2][sh][i+2],i+2));
				}
				if(s.size()){
					auto it=s.lower_bound(mk(t-(qian[1][xia][i]+qian[3][sh][i]-qian[3][xia][i]-qian[0][sh][i]),0));
					ll zhi=qian[1][xia][i]+qian[3][sh][i]-qian[3][xia][i]-qian[0][sh][i];
					if(it!=s.end()){
						if(ans>abs(zhi+(it->x)-t)){
							ans=abs(zhi+(it->x)-t);
							w1=sh,w2=i,w3=xia,w4=(it->y);		
						}
					}	
					if(it!=s.begin()){
						--it;
						if(ans>abs(zhi+(it->x)-t)){
							ans=abs(zhi+(it->x)-t);
							w1=sh,w2=i,w3=xia,w4=(it->y);		
						}
					}
				}
			}	
		}
	}
//	cout<<ans<<"::\n";
	cout<<w1<<' '<<w2<<' '<<w3<<' '<<w4;
	return 0;
}
/*
i,j
qian[1][xia][i]+qian[3][sh][i]-qian3[xia][i]-qian[0][sh][i]+qian[0][sh][j]-qian[1][xia][j]+qian[2][xia][j]-qian[2][sh][j]
*/
 						 		 		  	  	   		  		