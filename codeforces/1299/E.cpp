#include <bits/stdc++.h>
#define N 1005
#define pb push_back
using namespace std;

int n, a[N], b[N], pos[N];

int qry(vector<int> &v) {
	printf("? %u ", v.size());
	for (auto x : v) printf("%d ", x);
	puts(""); fflush(stdout); 
	int r = 0; scanf("%d", &r); return r; 
}
int ask(int x) {
	vector<int> v;
	for (int i = 1; i <= n; i++) if (!a[i] && i != x) v.pb(i);
	return qry(v);
}
void solve(int x, int y, int p, int q) {
	for (int i = 1; i <= n; i++) {
		if (!pos[x] && !a[i] && b[i]==p && ask(i)) pos[x] = i;
		else if (!pos[y] && !a[i] && b[i]==q && ask(i))	pos[y] = i;
	}
	a[pos[x]] = x; a[pos[y]] = y;
}

int main() {
	scanf("%d", &n);
	solve(1, n, 0, 0);
	for (int l = 2, r = n-1, t = 2; l <= r; t <<= 1) {
		for (int i = 1; i <= n; i++) if (!a[i]) {
			vector<int> v; v.pb(i);
			for (int j = 1; j <= t; j++) if (j%t != b[i]%t) v.pb(pos[j]);
			if (qry(v)) b[i] += t>>1;
		}
		while (l <= r && l <= (t<<1)) solve(l, r, l%t, r%t), ++l, --r;
	} 
	if (a[1] > n/2) for (int i = 1; i <= n; i++) a[i] = n+1-a[i];
	printf("! ");
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	puts(""); fflush(stdout);
	return 0;
}