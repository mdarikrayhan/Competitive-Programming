#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifdef LOCAL
#include<debug.h>
#include<writeout.h>
#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
#define debug(...) 28
#define write_output(...) 03
#define eprintf(...) 2003
#endif

template<typename T> void print_impl(const T& arg) { std::cout << arg; }
template<typename T, typename... Args> void print_impl(const T& arg, const Args&... rest) { std::cout << arg << ' '; print_impl(rest...); }
template<typename... Args> 
void print(const Args&... args) { 
	print_impl(args...); 	
#ifdef LOCAL
	std::cout << std::endl; 
#else
	std::cout << '\n';
#endif
}

template<typename T> T inv(T a, T m){ T u = 0, v = 1; while (a != 0) { T t = m / a; m -= t * a; swap(a, m); u -= t * v; swap(u, v); } assert(m == 1); return u; }

template<typename T>
class Modular{
public:
	long long x;
	constexpr Modular() {}
	template<typename U> Modular(U x){if(x < 0) x += mod(); this->x = x; }

	constexpr long long& operator()(){return x;}
	template<typename U> explicit operator U() const {return static_cast<U>(x);}
	constexpr static long long mod(){return T::value;}

	Modular& operator+= (const Modular &a){ x += a.x; if(x >= mod()) x -= mod(); return *this; }
	template<typename U> Modular& operator+=(const U& a){ return *this += Modular(a); }
	Modular& operator-= (const Modular &a){ x -= a.x; if(x < 0) x += mod(); return *this; }
	template<typename U> Modular& operator-=(const U& a){ return *this -= Modular(a); }
	Modular& operator*= (const Modular &a){ x = (x % mod()) * (a.x % mod()); x %= mod(); return *this; }
	Modular& operator/= (const Modular &a){ return *this *= Modular(inv(a.x, mod())); }	

	Modular& operator++(){ return *this += 1; }
	Modular operator++(int) { Modular res(*this); *this += 1; return res; }
	Modular& operator--(){ return *this -= 1; }
	Modular operator--(int){ Modular res(*this); *this -= 1; return res;}

	Modular operator-() const {return Modular(-x);}	

	template<typename U> friend std::ostream& operator<<(std::ostream& out, const Modular<U> &b);
	template<typename U> friend std::istream& operator>>(std::istream& in, Modular<U>& b);
};

template<typename T> Modular<T> operator+(const Modular<T>& a, const Modular<T>& b){ return Modular<T>(a) += b; }
template<typename T, typename U> Modular<T> operator+(const Modular<T>& a, U b){ return Modular<T>(a) += b; }
template<typename T, typename U> Modular<U> operator+(T a, const Modular<U>& b){ return Modular<U>(a) += b; }

template<typename T> Modular<T> operator-(const Modular<T>& a, const Modular<T>& b){ return Modular<T>(a) -= b; }
template<typename T, typename U> Modular<T> operator-(const Modular<T>& a, U b){ return Modular<T>(a) -= b; }
template<typename T, typename U> Modular<U> operator-(T a, const Modular<U>& b){ return Modular<U>(a) -= b; }

template<typename T> Modular<T> operator*(const Modular<T>& a, const Modular<T>& b){ return Modular<T>(a) *= b; }
template<typename T, typename U> Modular<T> operator*(const Modular<T>& a, U b){ return Modular<T>(a) *= b; }
template<typename T, typename U> Modular<U> operator*(T a, const Modular<U>& b){ return Modular<U>(a) *= b; }

template<typename T> Modular<T> operator/(const Modular<T>& a, const Modular<T>& b){ return Modular<T>(a) /= b; }
template<typename T, typename U> Modular<T> operator/(const Modular<T>& a, U b){ return Modular<T>(a) /= b; }
template<typename T, typename U> Modular<U> operator/(T a, const Modular<U>& b){ return Modular<U>(a) /= b; }

template<typename T, typename U> 
Modular<T> Pow(const Modular<T>& a, const U& b){ assert(b >= 0); Modular<T> x = a,res = 1; U p = b; while(p){ if(p & 1) res *= x; x *= x; p >>= 1; } return res; }

template<typename T> std::ostream& operator<<(std::ostream& out, const Modular<T> &a){ out << a.x; return out; }
template<typename T> std::istream& operator>>(std::istream& in, Modular<T> &a){ in >> a.x; a.x %= Modular<T>::mod(); return in; }

const int mod = 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(mod)>::type, mod>>;

const int mxN = 1e6 + 1;
Mint f[mxN];

Mint dp[1001][1001];

Mint C(int n, int k){
	if(n < k) return 0;
	return f[n] / (f[k] * f[n - k]);
}


void solve(){
	int n, m, k;
	cin >> n >> m >> k;

	if(m == 1){
		print(Pow(Mint(k), n));
		return;
	}

	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			dp[i][j] = 0;

	dp[0][0] = 1;
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			dp[i][j] = dp[i - 1][j] * j + dp[i - 1][j - 1];
		}
	}

	Mint res = 0;

	for(int y = 0; y <= n; ++y){
		for(int x = y; x <= n; ++x){
			Mint cur = 1;
			cur *= C(k, 2 * x - y);
			cur *= C(2 * x - y, x - y);
			cur *= C(x, x - y);
			cur *= dp[n][x] * dp[n][x];
			cur *= f[x] * f[x];
			cur *= Pow(Mint(y), n * (m - 2));

			res += cur;
		}
	}

	print(res);
}

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
#ifdef LOCAL
	freopen("out.txt", "w", stdout);
#endif

	f[0] = 1;
	for(int i = 1; i < mxN; ++i)
		f[i] = f[i - 1] * i;

	int test = 1;
	//cin >> test;

	for(int itest = 1; itest <= test; ++itest){
		eprintf("------- Case %d -------\n", itest);
		solve();
		eprintf("----------------------\n");
	}
	write_output();	

	return 0;
}



