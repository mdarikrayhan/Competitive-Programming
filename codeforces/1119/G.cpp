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

	int const N = 1e6 + 10;

	int n, m;
	int a[N + 1];
	int b[N + 1];
	int v[N + 1];
	int lmt[N + 1];
	int tot;
	int id[N + 1];

	void main() {
		std::cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			std::cin >> a[i];
		}

		memcpy(b, a, sizeof b);
		int p = 1;
		while (p <= m) {
			int sum = n;
			int pre = 0;
			while (p <= m && b[p] < sum) {
				if (p == m) {
					p++;
					break;
				}
				tot++;
				pre += b[p];
				lmt[tot] = pre;
				// fmterr("? {} {}\n", tot, pre);
				sum -= b[p];
				p++;
			}
			if (p <= m) {
				b[p] -= sum;
				if (!b[p]) {
					p++;
				}
			}
		}

		std::sort(lmt + 1, lmt + m);
		for (int i = 1; i < m; i++) {
			v[i] = lmt[i] - lmt[i - 1];
		}
		v[m] += n - lmt[m - 1];
		lmt[m] = n;
		for (int i = 1; i <= m; i++) {
			if (!id[lmt[i]]) {
				id[lmt[i]] = i;
			}
		}
		id[0] = 0;

		memcpy(b, a, sizeof b);
		std::vector<std::vector<int>> ans;
		p = 1;
		while (p <= m) {
			ans.emplace_back();

			int sum = n;
			int pre = 0;
			while (p <= m && b[p] < sum) {
				if (p == m) {
					p++;
					continue;
				}
				for (int j = id[pre] + 1; j <= id[pre + b[p]]; j++) {
					ans.back().push_back(p);
				}
				pre += b[p];
				sum -= b[p];
				p++;
			}
			// fmterr("????? {} {} {}\n", p, pre, id[pre]);
			if (p <= m) {
				for (int j = id[pre] + 1; j <= m; j++) {
					ans.back().push_back(p);
				}
				b[p] -= sum;
				if (!b[p]) {
					p++;
				}
			}
			else {
				for (int j = id[pre] + 1; j <= m; j++) {
					ans.back().push_back(m);
				}
			}
		}

		fmtout("{}\n", isz(ans));
		for (int i = 1; i <= m; i++) {
			fmtout("{} ", v[i]);
		}
		fmtout("\n");
		for (auto& vs : ans) {
			for (auto& v : vs) {
				fmtout("{} ", v);
			}
			fmtout("\n");
		}
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