#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define rep(var, start, num) for(int var = start; var < num; var++)
#define all(x) (x).begin(), (x).end()
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int MOD = 998244353;
struct mi {
    int v;
    explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
    if ((a.v += b.v) >= MOD) a.v -= MOD;
    return a;
}
mi &operator-=(mi &a, mi b) {
    if ((a.v -= b.v) < 0) a.v += MOD;
    return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi power(mi a, long long p) {
    assert(p >= 0);
    return p == 0 ? 1 : power(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
    assert(a.v != 0);
    return power(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

void solve() {
    int n,m;
    cin >> n >> m;

    vector<bool> is_prime(n+1, true);
    is_prime[1] = false;
    rep(i,2,n+1) {
        if (!is_prime[i]) continue;
        for (int j = 2*i; j <= n; j += i) {
            is_prime[j] = false;
        }
    }

    vector<int> cnt(n+1);
    cnt[2] = m/2;
    rep(i,3,n+1) {
        if (!is_prime[i]) {
            cnt[i] = cnt[i-1];
            continue;
        }
        cnt[i] = cnt[i-1]/i;
    }
    debug(cnt[n]);

    auto ctr = [&](int n, int m) -> mi {
        // how many numbers from 1 to m which are coprime with atleast 1 num from 2...n?
        return m - cnt[n];
    };

    vector<mi> dp(n+1);
    dp[2] = m*ctr(2,m);
    debug(dp[2].v);
    rep(i,2,n) {
        dp[i+1] = dp[i]*m + (power(m,i) - dp[i]) * ctr(i+1, m);
    }
    mi ans = 0;
    rep(i,1,n+1) ans += dp[i];
    cout << ans.v << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}