#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define forn(i,a, n) for(long long i = a; i<(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define vec(n)  vector <ll>a(n);
#define endl "\n"
#define sz size()
const long double PI = 3.14159265358979323846;
int dx[] = { +0, +0, -1, +1, +1, +1, -1, -1 };
int dy[] = { -1, +1, +0, +0, +1, -1, +1, -1 };

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
//998244353
#define isON(mask,i) ((((mask)>>i))&1)
// (__builtin_popcount(mask)
#define ispow2(n) (!(n&(n-1)))
#define lpr pair<long long ,long long >
#define sec second
#define fi first
#define ll long long
using vl = vector<ll>;
using pl = pair<ll, ll>;
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define no cout << "NO\n"
#define yes cout << "YES\n"
//log10(n) + 1 = size n
const int INV_2 =5e8+4;
const ll OOL =0x3f3f3f3f3f3f3f3fLL;
const int OOI = 0x3f3f3f3f;
#define EPS 1e-7
const ll Mod = 998244353;
bool compd(long double A, long double B){ long double diff = A - B; return (diff < EPS) && (-diff < EPS);}

ll mul (ll a , ll b,ll mod){
    return (((a %mod + mod) * (b%mod+mod)) %mod);
}

ll bpow(ll n, ll x) { return x <= 0 ? 1 : bpow(n * n, x / 2)  * (x % 2 ? n : 1) ; }
ll binpow(ll base,ll exp,ll mod){ll res=1;while(exp>0){if(exp & 1)res=mul(res,base,mod);base= mul(base,base,mod);exp>>=1;}return res;}
ll binpow(ll base,ll exp){ll res=1;while(exp>0){if(exp & 1)res=res*base;base= base*base;exp>>=1;}return res;}
ll inv(ll a,ll mod){
    return binpow(a,mod-2,mod);
}
const ll mod=998244353;
typedef long double ld;


void IloveYou() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
ll add(ll a, ll b,ll mod){
    return (a%mod + b%mod)%mod;
}

ll subtract(ll a, ll b,ll mod){
    return (a%mod - b%mod + 2*mod)%mod;
}
const ll inf = 1e9 + 5, N = 3e5+9, M = 4e6 + 5, LG = 18, P1 = 37, P2 = 31;
//< __builtin_popcountll(n);


int clz(int N) {
    return N ? 32 - __builtin_clz(N) : -inf;
}
int clzL(unsigned long long N) {
    return N ? 64 - __builtin_clzll(N) : -inf;
}

bool comp(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}
ll power(ll x , ll y){ // log n
    ll ret =1;
    while (y > 0){
        if (y%2==0) {
            x *= x;
            y /= 2;
        }
        else{
            ret *=x;
            y--;
        }
    }
    return ret;
}

ll NpR(ll n, ll r){
    ll ans = 1;
    for (ll i = (n - r) + 1; i <= n; i++){
        ans *= i;
        ans %= mod;
    }
    return ans;
}
vector <ll>ans(2000);
void build(){
    for (ll i =1; i <=1000+2; ++i){
        if (i&1)continue;
        ll p = NpR(i/2LL,i/2LL);
        ans[i] = mul(p,p,mod) ;
    }
}

void solve() {



    int n; cin >> n;

    cout <<ans[n];

}

int main() {
    int t = 1;
    IloveYou();
     build();
    cin >> t;

 //   int cnt = 1;
    while (t--) {
        // cout <<"Case #"<<cnt++<<" :"<<" ";
        solve();
         cout << endl;
    }

}
