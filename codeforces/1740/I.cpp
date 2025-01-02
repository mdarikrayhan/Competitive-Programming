#include <bits/stdc++.h>

namespace IO {
	template <class Stream>
	void write_int128(Stream& out, __int128 v) {
		if (v >= 10) {
			write_int128(out, v / 10);
		}
		out << (int) (v % 10);
	}

	template <class Stream>
	Stream& fmtbase(Stream& out, const char* format) {
		for (; *format; format++) {
			if (*format == '{' && *(format + 1) == '}') {
				throw std::invalid_argument("Error Number of Parameters!");
			}
			
			out << *format;
		}
		
		return out;
	}
	
	template <class Stream, class... Nxt>
	Stream& fmtbase(Stream& out, const char* format, const __int128& value, const Nxt&... nxt) {
		for (; *format; format++) {
			if (*format == '{' && *(format + 1) == '}') {
				write_int128(out, value);
				return fmtbase(out, format + 2, nxt...);
			} 
			
			out << *format;
		}
		
		throw std::invalid_argument("Error Number of Parameters!");
	}

	template <class Stream, class Fst, class... Nxt>
	Stream& fmtbase(Stream& out, const char* format, const Fst& value, const Nxt&... nxt) {
		for (; *format; format++) {
			if (*format == '{' && *(format + 1) == '}') {
				out << value;
				return fmtbase(out, format + 2, nxt...);
			} 
			
			out << *format;
		}
		
		throw std::invalid_argument("Error Number of Parameters!");
	}
	
	template <class... Ps>
	std::string to_string(const char* format, const Ps&... ps) {
		std::stringstream ss;
		fmtbase(ss, format, ps...);
		return ss.str();
	}

	template <class... Ps>
	std::ostream& fmtout(const char* format, const Ps&... ps) {
		return fmtbase(std::cout, format, ps...);
	}
	
	template <class... Ps>
	std::ostream& fmterr(const char* format, const Ps&... ps) {
		return fmtbase(std::cerr, format, ps...);
	}
	
	std::istream& allin() {
		return std::cin;
	}
	
	template <class Fst, class ... Nxt>
	std::istream& allin(Fst& fst, Nxt&... nxt) {
		std::cin >> fst;
		return allin(nxt...);
	}
	
	template <class Iter>
	std::istream& rangin(Iter begin, Iter end) {
		while (begin != end) {
			std::cin >> *begin;
			begin++;
		}
		
		return std::cin;
	}
	
	namespace Fast {
		bool sync = false;
		
		char buf[1 << 23];
		char *p1 = buf, *p2 = buf;
		
		void sync_with_ios(bool s) {
			sync = s;
		}
		
		inline char getchar() {
			if (sync) {
				return (char) std::cin.get();
			}
			else {
				return (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, 1 << 22, stdin)), p1 == p2 ? EOF : *p1++;
			}
		}
		
		void read() { }
		
		template <class T, class... U>
		void read(T& x, U&... us) {
			x = 0;
			T pos = 1;
			
			char c = getchar();
			while (!isdigit(c)) {
				if (c == '-') {
					pos = -1;
				}
				
				c = getchar();
			}
			
			while (isdigit(c)) {
				x = 10 * x + c - '0';
				c = getchar();
			}
			
			x *= pos;
			read(us...);
		}
		
		template <class T>
		void write(const T& t) {
			if (t > 10) {
				write(t / 10);
			}
			
			std::cout << (int) (t % 10);
		}
	}
}

namespace Solve {
	using namespace IO;

	using ll = long long;
	using ul = unsigned long long;
	using db = double;
	using ld = long double;
	using ui = unsigned;
	using ib = __int128;
	using ub = __uint128_t;

	int const INF = std::numeric_limits<int>::max();
	int const NINF = std::numeric_limits<int>::min();
	ll const LINF = std::numeric_limits<ll>::max();
	ll const LNINF = std::numeric_limits<ll>::min();
	ld const EPS = 1e-8;

	std::mt19937_64 mt;

	ll rnd(ll l, ll r) {
		return std::uniform_int_distribution<ll>(l, r)(mt);
	}

	template <class T>
	inline int isz(const T& v) {
		return v.size();
	}

	template <class T>
	inline T& ckmx(T& a, T b) {
		return a < b ? (a = b) : a;
	}

	template <class T>
	inline T& ckmi(T& a, T b) {
		return b < a ? (a = b) : a;
	}

	int gcd(int n, int m) {
		return !m ? n : gcd(m, n % m);	
	}

