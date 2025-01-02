// LUOGU_RID: 132636557
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int MAXN = 2e5 + 10;

int t, n, a[MAXN], b[MAXN], nxt[MAXN];

bool vis[MAXN]; set<int> s;

inline 
int check(int k, int p) {
	int cnt = 0; s.clear();
	for (int i = n; i; i--) {
		if (nxt[i]) a[i] = a[nxt[i]];
		else if (i >= k || i == p) a[i] = ++cnt;
		else {
			auto it = s.upper_bound(b[i]);
			if (it == s.begin()) return -1; --it;
			a[i] = a[*it], s.erase(it);
		}
		if (!vis[i]) s.insert(i);
	}
	if (!s.empty() && *s.rbegin() > b[1]) return 1;
	puts("Yes");
	for (int i = 1; i <= n; i++) printf("%d ", a[i]); return puts(""), 0;
}

int p, l, r, k; bool f;

int main() {
	for (scanf("%d", &t); t--;) {
		scanf("%d", &n), f = 1;
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]), f &= b[i] >= b[i - 1];
		if (!f || b[1] > n) { puts("No"); continue; }
		k = n + 1, p = -1, l = 1, r = n + 1;
		for (int i = 1; i <= n; i++) nxt[i] = vis[i] = 0;
		b[k] = k, vis[b[1]] = 1;
		for (int i = 1; i <= n; i++) {
			if (b[i] < b[i + 1]) b[i + 1] <= n ? vis[nxt[i] = b[i + 1]] = 1 : (p = i);
		}
		for (f = 0; b[l] <= n; l++);
		for (int mid, res; l <= r;) {
			res = check(mid = l + r >> 1, p);
			if (!res) { f = 1; break; }
			~res ? l = mid + 1 : r = mid - 1;
		}
		if (!f) puts("No");
	}
}
/*
5
3
2 3 4
5
2 3 5 4 6
1
1
3
1 3 4
8
3 6 6 6 8 9 9 9
*/