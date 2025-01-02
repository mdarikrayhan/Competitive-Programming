#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

const int MOD = 1e9 + 7;

template<ll mod> // template was not stolen from https://codeforces.com/profile/SharpEdged
struct modnum {
    static constexpr bool is_big_mod = mod > numeric_limits<int>::max();

    using S = conditional_t<is_big_mod, ll, int>;
    using L = conditional_t<is_big_mod, __int128, ll>;

    S x;

    modnum() : x(0) {}
    modnum(ll _x) {
        _x %= static_cast<ll>(mod);
        if (_x < 0) { _x += mod; }
        x = _x;
    }

    modnum pow(ll n) const {
        modnum res = 1;
        modnum cur = *this;
        while (n > 0) {
            if (n & 1) res *= cur;
            cur *= cur;
            n /= 2;
        }
        return res;
    }
    modnum inv() const { return (*this).pow(mod-2); }
    
    modnum& operator+=(const modnum& a){
        x += a.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    modnum& operator-=(const modnum& a){
        if (x < a.x) x += mod;
        x -= a.x;
        return *this;
    }
    modnum& operator*=(const modnum& a){
        x = static_cast<L>(x) * a.x % mod;
        return *this;
    }
    modnum& operator/=(const modnum& a){ return *this *= a.inv(); }
    
    friend modnum operator+(const modnum& a, const modnum& b){ return modnum(a) += b; }
    friend modnum operator-(const modnum& a, const modnum& b){ return modnum(a) -= b; }
    friend modnum operator*(const modnum& a, const modnum& b){ return modnum(a) *= b; }
    friend modnum operator/(const modnum& a, const modnum& b){ return modnum(a) /= b; }
    
    friend bool operator==(const modnum& a, const modnum& b){ return a.x == b.x; }
    friend bool operator!=(const modnum& a, const modnum& b){ return a.x != b.x; }
    friend bool operator<(const modnum& a, const modnum& b){ return a.x < b.x; }

    friend ostream& operator<<(ostream& os, const modnum& a){ os << a.x; return os; }
    friend istream& operator>>(istream& is, modnum& a) { ll x; is >> x; a = modnum(x); return is; }
};

using mint = modnum<MOD>;

struct Combi{
    vector<mint> _fac, _ifac;
    int n;
    
    Combi() {
        n = 1;
        _fac.assign(n + 1, 1);
        _ifac.assign(n + 1, 1);
    }
    
    void check_size(int m){
        int need = n;
        while (need < m) need *= 2;
        m = need;
        if (m <= n) return;
        
        _fac.resize(m + 1);
        _ifac.resize(m + 1);
        for (int i = n + 1; i <= m; i++) _fac[i] = i * _fac[i - 1];
        
        _ifac[m] = _fac[m].inv();
        for (int i = m - 1; i > n; i--) _ifac[i] = _ifac[i + 1] * (i + 1);
        n = m;
    }
    
    mint fac(int m){
        check_size(m);
        return _fac[m];
    }
    
    mint ifac(int m){
        check_size(m);
        return _ifac[m];
    }
    
    mint ncr(int n, int r){
        if (n < r || r < 0) return 0;
        
        return fac(n) * ifac(n - r) * ifac(r);
    }
    
    mint npr(int n, int r){
        if (n < r || r < 0) return 0;
        
        return fac(n) * ifac(n - r);
    }
} comb;

void solve(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    vector<int> odd, even;
    for (int x : a) {
        if (x & 1) odd.push_back(x);
        else even.push_back(x);
    }
    
    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());
    
    odd.push_back(0);
    even.push_back(0);
    
    mint ans = 1;
    for (int i = 0; i < odd.size() - 1; i++){
        int dif = odd[i] - odd[i + 1];
        ans *= comb.fac(i + 1).pow(dif);
    }
    
    for (int i = 0; i < even.size() - 1; i++){
        int dif = even[i] - even[i + 1];
        ans *= comb.fac(i + 1).pow(dif);
    }
    
    mint sum = 0;
    for (int x : a) sum += x;
    
    mint cnt = 0;
    sort(a.rbegin(), a.rend());
    a.push_back(1);
    a.push_back(0);
    
    int cur_odd = -1;
    int cur_even = -1;
    int cnt_odd = 0;
    int cnt_even = 0;
    mint pos = 0;
    
    for (int i = 0; i <= n + 1; i++){
        if (cur_odd == -1 && (a[i] & 1)) {
            cur_odd = a[i];
        }
        if (cur_even == -1 && a[i] % 2 == 0) {
            cur_even = a[i];
        }
        
        while (cur_odd > a[i] || cur_even > a[i]){
            if (cur_odd > cur_even){
                mint dif = (pos + cnt_odd - 1) * (pos + cnt_odd) / 2 - (pos - 1) * pos / 2;
                cnt += (cnt_odd * sum - 2 * dif - cnt_odd) * (cur_odd - 1);
                cur_odd -= 2;
                pos += cnt_odd;
            } else {
                mint dif = (pos + cnt_even - 1) * (pos + cnt_even) / 2 - (pos - 1) * pos / 2;
                cnt += (cnt_even * sum - 2 * dif - cnt_even) * (cur_even - 1);
                cur_even -= 2;
                pos += cnt_even;
            }
        }
        
        if (a[i] & 1) cnt_odd++;
        else cnt_even++;
    }
    
    cout << cnt << " " << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    
    solve();
}