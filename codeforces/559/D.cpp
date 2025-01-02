#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct Point {
	int x, y;
	ll operator^(const Point &b) const {
		return 1ll * x * b.y - 1ll * y * b.x;
	}
	ll operator&(const Point &b) const {
		ll dx = abs(x - b.x), dy = abs(y - b.y);
		ll d = gcd(dx, dy);
		return d;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	vector<Point> p(n);
	for (auto &[x, y] : p) {
		cin >> x >> y;
	}
	vector<ld> pw(n + 1);
	pw[0] = 1;
	for (int i = 1; i <= n; i++) {
		pw[i] = pw[i - 1] / 2;
	}
	ld s = 0, t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n && j < 100; j++) {
			auto &a = p[i], &b = p[(i + j) % n];
			s += (a ^ b) * pw[j + 1] / 2;
			t += (a & b) * pw[j + 1];
		}
	}
	if (n <= 100) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				t -= (p[i] & p[j]) * pw[n - 1];
			}
		}
	}
	ld ans = s - t / 2;
	ld pv = n + n * (n - 1ll) / 2 + 1;
	for (int i = 0; i < n; i++) {
		pv /= 2;
	}
	ans = ans / (1 - pv) + 1;
	cout << fixed << setprecision(20) << double(ans) << '\n';
	return 0;
}
