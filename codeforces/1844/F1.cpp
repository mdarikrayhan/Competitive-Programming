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

int n; ll x;
const int maxn = 5e3 + 4;
ll a[maxn], valx[maxn];

void solve() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	if (x >= 0) {
		sort(a, a + n);
		for (int i = 0; i < n; i++) cout << a[i] << sep;
		cout << endl;
		return ;
	}
	
	sort(a, a + n, greater<ll>()); ll res = 0;
	for (int i = 1; i < n; i++) res += abs(a[i] - a[i - 1] - x);
	
	for (int i = 0; i < n; i++) {
		ll val = 0;
		for (int j = 1; j < n; j++) {
			if (j == i) continue;
			val += abs(a[j] - a[j - 1] - x);
		}
		for (int j = i + 1; j < n; j++) {
			valx[j] = 0;
			if (j - 1 >= 0) valx[j] -= abs(a[j] - a[j - 1] - x);
			if (j + 1 < n) valx[j] -= abs(a[j + 1] - a[j] - x);
			if (j - 1 >= 0 && j + 1 < n) {
				valx[j] += abs(a[j + 1] - a[j - 1] - x);
			}
		}
		
		int k = i;
		for (int j = i + 1; j < n; j++) {
			ll R = val + valx[j];
			if (i - 1 >= 0) R += abs(a[j] - a[i - 1] - x);
			if (i != j) R += abs(a[i] - a[j] - x);
			if (R == res && a[j] < a[k]) k = j;
		}
		while (k > i) {
			swap(a[k], a[k - 1]); k--;
		}
	}
	
	for (int i = 0; i < n; i++) cout << a[i] << sep;
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
