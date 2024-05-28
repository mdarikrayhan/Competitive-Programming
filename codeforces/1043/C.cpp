
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define pb(x) push_back(x)
#define ll long long int
#define ld long double
const int mod = 1e9 + 7;
using namespace std;


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using sett = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define INF LLONG_MAX
#define NINF LLONG_MIN

ll get_bit_count(long long n){
    return __builtin_popcountll(n);
}

//bultin functions
#define setbits(x) __builtin_popcountll(x) ///No of set bits 
#define tzrobits(x) __builtin_ctz(x) ///Trailing zeros 
#define lzrobits(x) __builtin_clz(x) ///Leading zeros 
#define lastset(x)   __builtin_ffs(x) //last set bit position(1-based)

#define precision(x) fixed << setprecision(x)
ll binpow(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll invprime(ll a, ll b) {return binpow(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, invprime(b, m), m) + m) % m;} 
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
 
/***********************************************************************************/

                         //MAIN CODE START//




void solve()
{

    string s;
    cin>>s;

    ll n=s.size();

    vector<ll>ans(n,0);

    for(ll i=1;i<n;++i)
    {
        if(s[i]=='a')
        {
            ans[i-1]^=1;
            ans[i]=1;
        }
    }
    for(auto &x:ans) cout<<x<<" ";
    cout<<"\n";

    
    
    

}
int main()
{
    fast 
   
    

    int t=1;
    //cin>>t;
    ll l1=1;
    while(t--)
    {
        //cout<<"Case #"<<l1++<<": ";
        solve();
    }
    return 0;
}
 


    

