#include <bits/stdc++.h>
namespace std {
    template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T,U>& p) { return os << p.first << ' ' << p.second; }
    template<typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) { return apply([&](auto&&... args){ ((os << args << ' '), ...); }, t), os; }
    template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) { for (auto& e : v) os << e << ' '; return os; }
    template<typename T, typename U> istream& operator>>(istream& is, pair<T,U>& p) { return is >> p.first >> p.second; }
    template<typename... Args> istream& operator>>(istream& is, tuple<Args...>& t) { return apply([&](auto&&... args){ ((is >> args), ...); }, t), is; }
    template<typename T> istream& operator>>(istream& is, complex<T>& v) { T x; is >> x; v.real(x); is >> x; v.imag(x); return is; }
    template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (auto& e : v) is >> e; return is; }
    template<typename T> bool operator<(const complex<T>& a, const complex<T>& b) { return pair{a.real(), a.imag()} < pair{b.real(), b.imag()}; }
}
using namespace std;
template<typename T> ostream& operator,(ostream& os, const T& x) { return os << x << ' '; }
using num = long long;
using ull = unsigned long long;
using seq = vector<num>;
using bits = vector<char>;
template<typename T> using Table = vector<vector<T>>;
#define dbg(a) cerr << (#a) << " = " << (a) << endl
#define rep(a, b) for (num a = 0; a < (b); ++a)
#define all(a) begin(a), end(a)
constexpr num operator ""_e(unsigned long long x) { num ans = 1; rep(i, static_cast<num>(x)) ans *= 10; return ans; }
mt19937 rng(static_cast<unsigned>(chrono::steady_clock::now().time_since_epoch().count()));

struct TwoSat {
	vector<pair<int,int>> e;
	int n;

	TwoSat(int n) : n(n) { e.reserve(83'200'000); }

	void either(int a, int b) {
		e.emplace_back(max(2 * a, 2 * ~a + 1), max(2 * b, 2 * ~b + 1));
	}

	vector<int> solve() {
		vector<int> s(2 * n + 1), q(2 * size(e)), ans(n, -1), z;
		for (const auto& [a, b] : e)
			s[a]++, s[b]++;
		partial_sum(all(s), begin(s));
		for (const auto& [a, b] : e)
			q[--s[a]] = b ^ 1, q[--s[b]] = a ^ 1;
		function<bool(int)> dfs = [&] (int u) {
			z.push_back(u / 2);
			ans[u / 2] = u % 2;
			for (int i = s[u]; i < s[u + 1]; i++)
				if (ans[q[i] / 2] == -1 ? dfs(q[i]) : ans[q[i] / 2] != q[i] % 2)
					return true;
			return false;
		};
		rep(i, n) {
			if (ans[i] == -1) {
				z.clear();
				if (dfs(2 * i)) {
					for (int x : z)
						ans[x] = -1;
					if (dfs(2 * i + 1))
						return {};
				}
			}
		}
		return ans;
	}

	void atMostOne(const vector<int>& v) {
		if (size(v) > 1)
			either(~v[0], ~v[1]);
		for (int i = 1, p = v[0]; i + 1 < ssize(v); i++, p = n++) {
			either(~p, n);
			either(~v[i], n);
			either(~n, ~v[i+1]);
		}
	}

	void force(int a) { either(a, a); }
	void implies(int a, int b) { either(~a, b); }
};

template<typename T, typename cmp = less<>> // less => max, greater => min
struct OpSparseTable {
    Table<T> m;

    OpSparseTable(const vector<T>& a) : m(bit_width(size(a)), vector<T>(size(a))) {
        if (!empty(a)) m[0].assign(all(a)); // !empty check specifically added for LCA which may construct an empty ST
        rep(l, ssize(m) - 1)
            for (num i = 0; i + (2 << l) <= ssize(a); i++)
                m[l+1][i] = max(m[l][i], m[l][i + (1 << l)], cmp{});
    }

    T query(int l, int r) const {
        auto t = bit_width(unsigned(r - l)) - 1;
        return max(m[t][l], m[t][r - (1 << t)], cmp{});
    }
};

struct LCA {
    int t = 0;
    vector<int> d, o, r, q, p;
    OpSparseTable<int, greater<>> st;
    LCA(const Table<int>& adj, int root = 0) : d(size(adj)), q(d), p(d), st((dfs(root, adj), r)) {}

    void dfs(int u, const Table<int>& adj) {
        q[u] = t++;
        for (int v : adj[u])
            if (v != p[u])
                p[v] = u, d[v] = d[u] + 1, o.push_back(u), r.push_back(q[u]), dfs(v, adj);
    }

    int query(int u, int v) const {
        if (u == v)
            return u;
        if (q[u] > q[v])
            swap(u, v);
        return o[st.query(q[u], q[v])];
    }

    int dist(int u, int v) const {
        return d[u] + d[v] - 2 * d[query(u, v)];
    }

    // Only for virtual tree
    // Computes virtual tree in O(k log k).
    // Children are stored in aux (overwrites previous calls). Returns root of virtual tree.
//    Table<int> aux{Table<int>(size(d))};
//    int virtualTree(vector<int> a) {
//        int k = size(a);
//        assert(k);
//        ranges::sort(a, {}, [&] (int x) { return q[x]; });
//        rep(i, k - 1) a.push_back(query(a[i], a[i + 1]));
//        ranges::sort(a, {}, [&] (int x) { return q[x]; });
//        a.erase(unique(all(a)), end(a));
//        stack<int> s{{a[0]}};
//        for (int x : a) {
//            while (query(s.top(), x) != s.top())
//                s.pop();
//            aux[s.top()].push_back(x);
//            aux[x].clear();
//            s.push(x);
//        }
//        return a[0];
//    }
};

auto solve() {
    num n, q;
    cin >> n >> q;
    Table<int> adj(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    LCA lca(adj);
    TwoSat ts(2 * n + q);
    rep(i, n)
        ts.either(~(2 * i), ~(2 * i + 1));
    vector<vector<char>> meaning(n);
    rep(i, q) {
        num x, y;
        string s;
        cin >> x >> y >> s;
        --x, --y;
        vector<int> px, yp;
        while (x != lca.query(x, y))
            px.push_back(exchange(x, lca.p[x]));
        px.push_back(x);
        while (y != x)
            yp.push_back(exchange(y, lca.p[y]));
        px.insert(end(px), rbegin(yp), rend(yp));
        for (int j = 0; j < ssize(s); j++) {
            for (auto [z, u] : {pair{s[j], 2 * n + i}, {s[ssize(s) - j - 1], ~(2 * n + i)}}) {
                if (ssize(meaning[px[j]]) < 2)
                    meaning[px[j]].push_back(z);
                if (auto it = find(all(meaning[px[j]]), z); it != end(meaning[px[j]])) {
                    ts.implies(u, 2 * px[j] + (it - begin(meaning[px[j]])));
                } else
                    ts.force(~u);
            }
        }
    }
    auto ans = ts.solve();
    if (empty(ans))
        return void(cout << "NO\n");
    cout << "YES\n";
    rep(i, n) {
        if (empty(meaning[i])) cout << 'z';
        else cout << meaning[i][!ans[2*i]];
    }
}

constexpr bool MULTI{false};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    if (MULTI) cin >> t;
    while (t--)
        cout, solve(), '\n';
    return 0;
}
