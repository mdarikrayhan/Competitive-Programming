// author:	Anshul_Johri
// created:	Thursday, 23-May-2024, 16:12 (UTC+05:30)

#include <bits/stdc++.h>
using namespace std;

// #define STRESS_TEST 1
#ifdef STRESS_TEST
#define ONLINE_JUDGE
#include "Algo/StressTest.cpp"
#endif
#ifndef ONLINE_JUDGE
#include "Algo/Debug.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
/* clang-format off */
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define LL(...) long long __VA_ARGS__; in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)
#define YES_R cout << "YES" << endl; return
#define NO_R cout << "NO" << endl; return
#define endl '\n'
#define all(x) x.begin(), x.end()
template <size_t N> istream &operator>>(istream &in, bitset<N> &x) { size_t num; in >> num; x = bitset<N>(num); return in; } template <typename T> istream &operator>>(istream &in, vector<T> &vec) { for (auto &i : vec) in >> i; return in; }
template <typename T, typename... V> void out(const T &x, const V &...tail) { cout << x; if constexpr (sizeof...(tail)) cout << ' ', out(tail...); else cout << endl; } template <typename T> void out(const vector<T> &vec) { int i = 0; for (const auto &x : vec) cout << (i++ ? " " : "") << x; cout << endl; } 
template <typename... Args> auto &in(Args &...args) { return (cin >> ... >> args); }
using ll = long long;
using ld = long double;
const double EPS = 1e-9;
const int MOD = 1e9 + 7, INF = 1e9, MAXN = 1e5 + 10, FAST_IO = [] {ios_base::sync_with_stdio(0); cin.tie(0); return 1; }();
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) { return l + mt() % (r - l + 1); }
void generateTestCase() {}
namespace correct { void brute() {} }
/* clang-format on */

void solve();
signed main()
{
#ifdef STRESS_TEST
    main2();
#else
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; t++)
    {
#ifndef ONLINE_JUDGE
        cerr << "\n______Test : " << t << "\n\n";
        // correct::brute();
#endif
        solve();
    }
#ifndef ONLINE_JUDGE
    cerr << "\nDone!";
#endif
#endif
    return 0;
}

ll dp[2][20];
ll fun2(string &num, int ind, bool tight)
{
    if (num.size() == 1)
    {
        return stoi(num);
    }
    if (ind == num.size() - 1)
    {
        if (tight and num.back() < num.front())
            return 0;
        else
            return 1;
    }
    if (dp[tight][ind] != -1)
        return dp[tight][ind];
    char lb = ind == 0 ? '1' : '0';
    char ub = tight ? num[ind] : '9';
    ll ans = 0;
    for (char ch = lb; ch <= ub; ch++)
    {
        ans += fun2(num, ind + 1, tight and ch == ub);
    }
    return dp[tight][ind] = ans;
}
ll fun(ll x)
{
    string num = to_string(x);
    memset(dp, -1, sizeof(dp));
    ll ans = fun2(num, 0, true);
    for (int len = 1; len < num.size(); len++)
    {
        string temp(len, '9');
        memset(dp, -1, sizeof(dp));
        ans += fun2(temp, 0, true);
    }
    return ans;
}
void solve()
{
    LL(l, r);
    out(fun(r) - fun(l - 1));
}