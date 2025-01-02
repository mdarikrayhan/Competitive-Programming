#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	int n, m; cin >> n >> m;
	vector<string> v(n), res;
	vector<pair<int, int>> a(n + 1, {0, 0});
	int tp = 0, tm = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		int c = stoi(v[i].substr(1));
		if (v[i][0] == '+') {
			a[c].first++;
			tp++;
		}
		else {
			tm++;
			a[c].second++; 
		}
	}
	if (m == n || m == 0) {
		string s = (m == n) ? "Truth\n" : "Lie\n"; 
		for (int i = 0; i < n; i++) cout << s;
		return 0;
	}
	vector<bool> p(n + 1, false);
	int kc = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].first + tm - a[i].second == m) {
			p[i] = true;
			kc++;
		}
	}
	for (string x: v) {
		char c = x[0];
		int s = stoi(x.substr(1));
		if (kc > 1) {
			if (c == '+') cout << (p[s] ? "Not defined\n" : "Lie\n");
			else cout << (p[s] ? "Not defined\n" : "Truth\n");
		}
		else {
			if (c == '+') cout << ((p[s]) ? "Truth\n" : "Lie\n");
			else cout << ((p[s]) ? "Lie\n" : "Truth\n");
		}
	}
}