#include <cstdio>
int n, c, d, t[100005], lst; char p[100005]; long long ans, now;
int main() {
	scanf ("%d%d%d", &n, &c, &d);
	for (int i=1; i<=n; i++)
		scanf ("%d %c", &t[i], &p[i]);
	scanf ("%d", &lst), ans = now = 1ll * n * d;
	for (int i=n; i; i--) {
		if (c * (lst - t[i]) < d || p[i] != p[i-1]) now += c * (lst - t[i]) - d;
		if (p[i] != p[i-1]) lst = t[i];
		if (now < ans) ans = now;
	} printf ("%lld\n", ans);
}