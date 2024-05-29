#include<bits/stdc++.h>
using std::cin;
using std::cout;
using ll = long long;
using u64 = unsigned long long;
void IOinit() {
	std::ios::sync_with_stdio(false), cin.tie(0);
#ifdef zqj
	freopen("$.in", "r", stdin);
#endif
}
const int N = 50005;
const int V = 50000;
using pr = std::pair<int, int>;
std::vector<int> d[N];
struct ds {
	std::vector<int> st[20];
	std::vector<int> pos;
	ds() { st -> push_back(0); }

	void init() {
		int n = pos.size();
		for(int i = 1;1 << i <= n;++i) {
			st[i].resize(n - (1 << i) + 2);
			for(int j = 1;j + (1 << i) - 1 <= n;++j) {
				st[i][j] = std::min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}
	int qmin(int l, int r) {
		l = lower_bound(pos.begin(), pos.end(), l) - pos.begin() + 1;
		r = upper_bound(pos.begin(), pos.end(), r) - pos.begin();
		if(l > r) return 1e9;
		const int lg = std::__lg(r - l + 1);
		return std::min(st[lg][l], st[lg][r - (1 << lg) + 1]);
	}
} pb[N];
int n, q;
int a[N], b[N];
using ll = long long;
ll qmin(int w, int l, int r) {
	if(r - l <= 80) {
		ll ans = 1e18;
		for(int i = l;i <= r;++i) {
			int gcd = std::gcd<unsigned>(w, b[i]);
			ans = std::min(ans, (ll) w * b[i] / gcd / gcd);
		}
		return ans;
	}
	ll ans = 1e18;
	for(int x : d[w]) {
		if(w / x >= ans) {
			break;
		}
		int min = pb[x].qmin(l, r);
		if(min <= V) {
			ans = std::min(ans, (ll) w * min / x / x);
		}
	}
	assert(ans > 0);
	return ans;
}
struct seg {
	ll min[N << 2]; int L;
	void init(int n) {
		L = 2 << std::__lg(n + 1);
	}
	void upt(int p, ll v) {
		for(min[p += L] = v;p >>= 1;)
			min[p] = std::min(min[p << 1], min[p << 1 | 1]);
	}
	ll qry(int l, int r) {
		l += L - 1;
		r += L + 1;
		ll ans = 1e18;
		for(;l ^ r ^ 1;l >>= 1, r >>= 1) {
			if((l & 1) == 0) ans = std::min(ans, min[l ^ 1]);
			if((r & 1) == 1) ans = std::min(ans, min[r ^ 1]);
		}
		return ans;
	}
} sgt;
std::map<int, int> map;
using IT = std::map<int, int>::iterator;
IT split(int p, int s = 3) {
	auto iter = map.lower_bound(p);
	if(iter -> first == p) return iter;
	auto A = prev(iter);
	auto B = map.emplace_hint(A, p, A -> second);

	if(s & 1) sgt.upt(A -> first, qmin(A -> second, A -> first, next(A) -> first - 1));
	if(s & 2) sgt.upt(B -> first, qmin(B -> second, B -> first, next(B) -> first - 1));

	return B;
}
int main() {
	IOinit();
	for(int i = V;i >= 1;--i) {
		for(int j = i;j <= V;j += i) {
			d[j].push_back(i);
		}
	}
	cin >> n >> q;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		map[i] = a[i];
	}
	map[n + 1] = 0;
	for(int i = 1;i <= n;++i) {
		cin >> b[i];
		for(int x : d[b[i]]) {
			pb[x].pos.push_back(i);
			pb[x].st -> push_back(b[i]);
		}
	}
	for(int i = 1;i <= V;++i) {
		pb[i].init();
	}
	sgt.init(n);
	for(int i = 1;i <= n;++i) 
		sgt.upt(i, qmin(a[i], i, i));
	for(int i = 1, t, l, r;i <= q;++i) {
		cin >> t >> l >> r;
		if(t == 2) {
			split(r + 1);
			ll ans = sgt.qry(l, r);
			auto iter = map.lower_bound(l);
			if(iter -> first > l) {
				ans = std::min(ans, qmin(prev(iter) -> second, l, iter -> first - 1));
			}
			cout << ans << '\n';
		} else {
			int x; cin >> x;
			auto R = split(r + 1, 2);
			auto L = split(l, 1);
			for(auto i = L;i != R;++i) {
				sgt.upt(i -> first, 1e18);
			}
			map.erase(L, R);
			map[l] = x;
			sgt.upt(l, qmin(x, l, r));
		}
	}
}
