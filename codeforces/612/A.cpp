#include <bits/stdc++.h>
using namespace std;

int n, p, q, t, cntp, cntq;
string s;
int main() {
	cin >> n >> p >> q;
	cin >> s;
	for (int i = 0; i <= n / p; i++) 
		if ((n - i * p) % q == 0) {
			cntp = i;
			cntq = (n - i * p) / q;
			break;
		}
	if (cntp == 0 && cntq == 0) puts("-1"), exit(0);
	cout << cntp + cntq << '\n';
	while (cntp--) {
		for (int i = t; i <= t + p - 1; i++) cout << s[i];
		cout << '\n';
		t += p;
	}
	while (cntq--) {
		for (int i = t; i <= t + q - 1; i++) cout << s[i];
		cout << '\n';
		t += q;
	}
}