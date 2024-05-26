#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll d, k, a, b, t, cnt;
	cin >> d >> k >> a >> b >> t;
	if (d <= k) {
		cout << d * a;
		return 0;
	}
	if (a * k + t > b * k) {
		cout << k * a + (d - k) * b;
		return 0;
	}
	cnt = d / k;
	cout << a * k * cnt + t * (cnt - 1) + min (t + ( d % k) * a, (d % k) * b);
	return 0;
}