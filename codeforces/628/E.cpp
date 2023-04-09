#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3010;
bitset<N>a[N], b[N], c[N];
int main() {
	ll n, m, res = 0;
	scanf("%lld%lld", &n, &m);
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		b[i].set(), c[i].set();
		for (ll j = 0; j < m; j++) {
			a[i][j] = (s[m - 1 - j] == 'z');
		}
	}
	for (ll j = 0; j < min(m, n); j++) {
		for (ll i = 0; i < n; i++) {
			b[i] &= a[i] >> j;
		}
		for (ll i = 0; i + j < n; i++) {
			c[i] &= a[i + j] >> j;
			res += (b[i] & b[i + j] & c[i]).count();
		}
	}
	printf("%lld\n", res);
}