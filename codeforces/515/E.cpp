#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld double
#define pb push_back
#define pf push_front
#define vi vector<ll>
#define vll vector<vi>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define all(a) a.begin(), a.end()
#define fi first
#define se second
using namespace std;
const ll mod = 1e9+7;
const ll inf = 1e18;
const ll base = 31;
const ll blocksz = 320;
const ll N = 2e5+8;
const ll buff = 1e6+8;
ll n,d[N],h[N],q,pre[N],a[N],b[N];
struct node {
	long long mx_a, mx_b, ans;
	node() {}
	node(long long _a, long long _b, long long _ans) : mx_a(_a), mx_b(_b), ans(_ans) {}
} st[N<<2];
 
const node dumb = node(-inf, -inf, -inf);
 
node res;
node merge(node& l, node& r) {
	res.mx_a = max(l.mx_a, r.mx_a); res.mx_b = max(l.mx_b, r.mx_b);
	res.ans = max({l.mx_b + r.mx_a, l.ans, r.ans});
	return res;
}
void build(ll id, ll l, ll r) {
	if (l == r) {st[id] = node(a[l], b[l], -inf); return;}
	ll mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	st[id] = merge(st[id * 2], st[id * 2 + 1]);
}
 
node get(ll id, ll l, ll r, ll u, ll v) {
	if (v < l || u > r) return dumb;
	if (u <= l && v >= r) return st[id];
	ll mid = (l + r) / 2;
	node opt1 = get(id * 2, l, mid, u, v);
	node opt2 = get(id * 2 + 1, mid + 1, r, u, v);
	return merge(opt1, opt2);
}
void solve(){
	cin >> n >> q;
	for (ll i = 1; i <= n; ++i) cin >> d[i];
	for (ll i = 1; i <= n; ++i) cin >> h[i];
	for (ll i = n + 1; i <= n + n; ++i) d[i] = d[i - n], h[i] = h[i - n];
	for (ll i = n + n; i; --i) d[i + 1] = d[i];
	d[1] = d[n + n + 1];
	for (ll i = 1; i <= n + n; ++i) pre[i] = pre[i - 1] + d[i];
	for (ll i = 1; i <= n + n; ++i) a[i] = pre[i] + 2 * h[i], b[i] = 2 * h[i] - pre[i];
	build(1, 1, n + n);
	while (q--) {
		ll l,r;cin >> l >> r;
		if (l > r) cout << get(1, 1, n + n, r + 1, l - 1).ans << '\n';
		else cout << get(1, 1, n + n, r + 1, l + n - 1).ans << '\n';
	}
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("test.inp","r")){
        freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
    }
    ll T = 1;
    // cin >> T;
    while(T--){
        solve();
        cout << '\n';
    }
}