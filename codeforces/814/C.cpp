/****************************************************
         ❤ Bsmellah El Rahman El Rahim ❤
****************************************************/
// @formatter:off
#include <bits/stdc++.h>
using namespace std;
#define ZA7med ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
using ll = long long;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef map<int, int> mii;
typedef set<int> si;
using iii = tuple<ll, int, int>;
#define LSO(x) (x & (-x))
#define pb(x) push_back(x)
#define ss second
#define ff first
#define endl "\n"
#define all(v) v.begin(), v.end()
#define allr(v) (v).rbegin(),(v).rend()
#define sz(v) ((int)(v).size())
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x)
void FRead() {}
#endif
// ==============================================================================================
const ll N = 1599 + 5, OO = 1000000000, mod = 1e9 + 7, LOO = 1e18;
enum {UNVISITED = -1, VISITED = 1, EXPLORED = 2};
const int dx8[8] = {0, 0, 1, -1, 1, -1, -1, 1};
const int dy8[8] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
string operator *(string a, int b) { string s = ""; while(b) { if(b & 1) s += a; a += a; b >>= 1; } return s; }
int MOD(int x, int m) { return ((x % m + m) % m); }
bool issquare(ll a){ll sq = (ll)sqrt(a); return (sq * sq == a);}
bool ispow2(ll x) {return x && !(x & (x - 1));}
bool isprime(ll x) {if(x == 1) return false;if(x == 2) return true;if(x % 2 == 0) return false;for(int d = 3; 1ll * d * d <= x; d += 2)if(x % d == 0) return false;return true;}
int msb(ll n){return 63 - __builtin_clzll(n);}
// @formatter:on
int dp[26][N]; // char, rep
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char i = 'a'; i <= 'z'; ++i) {
        for (int j = 0; j < n; ++j) {
            int cur = 0;
            for (int k = j; k < n; ++k) {
                int sz = k - j + 1;
                cur += (s[k] != i);
                dp[i - 'a'][cur] = max(sz, dp[i - 'a'][cur]);
            }
        }
        for (int j = 1; j <= n; ++j)
            dp[i - 'a'][j] = max(dp[i - 'a'][j], dp[i - 'a'][j - 1]);
    }

    int q;
    cin >> q;
    while (q--) {
        char b;
        int a;
        cin >> a >> b;
        b -= 'a';
        cout << dp[b][a] << endl;
    }
}

signed main() {
    //  =============================================================================
    ZA7med;
    FRead();
    //  =============================================================================
    int TC = 1;
//    cin >> TC;
    while (TC--)
        solve();
    return 0;
}

