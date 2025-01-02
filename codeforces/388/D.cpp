#include<bits/stdc++.h>
using namespace std;
using LL = long long;

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
using mint = ModInt<1000000007>;

mint f[40][40][2];
bool v[40][40][2];
int a[40];

mint dfs(int u, int cnt, bool lim){
    if (u == 0) return 1;
    if (v[u][cnt][lim]) return f[u][cnt][lim];
    v[u][cnt][lim] = true;
    mint ans = 0;
    int up = lim ? a[u] : 1;
    // 该位为1
    {
        if (up == 1){
            ans += dfs(u - 1, cnt + 1, lim && (1 == up));
        }
        if (up == 1 && cnt > 0){
            ans += (1 << (cnt - 1)) * dfs(u - 1, cnt, lim && (1 == up));
        }
    }
    // 该位为0
    {
        if (cnt == 0) ans += dfs(u - 1, cnt, lim && (0 == up));
        else ans += (1 << (cnt - 1)) * dfs(u - 1, cnt, lim && (0 == up));
    }
    return f[u][cnt][lim] = ans;
}

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int len = 0;
    while(n){
        a[++len] = n % 2;
        n /= 2;
    }
    cout << dfs(len, 0, true) << '\n';

}