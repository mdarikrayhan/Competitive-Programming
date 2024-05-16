#include <bits/stdc++.h>
using namespace std;
#define read(type) readInt<type>() // Fast read
#define fr(i,a,b) for(int i=a; i<b;i++);
#define f first
#define s second
#define pb push_back
#define nl '\n'
#define MAXN 10000001
#define show(v) for(auto i: v) cout<<i<<" ";
#define show1(v) for(int i=1; i<=v.size(); i++) cout<<v[i]<<" ";
#define showp(v) for(auto i: v) cout<<i.f<<" "<<i.s<<nl;
#define ncr(n,r) fact[n]*modInv(fact[r])*modInv(fact[n-r])
#define all(x) (x).begin(),(x).end()

#include <ext/pb_ds/assoc_container.hpp> // use it when x1<=x<=x2
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
typedef long long int ll;

/*---------------------------------------------------------------------------------------------------------------------
Some properties of bitwise operations:
alb = a^b + a&b
a^(a&b) = (a|b)^b
b^(a&b) = (a|b)^a
(a&b)(a|b) = a^b
Addition:
a+b= a|b + a&b
a+b= a^b + 2(a&b)
Subtraction:
a-b = (a^(a&b))-((a|b)^a)
a-b = ((alb)^b)-((a|b)^a)
a-b = (a^ (a&b))-(b^ (a&b))
a-b = ((a|b) ^b)-(b^ (a&b))

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll gcd(ll a ,ll b){ if(b==0){ return a;} else return gcd(b,a%b);}\
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll modInv(ll a, ll m){ll arr[3]; extendgcd(a,m,arr); ll ans=(arr[0]%m+m)%m; return ans;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
long rangeBitwiseAnd(long m, long n) {long i = 0;int cnt = 0;while(m != n){m/=2;n/=2;i++;}return (m << i);}
ll sqrtbs(ll x) {ll left = 0, right = 2000000123;while (right > left) {ll mid = (left + right) / 2;if (mid * mid > x) right = mid;else left = mid + 1;}return left - 1;}
long long binpow(long long a, long long b, long long m) {a %= m;long long res = 1;while (b > 0) {if (b & 1)res = res * a % m;a = a * a % m;b >>= 1;}return res;}ll spf[MAXN]; void sieve() { spf[1] = 1; for (ll i = 2; i < MAXN; i++) spf[i] = i; for (ll i = 4; i < MAXN; i += 2) spf[i] = 2; for (ll i = 3; i * i < MAXN; i++) if (spf[i] == i) for (ll j = i * i; j < MAXN; j += i) if (spf[j] == j) spf[j] = i; } vector<ll> getFactorization(ll x) { vector<ll> ret; while (x != 1) { ret.push_back(spf[x]); x = x / spf[x]; } return ret; }
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0; i<n; i++){
        int b;
        cin>>b;
        v.pb(b);
    }
    int ans=0;
    for(int i=0; i<n; i++){
        if(s[i]=='1'){
            int cnt=0;
            int mini=INT_MAX;
            bool f=false;
            if(i-1>=0){
                f=true;
                cnt+=v[i-1];
                mini=min(mini,v[i-1]);
            }
            // mini=min(mini,)
            while(s[i]=='1'){
                mini=min(mini,v[i]);
                cnt+=v[i];
                i++;
            }
            if(f) ans+=(cnt-mini);
            else ans+=cnt;
        }
    }
    cout<<ans<<nl;
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    // cout<<"YES"<<nl;
    while (t--) {
        solve();
    }
    return 0;
}

