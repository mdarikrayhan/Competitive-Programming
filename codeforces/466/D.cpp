#include <bits/stdc++.h>//
#include <climits>//
 
using namespace std;//
 
#define ll long long
// using ll = __int128;
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define ff first
#define ss second
// #define sc set<char>
 
/* FUNCTION */
#define f(i, s, e) for (long long i = s; i < e; i++)
#define fe(i, s, e) for (long long i = s; i <= e; i++)
#define rf(i, e, s) for (long long i = e - 1; i >= s; i--)
#define pb push_back
#define eb emplace_back
 
/* PRINTS */
template <class T>
void print_v(vector<T> &v)
{
    cout << "{";
    for (auto x : v)
        cout << x << ",";
    cout << "\b";
}
 
/* UTILS */
const ll MOD = 1e9+7;
#define debug(x) cout << #x << " " << x << endl;
#define pi 3.14159
ll min(ll a, int b)
{
    if (a < b)
        return a;
    return b;
}
ll min(int a, ll b)
{
    if (a < b)
        return a;
    return b;
}
ll max(ll a, int b)
{
    if (a > b)
        return a;
    return b;
}
ll max(int a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}
bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
 
 
int mul(const int v1, const int v2, int mod=MOD) {
    return (int)((1LL * v1 * v2) % mod);
}
 
int pow(int a, int p, int mod=MOD) {
    int res = 1;
    while (p != 0) {
        if (p & 1)
            res = mul(res, a, mod);
        p >>= 1;
        a = mul(a, a, mod);
    }
    return res;
}
 
 
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
 
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<string> vs;
 
template <typename T>
void add(T &a, T b, T M)
{
    a = ((a % M) + (b % M)) % M;
}
 
template <typename T>
void mul(T &a, T b, T M)
{
    a = ((a % M) * (b % M)) % M;
}
 
template <typename T>
void sub(T &a, T b, T M)
{
    a = (a - b + M) % M;
}
typedef vector<pair<ll,ll>>vpl; 
#define all(v) (v).begin(),(v).end() 
 
 
class dsu{
    ll n;
    vector<ll> par, sz;
    
 
public:
 
    int maxi = 0;
    dsu(ll s){
        n=s;
        for(ll i=0; i<n; i++){
            par.push_back(i);
            sz.push_back(1);
        }
 
        maxi = 1;
    }
 
    ll findPar(ll a){
        if(par[a]==a) return a;
 
        return par[a]=findPar(par[a]);
    }
 
    bool Union(ll a, ll b){
 
        int par_a = findPar(a);
 
        int par_b = findPar(b);
 
        if(par_a == par_b) return 0;
 
        if(sz[par_a]<sz[par_b]){
            par[par_a]=par[par_b];
            sz[par_b]+=sz[par_a];
            maxi = max(maxi, findsize(par_b));
        }
        else{
            par[par_b]=par[par_a];
            sz[par_a]+=sz[par_b];
            maxi = max(maxi, findsize(par_a));
        }
 
        return 1;
    }
    ll findsize(ll i){
        ll pa = findPar(i);
        
        return sz[pa];
    }
 
    
};
 
ll derangements(ll a){
 
    if(a == 1) return 0;
 
    if(a == 2) return 1 ;
 
    ll nm2 = 0;
 
    ll nm1 = 1;
 
    for(int i = 3 ; i <= a ; i ++ ){
 
        ll curr = (i-1)*(nm1+nm2);
 
        nm2 = nm1;
 
        nm1 = curr ;
 
    }
 
    return nm1 ;
 
}
 
 
/*   
***************************************************************************************
***************************************************************************************     
***************************************************************************************
 
----------------- IF YOU ARE GOOD AT SOMETHING NEVER DO IT FOR FREE ------------------
 
------------------------------ KEEP IT SIMPLE STUPID ---------------------------------
 
***************************************************************************************
***************************************************************************************
***************************************************************************************
 
                I been searching for the courage
 
                To face my enemies
 
                When they turn down the lights.....
 
                I hear my battle symphony
 
                All the world in front of me
 
                If my armor breaks
 
                I’ll fuse it back together
 
****************************************************************************************
****************************************************************************************
**************************************************************************************** 
*/
 
ll dp[2005][2005];
 
void solve(){
 
/******************* code by Ojas **************************/
 
    int n, k ;

    cin >> n >> k ;

    vector<int> nums(n+1);

    for(int i = 1 ; i <= n ; i ++ ){

        cin >> nums[i];

    }

    if(nums[1] == k || nums[1] + 1 == k ){

        dp[1][0] = 1;

    }

    if(nums[1] + 1 == k){

        dp[1][1] = 1;

    } 

    for(int i = 2 ; i <= n ; i ++ ){

        for(int j = 0 ; j <= i ; j ++ ){

            if(nums[i] + j == k){

                dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;

                dp[i][j] = (dp[i][j] + dp[i-1][j-1])%MOD;

            } 

            else if(nums[i] + j + 1 == k){

                dp[i][j] = (dp[i][j] + dp[i-1][j]*(j+1))%MOD;

                dp[i][j] = (dp[i][j] + dp[i-1][j+1]*(j+1))%MOD;

            }

        }

    }

    cout << dp[n][0] << '\n';
}   
 
 
int main(){
    
    #ifndef ONLINE_JUDGE
 
    // freopen("checklist.in", "r", stdin);   // file input.txt is opened in reading mode i.e "r"
 
    // freopen("checklist.out", "w", stdout); // file output.txt is opened in writing mode i.e "w"
 
 
    freopen("input.txt","r",stdin);
 
    freopen("output.txt","w",stdout);
 
     #endif
 
    ios_base::sync_with_stdio(0);
 
    cin.tie(0); 
 
    cout.tie(0);
 
    int64_t t ;
 
    t = 1 ;
 
    // cin >> t; 
 
    while(t--) {
      
      solve();
 
 
    }
 
 
    return 0;
 
}
