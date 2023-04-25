#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

const ll N = 2e5 + 1, mod = 1e9 + 7, inf = 1e17 + 1;

void solve() {
	ll a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	cout << a[1] << "\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(10);

	ll tt = 1;
	cin >> tt;
	for (int i = 1; i <= tt; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}