#include<bits/stdc++.h>
using namespace std;
using LL = long long;

template<const int T>
struct ModInt {
    const static int mod = T;
    int x;
    ModInt(int x = 0) : x((x % mod + mod) % mod) {}
    ModInt(long long x) : x(int((x % mod + mod) % mod)) {} 
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

struct Point{
    LL x, y;
    
    LL operator^(const Point &t){
        return x * t.y - y * t.x;
    }

};

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    const int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<Point> p(2 * n);
    for(int i = n - 1; i >= 0; i--) cin >> p[i].x >> p[i].y;
    for(int i = 0; i < n; i++) p[i + n] = p[i];
    vector<LL> area(2 * n + 1);
    __int128_t sum = 0;
    for(int i = 1; i <= n; i++){
        area[i] = area[i + n] = p[i - 1] ^ p[i];
        sum += area[i];
    }
    vector<mint> s1(2 * n + 1), s2(2 * n + 1), s3(2 * n + 1);
    for(int i = 1; i <= n; i++){
        mint t = area[i] % mod + mod;
        s1[i] = s1[i + n] = t;
        s2[i] = 2 * i * t;
        s2[i + n] = 2 * (i + n) * t;
        s3[i] = mint(mod - 2 * i) * t;
        s3[i + n] = mint(mod - 2 * (n + i)) * t;
    }
    vector<mint> sx(2 * n + 1), sy(2 * n + 1);
    for(int i = 1; i <= 2 * n; i++){
        sx[i] = sx[i - 1] + (p[i - 1].x % mod + mod);
        sy[i] = sy[i - 1] + (p[i - 1].y % mod + mod);
        s1[i] += s1[i - 1];
        s2[i] += s2[i - 1];
        s3[i] += s3[i - 1];
    }
    __int128_t cur = 0;
    mint ans = 0;
    for(int i = 0, j = 0; i < n; i++){
        if (i - 1 >= 0){
            cur -= p[i - 1] ^ p[i];
        }
        while(j < i + n && 2 * (cur + (p[j] ^ p[i])) <= sum){
            cur += p[j] ^ p[j + 1];
            j++;
        }
        int c1 = j - 1 - i - 1;
        int c2 = n - 3 - c1;
        {
            mint k = s1[i + n] - s1[j - 1];
            if (c1 != 0){
                ans += c1 * k;
                ans += (s2[j - 1] - s2[i + 1]) + (mod - c1 - mint(2 * (i + 2))) * (s1[j - 1] - s1[i + 1]);
                ans -= mint(area[i + 1]) * c1;
                mint xx = p[i].x % mod + mod;
                mint yy = p[i].y % mod + mod;
                ans += 2 * (xx * (sy[j] - sy[i + 2]) - yy * (sx[j] - sx[i + 2]));
            }
        }
        // cout << c1 << ' ' << c2 << '\n';
        {
            mint k = s1[j] - s1[i];
            if (c2 != 0){
                ans += c2 * k;
                ans += (s3[i + n - 1] - s3[j]) + mint(mod - c2 + 2 * (i + n - 1)) * (s1[i + n - 1] - s1[j]);
                ans -= mint(area[i + n]) * c2;
                mint xx = p[i].x % mod + mod;
                mint yy = p[i].y % mod + mod;
                ans -= 2 * (xx * (sy[i + n - 1] - sy[j]) - yy * (sx[i + n - 1] - sx[j]));
            }
        }
        // cout << ans << '\n';
    }
    cout << ans / 2 << '\n';

}