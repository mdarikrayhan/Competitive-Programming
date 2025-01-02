#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 105;
const ld eps = 1e-9l;

int hl, hr, n;
int v[Maxn], c[Maxn], a[Maxn], b[Maxn];
bool taken[Maxn];
int res;

int Get(int cur, int h1, int h2, int tims)
{
	if (h1 >= h2) return 0;
	int res = 0;
	fill(taken, taken + n, false);
	for (int i = 1; i <= tims; i++) {
		ld x = 1e5l / ld(h2 - h1) * (100 * i - h1);
		bool found = false;
		for (int j = 0; j < n && !found; j++)
			if (c[j] == cur && a[j] <= x + eps && x <= b[j] + eps)
				if (taken[j]) return 0;
				else { found = true; taken[j] = true; res += v[j]; }
		if (!found) return false;
		cur = 1 - cur;
	}
	return res;
}

int main()
{
	scanf("%d %d %d", &hl, &hr, &n);
	for (int i = 0; i < n; i++) {
		char ch; scanf("%d %c %d %d", &v[i], &ch, &a[i], &b[i]);
		c[i] = ch == 'T';
	}
	for (int i = 1; i <= n; i++) {
		res = max(res, Get(1, hl, 100 * i + (i % 2? 100 - hr: hr), i));
		res = max(res, Get(0, 100 - hl, 100 * i + (i % 2? hr: 100 - hr), i));
	}
	printf("%d\n", res);
	return 0;
}