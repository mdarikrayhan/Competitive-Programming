#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 510;
const int M = N * N;
int id[N][N];
bool isBlack[M];
vector<int> g[M];
vector<pii> neigh[N][N];
bool used[M];
int n;
int sumDeg;
int szComp;
bool allEmpty;

void check(int x, int y) {
	assert(x >= 2 && y >= 2 && x < N - 2 && y < N - 2);
	if (id[x][y] != -1) return;
	int cnt = 0;
	for (auto t : neigh[x][y]) {
		int xx = t.first, yy = t.second;
		if (id[xx][yy] != -1) cnt++;
	}
	if (cnt < 2) return;
	id[x][y] = n++;
	for (auto t : neigh[x][y])
		check(t.first, t.second);
}

void dfs(int v) {
	szComp++;
	sumDeg += (int)g[v].size();
	for (int u : g[v])
		if (isBlack[v] && isBlack[u])
			allEmpty = false;
	if (!isBlack[v]) {
		int cnt = 0;
		for (int u : g[v])
			if (isBlack[u])
				cnt++;
		if (cnt == 2) allEmpty = false;
	}
	used[v] = 1;
	for (int u : g[v])
		if (!used[u])
			dfs(u);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			id[x][y] = -1;
	for (int x = 2; x < N - 2; x++)
		for (int y = 2; y < N - 2; y++) {
			neigh[x][y].push_back(mp(x - 1, y));
			neigh[x][y].push_back(mp(x + 1, y));
			if (x % 2 == 0) {
				neigh[x][y].push_back(mp(x + 1, y - 1));
			} else {
				neigh[x][y].push_back(mp(x - 1, y + 1));
			}
		}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x += 4;
		y += 4;
		id[x][y] = i;
		isBlack[i] = 1;
	}
	for (int x = 2; x < N - 2; x++)
		for (int y = 2; y < N - 2; y++) {
			check(x, y);
		}
	for (int x = 2; x < N - 2; x++)
		for (int y = 2; y < N - 2; y++) {
			if (id[x][y] == -1) continue;
			int v = id[x][y];
			for (pii t : neigh[x][y]) {
				int u = id[t.first][t.second];
				if (u == -1) continue;
				g[v].push_back(u);
			}
		}
	int ans = 0;
	for (int v = 0; v < n; v++) {
		if (!isBlack[v]) continue;
		ans += 3;
		for (int u : g[v])
			if (isBlack[u])
				ans--;
	}
	for (int v = 0; v < n; v++) {
		if (used[v]) continue;
		sumDeg = 0;
		szComp = 0;
		allEmpty = true;
		ans -= 2;
		dfs(v);
		if (sumDeg != 2 * szComp - 2) {
			printf("SICK\n");
			return 0;
		}
		if (allEmpty && szComp > 1) ans -= 2;
	}
	printf("RECOVERED\n%d\n", ans);

	return 0;
}
