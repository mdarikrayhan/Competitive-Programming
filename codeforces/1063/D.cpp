# include <iostream>
# include <cstdio>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <vector>
# include <map>
# include <climits>
# include <unordered_map>

using namespace std;

typedef long long ll;

ll divfloor(ll a, ll b) {
	ll k = a / b;
	if (k * b > a) k--;
	return k;
}

ll divceil(ll a, ll b) {
	ll k = a / b;
	if (k * b < a) k++;
	return k;
}

void work() {
	ll n, i_l, i_r, i_k;
	cin >> n >> i_l >> i_r >> i_k;
	ll d = i_l <= i_r ? i_r - i_l + 1 : i_r + n - i_l + 1;
	ll s = i_k - d, v = n - d + 1, ans = -1;
	if (n <= 1000000) {
		for (ll r = 0; r <= n; r++) {
			ll a = max(0LL, r - v), b = min(d, r);
			ll mink = max(0LL, divceil(s - b, n + r));
			ll maxk = divfloor(s - a, n + r);
			if (mink <= maxk) ans = max(ans, r);
		}
	}
	else {
		for (ll k = 0; k * n <= s; k++) {
			ll t = s - k * n;
			ll minr = 0, maxr = n;
			if (k) maxr = min(maxr, divfloor(t, k));
			maxr = min(maxr, divfloor(t + v, k + 1));
			if (k) minr = max(minr, divceil(t - d, k));
			else if (t > d) continue;
			minr = max(minr, divceil(t, k + 1));
			if (minr <= maxr) ans = max(ans, maxr);
		}
	}
	cout << ans << endl ;
}
int main() {
	work();
	return 0;
}