	int const N = 2e6 + 10;

	struct Val {
		int a, b; // a * x0 + b

		friend Val operator+(const Val& a, const Val& b) {
			return { a.a + b.a, a.b + b.b };
		}

		friend Val operator-(const Val& a, const Val& b) {
			return { a.a - b.a, a.b - b.b };
		}
	};

	struct Segment {
		int k, b;

		int calc(int x) const {
			return k * x + b;
		}
	};

	struct Line {
		int l, r;
		Val v;
	};

	struct SegTree {
		struct Node {
			int ls, rs;
			Segment seg;
		};

		Node nd[2 * N + 1];
		int tot;

		int create() {
			tot++;
			nd[tot] = { 0, 0, { 0, INF } };
			return tot;
		}

		void update(int& x, Segment seg, int l, int r, int L, int R) {
			if (R < l || L > r) {
				return;
			}
			if (!x) {
				x = create();
			}
			if (L >= l && R <= r) {
				bool cl = seg.calc(L) < nd[x].seg.calc(L);
				bool cr = seg.calc(R) < nd[x].seg.calc(R);
				if (cl && cr) {
					nd[x].seg = seg;
				}
				else if (cl || cr) {
					int mid = (L + R) >> 1;
					if (seg.calc(mid) < nd[x].seg.calc(mid)) {
						std::swap(seg, nd[x].seg);
					}
					if (seg.k < nd[x].seg.k) {
						update(nd[x].rs, seg, l, r, mid + 1, R);
					}
					else {
						update(nd[x].ls, seg, l, r, L, mid);
					}
				}
			}
			else {
				int mid = (L + R) >> 1;
				update(nd[x].ls, seg, l, r, L, mid);
				update(nd[x].rs, seg, l, r, mid + 1, R);
			}
		}

		int ask(int x, int p, int L, int R) {
			if (!x) {
				return INF;
			}
			else {
				int ans = nd[x].seg.calc(p);
				if (L != R) {
					int mid = (L + R) >> 1;
					if (p <= mid) {
						ckmi(ans, ask(nd[x].ls, p, L, mid));
					}
					else {
						ckmi(ans, ask(nd[x].rs, p, mid + 1, R));
					}
				}
				return ans;
			}
		}
	};

	int n, m, k;
	int a[N + 1];
	int vis[N + 1];
	int val[N + 1];
	int bel[N + 1];
	int sumv[N + 1];
	std::vector<Line> ls[N + 1];
	std::vector<int> hs[N + 1];
	std::vector<int> vv[N + 1];
	std::vector<int> hd;
	int f[N + 1];
	SegTree seg;
	int rt;

	void main() {
		std::cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			int c0 = m - a[(i + k - 1) % n];
			int c1 = m - a[(i + k) % n];
			val[i] = (c1 - c0 + m) % m;
		}

		for (int i = 0; i < n; i++) {
			if (vis[i]) {
				continue;
			}

			hd.push_back(i);
			int sum = 0;
			int p = i;
			do {
				sumv[p] = sum;
				vis[p] = 1;
				bel[p] = i;
				vv[i].push_back(sum);
				sum = (sum + val[p]) % m;
				p = (p + k) % n;
			} while (!vis[p]);

			if (sum != 0) {
				fmtout("-1\n");
				return;
			}
		}

