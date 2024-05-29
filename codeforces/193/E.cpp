#include <bits/stdc++.h>
#define int __int128
using namespace std;

#ifndef ONLINE_JUDGE
#include <debug-template.hpp>
#define debug(...) cerr << "[ " << #__VA_ARGS__ << " ]: ", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int mod = 1e13;

struct matrix {
	int n, m;
	vector <vector <int>> rem;
	matrix (int nn, int mm) {
		n = nn, m = mm;
		rem.assign(n, vector <int> (m, 0));
	}
};

matrix operator * (matrix x, matrix y) {
	matrix c(x.n, y.m);
	for (int i = 0; i < x.n; i ++) for (int j = 0; j < y.m; j ++) {
		int now = 0;
		for (int k = 0; k < x.m; k ++) now += x.rem[i][k] * y.rem[k][j], now %= mod;
		c.rem[i][j] = now;
	}
	return c;
}

matrix con (matrix a, int k) {
	matrix res (a.n, a.m);
	for (int i = 0; i < a.n; i ++) res.rem[i][i] = 1;
	while (k) {
		if (k & 1) res = res * a;
		a = a * a;
		k >>= 1;
	}
	return res;
}

int f (int n) {
	matrix phi(2, 2);
	phi.rem = {{1, 1}, {1, 0}};
	return con(phi, n).rem[1][0];
}

int lcm (int x, int y) {
	return x * y / __gcd(x, y);
}

int con(int n, int x) {
	int ans = 1;
	while (x) {
		if (x & 1) ans *= n;
		n *= n;
		x >>= 1;
	}
	return ans;
}

void pf (int x) {
	long long y = x;
	cout << y << "\n";
}

void in (__int128 &x) {
	long long y; cin >> y;
	x = y;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; in(n);
	int t, len = 10, tt = 1;
	vector <int> rem;
	for (int i = 0; i < 60; i ++) if (f(i) % len == n % len) rem.push_back(i);
	
	tt = 60;
	for (int now = 2; now <= 13; now ++) {
		len *= 10;
		t = lcm(con(2, now - 1) * 3, con(5, now - 1) * 20);
		
		vector <int> use;
		for (auto pos : rem) {
			for (int i = pos; i < pos + t; i += tt) {
				if (f(i) % len == n % len) use.push_back(i);
			}
		}
		rem.resize(use.size());
		for (int i = 0; i < rem.size(); i ++) rem[i] = use[i];
		tt = t;
	}
	
	sort(rem.begin(), rem.end());
	if (rem.size()) pf (rem[0]);
	else cout << "-1\n";
	
	return 0;
}