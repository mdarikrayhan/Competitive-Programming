#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define ull unsigned long long 
#define i128 __int128
using namespace std; 
const int N = 2e5 + 7, mod = 998244353;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
inline int sgn(int x) {
	return (x & 1) ? mod - 1 : 1;
}

ll n, k;

const int L = 1e5, block = 320;
int H[L / block + 7][L * 2 + 7];
int f[block + 5][block * 2 + 5];

void preslv() {
	f[0][0] = 1;
	L(i, 0, block - 1) {
		L(j, 0, i * 2) {
			(f[i + 1][j] += f[i][j]) %= mod;
			(f[i + 1][j + 1] += f[i][j]) %= mod;
			(f[i + 1][j + 2] += f[i][j]) %= mod;
		}
	}
	L(i, 0, L / block) {
		int M = i * block;
		H[i][0] = 1, H[i][1] = M;
		L(j, 2, L * 2) {
			H[i][j] = ((ll)H[i][j - 1] + H[i][j - 2] * 2) % mod * M % mod;
			(H[i][j] += mod - (ll) H[i][j - 1] * (j - 1) % mod) %= mod;
			(H[i][j] += mod - (ll) H[i][j - 2] * (j - 2) % mod) %= mod;
			H[i][j] = (ll)H[i][j] * inv[j] % mod;
		}
	}
}

inline int suan(int x, int y) {
	if(!(0 <= y && y <= x * 2)) return 0;
	int ans = 0;
	int t = x / block;
	int c = x % block;
	L(i, 0, min(y, c * 2)) {
		(ans += (ll)f[c][i] * H[t][y - i] % mod) %= mod;
	}
	return ans;
}
inline int brute(int x, int y) {
	if(!(0 <= y && y <= x * 2)) return 0;
	int ans = 0;
	L(i, 0, x) {
		L(j, 0, x - i) {
			if(i + j * 2 == y) {
				(ans += (ll)C(x, i) * C(x - i, j) % mod) %= mod;
			}
		}
	}
	return ans;
}
void Main() {
	cin >> n >> k;
	if(k * 2 >= n) {
		cout << 0 << ' ' << C(k - 1, n - k - 1) << '\n';
	} else {
		k *= 2;
		ll ls = n / k;
		int md = n % k;
		cout << ls * (ls - 1) / 2 * (k - md) + ls * (ls + 1) / 2 * md << ' ';
		k /= 2;
		int ans = 0;
		L(i, 0, 2)  {
			(ans += (ll)suan(k - 1, md - i) * C(2, i) % mod) %= mod;
		} 
		cout << ans << '\n';
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init(N - 3);
	preslv();
//	cout << suan(2233, 3333) << ' ' << brute(2233, 3333) << endl;
//	cout << H[2][233] << ' ' << suan(block * 2, 233) << endl;
	int t; cin >> t; while(t--) Main();
	return 0;
}
