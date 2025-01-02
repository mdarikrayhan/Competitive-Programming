#include <iostream>
#include <vector>
#include <algorithm>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#define int long long
#define res(a, n) a.clear(); a.resize(n)
#define ress(a, n, b) a.clear(); a.resize(n, b);

using namespace std;

const int N = 3e5 + 1;
int n, q, s = 1, nx = 0, mod = 1e9 + 7;
int pos[N], sizee[N], h[N], tree[N], tree2[N];

vector<vector<int>> g;

int read(int* f, int ind) {
	int sum = 0;
	while (ind < N) {
		sum = sum + f[ind];
		ind = (ind) | (ind + 1);
	}
	return sum;
}

// [0; ind]
void write(int* f, int ind, int a) {
	while (ind >= 0) {
		f[ind] = a + f[ind];
		ind = (ind & (ind + 1)) - 1;
	}
}

void dfs(int v) {
	sizee[v] = 1;
	pos[v] = nx++;
	for (auto x : g[v]) {
		h[x] = h[v] + 1;
		dfs(x);
		sizee[v] += sizee[x];
	}
}

signed main() {
	cin >> n;
	while (s < n) s <<= 1;
	res(g, n);
	for (int i = 1; i < n; i++) {
		int p; cin >> p;
		g[p - 1].push_back(i);
	}
	h[0] = 0;
	dfs(0);

	cin >> q;
	while (q--) {
		int t, v, x, k;
		cin >> t;
		if (t == 1) {
			cin >> v >> x >> k; --v;
			int aa = (x + (h[v] * k) % mod) % mod;
			write(tree, pos[v] + sizee[v] - 1, aa);
			write(tree, pos[v] - 1, -aa);
			write(tree2, pos[v] + sizee[v] - 1, k);
			write(tree2, pos[v] - 1, -k);
		}
		else {
			cin >> v; --v;
			int ba = read(tree, pos[v]); ba %= mod;
			int bb = read(tree2, pos[v]); bb %= mod;
			cout << (ba - (h[v] * bb) % mod + mod) % mod << endl;
		}
	}
}