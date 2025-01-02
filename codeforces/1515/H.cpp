#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef array<int, 3> ai3;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int Mod = 998244353;
inline int sign(int a){ return (a&1) ? (Mod-1) : 1; }
inline void uadd(int &a, int b){ a += b-Mod; a += (a>>31) & Mod; }
inline void usub(int &a, int b){ a -= b, a += (a>>31) & Mod; }
inline void umul(int &a, int b){ a = (int)(1ll * a * b % Mod); }
inline int add(int a, int b){ a += b-Mod; a += (a>>31) & Mod; return a; }
inline int sub(int a, int b){ a -= b, a += (a>>31) & Mod; return a; }
inline int mul(int a, int b){ a = (int)(1ll * a * b % Mod); return a; }
int qpow(int b, ll p){ int ret = 1; while(p){ if(p&1) umul(ret, b); umul(b, b), p >>= 1; } return ret; }
const int fN = 1010;
int fact[fN], invfact[fN], pw2[fN], invpw2[fN], inv[fN];
void initfact(int n){
	pw2[0] = 1; for(int i = 1; i <= n; ++i) pw2[i] = mul(pw2[i-1], 2);
	invpw2[0] = 1; for(int i = 1; i <= n; ++i) invpw2[i] = mul(invpw2[i-1], (Mod+1) / 2);
	fact[0] = 1; for(int i = 1; i <= n; ++i) fact[i] = mul(fact[i-1], i);
	invfact[n] = qpow(fact[n], Mod-2); for(int i = n; i > 0; --i) invfact[i-1] = mul(invfact[i], i);
	for(int i = 1; i <= n; ++i) inv[i] = mul(invfact[i], fact[i-1]);
}
int binom(int n, int m){ return (m < 0 || m > n) ? 0 : mul(fact[n], mul(invfact[m], invfact[n-m])); }
const double pi = acos(-1);
inline void chmax(int &a, int b){ (b>a) ? (a=b) : 0; }
inline void chmin(int &a, int b){ (b<a) ? (a=b) : 0; }
inline void chmax(ll &a, ll b){ (b>a) ? (a=b) : 0; }
inline void chmin(ll &a, ll b){ (b<a) ? (a=b) : 0; }

const int S = (1<<20) - 1;

struct tag{
	int t0, t1, x;
	tag(){ t0 = t1 = x = 0; }
	tag(int _t0, int _t1, int _x){
		t0 = _t0, t1 = _t1, x = _x;
	}
	int op(int a){
		a &= (S ^ t0), a |= t1, a ^= x;
		return a;
	}
};
tag operator * (tag lh, tag rh){
	//cout << (bitset<6>)lh.t0 << " " << (bitset<6>)lh.t1 << " " << (bitset<6>)lh.x << ", ";
	//cout << (bitset<6>)rh.t0 << " " << (bitset<6>)rh.t1 << " " << (bitset<6>)rh.x << endl;

	//map<int, int> st, ed;
	//rep(i, 32) st[i] = lh.op(rh.op(i));

	tag ret = tag();
	int free = S ^ lh.t0 ^ lh.t1;
	rh.t0 &= free, rh.t1 &= free, rh.x &= free;
	int tmp = (lh.x & rh.t0) ^ (lh.x & rh.t1);
	rh.t0 ^= tmp, rh.t1 ^= tmp, lh.x ^= tmp;
	ret.t0 = lh.t0 | rh.t0, ret.t1 = lh.t1 | rh.t1, ret.x = lh.x ^ rh.x;

	//rep(i, 32) ed[i] = ret.op(i);
	//cout << (bitset<6>)ret.t0 << " " << (bitset<6>)ret.t1 << " " << (bitset<6>)ret.x << endl;
	//assert(st == ed);

	return ret;
}

