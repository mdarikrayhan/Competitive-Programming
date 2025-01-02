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


void solve() {
	string a, b;
	cin >> a >> b;

	int a4 = 0, a7 = 0;

	int n = sz(a);
	forn(i, n) {
		if (a[i] != b[i]) {
			(a[i] == '4' ? a4 : a7) += 1;
		}
	}

	cout << max(a4, a7) << "\n";
}
