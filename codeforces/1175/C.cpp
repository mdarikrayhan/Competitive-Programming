#include "bits/stdc++.h"
using namespace std;
const int Mod1 = 998244353;
const int Mod2 = 1000000007;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<pdd> vpdd;
typedef vector<vd> vvd;
#define yn(ans) printf("%s\n", (ans)?"Yes":"No");
#define YN(ans) printf("%s\n", (ans)?"YES":"NO");
template<class T> bool chmax(T &a, T b) {
    if (a >= b) return false;
    a = b; return true;
}
template<class T> bool chmin(T &a, T b) {
    if (a <= b) return false;
    a = b; return true;
}
#define FOR(i, s, e, t) for ((i) = (s); (i) < (e); (i) += (t))
#define REP(i, e) for (int i = 0; i < (e); ++i)
#define REP1(i, s, e) for (int i = (s); i < (e); ++i)
#define RREP(i, e) for (int i = (e); i >= 0; --i)
#define RREP1(i, e, s) for (int i = (e); i >= (s); --i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front
#define maxe max_element
#define mine min_element
ll inf = 1e18;
int gcd(int x,int y) {return (!y) ? x: gcd(y, x % y);}
ll qpow(ll a, ll n, int Mod){ll r = 1; while (n) {if (n & 1) {r = r * a % Mod;}; a = a * a % Mod; n >>= 1;}return r;}

int a[200005];
void solve(){
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = -1, optimal = 2e9;
    for (int i = 0; i < n - k; i++){
        if (a[i + k] - a[i] < optimal){
            optimal = a[i + k] - a[i];
            ans = (a[i + k] + a[i]) / 2;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T = 1; cin >> T;
    while (T--) solve();
}
