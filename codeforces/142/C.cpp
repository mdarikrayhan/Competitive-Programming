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

char board[9][9];
int n, m;

pii shape[4][5] = {
	{{0,0}, {0,1}, {0,2}, {1,1}, {2,1}},
	{{0,2}, {1,0}, {1,1}, {1,2}, {2,2}},
	{{0,1}, {1,1}, {2,0}, {2,1}, {2,2}},
	{{0,0}, {1,0}, {1,1}, {1,2}, {2,0}},
};

bool run(int k, char c, int i0, int j0) {

	int fr = 0;
	forr(i, i0, n) forr(j, i==i0?j0:0, m)
		fr += board[i][j] == '.';
	if (fr / 5 < k) return false;

	if (k == 0) return true;
	forr(i, i0, n-2) forr(j, i==i0?j0:0, m-2) {
		forn(d, 4) {
			bool ok = true;
			for (auto [di,dj] : shape[d]) {
				if (board[i+di][j+dj] != '.') {
					ok = false; break;
				}
			}
			if (not ok) continue;
			for (auto [di, dj] : shape[d]) {
				board[i+di][j+dj] = c;
			}
			if (run(k-1, c+1, i, j+1)) return true;
			for (auto [di, dj] : shape[d]) {
				board[i+di][j+dj] = '.';
			}
		}
	}
	return false;
}


void solve() {
	cin >> n >> m;

	if (n == 9 and m == 9) {
		cout << 
R"(
13
AAA.BCCC.
.ABBB.CD.
.AE.BFCD.
EEEFFFDDD
G.E.HFIII
GGGJHHHI.
GK.JHL.IM
.KJJJLMMM
KKK.LLL.M
)";
		return;
	}

	if (n == 8 and m == 9) {
		cout <<
R"(
12
AAABBB..C
.AD.BECCC
.AD.BEEEC
FDDDGEHHH
FFFIGGGH.
FJ.IGK.HL
.JIIIKLLL
JJJ.KKK.L
)";
		return;
	}

	if (n == 9 and m == 8) {
		cout <<
R"(
12
AAA.BCCC
.ABBBDC.
EA.FBDC.
EEEFDDDG
EHFFFGGG
.HHHIIIG
JHKKKIL.
JJJK.IL.
J..K.LLL
)";
		return;
	}

	char ans[9][9];

	forn(k, 20) {
		memset(board, '.', sizeof(board));
		bool pude = run(k,'A',0,0);
		if (pude) {
			memcpy(ans, board, sizeof(board));

			// cerr << "~~ " << k << "\n";
			// forn(i, n) {
			// 	cerr << "~~ ";
			// 	forn(j, m) cerr << ans[j][i];
			// 	cerr << "\n";
			// }

		} else {
			cout << k-1 << "\n";
			forn(i, n) {
				forn(j, m) cout << ans[i][j];
				cout << "\n";
			}
			return;
		}
	}
}
