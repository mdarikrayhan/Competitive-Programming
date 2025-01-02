// LUOGU_RID: 160475743
#include<bits/stdc++.h>

#define REP(i, l, r) for (int i = l; i <= r; ++i)

#define ll long long

using namespace std;

const int N = 2707;

int n, f[N][N];

struct back {int f_l, f_r, op;} p[N][N];

string S, Ans;

inline void update(int x, int y, int f_x, int f_y, int op = 0) {
	if (f[x][y] < f[f_x][f_y] + (op ? 2 : 0)) {
		f[x][y] = f[f_x][f_y] + (op ? 2 : 0);
		p[x][y] = (back){f_x, f_y, op};
	}
}

int tot = 0, poses[514];

inline void find(int l, int r, int len) {
	if (l > r) return;
	if (l == r) { Ans[tot] = S[l], ++tot; return;} 
	if (p[l][r].op) Ans[tot] = Ans[len - tot - 1] = S[l], ++tot;
	find(p[l][r].f_l, p[l][r].f_r, len);
}

signed main() {
//	freopen("asdasdasd.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> S;
	n = S.length();
	if (n > 2700) {
		REP(i, 0, n - 1) ++poses[S[i]];
		REP(i, 'a', 'z') {
			if (poses[i] >= 100) {
				REP(j, 1, 100) cout << (char)(i);
				cout << '\n';
				return 0;
			}
		} throw runtime_error("fucked ld.");
		return 0;
	}
	
//	cout << S << '\n';
	REP(i, 0, n - 1) f[i][i] = 1;
	REP(len, 2, n) {
		REP(i, 0, n - len) {
			int j = i + len - 1;
			update(i, j, i + 1, j);
			update(i, j, i, j - 1);
			if (S[i] == S[j]) update(i, j, i + 1, j - 1, 1); 
			if (f[i][j] >= 100) {
				Ans.resize(f[i][j]);
				find(i, j, f[i][j]);
				int pos = f[i][j] - 100;
				if (f[i][j] & 1) --pos;
				REP(k, (pos >> 1), f[i][j] - (pos >> 1) - 1) {
					if (f[i][j] & 1 & (k << 1) == f[i][j] - 1) continue;
					cout << Ans[k];
				} cout << '\n';
				return 0;
			}		
		}
	} 
//	REP(i, 0, n - 1) {
//		REP(j, i, n - 1) cout << f[i][j] << ' ';
//		cout << '\n';
//	}
	Ans.resize(f[0][n - 1]);
	find(0, n - 1, f[0][n - 1]);
	cout << Ans << '\n'; 
	return 0;
} 