#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define pb emplace_back

#define AI(i) begin(i), end(i)

template<class T> bool chmin(T &a, T b) { return b < a && (a = b, true); }

template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); }

#ifdef KEV

#define DE(args...) kout("[ " + string(#args) + " ] = ", args)

void kout() { cerr << endl; }

template<class T, class ...U> void kout(T a, U ...b) { cerr << a << ' ', kout(b...); }

template<class T> void debug(T l, T r) { while (l != r) cerr << *l << " \n"[next(l)==r], ++l; }

#else

#define DE(...) 0

#define debug(...) 0

#endif

// My bug list :

// integer overflow

// 0based, 1based forgotten

// index out of bound

// n, m, i, j typo

// some cases are missing



const int MAX_N = 300010, p = 998244353, inf = 1e9 + 10, MAX_K = 19;



vector<pair<int,int>> proc(vector<pair<int,int>> seg) {

	sort(AI(seg), [&](auto a, auto b) {

		return make_pair(-a.first, a.second) < make_pair(-b.first, b.second);

	});

	int m = seg.size();

	int r_bound = inf;

	vector<pair<int,int>> res;

	for (auto [l, r] : seg) {

		if (r >= r_bound) continue;

		r_bound = r;

		res.pb(l, r);

	}

	for (auto [al, ar] : res) DE(al, ar);

	return res;

}





vector<int> edge[MAX_N];

int in[MAX_N], out[MAX_N], dep[MAX_N];

bool isanc(int a, int b) {

	return in[a] <= in[b] && out[a] >= out[b];

}



void dfs(int x, int d = 1) {

	static int t;

	in[x] = ++t;

	dep[x] = d;

	for (int u : edge[x])

		dfs(u, d+1);

	out[x] = ++t;

}

void solve(vector<int> lb, vector<int> rb, vector<tuple<int,int,int>> allq) {



	vector<int> res(allq.size());



	int n = lb.size();



	lb.pb(inf), rb.pb(inf+10);

	for (int i = 0;i < n;++i)

		assert(lb[i] < rb[i]);



	vector<int> rmost(n);

	int cr = inf;

	for (int i = n-1, j = n;i >= 0;--i) {

		while (j >= 0 && lb[j-1] > rb[i]) --j;

		if (j > i+1)

			edge[j].pb(i);



		if (lb[i+1] > rb[i]) cr = rb[i];

		rmost[i] = cr;

	}



	for (int i = n;i >= 0;--i) if (!dep[i])

		dfs(i);



	auto qry = [&](int l, int r) {

		DE(l, r);

		int x = lower_bound(AI(lb), l) - begin(lb);

		int y = lower_bound(AI(rb), r) - begin(rb);

		if (lb[x] != l || rb[y] != r) return 0;

		if (x == y) return -1;

		if (x > y) return 0;

		if (rmost[x] < r) return 0;

		if (lb[x+1] > rb[x]) return 0;

		if (isanc(y, x) && isanc(y, x+1)) return 0;

		if (isanc(y, x)) return -1;

		if (isanc(y, x+1)) return 1;

		return 0;

	};

	for (auto [l, r, id] : allq) {

		ll res = qry(l, r);

		if (res < 0) res += p;

		cout << res << '\n';

	}



}



int32_t main() {

	ios_base::sync_with_stdio(0), cin.tie(0);



	int m, q;

	cin >> m >> q;



	vector<pair<int,int>> seg(m);

	for (auto &[l, r] : seg) cin >> l >> r;

	vector<tuple<int,int,int>> allq(q);

	for (int i = 0;i < q;++i) {

		auto &[l, r, id] = allq[i];

		id = i;

		cin >> l >> r;

	}



	seg = proc(seg);



	m = seg.size();



	sort(AI(seg));



	vector<int> lb, rb;

	for (auto [l, r] : seg) lb.pb(l), rb.pb(r);

	

	solve(lb, rb, allq);



}



