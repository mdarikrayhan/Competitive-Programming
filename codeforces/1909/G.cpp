#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include<bits/stdc++.h>

using namespace std;
#define int long long
#define app push_back
#define all(x) x.begin(), x.end()

#ifdef LOCAL
#define debug(...) [](auto...a){ ((cout << a << ' '), ...) << endl;}(#__VA_ARGS__, ":", __VA_ARGS__)
#define debugv(v) do { cout << #v << ": "; for (auto x : v) cout << x << ' '; cout << endl; } while(0)
#else
#define debug(...)
#define debugv(v)
#endif

void solve();

int32_t main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1;
//    cin >> t;
    while (t--) solve();
}

const int p = (1LL << 61) - 1;
const int b = 43872;
const __int128 one = 1;

int po(int b, int e) {
    if (e == 0) return 1;
    if (e % 2 == 0) return po(b * one * b % p, e / 2);
    return b * one * po(b, e - 1) % p;
}

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> pow(m + 1, 1), inv(m + 1, 1);
    for (int i = 1; i <= m; ++i) pow[i] = (pow[i - 1] * one * b) % p;
    inv[m] = po(pow[m], p - 2);
    for (int i = m - 1; i >= 0; --i) inv[i] = (inv[i + 1] * one * b) % p;
    vector<int> hash(m + 1);
    for (int i = 0; i < m; ++i) hash[i + 1] = (hash[i] + pow[i] * one * t[i]) % p;
    auto get = [&](int l, int r) -> int {
        return ((hash[r] - hash[l] + p) * one * inv[l]) % p;
    };
    auto period = [&](int l, int m, int r) {
        assert((r - l) % (m - l) == 0);
        int total = get(l, r);
        int small = get(l, m);
        // return small + small * po(b, m - l) + small * po(b, 2 * (m - l)) + ... + small * po(b, (r - l) - (m - l) == total;
        int periodic = small * one * (1 - po(b, r - l)) % p * po(1 - po(b, m - l), p - 2) % p;
        return (periodic % p + p) % p == total;
    };
    int b = 0, e = 0;
    while (b < n && s[b] == t[b]) b++;
    while (e < n && s.rbegin()[e] == t.rbegin()[e]) e++;
    int ans = 0;
    for (int y = 1; y <= b + e - n; ++y) {
        if ((m - n) % y) continue;
        bool ok1 = period(b - y, b, m - n + b);
        bool ok2 = period(n - e,n - e + y,m - e + y);
        assert(ok1 == ok2);
        ans += ok1 * (b + e - n - y + 1);
    }
    cout << ans << '\n';
}