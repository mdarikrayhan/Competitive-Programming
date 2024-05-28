#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll,ll> pll;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;

#define forr(_a,_b,_c) for(int _a = (_b); _a <= (_c); ++_a)
#define ford(_a,_b,_c) for(int _a = (_b) + 1; _a --> (_c);)
#define forf(_a,_b,_c) for(int _a = (_b); _a < (_c); ++_a)
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define mask(i) (1LL << (i))
#define bit(x, i) (((x) >> (i)) & 1)
#define bp __builtin_popcountll
#define file "test"

template<class X, class Y>
    bool minz(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } return false;
    }
template<class X, class Y>
    bool maxz(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } return false;
    }

const int N = 5e5 + 5;
const ll oo = 1e9;
const ll mod = 1e9 + 7; // 998244353;

ll x, dp[N][64];

void solve (){
    cin >> x;

    forr (i, 0, 3)
        dp[1][i] = 1;

    forf (i, 1, 60){
        if (!bit(x, i)){
            dp[i + 1][0] = (dp[i][0]) % mod;
            dp[i + 1][1] = (dp[i + 1][0] + dp[i][2] + dp[i][1]) % mod;
            dp[i + 1][2] = (dp[i + 1][1] + dp[i][4] + dp[i][3]) % mod;
            dp[i + 1][3] = (dp[i + 1][2] + dp[i][6] + dp[i][5]) % mod;
            dp[i + 1][4] = (dp[i + 1][3] - dp[i + 1][0] + mod) % mod;
            dp[i + 1][5] = (dp[i + 1][3] - dp[i + 1][1] + mod) % mod;
            dp[i + 1][6] = (dp[i + 1][3] - dp[i + 1][2] + mod) % mod;
        } else {
            dp[i + 1][0] = (dp[i][0] + dp[i][1]) % mod;
            dp[i + 1][1] = (dp[i + 1][0] + dp[i][2] + dp[i][3]) % mod;
            dp[i + 1][2] = (dp[i + 1][1] + dp[i][4] + dp[i][5]) % mod;
            dp[i + 1][3] = (dp[i + 1][2] + dp[i][6]) % mod;
            dp[i + 1][4] = (dp[i + 1][3] - dp[i + 1][0] + mod) % mod;
            dp[i + 1][5] = (dp[i + 1][3] - dp[i + 1][1] + mod) % mod;
            dp[i + 1][6] = (dp[i + 1][3] - dp[i + 1][2] + mod) % mod;
        }
    }
    cout << dp[60][0] << "\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef hqm
        freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
    #endif

    int q = 1;
    cin >> q;
    while (q--)
        solve();

    return 0;
}
/*



*/

