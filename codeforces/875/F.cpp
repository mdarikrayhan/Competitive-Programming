// LUOGU_RID: 160070145
#include<algorithm>
#include<iostream>
#include<cstring>

const int N = 2e5;
int a[N], b[N], w[N], f[N], o[N];
int gf(int u) { return f[u] < 0 ? u : f[u] = gf(f[u]); }
int main() {
	int n, m; long long sm = 0;
	std::cin >> n >> m, memset(f, -1, n*4);
	for (int i=0; i<m; o[i]=i, i++)
		std::cin >> a[i] >> b[i] >> w[i];
	std::sort(o, o+m, [](int i, int j){return w[i]>w[j];});
	for (int i=0, j, x, y; i<m; i++)
		if (x = gf(a[j=o[i]]-1), y = gf(b[j]-1), x != y) {
			if (f[x] > -1e9 || f[y] > -1e9)
				f[x] += f[y], f[y] = x, sm += w[j];
		} else if (f[x] > -1e9) f[x] = -1e9, sm += w[j];
	std::cout << sm;
}
