/*
    Những mùa thu khác có thể trở về
Nhưng mùa thu của chúng ta đã chết...
*/

// #pragma GCC optimize("Ofast,O3") 
// #pragma GCC target("avx,avx2,fma,sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#ifdef Debug
#include "Debug.h"
#else
#define dbg(...)
#endif

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lb lower_bound
#define ub upper_bound
#define ins insert

#define nl "\n"

#define vi vector<long long>
#define vii vector<pair<long long, long long>>
#define pi pair<ll, ll>

template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class X, class Y> bool ckmin(X& a, const Y& b) {return a > b ? a = b, 1 : 0;}
template<class X, class Y> bool ckmax(X& a, const Y& b) {return a < b ? a = b, 1 : 0;}

// const ll M = 1e9 + 9; // (1ll << 61) - 1
// mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
// const ll B = uniform_int_distribution<ll>(311, M - 1)(rng);

const ll mod = 1e9 + 7;

ll add(ll a, ll b) {
    a += mod, b += mod;
    a %= mod, b %= mod;
    return (a + b + mod) % mod;
}

ll mul(ll a, ll b) {
    a += mod, b += mod;
    a %= mod, b %= mod;
    return ((a * b) + mod) % mod;
}

ll p(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n & 1) { res = res * x % m; }
		x = x * x % m;
		n >>= 1;
	}
	return res;
}

long long dp[2005][1005][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifdef Debug
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    int n; cin >> n;
    FORD(i, 2 * n - 1, 0) {
        FORD(j, n, 0) {
            if ((i + j) & 1) continue;
            int open = (i + j) / 2, close = (i - j) / 2;
            if (open < close || close < 0) continue;
            if (open == close) {
                dp[i][j][0] = max(dp[i + 1][j + 1][0], dp[i + 1][j + 1][1]);
                dp[i][j][1] = max(dp[i + 1][j + 1][0] + 1, dp[i + 1][j + 1][1]);
            }
            else if (open == n) {
                dp[i][j][0] = max(dp[i + 1][j - 1][0], dp[i + 1][j - 1][1]);
                dp[i][j][1] = max(dp[i + 1][j - 1][0] + 1, dp[i + 1][j - 1][1]);
            }
            else {
                dp[i][j][0] = add(max(dp[i + 1][j + 1][0], dp[i + 1][j + 1][1]), max(dp[i + 1][j - 1][0], dp[i + 1][j - 1][1]));
                bool ok = false;
                if (dp[i + 1][j + 1][0] >= dp[i + 1][j + 1][1] || dp[i + 1][j - 1][0] >= dp[i + 1][j - 1][1]) ok = true;
                dp[i][j][1] = add(max(dp[i + 1][j + 1][0], dp[i + 1][j + 1][1]), max(dp[i + 1][j - 1][0], dp[i + 1][j - 1][1]));
                dp[i][j][1] += ok;
            }
            dp[i][j][0] %= mod;
            dp[i][j][1] %= mod;
        }
    }
    cout << max(dp[0][0][1], dp[0][0][0]);
    return 0;
}