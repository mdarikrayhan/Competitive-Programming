# include <iostream>
# define ll long long
using namespace std;

const int N = 2e5 + 5;

ll n, a[N], b[N];

ll gcd(ll x, ll y) {return y? gcd(y, x%y): x;}
ll lcm(ll x, ll y) {return x/gcd(x, y)*y;}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
	ll g = 0, k = 1;
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		if (gcd(g, a[i] * b[i]) % lcm(k, b[i]) == 0) {
			g = gcd(a[i] * b[i], g);
			k = lcm(k, b[i]);
		}
		else {
			++ans;
			g = a[i] * b[i];
			k = b[i];
		}
	}
	cout << ans << '\n';
}

int main() {
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}