// LUOGU_RID: 160271229
#include <bits/stdc++.h>
#define For(i,a,b) for(i32 i = (a), endi = (b); i <= endi; ++i)
#define foR(i,a,b) for(i32 i = (a), endi = (b); i >= endi; --i)
using namespace std;

template<typename T, typename U>
void chkmin(T &a, U b) { if(a > b) a = b; }
template<typename T, typename U>
void chkmax(T &a, U b) { if(a < b) a = b; }

template<typename T>
void clr(vector<T> &a, const T t = 0) { fill(a.begin(),a.end(),t); }

using i32 = int;
using i64 = long long;
using i128 = __int128;
using u32 = unsigned int;
using u64 = unsigned long long;
using f64 = long double;
using pii = pair<i32,i32>;
using pll = pair<i64,i64>;
using pli = pair<i64,i32>;

constexpr i32 INF = 0x3fffffff;
constexpr i32 P = 998244353;

template<typename T>
constexpr T qpow(T x, i64 n)
{
    T res(1);
    while(n)
    {
        if(n&1) res *= x;
        x *= x; n >>= 1;
    }
    return res;
}

void init() {}

void solve()
{
    i32 n;
    cin >> n;
    vector<array<i32, 2>> a(n+1);
    vector<array<i64, 2>> sum(n+1), sum2(n+1);
    For(p, 0, 1) For(i, 1, n) cin >> a[i][p], sum[i][p] = sum[i-1][p] + a[i][p], sum2[i][p] = sum2[i-1][p] + 1ll * i * a[i][p];
    auto get = [&](i32 pos, i32 op, i32 t)
    {
        i64 res = t * (sum[n][op] - sum[pos-1][op]) + sum2[n][op] - sum2[pos-1][op] - pos * sum[n][op] + pos * sum[pos-1][op];
        t += n - pos + 1; op ^= 1;
        res += t * (sum[n][op] - sum[pos-1][op]) + n * (sum[n][op] - sum[pos-1][op]) - sum2[n][op] + sum2[pos-1][op];
        return res;
    };
    i64 ans = get(1, 0, 0); 
    i64 res = 0; bool op = 0;
    For(i, 1, n)
    {
        res += (2 * i - 2ll) * a[i][op] + (2 * i - 1ll) * a[i][!op];
        op ^= 1;
        chkmax(ans, res + get(i+1, op, 2 * i));
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int T = 1; 
    // cin >> T;
    while(T--) solve();
    return 0;
}

