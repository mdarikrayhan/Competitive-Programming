// Problem: F. Omkar and Modes
// Contest: Codeforces - Codeforces Round 655 (Div. 2)
// URL: https://codeforces.com/contest/1372/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
PII ask(int l,int r){
	cout <<"? "<< l <<" "<<r << endl;
	PII x;
	cin >> x.first >> x.second;
	assert(x.first != -1);
	return x;
}
const int N = 2e5 + 10;
int tr[N];
void build(int l,int r,int L,int R){
	if(l > r)return ;
	if(L == R){
		for(int i = l;i <= r; i ++)
			tr[i] = L;
		return ;
	}
	PII ans = ask(l,r);
	if(ans.first == L){
		for(int j = 0 ;j < ans.second;j ++)
			tr[l + j] = L;
		build(l + ans.second,r,L,R);
		return ;
	}else if(ans.first == R){
		for(int j = 0 ;j < ans.second;j ++)
			tr[r - j] = R;
		build(l,r - ans.second,L,R);
		return ;
	}
	int mid = l + r >> 1;
	int c = ask(mid,mid).first;
	build(l,mid,L,c);
	build(mid + 1,r,c,R);
}
void solve() {
	int n;cin >> n;
	build(1,n,ask(1,1).first,ask(n,n).first);
	cout <<"! ";
	for(int i = 1; i<= n ;i ++)
		cout << tr[i] <<" ";
	cout <<endl;
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