int cn = 2;
int ch[2][12000120], cnt[12000120], has0[12000120], has1[12000120];
tag laz[12000120];
void ins(int x){
	int p = 1, isnew = 0;
	for(int i = 19; i >= 0; --i){
		int c = ((x>>i) & 1);
		if(!ch[c][p]) ch[c][p] = cn++, isnew = 1;
		p = ch[c][p];
	}
	if(isnew){
		p = 1;
		for(int i = 19; i >= 0; --i){
			++cnt[p], has0[p] |= (S ^ x) & ((1<<(i+1)) - 1), has1[p] |= (x & ((1<<(i+1)) - 1));
			int c = ((x>>i) & 1);
			p = ch[c][p];
		}
		++cnt[p];
	}
}

void pushdown(int u, int lvl);
void pushup(int u, int lvl);
int mrg(int u, int v, int lvl);

inline int fanod(int lvl, int l, int r){
	if(!l && !r) return 0;
	ch[0][cn] = l, ch[1][cn] = r;
	pushup(cn, lvl);
	return cn++;
}

void pushtag(int u, int lvl, tag v){
	if((!v.t0 && !v.t1 && !v.x) || !u || lvl <= 0) return ;
	//cout << "pushtag " << u << " " << lvl << ": " << (bitset<6>)v.t0 << " " << (bitset<6>)v.t1 << " " << (bitset<6>)v.x << "\n";
	laz[u] = v * laz[u];
	if((v.t0 | v.t1) & (has0[u] & has1[u])){
		pushdown(u, lvl);
		if((v.t0 | v.t1) & (1<<(lvl-1))){
			int dir = ((v.t1 >> (lvl-1)) & 1);
			ch[dir][u] = mrg(ch[0][u], ch[1][u], lvl - 1), ch[dir^1][u] = 0;
		} else if(v.x & (1<<(lvl-1))) 
			swap(ch[0][u], ch[1][u]);
		pushup(u, lvl);
	} else {
		if((v.t0 | v.t1) & (1<<(lvl-1))) assert(!ch[0][u] || !ch[1][u]);
		if(v.x & (1<<(lvl-1))) swap(ch[0][u], ch[1][u]);
		if(v.t0 & (1<<(lvl-1))) ch[0][u] |= ch[1][u], ch[1][u] = 0;
		if(v.t1 & (1<<(lvl-1))) ch[1][u] |= ch[0][u], ch[0][u] = 0;
		int tmp0 = (has0[u] & (S ^ v.x ^ v.t1)) | (has1[u] & (v.x | v.t0));
		int tmp1 = (has1[u] & (S ^ v.x ^ v.t0)) | (has0[u] & (v.x | v.t1));
		has0[u] = tmp0, has1[u] = tmp1;
	}
}

void pushdown(int u, int lvl){
	pushtag(ch[0][u], lvl - 1, laz[u]), pushtag(ch[1][u], lvl - 1, laz[u]);
	laz[u] = tag();
}

void pushup(int u, int lvl){
	cnt[u] = cnt[ch[0][u]] + cnt[ch[1][u]]; 
	has0[u] = has0[ch[0][u]] | has0[ch[1][u]] | ((bool)(ch[0][u]) << (lvl - 1));
	has1[u] = has1[ch[0][u]] | has1[ch[1][u]] | ((bool)(ch[1][u]) << (lvl - 1));
	assert(has0[u] < (1<<lvl) && has1[u] < (1<<lvl));
}

