// In the name of Allah

#include <bits/stdc++.h>
using namespace std;

typedef		long long int			ll;
typedef		long double				ld;
typedef		pair<int, int>			pii;
typedef		pair<ll, ll>			pll;
typedef		complex<ld>				cld;

#define		all(x)					(x).begin(),(x).end()
#define		len(x)					((ll) (x).size())
#define		F						first
#define		S						second
#define		X						real()
#define		Y						imag()
#define		pb						push_back
#define		sep						' '
#define		endl					'\n'
#define		Mp						make_pair
#define		kill(x)					cout << x << '\n', exit(0)
#define		set_dec(x)				cout << fixed << setprecision(x);
#define		file_io(x,y)			freopen(x, "r", stdin); freopen(y, "w", stdout);

const int maxn = 2e5 + 7;
const int maxlg = 20;

int n; ll k;
int a[maxn], mark[maxn], c;
vector<int> A[maxn], ls[maxn], res;
int M[maxn], ans[maxn];

ll power(ll a, ll b, ll mod) {
	if (b == 0) return (1 % mod);
	return power(a * a % mod, b / 2, mod) * ((b & 1) ? a : 1) % mod;
}

ll Gx(ll R, int k) {
	int j = __builtin_ctzl(R); ll x = (R >> j);
	return power((x + 1) / 2, k, R) * (1ll << j) % R;
}

void merge(int u, int v) {
	res.clear();
	for (int i = 0; i < len(A[u]); i++) {
		res.pb(A[u][i]); res.pb(A[v][i]);
	}
	A[u].clear(); M[u] &= M[v];
	for (int x : res) A[u].pb(x);
	A[v].clear(); A[v].shrink_to_fit();
}

void opr(int u, ll x) {
	res.clear(); res.resize(len(A[u]));
	int g = __gcd(len(A[u]), x);
	for (int i = 0; i < g; i++) {
		int j = i;
		for (int T = 0; T < len(A[u]) / g; T++) {
			res[j] = A[u][i];
			i = (i + x); j += g;
			if (i >= len(A[u])) i -= len(A[u]);
		}
	}
	A[u].clear();
	for (int x : res) A[u].pb(x);
}

bool make_opr() {
	for (int i = 1; i <= n; i++) ls[i].clear();
	for (int T : {0, 1}) {
		for (int i = 0; i < c; i++) {
			if (len(A[i]) == 0) continue;
			if (M[i] == T) ls[len(A[i])].pb(i);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < len(ls[i]); j += 2) {
			merge(ls[i][j - 1], ls[i][j]);
		}
		if (len(ls[i]) % 2 == 1) {
			int u = ls[i].back();
			if (!M[u]) return 0;
			opr(u, Gx(len(A[u]), 1));
		}
	}
	return 1;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
	}
	
	fill(mark, mark + n, 0); c = 0;
	for (int i = 0; i < n; i++) A[i].clear();
	for (int i = 0; i < n; i++) {
		if (mark[i]) continue;
		int v = i;
		while (!mark[v]) {
			mark[v] = 1; A[c].pb(v);
			v = a[v];
		}
		M[c] = len(A[c]) & 1; c++;
	}
	
	for (int T = 0; T < maxlg; T++) {
		if (k == 0) break;
		if (!make_opr()) {
			cout << "NO" << endl;
			return ;
		}
		k--;
	}
	
	for (int u = 0; u < c; u++) {
		if (len(A[u]) == 0) continue;
		opr(u, Gx(len(A[u]), k));
	}
	
	for (int u = 0; u < c; u++) {
		for (int i = 0; i < len(A[u]); i++) {
			int j = (i + 1);
			if (j >= len(A[u])) j -= len(A[u]);
			int j1 = A[u][i], j2 = A[u][j];
			ans[j1] = j2;
		}
	}
	
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) cout << ans[i] + 1 << sep;
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	
	return 0;
}
