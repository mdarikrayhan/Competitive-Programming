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
const int mod = 998244353;
ll fpow(ll x, ll n) {
    if (n == 0)return 1 % mod;
    if (n == 1)return x % mod;
    ll ans = fpow(x, n / 2);
    ans = ans * ans % mod;
    if (n & 1)ans = ans * (x % mod) % mod;
    return ans;
}
int main() {

    fast();
    int n; cin >> n;
    vector<int>v(n + 1);
    for (int i = 1; i <= n; i++)cin >> v[i];
    ll num = 1, modinv = fpow(2, mod - 2);
    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        int z = i - 1;
        //first dig
        ans += (num * v[i]) % mod; ans %= mod;
        //the rest of the digits
        ans += ((n - 1 - z) * (num*modinv%mod) % mod) * v[i] % mod;
        ans %= mod;
        num *= 2; num %= mod;
    }
    cout << ans;

    return 0;
}
void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
						 			  		 	 	  	  	 			