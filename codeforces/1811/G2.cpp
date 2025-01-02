#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define INF 0x3f3f3f3f
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const double epsilon = PI / 180.0;//�Ƕ�ת����

ll powmod(ll a, ll b) {
	ll res = 1;
	a %= mod;
	assert(b >= 0);
	for (; b; b >>= 1) {
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
const int N = 5e3 + 10;


int n, k;
int c[N];
ll f[N][N];
ll sum[N];
ll res1[N][N], res2[N];

int main() {
	int _;
	cin >> _;
	while (_--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> c[i];
		f[0][0] = 1;
		for (int i = 0; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = res1[i][j] = 0;
			}
			sum[i] = res2[i] = 0;
		}
		sum[0] = 1;
		res1[0][0] = 1;
		res2[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = n; j >= 1; j--) {
				if ((j - 1) % k == 0) {
					f[j][c[i]] = (f[j][c[i]] + sum[j - 1]) % mod;
					res1[j][c[i]] = max(res1[j][c[i]], res2[j - 1]);
					sum[j] = (sum[j] + sum[j - 1]) % mod;
					res2[j] = max(res2[j], res2[j - 1]);
				} else {
					f[j][c[i]] = (f[j][c[i]] + f[j - 1][c[i]]) % mod;
					res1[j][c[i]] = max(res1[j][c[i]], res1[j - 1][c[i]]);
					sum[j] = (sum[j] + f[j - 1][c[i]]) % mod;
					res2[j] = max(res2[j], res1[j - 1][c[i]]);
				}

			}
		}
		for (int i = n; i >= 0; i--) {
			if (res2[i] && i % k == 0) {
				cout << sum[i] << "\n";
				break;
			}
		}
	}
	return 0;
}