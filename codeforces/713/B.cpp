#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=int(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define fore(e,c) for(const auto &e : (c))
#define db(v) cerr<<#v" = "<<(v)<<'\n'
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
using ll = long long;
using ull = unsigned ll;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using veci = vector<int>;
using vecll = vector<ll>;
using vecb = vector<bool>;
using vecveci = vector<veci>;
template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}
template<class T,class U>ostream&operator<<(ostream&o,pair<T,U>const&p){return o<<"("<<p.fst<<", "<<p.snd<<")";}
template<class T>void maxa(T&x,T const&y){  x=max(x,y);  }
template<class T>void mina(T&x,T const&y){  x=min(x,y);  }
template<class T>void sort2(T&x,T&y){  if(y<x)swap(x,y);  }
template<class T>void sort3(T&x,T&y,T&z){  sort2(x,y);sort2(y,z);sort2(x,y);  }

void solve();
void global_init();

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	// cin >> t;
	global_init();
	forn(_,t) solve();
}

const ll MAXN = -1;
const ll INF = 1e18+100;
const ll MOD = 1000000007; /* NTT prime: 998244353 */
const ld EPS = 1e-9;
const ld PI = acosl(-1);

void global_init() {

}

int query(int x0, int y0, int x1, int y1) {
	if (x0 == x1) return 0;
	if (y0 == y1) return 0;
	x0++; y0++;
	cout << "?";
	cout << " " << x0 << " " << y0 << " " << x1 << " " << y1;
	cout << endl;
	int ans;
	cin >> ans;
	return ans;
}

void answer(int x00, int y00, int x01, int y01, int x10, int y10, int x11, int y11) {
	x00++; y00++;
	x10++; y10++;
	cout << "!";
	cout << " " << x00 << " " << y00 << " " << x01 << " " << y01;
	cout << " " << x10 << " " << y10 << " " << x11 << " " << y11;
	cout << endl;
}

template<class Fun>
pii bsearch(int lo, int hi, Fun f) {
	while (hi - lo > 1) {
		int mi = (hi + lo) / 2;
		(f(mi)?lo:hi) = mi;
	}
	return {lo, hi};
}

tuple<int,int,int,int> find(int x0, int y0, int x1, int y1) {
	int ycut1 = bsearch(y0, y1, [=](int mi) { return query(x0,y0,x1,mi) == 0; }).snd;
	int xcut1 = bsearch(x0, x1, [=](int mi) { return query(x0,y0,mi,ycut1) == 0; }).snd;
	int ycut2 = bsearch(y0, ycut1, [=](int mi) { return query(x0,mi,xcut1,ycut1) != 0; }).fst;
	int xcut2 = bsearch(x0, xcut1, [=](int mi) { return query(mi,y0,xcut1,ycut1) != 0; }).fst;
	return {xcut2, ycut2, xcut1, ycut1};
}

void solve() {
	int n;
	cin >> n;

	auto [x00, y00, x01, y01] = find(0,0,n,n);

	int x10, y10, x11, y11;

	/****/ if (query(0,0,x00,n)) {
		tie(x10,y10,x11,y11) = find(0,0,x00,n);
	} else if (query(x01,0,n,n)) {
		tie(x10,y10,x11,y11) = find(x01,0,n,n);
	} else if (query(0,0,n,y00)) {
		tie(x10,y10,x11,y11) = find(0,0,n,y00);
	} else if (query(0,y01,n,n)) {
		tie(x10,y10,x11,y11) = find(0,y01,n,n);
	}

	answer(x00, y00, x01, y01, x10, y10, x11, y11);
}
