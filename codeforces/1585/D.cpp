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
#define geta(c,n) ll c[n]; for(ll i=0;i<n;i++)cin>>c[i];
ll c(char i){return (ll)(i-'0');}
ll floo(ll n,ll m){
    if(n%m==0)return n/m;
    return (n/m)+1;
}
// Binary Exponentiation
ll binpow(ll n, ll m, ll M)
{
    ll pow = 1;
    while (m)
    {
        n = n % M;
        if (m & 1)
        {
            pow = (pow * n) % M;
        }
        m = m >> 1;
        n = (n * n) % M;
    }
    return pow;
}
// Multiplication of two long numbers modulo M
ll binmul(ll n, ll m, ll M)
{
    ll ans = 0;
    while (m)
    {
        if (m & 1)
        {
            ans = (ans + n) % M;
        }
        n = (n + n) % M;
        m >> 1;
    }
    return ans;
}
 
ll fact[10001];
void factorial(ll m)
{
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= 10000; i++)
    {
        fact[i] = (fact[i - 1] * i) % m;
    }
}
ll nCr(ll n, ll r, ll m)
{
    if(n<r)return 0;
    ll ans = fact[n];
    ll den = (fact[r] * fact[n - r]) % m;
    ans = (ans * binpow(den, m - 2, m)) % m;
    return ans;
}

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

ll moduloI(ll n){return binpow(n, M-2,M);}

// fenwick tree


void update(ll x,ll add,vll &fen){
    ll N=fen.size();
    while(x<N){
        fen[x]+=add;
        x+=(x&(-x));
    }
}
ll sum(ll x,vll &fen){
    ll s=0;
    while(x>0){
        s+=fen[x];
        x=x-(x&(-x));
    }
    return s;
}
ll rangesum(ll l,ll r,vll &fen){
    return sum(r,fen)-sum(l-1,fen);
}
int main()
{
    IOS
    ll w;cin>>w;
    while (w--)
    {
        ll n,m,a,b,c,d;
        cin>>n;map<ll,ll>f;
        vll fen(5*n+5,0);
        rep1(i,n)update(i,0,fen);
        ll k[n];rep(i,n)cin>>k[i],f[k[i]]=i+1;
        if(f.size()!=n||n==1){cout<<"YES"<<endl;continue;}

   
        if(f[1]<f[n])a=(f[1]-1+n-f[n])%2;
        else a=(f[1]-1+n-f[n]+1)%2;
        
        
        
        update(f[n],1,fen);
        update(f[1],1,fen);
        for(int i=n-1;i>=2;i--){

            ll x=rangesum(f[i],n,fen);
            a+=(n-x-f[i])%2;
            update(f[i],1,fen);
        }
        
        if(a%2==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
        

     
   }
    return 0;
}
     

     