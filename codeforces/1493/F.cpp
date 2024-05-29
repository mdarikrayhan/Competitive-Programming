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

int n, m; ll ans;
const int maxn = 1000 + 7;
vector<ll> ls1, ls2;

vector<ll> calF(ll x) {
	vector<ll> res;
	for (ll i = 2; i * i <= x; i++) {
		while (x % i == 0) {
			res.pb(i); x /= i;
		}
	}
	if (x != 1) res.pb(x);
	return res;
}

ll calD(ll x) {
	ll res = 0;
	for (ll i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			res++;
			if (x / i != i) res++;
		}
	}
	return res;
}

bool check(int h, int w, pii A, pii B) {
	cout << '?' << sep << h << sep << w << sep;
	cout << A.F + 1 << sep << A.S + 1 << sep;
	cout << B.F + 1 << sep << B.S + 1 << endl;
	cout.flush();
	int x; cin >> x;
	return x;
}

bool ok1(ll R, ll x) {
	ll t = x;
	while (t * 2 <= R) t *= 2;
	if (t < R && !check(R - t, m, Mp(0, 0), Mp(t, 0))) return 0;
	R = t;
	while (R > x) {
		if (!check(R / 2, m, Mp(0, 0), Mp(R / 2, 0))) return 0;
		R /= 2;
	}
	return 1;
}

bool ok2(ll R, ll x) {
	ll t = x;
	while (t * 2 <= R) t *= 2;
	if (t < R && !check(n, R - t, Mp(0, 0), Mp(0, t))) return 0;
	R = t;
	while (R > x) {
		if (!check(n, R / 2, Mp(0, 0), Mp(0, R / 2))) return 0;
		R /= 2;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m; ans = 1;
	ls1 = calF(n); ls2 = calF(m);
	
	ll val = 1, R = n;
	for (ll x : ls1) {
		if (ok1(R, R / x)) {
			val *= x; R /= x;
		}
	}
	ans *= calD(val);
	
	val = 1; R = m;
	for (ll x : ls2) {
		if (ok2(R, R / x)) {
			val *= x; R /= x;
		}
	}
	ans *= calD(val);
	
	cout << '!' << sep << ans << endl;
	cout.flush();
	
	return 0;
}