		for (auto& h : hd) {
			// fmterr("h {}\n", h);
			// fmterr("vv: ");
			// for (auto& v : vv[h]) {
			// 	fmterr("{} ", v);
			// }
			// fmterr("\n");
			for (auto& v : vv[h]) {
				// v0 <= m / 2 - v
				// v0 > m / 2 - v
				// v0 <= m / 2 - v + m
				// v0 > m / 2 - v + m
				std::vector<int> key;
				key.push_back(0);
				key.push_back(m);
				
				auto push = [&](int v) {
					if (0 <= v && v < m) {
						key.push_back(v);
					}
				};
				push(m / 2 - v);
				push(m / 2 - v + 1);
				push(m / 2 - v + m);
				push(m / 2 - v + m + 1);
				push(m - v);

				std::sort(key.begin(), key.end());
				key.erase(std::unique(key.begin(), key.end()), key.end());
				for (auto& w : key) {
					hs[h].push_back(w);
				}

				for (int i = 1; i < isz(key); i++) {
					Val cur = { 1, v };
					if (key[i - 1] + v >= m) {
						cur.b -= m;
					}
					int p = (key[i - 1] + v) % m;
					
					if (p <= m / 2) {
						ls[h].push_back({ key[i - 1], key[i] - 1, cur });
					}
					else {
						ls[h].push_back({ key[i - 1], key[i] - 1, { -cur.a, -cur.b + m } });
					}
				}
			}

			std::sort(hs[h].begin(), hs[h].end());
			hs[h].erase(std::unique(hs[h].begin(), hs[h].end()), hs[h].end());

			std::vector<Val> tmp(isz(hs[h]));
			for (auto& v : ls[h]) {
				auto L = std::lower_bound(hs[h].begin(), hs[h].end(), v.l) - hs[h].begin();
				auto R = std::upper_bound(hs[h].begin(), hs[h].end(), v.r) - hs[h].begin();
				tmp[L] = tmp[L] + v.v;
				tmp[R] = tmp[R] - v.v;
			}

			for (int i = 1; i < isz(tmp); i++) {
				tmp[i] = tmp[i] + tmp[i - 1];
			}

			// fmterr("ls: ");
			ls[h].clear();
			for (int i = 1; i < isz(tmp); i++) {
				ls[h].push_back({ hs[h][i - 1], hs[h][i] - 1, tmp[i - 1] });
				// fmterr("({} {} {} {}) ", hs[h][i - 1], hs[h][i] - 1, tmp[i - 1].a, tmp[i - 1].b);
				// for (int j = hs[h][i - 1]; j < hs[h][i]; j++) {
				// 	int cur = 0;
				// 	for (auto& v : vv[h]) {
				// 		int t = (v + j) % m;
				// 		if (t <= m / 2) {
				// 			cur += t;
				// 		}
				// 		else {
				// 			cur += m - t;
				// 		}
				// 	}
				// 	assert(cur == tmp[i - 1].a * j + tmp[i - 1].b);
				// }
			}
			// fmterr("\n");
		}

		int goal = (m - a[k - 1]) % m;
		int mul = k / gcd(k, n);
		for (int i = 0; i < k; i++) {
			goal = (goal - sumv[i] + m) % m;
		}

		for (int i = 0; i < m; i++) {
			f[i] = INF;
		}
		f[0] = 0;

		for (auto& h : hd) {
			seg.tot = 0;
			rt = 0;
			for (int i = 0; i < m; i++) {
				if (f[i] == INF) {
					continue;
				}

				for (auto& l : ls[h]) {
					// for (int j = l.l; j <= l.r; j++) {
					// 	ckmi(g[(i + j) % m], f[i] + l.v.a * j + l.v.b);
					// }
					if (i + l.l >= m) {
						seg.update(rt, { l.v.a, -(i - m) * l.v.a + l.v.b + f[i] }, i + l.l - m, i + l.r - m, 0, m - 1);
					}
					else if (i + l.r >= m) {
						seg.update(rt, { l.v.a, -i * l.v.a + l.v.b + f[i] }, i + l.l, m - 1, 0, m - 1);
						seg.update(rt, { l.v.a, l.v.a * (m - i) + l.v.b + f[i] }, 0, i + l.r - m, 0, m - 1);
					}
					else {
						seg.update(rt, { l.v.a, -i * l.v.a + l.v.b + f[i] }, i + l.l, i + l.r, 0, m - 1);
					}
				}
			}

			for (int i = 0; i < m; i++) {
				f[i] = seg.ask(rt, i, 0, m - 1);
			}

		// 	for (int i = 0; i < m; i++) {
		// 		fmterr("{} ", f[i]);
		// 	}
		// 	fmterr("\n");
		}

		// fmterr("goal {} {}\n", goal, mul);
		int ans = INF;
		for (int i = 0; i < m; i++) {
			if (f[i] != INF && i * mul % m == goal) {
				ckmi(ans, f[i]);
			}
		}

		if (ans == INF) {
			fmtout("-1\n");
			return;
		}
		fmtout("{}\n", ans);
	}

	void init() {

	}

	void clear() {

	}
}

signed main() {
#ifndef ONLINE_JUDGE
	auto input_file = freopen("d.in", "r", stdin);
	auto output_file = freopen("d.out", "w", stdout);
#endif

	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

	IO::fmterr("seed: {}\n", seed);
	Solve::mt.seed(seed);

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int t = 1;
	// std::cin >> t;

	Solve::init();

	for (int id = 1; id <= t; id++) {
		Solve::main();
		Solve::clear();
	}

#ifndef ONLINE_JUDGE
	std::cout.flush();
	fclose(input_file);
	fclose(output_file);
#endif

	return 0;
}