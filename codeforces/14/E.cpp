// LUOGU_RID: 160309990
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int nn = 2000;
#define cle(a,val) memset(a,(val),sizeof(a))
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define red(i,a,b) for(register int i=(a);i>=(b);--i)
#define pii pair<int,int>
#define x first
#define y second
#define mk make_pair
int n, t;
ll res = 0;

ll memo[22][5][3][11][11];

ll dfs(int k, int pre, int flag, int t1, int t2, ll v) {
	if (memo[k][pre][flag][t1][t2] != -1) {
		res += memo[k][pre][flag][t1][t2];
		return memo[k][pre][flag][t1][t2];
	}
	memo[k][pre][flag][t1][t2] = 0;
	if (k == n + 1) {
		if (t1 == t && t2 == t - 1) {
			++res;
			return memo[k][pre][flag][t1][t2] = 1;
		} else
			return memo[k][pre][flag][t1][t2] = 0;
	}
	if (k == 1) {
		rep(i, 1, 4) memo[k][pre][flag][t1][t2] += dfs(k + 1, i, 1, t1, t2, v + 1);
		return memo[k][pre][flag][t1][t2];
	} else {
		if (flag == 1) {
			rep(i, 1, 4) {
				if (i > pre)
					memo[k][pre][flag][t1][t2] += dfs(k + 1, i, 2, t1, t2, v + 1);
				if (i == pre)
					continue;
				if (i < pre)
					memo[k][pre][flag][t1][t2] += dfs(k + 1, i, 0, t1, t2, v + 1);
			}
			return memo[k][pre][flag][t1][t2];
		} else if (flag == 0) {
			rep(i, 1, 4) {
				if (i > pre)
					memo[k][pre][flag][t1][t2] += dfs(k + 1, i, 2, t1, t2 + 1, v + 1);
				if (i == pre)
					continue;
				if (i < pre)
					memo[k][pre][flag][t1][t2] += dfs(k + 1, i, 0, t1, t2, v + 1);
			}
			return memo[k][pre][flag][t1][t2];
		} else {
			rep(i, 1, 4) {
				if (i > pre)
					memo[k][pre][flag][t1][t2] += dfs(k + 1, i, 2, t1, t2, v + 1);
				if (i == pre)
					continue;
				if (i < pre)
					memo[k][pre][flag][t1][t2] += dfs(k + 1, i, 0, t1 + 1, t2, v + 1);
			}
			return memo[k][pre][flag][t1][t2];
		}
	}
}


int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> t;
	memset(memo, -1, sizeof memo);
	ll d = dfs(1, 0, 1, 0, 0, 0);
	cout << res;
	return 0;
}