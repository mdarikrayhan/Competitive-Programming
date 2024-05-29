#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fast_io cin.tie(0)->sync_with_stdio(0);

using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a) * b/a : 1;
}

ll get(ll x, ll L) {
	x = x % L;
	if (x < 0) x += L;
	return x;
}

vector<ll> solve(ll a, ll t, ll l) {
	ll G = gcd(a, l);
	//cout << a << " " << t << " " << l << " L=" << L << endl;
	if (t % G) return {};
	ll al = a / G;
	ll tl = t / G;
	ll lll = l / G;
	//cout << "na=" << a << " nt=" << t << " nl=" << l << endl;
	//cout.flush();

	//cout << "a=" << a;
	//cout << " t=" << t;
	//cout << " l=" << l;
	//cout << endl;

	//cout << "na=" << al;
	//cout << " nt=" << tl;
	//cout << " nl=" << lll;
	//cout << endl;
	//cout.flush();

	//if (gcd(al, lll) != 1) return {};
	vector<ll> ans;

	ll orig = get(tl * inv(al, lll), lll);
	//cout << "orig=" << orig << endl;
	//cout.flush();
	for (ll i = 0; i < G; i++) {
		ans.push_back(orig + i * (l / G));
		assert(get((orig + i * (l / G)) * a - t, l) == 0);
	}

	return ans;
}

void test_case() {
	ll t; cin >> t;
	int n; cin >> n;
	vector<ll> a(n);
	for (auto &x : a) cin >> x;
	sort(a.rbegin(), a.rend());

	ll L = a[0];
	for (ll x : a) L = lcm(x, L);

	if (n == 1) {
		cout << (t % a[0] == 0) << endl;
		return;
	}

	if (n == 2) {
		ll ans = 0;
		for (ll i = 0; i * a[0] < L; i++) {
			ll resta = t - i * a[0];
			auto ivs = solve(a[1], get(resta, L), L);
			for (ll iv : ivs) {
				if (iv * a[1] >= L) continue;
				ll gasto = iv * a[1] + i * a[0];
				if (gasto > t) continue;
				
				ll k = (t - gasto) / L;
				ll soma = k + 1;
				//cout << "i=" << i << " iv=" << iv << " k=" << k << " soma=" << soma << endl;

				ans += soma;
			}
		}
		cout << ans << endl;

		return;
	}

	if (n == 3) {
		ll ans = 0;
		for (ll i = 0; i * a[0] < L; i++) {
			for (ll j = 0; j * a[1] < L; j++) {
				ll resta = t - i * a[0] - j * a[1];
				auto ivs = solve(a[2], get(resta, L), L);

				for (auto iv : ivs) {
					if (iv * a[2] >= L) continue;
					ll gasto = i * a[0] + j * a[1] + iv * a[2];
					if (gasto > t) continue;

					ll k = (t - gasto) / L;
					ll soma = (k + 2)*(k + 1) / 2;
					//cout << "i=" << i << " j=" << j << " iv=" << iv << " k=" << k << " soma=" << soma << endl;

					ans += soma;
				}
			}
		}
		cout << ans << endl;

		return;
	}

	assert(false);
}

int main() {
	fast_io;

	int t; cin >> t;
	while (t--) test_case();

	return 0;
}
