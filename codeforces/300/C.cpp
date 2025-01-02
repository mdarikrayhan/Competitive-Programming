



/****************************
Author -> yashdabhade283
****************************/

#include <bits/stdc++.h>
using namespace std;

// import libraries
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace chrono;
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pi;
typedef pair<double, double> pdd;
typedef map<int, int> mpi;
typedef map<char, int> mpc;
typedef map<ll, ll> mpl;

#define endl "\n"
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define NO {cout<<"NO"<<endl;}
#define YES {cout<<"YES"<<endl;}
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REV(i,x,y) for(ll i=x;i>=y;i--)
#define inf 0x7fffffff
#define INF 4e18
#define MIN(x) *min_element(all(x))
#define MAX(x) *max_element(all(x))
ll FLOOR(ll n, ll div) {assert(div > 0); return n >= 0 ? n / div : (n - div + 1) / div;}
ll CEIL(ll n, ll div) {assert(div > 0); return n >= 0 ? (n + div - 1) / div : n / div;}

template <typename T>
void op(T inp) {
	cout << inp << endl;
}


#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#endif

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

long long M = 1e9 + 7ll;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(RNG);}  // line 3


const ll MOD = 1e9 + 7;
struct Mint {
	ll val;

	Mint(ll v = 0) {
		if (v < 0)
			v = v % MOD + MOD;
		if (v >= MOD)
			v %= MOD;
		val = v;
	}

	static ll mod_inv(ll a, ll m = MOD) {
		ll g = m, r = a, x = 0, y = 1;
		while (r != 0) {
			int q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}
		return x < 0 ? x + m : x;
	}
	explicit operator int() const {
		return val;
	}
	Mint& operator+=(const Mint &other) {
		val += other.val;
		if (val >= MOD) val -= MOD;
		return *this;
	}
	Mint& operator-=(const Mint &other) {
		val -= other.val;
		if (val < 0) val += MOD;
		return *this;
	}
	static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
		return x % m;
#endif
		unsigned x_high = x >> 32, x_low = (unsigned) x;
		unsigned quot, rem;
		asm("divl %4\n"
		    : "=a" (quot), "=d" (rem)
		    : "d" (x_high), "a" (x_low), "r" (m));
		return rem;
	}
	Mint& operator*=(const Mint &other) {
		val = fast_mod((uint64_t) val * other.val);
		return *this;
	}
	Mint& operator/=(const Mint &other) {
		return *this *= other.inv();
	}
	friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
	friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
	friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
	friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
	Mint& operator++() {
		val = val == MOD - 1 ? 0 : val + 1;
		return *this;
	}
	Mint& operator--() {
		val = val == 0 ? MOD - 1 : val - 1;
		return *this;
	}
	// friend Mint operator<=(const Mint &a, const Mint &b) { return (int)a <= (int)b; }
	Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
	Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
	Mint operator-() const {
		return val == 0 ? 0 : MOD - val;
	}
	bool operator==(const Mint &other) const { return val == other.val; }
	bool operator!=(const Mint &other) const { return val != other.val; }
	Mint inv() const {
		return mod_inv(val);
	}
	Mint power(long long p) const {
		assert(p >= 0);
		Mint a = *this, result = 1;
		while (p > 0) {
			if (p & 1)
				result *= a;

			a *= a;
			p >>= 1;
		}
		return result;
	}
	friend ostream& operator << (ostream &stream, const Mint &m) {
		return stream << m.val;
	}
	friend istream& operator >> (istream &stream, Mint &m) {
		return stream >> m.val;
	}
};

struct Comb {
	ll n;
	vector<Mint> _fac, _invfac, _inv;
	Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
	Comb(int n) : Comb() {
		init(n);
	}

	void init (ll m) {
		m = min (m, MOD - 1);
		if (m <= n) return;

		_fac.resize(m + 1);
		_invfac.resize(m + 1);
		_inv.resize(m + 1);

		for (ll i = n + 1; i <= m; i++) {
			_fac[i] = _fac[i - 1] * i;
		}

		_invfac[m] = _fac[m].inv();
		for (ll i = m; i > n; i--) {
			_invfac[i - 1] = _invfac[i] * i;
			_inv[i] = _invfac[i] * _fac[i - 1];
		}
		n = m;
	}

	Mint fac(ll m) {
		if (m > n) init(2 * m);
		return _fac[m];
	}

	Mint invfac(ll m) {
		if (m > n) init(2 * m);
		return _invfac[m];
	}

	Mint inv(ll m) {
		if (m > n) init(2 * m);
		return _inv[m];
	}

	Mint ncr(ll n, ll r) {
		if (n < r || r < 0) return 0;
		return fac(n) * invfac(r) * invfac(n - r);
	}
} comb;


Mint ans = 0;
Comb cm = Comb();

bool isValid(string res, ll a, ll b) {
	for (auto it : res) if ((it - '0') != a and (it - '0') != b) return false;
	return true;
}


void solve() {
	ll a, b, n; cin >> a >> b >> n;
	for (ll i = 0; i <= n; i++) {
		ll takeA = i, takeB = (n - i);
		ll res = (a * takeA) + (b * takeB);
		if (isValid(to_string(res), a, b)) {
			ans += cm.ncr(n, takeB);
		}
	}
	op(ans);
}


int32_t main() {
	auto begin = std::chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	ll t = 1;
	// cin >> t;
	while (t--)
		solve();

	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

	return 0;
}