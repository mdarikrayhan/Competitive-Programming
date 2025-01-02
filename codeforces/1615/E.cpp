#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))
#define sz(x) (int)(x.size())
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
const int mxN = 2e5 + 5;

mt19937 rng((ll)std::chrono::steady_clock::now().time_since_epoch().count());

int n, k;
pi dep[mxN];
int lazy[4 * mxN];
pi s1[4 * mxN];

pi comb(pi a, pi b){
	if(a.fi > b.fi) return a;
	return b;
}

void build(int id = 1, int l = 0, int r = n){
	if((r - l) < 2){
		s1[id] = dep[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build((id << 1) + 1, mid, r);
	s1[id] = comb(s1[id << 1], s1[(id << 1) + 1]);
}
 
void down(int id, int l, int r){
	if(lazy[id]){
		s1[id].fi += lazy[id];
		if((r - l) > 1){
			lazy[id << 1] += lazy[id];
			lazy[(id << 1) + 1] += lazy[id];
		}
	}
	lazy[id] = 0;
}
 
void increase(int x, int y, ll u, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		lazy[id] += u;
		down(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	increase(x, y, u, id << 1, l, mid);
	increase(x, y, u, (id << 1) + 1, mid, r);
	s1[id] = comb(s1[id << 1], s1[(id << 1) + 1]);
}
 
pi maxQ(int x, int y, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return {-1, -1};
	if(x <= l && r <= y) return s1[id];
	int mid = (l + r) / 2;
	return comb(maxQ(x, y, id * 2, l, mid), maxQ(x, y, id * 2 + 1, mid, r));
}

vi g[mxN];
int d[mxN];
int vis[mxN], par[mxN];
int tt = 0;
int st[mxN], en[mxN];

void dfs(int cur, int prev, int cnt = 1){
	d[cur] = 1;
	par[cur] = prev;
	st[cur] = tt++;
	dep[st[cur]] = {cnt, cur};
	for(int x : g[cur]) if(x != prev){
		dfs(x, cur, cnt + 1);
		d[cur] += d[x];
	}
	en[cur] = tt;
}

void solve(){
	cin >> n >> k;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
	int l = 0;
	rep(i, n) if(d[i] == 1) l++;
	if(l <= k){
		ll ans = 0LL;
		repn(i, l, k + 1) ans = max(ans, (ll)(n - i) * (ll)(i));
		cout << ans << '\n';
		return;
	}
	build();
	int tot = 0;
	rep(i, k){
		pi bst = maxQ(st[0], en[0]);
		int uwu = bst.se;
		while(uwu != -1 && !vis[uwu]){
			increase(st[uwu], en[uwu], -1);
			vis[uwu] = 1;
			tot++;
			uwu = par[uwu];
		}
	}
	int b = n - tot;
	ll ans = 1e18;
	rep(i, b + 1){
		ans = min(ans, (ll)(n - k - i) * (ll)(k - i));
	}
	cout << ans << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--) solve();
	return 0;
}