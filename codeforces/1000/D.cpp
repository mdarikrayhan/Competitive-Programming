#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
void print() { cout << '\n'; }
template <typename T, typename...Args>
void print(T t, Args...args) { cout << t << ' '; print(args...); }
using P = pair<int, int>;
using ll = long long;
const int N = 1010;
// function

int dir[4][2] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};

template <typename T> void chmax(T &x, T y) { x = max(x, y); }
template <typename T> void chmin(T &x, T y) { x = min(x, y); }

template <typename T = int>
vector<T> readVector(int n) {
    vector<T> a(n);
    for(T &x: a) cin >> x;
    return a;
} 

template<const int T>
struct ModInt {
    const static int mod = T;
    int x;
    ModInt(int x = 0) : x(x % mod) {}
    ModInt(long long x) : x(int(x % mod)) {} 
    int val() { return x; }
    ModInt operator + (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    ModInt operator - (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    ModInt operator * (const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }
    ModInt operator / (const ModInt &a) const { return *this * a.inv(); }
    bool operator == (const ModInt &a) const { return x == a.x; };
    bool operator != (const ModInt &a) const { return x != a.x; };
    void operator += (const ModInt &a) { x += a.x; if (x >= mod) x -= mod; }
    void operator -= (const ModInt &a) { x -= a.x; if (x < 0) x += mod; }
    void operator *= (const ModInt &a) { x = 1LL * x * a.x % mod; }
    void operator /= (const ModInt &a) { *this = *this / a; }
    friend ModInt operator + (int y, const ModInt &a){ int x0 = y + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    friend ModInt operator - (int y, const ModInt &a){ int x0 = y - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    friend ModInt operator * (int y, const ModInt &a){ return ModInt(1LL * y * a.x % mod);}
    friend ModInt operator / (int y, const ModInt &a){ return ModInt(y) / a;}
    friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x;}
    friend istream &operator>>(istream &is, ModInt &t){return is >> t.x;}
 
    ModInt pow(int64_t n) const {
        ModInt res(1), mul(x);
        while(n){
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
     
    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }
     
};
using mint = ModInt<998244353>;
// 1000000007

mint fact[N], invfact[N];

void init(){
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < N; i ++) fact[i] = fact[i - 1] * i;
    invfact[N - 1] = fact[N - 1].inv();
    for(int i = N - 2; i; i --)
        invfact[i] = invfact[i + 1] * (i + 1);  
}

inline mint C(int a, int b){
    if (a < 0 || b < 0 || a < b) return 0;
    return fact[a] * invfact[b] * invfact[a - b];
}

void solve(){
    init();
    
    int n;
    cin >> n;
    
    auto a = readVector(n);
    
    mint ans = 0;
    vector<mint> dp(n);
    
    for (int i = n - 2; i >= 0; i --) {
        if (a[i] > 0 && a[i] <= n - i - 1) {
            dp[i] = C(n - i - 1, a[i]);
            for (int j = i + a[i] + 1; j < n; j ++) {
                dp[i] += C(j - i - 1, a[i]) * dp[j];
            }
            ans += dp[i];
        }
    }
    cout << ans;
}

int main() {
	ios
	int t = 1; //cin >> t;
	while(t --) solve();

	return 0;
}