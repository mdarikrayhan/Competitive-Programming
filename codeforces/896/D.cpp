// LUOGU_RID: 160328739
/*
*/
#include <bits/stdc++.h>
using namespace std;
long long a[20];
long long f[100010][20];
long long cnt = 0;
long long n, mod, l, r, e;
inline long long qmi(long long a, long long b) {
	long long ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}
inline void F(int x) {
	for(int i = 2; i <= x / i; i++){
		if(x % i == 0) {
			a[++cnt] = i;
			while(x % i == 0)  x /= i;
		}
	}
	if(x > 1) a[++cnt] = x;
}
inline long long cnm(int n, int m) {
	if(m > n) return 0;
	long long ret = f[n][0] * qmi(f[m][0], e - 1) % mod * qmi(f[n - m][0], e - 1) % mod;
	for(int i = 1; i <= cnt; i++) for(int j = 1; j <= f[n][i] - f[m][i] - f[n - m][i]; j++) ret = ret * a[i] % mod;
	return ret;
}
int main(){
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n >> mod >> l >> r;
	F(mod);
	e = mod;
	for(int i = 1; i <= cnt; i++) e = e / a[i] * (a[i] - 1);
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		int tmp = i;
		for(int j = 1; j <= cnt; j++) {
			f[i][j] += f[i - 1][j];
			while(tmp % a[j] == 0) ++f[i][j], tmp /= a[j];
		}
		f[i][0] = f[i - 1][0] * tmp % mod;
		
	}
	long long ans = 0;
	for(int i = 0; i <= n; i++) ans = (ans + cnm(n, i) * (cnm(i, (l + i + 1) / 2) - cnm(i, (r + i) / 2 + 1) + mod) % mod) % mod;
	cout << ans << endl;

	return 0;
}
