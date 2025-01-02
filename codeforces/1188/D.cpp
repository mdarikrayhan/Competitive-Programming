#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5, M = 62; 
typedef long long ll; 
int n, o[M][N], op; 
ll a[N], f[M][N], b[N]; 

bool cmp (int x, int y) {
	return (a[x]&((1ll<<op)-1)) > (a[y]&((1ll<<op)-1)); 
}

int main () {
	cin >> n; ll m = 0;  
	for (int i = 1;i <= n;i++) cin >> a[i], m = max(m, a[i]); 
	for (int i = 1;i <= n;i++) a[i] = m-a[i]; 
	ll ans = 1e18; memset(f, 0x3f, sizeof f);   
	for (int i = 0;i < M;i++) {
		for (int j = 1;j <= n;j++) o[i][j] = j; 
		op = i+1; 
		sort(o[i]+1, o[i]+1+n, cmp); 
	}
	for (int i = 0;i < M;i++) {
		int s = 0; 
		for (int j = 1;j <= n;j++) b[j] = a[j]>>i, s += (a[j]>>i&1);  
		if (!i) {
			f[0][0] = 0; 
			for (int j = 1;j <= n;j++) if (a[j]&1) f[0][0]++;  
			f[0][f[0][0]] = min(f[0][f[0][0]], n-f[0][0]); 
			continue; 
		}
		int c = 0, c2 = 0; 
		for (int j = 0;j <= n;j++) {
			if (j) {
				if (b[o[i-1][j]]&1) c++; 
				else c2++; 
			}
			f[i][c] = min(f[i][c], f[i-1][j]+s-c+c2); 
			f[i][s+c2] = min(f[i][s+c2], f[i-1][j]+c+n-s-c2); 
		}
	} 
	cout << f[M-1][0]; 
	return 0; 
} 
