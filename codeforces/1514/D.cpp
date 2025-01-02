#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<pair<ll , ll>> vpll;
typedef vector<pair<ld , ld>> vplld;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef priority_queue<ll> pq;
typedef priority_queue<pair<ll,ll>> pqp;

#define fi first
#define se second
#define pb push_back
#define mk make_pair
#define endl "\n"
#define yes cout<<"YES"
#define no cout<<"NO"
#define graph vector<vector<int>>
#define all(x) x.begin(), x.end()
const int mod = (int)1e9 + 7;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
// #define inf 1e18

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

ll fact[200005];
void factorial(int sz){
    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2 ; i < sz ; i ++)
    {
        fact[i] = (fact[i-1]*i)%mod;		
    }
}

ll pow_mod(ll x, ll n){   //(x^n % mod)
    ll ret = 1;
    while(n){
        if(n&1)
            ret = ((ret*x)%mod);
        n >>= 1;
        x = ((x*x)%mod);
    }
    return ret;
}

vll getDivisor(ll a) {
        vll divisors{ 1, a };
        ll i;
        for (i = 1; i * i < a; i++) {
            if (a % i == 0) {
                divisors.push_back(i);
                divisors.push_back(a / i);
            }
        }
        if (i * i == a)
            divisors.push_back(i);
        return divisors;
}

ll inv_mod(ll x){
    return pow_mod(x , mod - 2)%mod;
}

ll ncr(ll n , ll r)
{
    if(r == 0) return 1;
    if(n<r || r<0) return 0;
    return (((fact[n]*inv_mod(fact[n-r]))%mod)*inv_mod(fact[r])%mod)%mod;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(auto &x : v)cin>>x;
    vector<int>mp[300001];
    for(int i=0; i<n; ++i){
        mp[v[i]].pb(i);
    }
    for(int i=0; i<m; ++i){
        int l, r, res = 1;
        cin>>l>>r;
        l--, r--;
        for(int x = 0; x<40; ++x){
            int val = v[uniform_int_distribution<int>(l,r)(rng)];
            int f = upper_bound(all(mp[val]), r) - lower_bound(all(mp[val]), l);
            res = max(res, 2*f-(r-l+1));
        }
        cout<<res<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    // cout<<setprecision(15)<<fixed;
    for(int i=1; i<=t; ++i){
        // cout<<"Case #"<<i<<": ";
        solve();
        cout<<"\n";
    }
    return 0;
}