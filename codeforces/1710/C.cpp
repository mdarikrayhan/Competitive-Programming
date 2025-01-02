// In the name of Allah

#include <bits/stdc++.h>
using namespace std;

typedef		long long int			ll;
typedef		long double				ld;
typedef		pair<int, int>			pii;
typedef		pair<ll, ll>			pll;
typedef		complex<ld>				cld;

#define		all(x)					(x).begin(),(x).end()
#define		len(x)					((ll) (x).size())
#define		F						first
#define		S						second
#define		X						real()
#define		Y						imag()
#define		pb						push_back
#define		sep						' '
#define		endl					'\n'
#define		Mp						make_pair
#define		kill(x)					cout << x << '\n', exit(0)
#define		set_dec(x)				cout << fixed << setprecision(x);
#define		file_io(x,y)			freopen(x, "r", stdin); freopen(y, "w", stdout);

const int maxn = 2e5 + 7;
const int mod = 998244353;

int n; string s;
ll dp[2][8][8];


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> s; n = len(s);
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		int j = (i + 1);
		for (int R1 = 0; R1 < 8; R1++) {
			for (int R2 = 0; R2 < 8; R2++) {
				dp[j & 1][R1][R2] = 0;
			}
		}
		for (int R1 = 0; R1 < 8; R1++) {
			for (int R2 = 0; R2 < 8; R2++) {
				for (int x = 0; x < 8; x++) {
					int S1 = R1, S2 = R2;
					if (s[i] == '1') {
						if (!(x & 1)) S1 |= 1;
						if (!(x & 2)) S1 |= 2;
						if (!(x & 4)) S1 |= 4;
					}
					else {
						if ((x & 1) && !(R1 & 1)) continue;
						if ((x & 2) && !(R1 & 2)) continue;
						if ((x & 4) && !(R1 & 4)) continue;
					}
					if (x != 0 && x != 7) {
						int w = 0;
						if (__builtin_popcount(x) == 1) w = __builtin_ctz(x);
						else w = __builtin_ctz(x ^ 7);
						S2 |= (1 << w);
					}
					dp[j & 1][S1][S2] += dp[i & 1][R1][R2];
					if (dp[j & 1][S1][S2] >= mod) dp[j & 1][S1][S2] -= mod;
				}
			}
		}
	}
	
	ll ans = 0;
	for (int R1 = 0; R1 < 8; R1++) {
		ans += dp[n & 1][R1][7];
		if (ans >= mod) ans -= mod;
	}
	cout << ans << endl;
	
	return 0;
}