ai3 split(int u, int lvl, int tl, int tr){
	//cout << "split " << u << " " << lvl << " " << tl << " " << tr << endl;
	if(!u) return (ai3){0, 0, 0};
	if(tr < 0) return (ai3){0, 0, u};
	if(tl >= (1<<lvl)) return (ai3){u, 0, 0};
	if(tl <= 0 && tr >= (1<<lvl) - 1){
		return (ai3){0, u, 0};
	}
	pushdown(u, lvl);
	int mid = (1<<(lvl-1));
	ai3 ret = {0, 0, 0};
	if(tl >= mid){
		ret = split(ch[1][u], lvl-1, tl - mid, tr - mid);
		if(ch[0][u] || ret[0]) ch[1][u] = ret[0], ret[0] = u, pushup(u, lvl);
		ret[1] = fanod(lvl, 0, ret[1]), ret[2] = fanod(lvl, 0, ret[2]);
	} else if(tr < mid){
		ret = split(ch[0][u], lvl-1, tl, tr);
		if(ch[1][u] || ret[2]) ch[0][u] = ret[2], ret[2] = u, pushup(u, lvl);
		ret[0] = fanod(lvl, ret[0], 0), ret[1] = fanod(lvl, ret[1], 0);
	} else {
		ai3 retl = split(ch[0][u], lvl-1, tl, tr), retr = split(ch[1][u], lvl-1, tl - mid, tr - mid);
		ret[0] = fanod(lvl, retl[0], 0), ret[2] = fanod(lvl, 0, retr[2]);
		if(retl[1] || retr[1]) ch[0][u] = retl[1], ch[1][u] = retr[1], ret[1] = u, pushup(u, lvl);
	}
	//cout << "split " << u << " " << lvl << " " << tl << " " << tr << ": " << ret[0] << " " << ret[1] << " " << ret[2] << ": " << cnt[ret[0]] << " " << cnt[ret[1]] << " " << cnt[ret[2]] << endl;
	return ret;
}

int mrg(int u, int v, int lvl){
	if(!u || !v) return u | v;
	//cout << "mrg " << u << " " << v << " " << lvl << endl;
	if(lvl == 0) return u;
	pushdown(u, lvl), pushdown(v, lvl);
	ch[0][u] = mrg(ch[0][u], ch[0][v], lvl-1), ch[1][u] = mrg(ch[1][u], ch[1][v], lvl-1);
	pushup(u, lvl);
	return u;
}

void trav(int u, int x, int lvl){
	if(lvl == 20) cout << "{";
	if(u){
		if(lvl == 0){
			cout << x << ", ";
			return ;
		}
		pushdown(u, lvl);
		trav(ch[0][u], x, lvl - 1), trav(ch[1][u], x + (1<<(lvl-1)), lvl - 1);
	}
	if(lvl == 20) cout << "}" << endl;
}

int n, q;

int main(){
	//freopen("e.in", "r", stdin);
	//freopen("e.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	while(n--){
		int x;
		cin >> x;
		ins(x);
	}

	int rt = 1;

	//trav(rt, 0, 20);
	//cout << (bitset<6>)has0[rt] << " " << (bitset<6>)has1[rt] << endl;

	while(q--){
		int tp;
		cin >> tp;
		if(tp <= 3){
			int l, r, x;
			cin >> l >> r >> x;
			ai3 ret = split(rt, 20, l, r);
			//trav(ret[0], 0, 20), trav(ret[1], 0, 20), trav(ret[2], 0, 20);
			//cout << (bitset<6>)has0[ret[1]] << " " << (bitset<6>)has1[ret[1]] << endl;
			pushtag(ret[1], 20, tag((tp == 1) ? (S ^ x) : 0, (tp == 2) ? x : 0, (tp == 3) ? x : 0));
			//trav(ret[1], 0, 20);
			rt = mrg(mrg(ret[0], ret[1], 20), ret[2], 20);
		} else {
			int l, r;
			cin >> l >> r;
			ai3 ret = split(rt, 20, l, r);
			//cout << ret[0] << " " << ret[1] << " " << ret[2] << endl;
			cout << cnt[ret[1]] << "\n";
			rt = mrg(mrg(ret[0], ret[1], 20), ret[2], 20);
		}
		//trav(rt, 0, 20);
		//cout << "------------------" << endl;
	}

	cerr << 1. * clock() / CLOCKS_PER_SEC << "\n";
	cerr << cn << "\n";

	return 0;
}
		  			    	  			 	   								