// LUOGU_RID: 160529631
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define fi first
#define se second
#define pir pair <ll, ll>
#define mkp make_pair
#define pb push_back
using namespace std;
const ll maxn = 2e5 + 10, mod = 998244353;
ll n, a[maxn];
struct SGT {
	ll mn[maxn << 2];
	void modify(ll p, ll l, ll r, ll x, ll v) {
		if(l == r) {
			mn[p] = v;
			return;
		}
		ll mid = l + r >> 1;
		if(x <= mid) modify(p << 1, l, mid, x, v);
		else modify(p << 1|1, mid + 1, r, x, v);
		mn[p] = min(mn[p << 1], mn[p << 1|1]);
	} 
	ll query(ll p, ll l, ll r, ll ql, ll qr) {
		if(ql <= l && r <= qr) return mn[p];
		if(qr < l || r < ql) return n + 1;
		ll mid = l + r >> 1;
		return min(query(p << 1, l, mid, ql, qr),
		query(p << 1|1, mid + 1, r, ql, qr));
	}
} T1, T2;
ll ans, stk[maxn], top;
ll L_dn[maxn], L_up[maxn], R_dn[maxn], R_up[maxn];
bool chk(ll i) {
	return T1.query(1, 1, n, 1, a[i] - 1) >= L_up[i] &&
	T2.query(1, 1, n, a[i] + 1, n) >= L_dn[i];
}
int main() {
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) R_dn[i] = R_up[i] = n + 1;
	for(ll i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		while(top && a[stk[top]] > a[i]) R_dn[stk[top--]] = i;
		if(top) L_dn[i] = stk[top];
		stk[++top] = i;
	}
	top = 0;
	for(ll i = 1; i <= n; i++) {
		while(top && a[stk[top]] < a[i]) R_up[stk[top--]] = i;
		if(top) L_up[i] = stk[top];
		stk[++top] = i;
	}
	for(ll i = 1; i <= n; i++) {
		T1.modify(1, 1, n, i, n + 1);
		T2.modify(1, 1, n, i, n + 1);
	}
	for(ll l = 1, r = 0; l <= n; l++) {
		while(r < n && chk(r + 1)) {
			++r;
			T1.modify(1, 1, n, a[r], R_dn[r]);
			T2.modify(1, 1, n, a[r], R_up[r]);
		}
		ans += r - l + 1;
		T1.modify(1, 1, n, a[l], n + 1);
		T2.modify(1, 1, n, a[l], n + 1);
	}
	printf("%lld", ans);
	return 0;
}