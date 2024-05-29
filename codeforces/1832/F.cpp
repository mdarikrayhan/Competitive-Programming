// LUOGU_RID: 158048334
#include <bits/stdc++.h>

using namespace std;
const int N = 2005; 
typedef long long ll; 
int n, k, x, m, t[N<<2], tl; 
struct node {
	int l, r; 
}a[N];
bool cmp (node a, node b) {
	return a.l+a.r < b.l+b.r; 
}
ll f[N][N<<2], ans, c[N][N<<2];  

int cap (int l, int r, int x, int y) {
	return max(0, min(y, r)-max(x, l)); 
}

ll chk (ll k) {
	memset(f, -0x3f, sizeof f); 
	ans = -1e18; 
	f[0][0] = 0; c[0][0] = 0; 
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= tl;j++) {
			f[i][j] = f[i-1][j]+cap(t[j], t[j]+m, a[i].l, a[i].r); 
			c[i][j] = c[i-1][j]; 
		}
		ll v = -1e18, cnt = 0; 
		for (int j = 0;j <= tl;j++) {
			if (f[i-1][j] > v) v = f[i-1][j], cnt = c[i-1][j]; 
			else if (f[i-1][j] == v) cnt = max(cnt, c[i-1][j]);  
		}
		for (int j = 1;j <= tl;j++) {
			ll dp = v+cap(t[j], t[j]+m, a[i].l, a[i].r)-k; 
			if (dp > f[i][j]) f[i][j] = dp, c[i][j] = cnt+1; 
			else if (dp == f[i][j]) c[i][j] = max(cnt+1, c[i][j]); 
		}
	}
	ll cnt = 0; 
	for (int j = 1;j <= tl;j++) if (f[n][j] > ans) ans = f[n][j], cnt = c[n][j]; else if (f[n][j] == ans) cnt = max(cnt, c[n][j]);  
	return cnt; 
}

int main () {
	cin >> n >> k >> x >> m; ll s = 0; 
	for (int i = 1;i <= n;i++) {
		cin >> a[i].l >> a[i].r; 
		t[++tl] = a[i].r-m; t[++tl] = a[i].l;
		s += x+a[i].l-a[i].r-m;  
	}
	sort(a+1, a+1+n, cmp); 
	sort(t+1, t+1+tl); tl = unique(t+1, t+1+tl)-t-1; 
	ll l = 0, r = 1e9, ct;
	while (l < r) {
		ll mid = l+r+1>>1;
		if (chk(mid) < k) r = mid-1; 
		else l = mid; 
	}
	ll t = chk(l);
	cout << ans+k*l+s; 
	return 0; 
}