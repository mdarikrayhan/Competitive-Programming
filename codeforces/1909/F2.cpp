#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) (x).size())
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> inline bool umin(T &a, const T &b) { if(a > b) { a = b; return 1; } return 0; }
template <typename T> inline bool umax(T &a, const T &b) { if(a < b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
const ll base = 1e6 + 9;
const ll inf = 1e18;
const int MAX = 2e5 + 42;
const int LG = 20;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<ll> dis(1, inf);


const int phi_minus_one = mod - 2;

class Mint {
    public:
        int x;

    public:
        void norm() {
            x %= mod;
            if(x < 0) x += mod;
        }
        Mint(int a, bool small) {
            x = a;
            if(x >= mod) x -= mod;
            if(x < 0) x += mod;
        }
        Mint() { x = 0; }
        Mint(ll a) {
            x = a % mod;
            if(x < 0) x += mod;
        }
        friend ostream &operator <<(ostream &out, const Mint &a) { out << a.x; return out; }
        friend istream &operator >>(istream &in, Mint &a) { in >> a.x; return in; }
        Mint operator +(const Mint &b) const {
            return Mint(x + b.x, 1);
        }
        Mint operator +(int a) {
            return Mint(x + a, 1);
        }
        Mint operator -(const Mint &b) const {
            return Mint(x - b.x, 1);
        }
        Mint operator -(int a) {
            return Mint(x - a, 1);
        }
        friend Mint operator -(Mint a) {
            return Mint(mod - a);
        }
        Mint operator *(const Mint &b) const {
             return Mint(1LL * x * b.x);
        }
        Mint operator *(int a) {
            return Mint(1LL * x * a);
        }
        Mint& operator +=(const Mint &b) {
            x += b.x;
            if(x >= mod) x -= mod;
            return *this;
        }
        Mint& operator +=(int a) {
            x += a;
            if(x >= mod) x -= mod;
            return *this;
        }
        Mint& operator -=(Mint b) {
            x += mod - b.x;
            if(x >= mod) x -= mod;
            return *this;
        }
        Mint& operator -=(int a) {
            x += mod - a;
            if(x >= mod) x -= mod;
            return *this;
        }
        Mint& operator *=(Mint b) {
            x = (ll) x * b.x % mod;
            return *this;
        }
        Mint& operator *=(int a) {
            x = (ll) x * a % mod;
            return *this;
        }
        Mint& operator ++() {
            if(++x == mod) x = 0;
            return *this;
        }
        Mint bpow(ll n) {
            Mint a(x);
            Mint ans(1);
            while(n) {
                if(n & 1) ans *= a;
                n >>= 1;
                a *= a;
            }
            return ans;
        }
        Mint inv() {
            return bpow(phi_minus_one);
        }
        Mint operator /(Mint b) {
            return b.inv() * x;
        }
        Mint operator /(int a) {
            return Mint(a, 1).inv() * x;
        }
        friend Mint operator -(int a, Mint b) {
            Mint res(b - a);
            res.x = mod - res.x;
            if(res.x == mod) res.x = 0;
            return res;
        }
        friend Mint operator +(int a, Mint b) {
            return Mint(b + a);
        }
        friend Mint operator *(int a, Mint b) {
            return Mint(b * a);
        }
        friend Mint operator /(int a, Mint b) {
            return Mint(a, 1) * b.inv();
        }
        Mint operator =(Mint b) {
            x = b.x;
            return b;
        }
        bool operator ==(int a) {
            return (x == a);
        }
        bool operator !=(int a) {
            return !(x == a);
        }
        friend bool operator ==(int a, Mint b) {
            return (b.x == a);
        }
        friend bool operator !=(int a, Mint b) {
            return b.x != a;
        }
};

Mint fact[MAX], inv[MAX];

Mint C(int n, int k) {
    if(n < k || k < 0) return 0;
    return fact[n] * inv[k] * inv[n - k];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a) {
        cin >> i;
    }
    a.insert(a.begin(), 0);
    Mint ans = 1;
    if(a[n] != n && ~a[n]) ans = 0;
    a[n] = n;
    for(int i = 0; i < n; i++) {
        int j = i + 1;
        while(!~a[j]) j++;
        int d = a[j] - a[i];
        if(d < 0 || d > 2 * (j - i) || a[j] > j) {
            ans = 0;
            break;
        }
        int left = i - a[i];
        Mint ways = 0;
        for(int small = 0; small <= d; small++) {
            int big = d - small;
            Mint curr = C(left, small) * C(j - i, small) * fact[small] * C(left + j - i - small, big) * C(j - i, big) * fact[big];
            ways += curr;
        }
        ans *= ways;
        i = j - 1;
    }
    cout << ans << '\n';
}

signed main() {
    fact[0] = 1; for(int i = 1; i < MAX; i++) fact[i] = fact[i - 1] * i;
    inv[MAX - 1] = 1 / fact[MAX - 1];
    for(int i = MAX - 1; i; i--) inv[i - 1] = inv[i] * i; assert(inv[0] == 1);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while(ttt--) {
        solve();
    }
}