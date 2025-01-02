#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void link(int* a, int* b) { a = b; }
int main() {
	IOS; int n, m = 360; cin >> n;
	vector<int>v(n); for (int& x : v)cin >> x;
	for (int i = 0; i < n; i++) {
		int sum{}; for (int a = 0; a < i; a++)sum += v[a];
		for (int j = i; j < n + i; j++) {
			sum += v[j%n];
			m = min(m, abs(2 * sum - 360));
			sum -= v[(j - i) % n];
		}
	}
	cout << m;

}