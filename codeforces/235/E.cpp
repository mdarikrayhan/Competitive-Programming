// LUOGU_RID: 159720001
#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
using namespace std;

constexpr int N = 2005, P = 1e9 + 7;

int p[N], v[N], idx, mu[N], a, b, c;
ll ans;

ll f(int n, int t) {
	ll ret = 0;
	for(int i = 1; i <= n; ++ i) if(__gcd(i, t) == 1) ret += n / i;
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	mu[1] = 1;
	for(int i = 2; i <= 2000; ++ i) {
		if(v[i] == 0) {
			p[++ idx] = i;
			mu[i] = -1;
		}
		for(int j = 1; j <= idx && p[j] <= 2000 / i; ++ j) {
			v[i * p[j]] = 1;
			if(i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = -mu[i];
		}
	}
	cin >> a >> b >> c;
	for(int z = 1; z <= c; ++ z) {
		ll tmp = 0;
		for(int k = 1; k <= min(a, b); ++ k) {
			if(__gcd(k, z) != 1 || mu[k] == 0) continue;
			tmp += mu[k] * f(a / k, z) * f(b / k, z);
		}
		ans += tmp * (c / z);
	}
	cout << ans % 1073741824;
	return 0;
}