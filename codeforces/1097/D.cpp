#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define oo 0x3f3f3f3fLL
#define INF 0x3f3f3f3f3f3f3f3fLL
#define mem(a,n) memset((a),n,sizeof (a))
#define sz(s) (int) (s.size())
#define all(v) v.begin(), v.end()
void fast();
ll gcd(ll x, ll y) { return(!y ? x : gcd(y, x % y)); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
int dx[]{ 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[]{ 0, 0, 1, -1, 1, -1, 1, -1 };
using namespace std;
vector<pair<ll, int>>primeFact(ll n) {
    vector<pair<ll, int>>ret;
    for (ll i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i; cnt++;
        }
        if (cnt)ret.push_back({ i,cnt });
    }
    if (n > 1)
        ret.push_back({ n,1 });
    return ret;
}
ll dp[(int)1e4 + 5][70];
int k;
const int mod = 1e9 + 7;
ll fpow(ll x, ll n) {
    if (n == 0)return 1 % mod;
    if (n == 1)return x % mod;
    ll ans = fpow(x, n / 2);
    ans = ans * ans % mod;
    if (n & 1)ans = ans * (x % mod) % mod;
    return ans;
}
ll solve(int indx, int rem, ll num) {
    if (indx == k) {
        return fpow(num, rem);
    }
    ll& ret = dp[indx][rem];
    if (~ret)return ret;
    ret = 0;
    for (int i = 0; i <= rem; i++) {
        ret += solve(indx + 1, rem - i, num);
        if (ret >= mod)ret -= mod;
    }
    ret *= fpow(rem + 1, mod - 2);
    ret %= mod;
    return ret;
}
void solve() {
    ll n; cin >> n >> k;
    vector<pair<ll, int>>primef = primeFact(n);
    ll ans = 1;
    for (auto& it : primef) {
        mem(dp, -1);
        ans *= solve(0, it.second, it.first);
        ans %= mod;
    }
    cout << ans;
}
int main() {

    fast();
    int t=1; //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
  			  	    		 	    		 	    		