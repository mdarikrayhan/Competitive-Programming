#include <bits/stdc++.h>
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mkp make_pair
#define eb emplace_back
#define mem(a,b) memset(a,b,sizeof(a))
#define mpy(a,b) memcpy(a,b,sizeof(b))
#define dbg(...) cerr<<"#"<<__LINE__<<": "<<__VA_ARGS__<<endl
#define Fi(s) freopen(s,"r",stdin)
#define Fo(s) freopen(s,"w",stdout)
#define Fio(s) Fi(s".in"),Fo(s".out")
#define SZ(S) (int)S.size()
#define mod 998244353
//#define mod 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
using namespace std;

template<int P>
class mod_int{
	using Z=mod_int;
private:
	static int mo(int x){return x<0?x+P:x;}
public:
	int x;
	int val()const{return x;}
	mod_int():x(0){}
	template<class T>mod_int(const T&x_):x(x_>=0&&x_<P?static_cast<int>(x_):mo(static_cast<int>(x_%P))){}
	bool operator==(const Z&rhs)const{return x==rhs.x;}
	bool operator!=(const Z&rhs)const{return x!=rhs.x;}
	Z operator-()const{return Z(x?P-x:0);}
	Z pow(long long k)const{Z res=1,t=*this;while(k){if(k&1)res*=t;if(k>>=1)t*=t;}return res;}
	Z&operator++(){x<P-1?++x:x=0;return *this;}
	Z&operator--(){x?--x:x=P-1;return *this;}
	Z operator++(int){Z ret=x;x<P-1?++x:x=0;return ret;}
	Z operator--(int){Z ret=x;x?--x:x=P-1;return ret;}
	Z inv()const{return pow(P-2);}
	Z&operator+=(const Z&rhs){(x+=rhs.x)>=P&&(x-=P);return *this;}
	Z&operator-=(const Z&rhs){(x-=rhs.x)<0&&(x+=P);return *this;}
	Z&operator*=(const Z&rhs){x=1ULL*x*rhs.x%P;return *this;}
	Z&operator/=(const Z&rhs){return *this*=rhs.inv();}
#define setO(T,o) friend T operator o(const Z&lhs,const Z&rhs){Z res=lhs;return res o##=rhs;}
	setO(Z,+)setO(Z,-)setO(Z,*)setO(Z,/)
#undef setO
};
using Z = mod_int<mod>;

ll qpow(ll x, ll k){
	ll ret = 1;
	while(k){
		if(k & 1) (ret *= x) %= mod;
		(x *= x) %= mod, k >>= 1;
	}
	return ret;
}

namespace Poly_space{
	Z inv2 = (mod + 1) / 2;
	vector<int> rev;
	vector<Z> gg = {0, 1};
	Z rt = 3;
	void setroot(Z x){rt = x;}
	void dft(vector<Z> &a){
		int n = a.size();
		if((int)rev.size() != n){
			int k = __builtin_ctz(n) - 1; rev.resize(n);
			for(int i = 0; i < n; i++){rev[i] = rev[i >> 1] >> 1 | (i & 1 ? (1 << k) : 0);}
		}
		for(int i = 0; i < n; i++) if(i < rev[i]) swap(a[i], a[rev[i]]);
		if((int)gg.size() < n){
			int k = __builtin_ctz(gg.size()); gg.resize(n);
			while((1 << k) < n){
				Z e = rt.pow((mod - 1) >> (k + 1));
				for(int i = (1 << (k - 1)); i < (1 << k); i++) gg[i << 1] = gg[i], gg[(i << 1) | 1] = gg[i] * e;
				k++;
			}
		}
		for(int mid = 1; mid < n; mid <<= 1) for(int i = 0; i < n; i += (mid << 1)) for(int j = 0; j < mid; j++){
			Z x = a[i + j], y = a[i + j + mid] * gg[mid + j];
			a[i + j] = x + y, a[i + j + mid] = x - y;
		}
	}
	void idft(vector<Z> &a){
		int n = a.size(); reverse(a.begin() + 1, a.end()), dft(a);
		Z inv = Z(1 - mod) / Z(n); for(int i = 0; i < n; i++) a[i] *= inv;
	}
	struct Poly{
		vector<Z> a;
		Poly(){} Poly(const vector<Z> &x): a(x){} Poly(const initializer_list<Z> &x): a(x){}
		int size()const{return a.size();} void resize(int x){a.resize(x);}
		Z operator [](int ind)const{if(ind < 0 || ind >= size()) return 0; return a[ind];}
		Z&operator [](int ind){return a[ind];}
		Poly modxk(int k)const{k = min(k, size()); return Poly(vector<Z>(a.begin(), a.begin() + k));}
		Poly mulxk(int k)const{vector<Z> b = a; b.insert(b.begin(), k, 0); return b;}
		Poly divxk(int k)const{if(size() <= k) return Poly(); return Poly(vector<Z>(a.begin() + k, a.end()));}
		friend Poly operator + (const Poly &a, const Poly &b){
			vector<Z> ret(max(a.size(), b.size()));
			for(int i = 0; i < ret.size(); i++) ret[i] = a[i] + b[i];
			return Poly(ret);
		}
		friend Poly operator - (const Poly &a, const Poly &b){
			vector<Z> ret(max(a.size(), b.size()));
			for(int i = 0; i < ret.size(); i++) ret[i] = a[i] - b[i];
			return Poly(ret);
		}
		friend Poly operator * (const Poly &a, const Z &b){
			vector<Z> ret(a.size());
			for(int i = 0; i < ret.size(); i++) ret[i] = a[i] * b;
			return Poly(ret);
		}
		friend Poly operator * (Poly a, Poly b){
			if(a.size() == 0 || b.size() == 0) return Poly();
			int sz = 1, n = a.size() + b.size() - 1;
			while(sz < n) sz <<= 1;
			a.resize(sz), b.resize(sz), dft(a.a), dft(b.a);
			for(int i = 0; i < sz; i++) a.a[i] = a[i] * b[i];
			idft(a.a), a.resize(n); return a;
		}
		Poly inv(int deg)const{
			if(deg == 1) return Poly({a[0].pow(mod - 2)});
			Poly res = inv((deg + 1) >> 1), tmp = *this;
			int sz = 1; while(sz < (deg << 1)) sz <<= 1;
			tmp = tmp.modxk(deg), tmp.resize(sz), res.resize(sz);
			dft(tmp.a), dft(res.a);
			for(int i = 0; i < sz; i++) res[i] = 2 * res[i] - res[i] * res[i] * tmp[i];
			idft(res.a), res.resize(deg);
			return res;
		}
		Poly derivative()const{
			if(size() == 1) return Poly();
			Poly ret(vector<Z>(size() - 1));
			for(int i = 1; i < size(); i++) ret.a[i - 1] = a[i] * i;
			return ret;
		}
		Poly integrate()const{
			Poly ret(vector<Z>(size() + 1));
			for(int i = 1; i < ret.size(); i++) ret.a[i] = a[i - 1] * Z(i).inv();
			return ret;
		}
		Poly ln(int deg){
			Poly res = derivative(), tmp = inv(deg);
			res = (res * tmp).integrate(), res.resize(deg);
			return res;
		}
		Poly exp(int deg){
			Poly ret(vector<Z>(1)); ret[0] = 1; int i = 1;
			while(i < deg) i <<= 1, ret = (ret * (Poly({1}) - ret.ln(i) + modxk(i))).modxk(i);
			return ret.modxk(deg);
		}
	};
}
using namespace Poly_space;

