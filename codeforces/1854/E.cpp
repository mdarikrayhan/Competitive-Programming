// LUOGU_RID: 160492342
#include <bits/stdc++.h>
using namespace std;

namespace SOL {

using i64 = long long;
void debug(const char *msg, ...) {
#ifdef CLESIP
    va_list arg;
    static char pbString[512];
    va_start(arg,msg);
    vsprintf(pbString,msg,arg);
    cerr << "[DEBUG] " << pbString << "\n";
    va_end(arg);
#endif    
}
template<typename T, typename L>
bool chkmax(T &x, L y) { if (x < y) return x = y, true; return false; }
template<typename T, typename L>
bool chkmin(T &x, L y) { if (y < x) return x = y, true; return false; }

const int N = 110;
const int lim = 60;
mt19937 rng(random_device{}());
i64 m, f[N];
int ans[N];

int rand(int l, int r) {
	return uniform_int_distribution<>(l, r)(rng);
}

void solve() {
	cin >> m;
	while (1) {
		for (int i = 0; i <= lim; i ++)
			f[i] = 0;
		f[0] = 1;
		int len = 0;
		while (f[lim] <= m && len + 1 < N) {
			int val = rand(1, 10);
			ans[++ len] = val;
			for (int j = lim; j >= val; j --)
				f[j] += f[j - val];
		}
		if (len > lim)
			continue;
		for (int j = ans[len]; j <= lim; j ++)
			f[j] -= f[j - ans[len]];
		len -= 1;
		while (f[lim] < m) {
			int mx = -1;
			for (int i = 1; i <= lim; i ++) {
				if (f[lim] + f[lim - i] > m)
					continue;
				if (mx == -1 || f[lim - mx] < f[lim - i])
					mx = i;
			}
			assert(mx != -1);
			ans[++ len] = mx;
			for (int i = lim; i >= mx; i --)
				f[i] += f[i - mx];					
		}
		if (len <= lim) {
			cout << len << "\n";
			for (int i = 1; i <= len; i ++)
				cout << ans[i] << " \n"[i == len];

			for (int i = 0; i <= lim; i ++)
				f[i] = 0;
			f[0] = 1;
			for (int i = 1; i <= len; i ++)
				for (int j = lim; j >= ans[i]; j --)
					f[j] += f[j - ans[i]];
			cerr << "sum: " << f[lim] << "\n";
			return;
		}
	}
}

}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	SOL::solve();
	return 0;
}