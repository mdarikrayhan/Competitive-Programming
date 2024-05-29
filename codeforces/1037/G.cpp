# include <iostream>
# include <cstdio>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <vector>
# include <map>
# include <cstdint>
# include <unordered_map>
using namespace std;
using nimber = uint8_t;
const int MAXN = 1.1e5;
int N;
int A[MAXN];
const int MAXD = 30;
const int D = 26;
int nxt[MAXN][MAXD];
int prv[MAXN][MAXD];
nimber pref[MAXN];
nimber dpnxt[MAXN][MAXD]; 
nimber dpprv[MAXN][MAXD]; 
bool seen[MAXD + 1];
nimber solveRange(int l, int r) {
	if (l > r) return 0;
	memset(seen, false, sizeof(seen));
	for (int d = 0; d < D; d++) {
		if (nxt[l][d] > r) continue;
		int x = nxt[l][d];
		int y = prv[r][d];
		nimber v = dpnxt[l][d] ^ dpprv[r][d];
		v ^= pref[y] ^ pref[x];
		if (v < D) seen[v] = true;
	}
	nimber res = 0;
	while (seen[res]) res++;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	string S; cin >> S;
	N = int(S.size());
	for (int i = 0; i < N; i++) {
		A[i + 1] = S[i] - 'a';
	}
	for (int d = 0; d < D; d++) {
		prv[0][d] = 0;
		nxt[N + 1][d] = N + 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int d = 0; d < D; d++) {
			prv[i][d] = prv[i - 1][d];
		}
		prv[i][A[i]] = i;
	}
	for (int i = N; i >= 1; i--) {
		for (int d = 0; d < D; d++) {
			nxt[i][d] = nxt[i + 1][d];
		}
		nxt[i][A[i]] = i;
	}
	for (int i = 1; i <= N; i++) {
		int p = prv[i - 1][A[i]];
		if (p > 0) {
			pref[i] = pref[p] ^ dpprv[i - 1][A[i]];
		} else {
			pref[i] = 0;
		}
		for (int j = i; j > p; j--) {
			dpnxt[j][A[i]] = solveRange(j, i - 1);
		}
		vector<pair<int, int>> lefts;
		for (int d = 0; d < D; d++) {
			if (prv[i][d] == 0) continue;
			lefts.emplace_back(-prv[i][d], d);
		}
		sort(lefts.begin(), lefts.end());

		for (auto it : lefts) {
			int d = it.second;
			dpprv[i][d] = solveRange(prv[i][d] + 1, i);
		}
	}

	int Q;
	cin >> Q;
	for (int q = 0; q < Q; q++) {
		int l, r; cin >> l >> r;
		nimber v = solveRange(l, r);
		cout << (v ? "Alice" : "Bob") << '\n';
	}
	return 0;
}
