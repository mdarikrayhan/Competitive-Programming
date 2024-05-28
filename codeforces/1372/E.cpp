// Problem: E. Omkar and Last Floor
// Contest: Codeforces - Codeforces Round 655 (Div. 2)
// URL: https://codeforces.com/contest/1372/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define lowit(x) (x & -x)
#define fre(z) freopen(z ".in", "r", stdin), freopen(z ".out", "w", stdout)

#define range(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using i64 = long long;
using PII = pair<ll, ll>;

inline ll read() {
    char ch;
    ll x = 0;
    bool f = true;
    for (ch = getchar(); !isdigit(ch); ch = getchar())
        if (ch == '-')
            f ^= f;
    for (; isdigit(ch); ch = getchar())
        x = (x << 3) + (x << 1) + ch - 48;
    return f ? x : -x;
}

template<class T>
constexpr T power(T a, i64 b) {
    T res {1};
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
 
constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}
 
template<i64 P>
struct MInt {
    i64 x;
    constexpr MInt() : x {0} {}
    constexpr MInt(i64 x) : x {norm(x % getMod())} {}
    
    static i64 Mod;
    constexpr static i64 getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(i64 Mod_) {
        Mod = Mod_;
    }
    constexpr i64 norm(i64 x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr i64 val() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & {
        if (getMod() < (1ULL << 31)) {
            x = x * rhs.x % int(getMod());
        } else {
            x = mul(x, rhs.x, getMod());
        }
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
    friend constexpr bool operator<(MInt lhs, MInt rhs) {
        return lhs.val() < rhs.val();
    }
};
 
// template<>
// i64 MInt<0>::Mod = 998244353;
 
// constexpr int P = 1000000007;
// using mint = MInt<P>;
 
#define PrDEBUG
#ifdef PrDEBUG
#define DE(x) cerr << __LINE__ << " " << #x << " " << x << endl
#else
#define DE(x)
#endif
// #define ONLINE_JUDGE
// #define LOCAL_DEFINE
// #define ON_T
const int N = 110;
ll dp[N][N];
ll work[N][N][N];
void solve() {
	int n = read(),m = read();
	for(int i = 1; i <= n ; i++){
		int k = read();
		for(int  j = 1; j <= k ;j ++){
			int l = read(),r = read();
			// [1,l][l,r][r,n] ++;
			int a[2] = {1,l + 1},b[2] = {l,r + 1},c[2] = {r,m + 1};	
			for(int p1 = 0;p1 < 2;p1 ++)
				for(int p2 = 0;p2 < 2;p2 ++)
					for(int p3 = 0;p3 < 2;p3 ++){
						int op = p1 ^ p2 ^ p3;
						if(op == 1)op = -1;
						else op = 1;
						work[a[p1]][b[p2]][c[p3]] += op;
					}
		}
	}
	for(int i = 1;i <= m; i ++)
		for(int j = 1;j <= m ;j ++)
			for(int k = 1;k <= m ;k ++){
				ll ans = 2 * work[i][j][k];
				for(int p1 = -1;p1 <= 0;p1 ++)
					for(int p2 = -1;p2 <= 0;p2 ++)
						for(int p3 = -1;p3 <= 0;p3 ++){
							int op = p1 + p2 + p3;
							if(op % 2 == 0)op = -1;
							else op = 1;
							ans += work[i + p1][j + p2][k + p3] * op;
						}
				work[i][j][k] = ans;
			}
	for(int len = 1;len <= m;len ++){
		for(int l = 1;l + len - 1 <= m; l ++){
			int r = l + len - 1;
			for(int k = l ;k <= r;k ++){
				dp[l][r] = max(dp[l][r],dp[l][k - 1] + dp[k + 1][r] + work[l][k][r] * work[l][k][r]);
			}
		}
	}
	cout << dp[1][m] <<"\n";
}

int main() {
#ifdef ONLINE_JUDGE
    // fre("1");
#endif
    cout << fixed << setprecision(12);
    int T = 1;
#ifdef ON_T
    T = read();
#endif
    for (int i = 1; i <= T; i++)
        solve();
        // std::cout << __cplusplus << std::endl;

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
