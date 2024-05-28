#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second
#define tcT template<class T
tcT> using V = vector<T>;
// tcT, size_t SZ> using AR = arr<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

#define each(a, x) for(auto& a: x)

const int MOD = 998244353;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
	return b < a ? a = b, 1 : 0;
}
tcT> bool ckmax(T& a, const T& b){
	return a < b ? a = b, 1 : 0;
}

int mul(int a, int b) {
	return (1LL * a * b) % MOD;
}

int sum(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}

int diff(int a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
	return a;
}

int power(int a, int deg) {
	int res = 1;
	for (; deg; a = mul(a, a), deg >>= 1) {
		if (deg & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int inv(int a) {
	return power(a, MOD - 2);
}

const int MAX_N = 5010;
int n, a[MAX_N], dp[MAX_N][MAX_N], pref[MAX_N], cnt_smaller[MAX_N], fact[MAX_N];
unordered_map<int, int> cnt;

void solve() {
	cnt.clear();
	cin >> n;
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = mul(i, fact[i - 1]);
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a, a + n);
	for (int i = 1; i < n; ++i) {
		cnt_smaller[i] = a[i] == a[i - 1] ? cnt_smaller[i - 1] : i;
	}
	for (int i = 0; i < n; ++i) {
		dp[1][i] = cnt_smaller[i];
	}
	for (int k = 1; k < n / 2; ++k) {
		for (int i = 1; i <= n; ++i) {
			pref[i] = sum(pref[i - 1], mul(dp[k][i - 1], diff(cnt_smaller[i - 1], 2 * k - 1)));
		}
		// cerr << k << '\n';
		// for (int i = 0; i < n; ++i) {
		// 	cerr << pref[i] << ' ';
		// }
		// cerr << '\n';
		for (int i = 0; i < n; ++i) {
			dp[k + 1][i] = pref[cnt_smaller[i]];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = sum(ans, dp[n / 2][i]);
	}
	for (auto [key, val] : cnt) {
		ans = mul(ans, inv(fact[val]));
	}
	cout << ans << '\n';
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}