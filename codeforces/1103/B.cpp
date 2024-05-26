#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define  vll vector<ll>
#define pb push_back
#define vp vector<pll>
#define tc ll t; cin >> t; for(ll i = 0; i < t; i++){solve(i, t);}
#define mpvll map<ll, vll>
#define vfast vll a(n); for (ll i = 0; i < n; i++) { cin >> a[i]; }
#define mpll map<ll,ll>
#define pll pair<ll,ll>
#define vll2 vector<vector<ll>> dp(n, vector<ll>(m));b
#define FIXED(A) cout << fixed; cout.precision(20); cout << A << "\n";
#define mp(A, B) make_pair(A, B)
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define F first
#define tc1 solve(1, 1);
#define S second
#define ckmin(a,b) a = min(a,b)
#define ckmax(a,b) a = max(a,b)
template <typename num_t>
using indexed_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
void setIO(string name) {freopen((name+".in").c_str(),"r",stdin);freopen((name+".out").c_str(),"w",stdout);}
ll rd(ll a, ll b){return (a+b-1) / b;}
ll isqrt(ll x){ll ans = 0; for(unsigned long long k = 1LL << 32; k != 0; k /= 2){if ((ans + k) * (ans + k) <= x) {ans += k;} } return ans;   }
vll prime(ll x){ll n = x; vll ans; while (n % 2 == 0) {ans.pb(2);n = n/2;} for (int i = 3; i <= sqrt(n); i = i + 2) {while (n % i == 0){ans.pb(i);n = n/i;}}if (n > 2){ans.pb(n);} return ans;}
ll binpow(ll a, ll b, ll m) { a %= m; ll res = 1; while (b > 0) { if (b & 1){res = res * a % m;}a = a * a % m; b >>= 1;} return res;}
ll lg2(ll n){ll cnt=0;while(n){cnt++;n/=2;}return cnt;}





void solve(ll TC, ll TC2) {

    while(true){
        string s; cin >> s;
        if(s!="start"){break;}
        ll l = 1;

        auto ask = [&](ll x, ll y){
            cout << "? " << x << " " << y << endl;
            char c; cin >> c;
            return c=='x';
        };

        while(!ask(l,l*2)){l*=2;}

        ll r =l*2;
        while(r-l>0){

            ll mid = (r+l)/2;
            if(ask(l-1,mid)){r=mid;}
            else{l=mid+1;}
        }

        cout << "! " << l << endl;

    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    tc1
}