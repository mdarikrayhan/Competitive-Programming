#include <bits/stdc++.h>
using namespace std;
 
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mkp make_pair
 
int rd() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!('0' <= ch && ch <= '9')) {
		if (ch == '-') f = -1; ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();
	}
	return x * f;
}
 
void wr(int x) {
	if (x < 0) putchar('-'), x = -x;
	if (x >= 10) wr(x / 10); putchar(x % 10 + '0');
}
 
const int N = 3e5 + 10;
 
struct node {
	int to, nxt;
} edge[N << 1];
int cnt, head[N];
 
int tot, a[N << 1];
 
void add (int u, int v) {
	cnt++;
	edge[cnt].to = v;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}
 
int dfs (int u, int fa) {
	int len = 0;
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (v == fa) continue;
		int x = dfs(v, u) + 1;
		if (len == 0) len = x;
		else a[++tot] = min(len, x), len = max(len, x);
	} 
	return len;
}
 
void solve() {
	int n;
	cin >> n;
	cnt = 0;
	for (int i = 1; i <= n; ++i)
		head[i] = 0;
	for (int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		add (u, v); add (v, u);
	}
	for (int i = 1; i <= (n << 1); ++i)
		a[i] = 0;
	tot = 0; int x = dfs(1, 0);
	a[++tot] = x; 
	sort (a + 1, a + tot + 1);
	reverse(a + 1, a + tot + 1);
	for (int i = 1; i <= (n << 1); ++i)
		a[i] += a[i - 1];
	for (int i = 1; i < (n << 1) - 2; i += 2)
		cout << n - 1 - a[i] << " ";//psdfsdfkosdf
	cout << endl;
} 
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);//asdfuasdfuasdfhuioasdfhuioasdf
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