Z power(Z p,ll k){
	Z ans = 1;
	while(k){
		if(k % 2 == 1) ans *= p;
		p *= p;
		k /= 2;
	}
	return ans;
}
Z fact[1000005],ifac[1000005];

void init(int L){
    fact[0] = 1;
    rep(i,1,L) fact[i] = fact[i - 1] * i;
    ifac[L] = 1 / fact[L];
    per(i,L - 1,0) ifac[i] = ifac[i + 1] * (i + 1);
}
int n,m,p;
int a[100005];

Z sum[2][100005],psum[2][100005];
Z b[100005];

Poly P[400005],Q[400005],F,G;
#define ls (rt * 2)
#define rs (rt * 2 + 1)
void solve(int rt,int l,int r){
	if(l == r){
		P[rt].a.eb(b[l]);
		Q[rt].a.eb(1);
		Q[rt].a.eb(-(a[l] + 1));
		return;
	}
	int mid = (l + r) >> 1;
	solve(ls,l,mid);solve(rs,mid+1,r);
	Q[rt] = Q[ls] * Q[rs];
	P[rt] = P[ls] * Q[rs] + Q[ls] * P[rs];
}	
int main(){
//	freopen("test.in","r",stdin);
	scanf("%d%d%d",&n,&m,&p);
	init(m);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n){
		sum[0][i] = (1 + sum[0][i - 1]) * (a[i] + 1);
		psum[0][i] = (1 + sum[0][i - 1]) * a[i] + psum[0][i - 1] * (a[i] + 1);
	}
	per(i,n,1){
		sum[1][i] = (1 + sum[1][i + 1]) * (a[i] + 1);
		psum[1][i] = (1 + sum[1][i + 1]) * a[i] + psum[1][i + 1] * (a[i] + 1);
	}
//	rep(i,1,n) printf("%d ",a[i] + 1);
//	printf("\n");
	F.a.resize(m + 1);
	Z qwq = 0;
	rep(i,1,n){
		b[i] = (1 + sum[0][i - 1]) * (1 + sum[1][i + 1]) + psum[0][i - 1] * (1 + sum[1][i + 1]) + (1 + sum[0][i - 1]) * psum[1][i + 1];
		qwq += b[i];
		b[i] *= power(p,a[i] + 1);
//		printf("%d ",b[i].val());
	}
//	printf("\n");
	solve(1,1,n);
	F = Q[1];
	F.a.resize(m + 1);
	F = F.inv(m + 1);
	F = F * P[1];
	F = F.modxk(m + 1);
	rep(i,0,m){
		F.a[i] *= ifac[i];
		F.a[i] = -F.a[i];
	}
	F.a[0] += qwq;
	rep(i,0,m) G.a.eb(-p * ifac[i]);
	G.a[0]++;
	G = G.inv(m + 1);
	F = F * G;
	printf("%d\n",(F.a[m] * fact[m]).val());
	return 0;
}