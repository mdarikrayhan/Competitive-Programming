#include<bits/stdc++.h>
	
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n';
	
const int N = 1e2 + 5;

int f[N], n, a[N];

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x != y) f[x] = y;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i]; f[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (i - x >= 1) merge(i, i - x);
		
		if (i + x <= n) merge(i, i + x);
	}

	for (int i = 1; i <= n; i++) {
		if (find(i) != find(a[i])) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}
    				  					 	 	  		   	  	