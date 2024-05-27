#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int INF = 1e9;
const long long INF64 = 1e18;
const int N = 1000 * 1000 + 13;

int n, m, k;
bool pos[N];
int lst[N], s[N], a[N];

int get(int l){
	int r = 0, i = -1, res = 0;
	while (r < n){
		if (lst[r] <= i)
			return INF;
		i = lst[r];
		r = lst[r] + l;
		++res;
	}
	return res;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	forn(i, m) scanf("%d", &s[i]);
	forn(i, k) scanf("%d", &a[i]);
	forn(i, n) pos[i] = true;
	forn(i, m) pos[s[i]] = false;
	forn(i, n){
		if (pos[i])
			lst[i] = i;
		else if (i)
			lst[i] = lst[i - 1];
		else
			lst[i] = -1;
	}
	long long ans = INF64;
	forn(i, k){
		long long t = get(i + 1);
		if (t != INF)
			ans = min(ans, a[i] * t);
	}
	printf("%lld\n", ans == INF64 ? -1 : ans);
	return 0;
}