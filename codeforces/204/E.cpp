#include <bits/stdc++.h>
using namespace std;


using ll = long long;
#define int ll
#define all(v) (v).begin(), (v).end()
#define pb push_back

void dbg_out() { cerr << endl; }
template<typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) //{ cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

template <typename T>
struct Bit {
	vector<T> bit;
	Bit(int sz): bit(sz) {}
	void update(int id, T val) {
		for(id++;id<=(int)bit.size();id+=id&-id) bit[id-1]+=val;
	}
	T query(int id) {
		T sum = 0;
		for(id++;id>0;id-=id&-id) sum+=bit[id-1];
		return sum;
	}
	T query_range(int l, int r) {
		return query(r) - query(l - 1);
	}
};

struct SuffixArray {
	string s;
	vector<int> sa, lcp;
	SuffixArray() {}
	SuffixArray(string v, int lim=256) {
		s = v;
		int n = s.size(), k = 0, a, b;
		vector<int> x(all(s) + 1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y; iota(all(sa), 0);
		for(int j = 0, p = 0; p < n; j = max<int>(1, j * 2), lim = p) {
			p = j; iota(all(y), n - j);
			for(int i = 0; i < n;i++) if(sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			for(int i=0;i<n;i++) ws[x[i]]++;
			for(int i=1;i<lim;i++) ws[i] += ws[i-1];
			for(int i=n;i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y); p = 1; x[sa[0]] = 0;
			for(int i=1;i<n;i++) a = sa[i-1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a+j] == y[b+j]) ? p - 1 : p++;
		}
		for(int i=1;i<n;i++) rank[sa[i]] = i;
		for(int i=0, j; i < n - 1; lcp[rank[i++]] = k)
			for(k && k--, j = sa[rank[i] - 1]; s[i+k] == s[j+k]; k++);
		lcp.erase(lcp.begin());
	}
};

template<typename T> struct RMQ {
	vector<vector<T>> dp;
	T ops(T a, T b) { return min(a, b); }
	RMQ(vector<T> v) {
		int n = v.size();
		int log = 32 - __builtin_clz(n);
		dp.assign(log, vector<T>(n));
		copy(all(v), dp[0].begin());
		for(int l = 1; l < log; l++) for(int i=0;i<n;i++) {
			auto &cur = dp[l], &ant = dp[l-1];
			cur[i] = ops(ant[i], ant[min(i+(1<<(l-1)), n - 1)]);
		}
	}
	T query(int a, int b) {
		if(a == b) return dp[0][a];
		int p = 31 - __builtin_clz(b-a);
		auto &cur = dp[p];
		return ops(cur[a], cur[b-(1<<p)+1]);
	}
};

void solve() {
	int n, k; cin >> n >> k;

	string s;
	vector<int> apos(n), alen(n);
	for(int i=0;i<n;i++) {
		string a; cin >> a;
		apos[i] = s.size();
		alen[i] = a.size();
		s += a;
		s += '$';
	}
	s += '!';
	SuffixArray suffix_array(s);
	vector<int> sa = suffix_array.sa;
	const int sz = sa.size();
	vector<int> lcp = suffix_array.lcp;
	RMQ rmq(lcp);
	vector<int> pos(sz);
	for(int i=0;i<int(sz);i++) pos[sa[i]] = i;
	vector<int> own(sz, -1);

	vector<vector<int>> occ(n);
	for(int a_id=0;a_id<n;a_id++) {
		for(int i = apos[a_id]; i < apos[a_id] + alen[a_id]; i++) {
			occ[a_id].pb(pos[i]);
			own[pos[i]] = a_id;
		}
		sort(all(occ[a_id]));
	}

	Bit<int> freq(sz + 1), double_freq(sz + 1);
	vector<int> occ_ptr(n);
	for(int a_id=0;a_id<n;a_id++) {
		occ_ptr[a_id] = 0;
		freq.update(occ[a_id][0], 1);
		dbg(occ[a_id][0], 1);
	}

	auto reach = [&](int id, int cur_sz) {
		int sl, sr;
		{
			int lo = 0, hi = id;
			while(lo < hi) {
				int mid = (lo + hi) / 2;
				if(rmq.query(mid, id - 1) >= cur_sz) hi = mid;
				else lo = mid + 1;
			}
			sl = lo;
		}
		{
			int lo = id, hi = sz - 1;
			while(lo < hi) {
				int mid = (lo + hi + 1) / 2;
				if(rmq.query(id, mid - 1) >= cur_sz) lo = mid;
				else hi = mid - 1;
			}
			sr = lo;
		}
		return pair<int,int>(sl, sr);
	};

	vector<int> ans(n);
	for(int p = 0; p < sz; p++) {
		int a_id = own[p];
		if(a_id == -1) continue;
		assert(occ[a_id][occ_ptr[a_id]] == p);
		assert(freq.query_range(p, p) == 1);
		if(occ_ptr[a_id] != 0) {
			int prv = occ[a_id][occ_ptr[a_id]-1];
			int cur = occ[a_id][occ_ptr[a_id]];
			freq.update(prv, -1);
			dbg(prv, -1);
			double_freq.update(rmq.query(prv, cur - 1), -1);
		}
		if(occ_ptr[a_id] + 1 < occ[a_id].size()) {
			int cur = occ[a_id][occ_ptr[a_id]];
			int nxt = occ[a_id][occ_ptr[a_id] + 1];
			freq.update(nxt, 1);
			dbg(nxt, 1);
			double_freq.update(rmq.query(cur, nxt - 1), 1);
		}
		occ_ptr[a_id]++;

		assert(apos[a_id] <= sa[p] && sa[p] < apos[a_id] + alen[a_id]);
		int lo = 0, hi = alen[a_id] - (sa[p] - apos[a_id]);

		dbg(p);
		while(lo < hi) {
			int mid = (lo + hi + 1) / 2;
			auto [l, r] = reach(p, mid);
			int diff = freq.query_range(l, r) - double_freq.query_range(mid, sz-1);
			dbg(p, diff, mid, l, r);
			dbg(freq.query_range(l, r));
			dbg(double_freq.query(mid));
			if(diff >= k) lo = mid;
			else hi = mid - 1;
		}
		dbg(a_id, lo, sa[p] - apos[a_id]);
		ans[a_id] += lo;
	}

	for(int i=0;i<n;i++) cout << ans[i] << " \n"[i==n-1];
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solve();
}

		    	 		 	 			 	 		 		   		 	