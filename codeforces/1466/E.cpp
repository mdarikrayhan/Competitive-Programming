#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
ll M = 1e9+7;
ll N = 5e5+5;
#define pb push_back
#define in insert
#define vll vector<ll>
#define vvl vector<vector<ll>>
#define vmp vector<map<ll,ll>>
#define pll pair<ll,ll>
#define vbl vector<bool>
#define vvll vector<vector<ll>>
#define vvpll vector<vector<pll>>
#define vvbl vector<vector<bool>>
#define vpll vector<pair<ll,ll>>
#define sll set<ll> 
#define msll multiset<ll>
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define geta(c,n) ll c[n]; for(ll i=0;i<n;i++)cin>>c[i];
// ll c(char i){return (ll)(i-'0');}
// ll floo(ll n,ll m){
//     if(n%m==0)return n/m;
//     return (n/m)+1;
// }
// // Binary Exponentiation
// ll binpow(ll n, ll m, ll M)
// {
//     ll pow = 1;
//     while (m)
//     {
//         n = n % M;
//         if (m & 1)
//         {
//             pow = (pow * n) % M;
//         }
//         m = m >> 1;
//         n = (n * n) % M;
//     }
//     return pow;
// }
// Multiplication of two long numbers modulo M
// ll binmul(ll n, ll m, ll M)
// {
    
//     ll ans=((n%M)*(m%M))%M;
//     return ans%M;
// }
 
// ll fact[10001];
// void factorial(ll m)
// {
//     fact[0] = 1;
//     fact[1] = 1;
//     for (int i = 2; i <= 10000; i++)
//     {
//         fact[i] = (fact[i - 1] * i) % m;
//     }
// }
// ll nCr(ll n, ll r, ll m)
// {
//     if(n<r)return 0;
//     ll ans = fact[n];
//     ll den = (fact[r] * fact[n - r]) % m;
//     ans = (ans * binpow(den, m - 2, m)) % m;
//     return ans;
// }

// dsu

// vll par(300005);
// vll siz(300005);
// void make(ll ver)
// {
//     par[ver] = ver;
//     siz[ver] = 1;
// }
// ll find(ll ver)
// {
//     if (par[ver] == ver)
//         return ver;
//     return par[ver] = find(par[ver]);
// }
// void Union(ll x, ll y)
// {
//     x = find(x);
//     y = find(y);
//     if (x != y)
//     {
//         if (siz[x] < siz[y])
//         {
//             swap(x, y);
//         }
//         par[y] = x;
//         siz[x] += siz[y];
//     }
// }

// ll moduloI(ll n){return binpow(n, M-2,M);}

// fenwick tree

// vll fen(N);
// void update(ll x,ll add){
//     while(x<N){
//         fen[x]+=add;
//         x+=(x&(-x));
//     }
// }
// ll sum(ll x){
//     ll s=0;
//     while(x>0){
//         s+=fen[x];
//         x=x-(x&(-x));
//     }
//     return s;
// }
// ll rangesum(ll l,ll r){
//     return sum(r)-sum(l-1);
// }
// ll pow2(ll n, ll m)
// {
    
//     ll pow = 1;
//     while (m)
//     {
//         n = n ;
//         if (m & 1)
//         {
//             pow = (pow * n) ;
//         }
//         m = m >> 1;
//         n = (n * n);
//     }
//     return pow;
// }
int main()
{
    vll pow1(60,0);ll xd=1;vll pow2(60,0);
    rep(i,60)pow2[i]=xd%M,xd=(xd*2)%M;xd=1;
    rep(i,60)pow1[i]=xd,xd=xd*2;
    IOS
    ll tt;cin>>tt;
    while(tt--){
        ll n,m,a,b,c,d;
        cin>>n;
        ll k[n];
        rep(i,n)cin>>k[i];
        vll f(62,0);
        rep(i,n){
            rep(j,60){
                if(((pow1[j])&k[i])!=0)f[j]++;
            }
        }
        ll ans1=0;
        rep(i,n){
            ll ans=0;
            rep(j,60){
                if((pow1[j]&k[i])!=0)ans= (ans+(n)*(pow2[j]))%M;
                else ans= (ans+(f[j])*(pow2[j]))%M;
            }
            rep(j,60){
                if((pow1[j]&k[i])!=0)ans1=(ans1+(((ans)*(f[j]))%M*(pow2[j])))%M;
            }
        }cout<<ans1<<endl;
        
        
       

        
        
        
        
    }
}
     

     