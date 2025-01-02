//  ॐ नमः शिवाय //
#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
// #include <iterator>
using namespace __gnu_pbds;
using namespace std;
typedef tree<long long, null_type, less<long long >, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define ppb pop_back
#define ld long double
#define vi vector<ll>
#define vii vector<pii>
#define mp make_pair
#define MOD 1000000007
#define mii map <ll, ll>
 #define pii pair<ll, ll>
#define SORT(x) is_sorted(all(x))
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define all(x) (x).begin(), (x).end()
#define forn(i,x,y) for(ll i=x;i<y;i++)
#define bck(i, a, b) for (ll i = a - 1; i >= b; i--)
#define SUM(x)  accumulate(all(x), 0LL)
#define input(v,n) for(ll i=0;i<n;i++)cin>>v[i];
#define printv(vec)  for(auto it : vec)cout<<it<<" ";
#define inf 2000000000
#define fore(i, l, r) for (ll i = l; i < r; ++i)

ll binpow(ll a, ll b){if (b == 0)return 1;ll res = binpow(a, b / 2); if (b % 2)return res * res * a; else return res * res;}
bool is_pali(string s){string t =s;reverse(all(s));return (s==t);}
bool isPowerOfTwo(ll x){if(x<0) return false;return x && (!(x & (x - 1)));}
bool is_prime(ll n){if(n==1)return false;for(ll i =2;i*i<=n ;i++){if(n%i==0)return false;}return true;}
ll power(ll v,ll B,ll C){if(v==0)return 0;if(B==0)return 1;ll y;if(B%2==0){y=power(v,B/2,C);y=(y*y)%C;}
else{y=v%C;y=(y*power(v,B-1,C)%C)%C;}return(ll)((y+C)%C);}
ll count_bit(ll a){ll ans=0;while(a>0){if(a&1){ans++;}a/=2;}return ans;}
bool is_sq(ll n){ll low=1,high=1e9;ll ans=0;while(low<=high){ll mid=(low+high)/2;
if(mid*mid<=n){ans=mid;low=mid+1;}else high=mid-1;}return(ans*ans==n);}

ll modadd(ll a,ll b,ll mod){ a %= mod;b %= mod; return (a + b) % mod;}
ll modmul(ll a,ll b,ll mod){ a %= mod;b %= mod; return (a * b) % mod;}
ll modsub(ll a,ll b,ll mod){ a %= mod;b %= mod; return (a - b + mod) % mod;}
ll expo(ll a, ll n, ll md){ll res=1; while(n){ if(n&1) {res = modmul(res,a,md);--n;} else {a = modmul(a,a,md);n >>= 1;}} return res;}
ll expo(ll a,ll n){ll res=1; while(n){ if(n&1) {res *= a;--n;} else {a *= a;n >>= 1;}} return res;}


ll mod = 1e9 + 7;
/* 
Observations 

*/
// bool sortbysec( pii &a,pii &b)
// {
//     return (a.second + a.first < b.second + b.first);
// }
// if DP works why to worry
// left shift
//a << b;
//multiply a with 2^b

//const ll N = 2e5 + 11;
// vi fac(N), invfac(N);
// ll modinv(ll k)
// {
//     return power(k, mod-2, mod);
// }
// void precompute()
// {
//     fac[0] = fac[1] = 1;
//     for(ll i = 2; i < N; i++)
//     {
//         fac[i] = fac[i-1] * i;
//         fac[i] %= mod;
//     }
//     invfac[N-1] = modinv(fac[N-1]);
//     for(ll i = N-2; i >= 0; i--)
//     {

// bool sortbysec( pii &a,pii &b)
// {     if(a.first != b.first)
//       return (a.first < b.first);
//       else return (a.second > b.second);
// }


/* INFO
Geometry

*/
vi fun(vi &vec)
{
    ll n=vec.size();
    vi  res(n);
    for(ll number_of_ele=1;number_of_ele<=n;number_of_ele++)
    {
        ll sum = accumulate(vec.begin(), vec.begin()+number_of_ele, 0ll);
        res[number_of_ele-1]=sum;
        for(ll i = number_of_ele, j=0; i<n; i++, j++)
        {
            sum+=(vec[i]-vec[j]);
            res[number_of_ele-1] = min(res[number_of_ele-1],sum);
        }
    }
    return res;
}


void solve() 
{
   ll n,m;
   cin>>n>>m;
   vi a(n);
   forn(i,0,n)cin>>a[i];
   vi b(m);
   forn(i,0,m)cin>>b[i];

   ll k;
   cin>>k;
   vi vec  = fun(a);
   vi vec1 = fun(b);
   
    ll ans=0;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
                if(vec[i]*vec1[j] <= k)
                ans=max(ans, (i+1)*(j+1));
        }
    }
    cout<<ans<<endl;
}

int main()
{
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            cout << fixed << setprecision(20);
            ll  t = 1;
            //cin>>t;
            //precompute();
            while(t--)
            solve();
}