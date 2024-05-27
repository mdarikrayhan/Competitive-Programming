#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;


template<typename T>
ostream_iterator<T> oit(const string &s = " "){ return ostream_iterator<T>(cout,s.c_str()); }
inline auto rep(int l, int r) { return views::iota(min(l, r), r); }
inline auto rep(int n) { return rep(0, n); }
inline auto rep1(int l, int r) { return rep(l, r + 1); }
inline auto rep1(int n) { return rep(1, n + 1); }
inline auto per(int l, int r) { return rep(l, r) | views::reverse; }
inline auto per(int n) { return per(0, n); }
inline auto per1(int l, int r) { return per(l, r + 1); }
inline auto per1(int n) { return per(1, n + 1); }
#define A(a) begin(a),end(a)
inline auto len = ranges::ssize;

struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename T, typename U> using pb_map = gp_hash_table<T, U, chash>;
template<typename T> using pb_set = gp_hash_table<T, null_type, chash>;
#define K first
#define V second

typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

constexpr ll NN = 2e5;
constexpr ll M = 1000000007;

ll f1[NN], f2[NN];

ll inv(ll a, ll b=M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; } // inv a mod b
ll choose(ll n, ll k) { return f1[n] * f2[k] % M * f2[n - k] % M; } // n choose k

void run()
{
    ll n; cin >> n; vll a(n); for(ll &x : a) cin >> x;

    ll tot = accumulate(A(a),0LL);
    if(tot%3)
        return void(cout << "0\n");
    ll need = tot/3;
    vll dp(n);
    for(ll sm=0; ll i : per(n)){
        sm+=a[i];
        if(sm == need)
            dp[i]++;
        if(i!=n-1) dp[i]+=dp[i+1];
    }
    ll ans = 0;
    // ranges::copy(a,oit<ll>()), cout << '\n';
    // ranges::copy(dp,oit<ll>()), cout << '\n';
    for(ll sm = 0;ll i : rep(n-2)){
        sm+=a[i];
        if(sm == need) ans += dp[i+2];
    }
    cout << ans << '\n';
}

int main()
{
    //KING OF THE WORLD...... U.W.T.B
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    f1[0] = 1;
    f2[0] = 1;
    for (int i = 1; i < NN; i++) {
        f1[i] = f1[i - 1] * i % M;
        f2[i] = inv(f1[i], M);
    }
    int t; t=1; while(t--) run();
}
