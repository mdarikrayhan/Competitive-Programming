#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+5;
int arr[MAXN];
int n;

typedef long double ld;

const ld eps = 1e-9;

int sign(int a) {
	return a < 0 ? -1 : (a == 0 ? 0 : 1);
}

void print(int a) {
	if (a > 0) cout << ">\n";
	else if (a == 0) cout << "=\n";
	else cout << "<\n";
	exit(0);
}

int main() {
	string a, b; cin >> a >> b;
	n = max(a.size(), b.size());
	for (int i = 0; i < a.size(); i++) arr[n-a.size()+i] += (a[i] - '0');
	for (int i = 0; i < b.size(); i++) arr[n-b.size()+i] -= (b[i] - '0');
	int res[2]; res[0] = 0;
	for (int i = 0; i < n; i++) {
		res[1] += arr[i];
		int nxt = 0;
		while (res[0] != 0) {
			if (sign(res[0]) != -sign(res[1])) print(res[0]);
			res[0] -= sign(res[0]);
			nxt -= sign(res[1]);
			res[1] -= sign(res[1]);
		}
		res[0] = res[1];
		res[1] = nxt;
	}
	ld phi = (1 + sqrt((ld)5))/2;
	// cout << phi << '\n';
	if (res[0]*phi + res[1] > eps) cout << ">\n";
	else if (res[0]*phi + res[1] < -eps) cout << "<\n";
	else cout << "=\n";
	/*
		

	*/
}