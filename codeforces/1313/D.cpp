// LUOGU_RID: 160100343
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define uint unsigned int
#define reg register
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define qint const int&
#define qll const ll&
#define quint cosnt uint&
#define qull const ull&

const int N = 200010, INF = INT_MAX;
int n, m, k, tot, optID[8], f[256];
pair<int, int> opt[N];

signed main() {
	cin >> n >> m >> k;
	const int nPtr = 1 << k;
	for (int i = 1, l, r; i <= n; ++i) {
		cin >> l >> r;
		opt[++tot] = make_pair(l, i);
		opt[++tot] = make_pair(r + 1, -i);
	}
	sort(opt + 1, opt + tot + 1);
	memset(f, 0x80, sizeof(f));
	f[0] = 0;
	for (int u = 1; u <= tot; ++u) {
		pair<int, int>& p = opt[u];
		int len = (u == tot ? 0 : opt[u + 1].first - opt[u].first), pos = 0;
		if (p.second > 0) {
			for (int i = 0; i < k; ++i) {
				if (!optID[i]) {
					optID[pos = i] = p.second;
					break;
				}
			}
			for (int i = nPtr - 1; i >= 0; --i) {
				if (i >> pos & 1) f[i] = f[i ^ 1 << pos] + len * __builtin_parity(i);
				else f[i] += len * __builtin_parity(i);
			}
		}
		else {
            for (int i = 0; i < k; ++i) {
                if (optID[i] == -p.second) {
                    optID[pos = i] = 0;
                    break;
                }
            }
            for (int i = 0; i < nPtr; ++i) {
                if (i >> pos & 1) f[i] = -INF;
                else f[i] = max(f[i], f[i ^ 1 << pos]) + len * __builtin_parity(i);
            }
        }
	}
	cout << f[0] << endl;
	return 0;
}
