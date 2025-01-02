#include <bits/stdc++.h>
 
using namespace std;

template<class F, class S>
ostream &operator<<(ostream &s, const pair<F, S> &v) {
    s << "(" << v.first << ", " << v.second << ")";
    return s;
}
 
template<ranges::range T> requires (!is_convertible_v<T, string_view>)
istream &operator>>(istream &s, T &&v) { 
    for (auto &&x : v) s >> x; 
    return s; 
}
template<ranges::range T> requires (!is_convertible_v<T, string_view>)
ostream &operator<<(ostream &s, T &&v) { 
    for (auto &&x : v) s << x << ' '; 
    return s; 
}
 
#ifdef LOCAL
template<class... T> void dbg(T... x) {
    char e{};
    ((cerr << e << x, e = ' '), ...);
}
#define debug(x...) dbg(#x, '=', x, '\n')
#else
#define debug(...) ((void)0)
#endif
 
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ff first
#define ss second
 
template <class T> inline constexpr T inf = numeric_limits<T>::max() / 2;
template <class T> bool chmin(T &a, T b) { return (b < a and (a = b, true)); }
template <class T> bool chmax(T &a, T b) { return (a < b and (a = b, true)); }
 
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr i64 mod = 998244353;

struct BigBinary : map<int, int> {
    void split(int x) {
        auto it = lower_bound(x);
        if (it != begin()) {
            it--;
            if (it->ss > x) {
                (*this)[x] = it->ss;
                it->ss = x;
            }
        }
    }
    void add(int x) {
        split(x);
        auto it = find(x);
        while (it != end() and it->ff == x) {
            x = it->ss;
            it = erase(it);
        }
        (*this)[x] = x + 1;
    }
    void sub(int x) {
        split(x);
        auto it = lower_bound(x);
        // assert(it != end());
        auto [l, r] = *it;
        erase(it);
        if (l + 1 < r) {
            (*this)[l + 1] = r;
        }
        if (x < l) {
            (*this)[x] = l;
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    BigBinary big;

    vector<int> A(n);
    cin >> A;

    for (int x : A) {
        big.add(x);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        big.sub(A[x]);
        A[x] = y;
        big.add(A[x]);

        cout << big.rbegin()->ss - 1 << '\n';
    }
    
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int t = 1;
    // cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}


