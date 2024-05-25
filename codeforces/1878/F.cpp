#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>  
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define M 998244353
#define M2 1000000007
#define mm 1000000000000000000
#define lim_i 1000000000
#define pie 3.141597653
#define mp make_pair
#define pb push_back
#define popb pop_back
#define GCD(x,y) __gcd(x,y)
#define all(x) x.begin(), x.end()
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef vector<pair<int,int>> vpi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<pair<long long, long long>> vpl;
typedef map<int, int> mk;
#define FF(i,a,b) for(ll i=a;i<b;i++)
ll expon(ll a, ll n)
{
    ll ans = 1;
    while(n)
    {
        if(n&1)
            ans = (ans*a);
        a = (a*a);
        n>>=1;
    }
    return ans;
}

//-------sieve--------//
const ll maxn = 1000000+5;
vll prim;
ll lpf[maxn+5] = {0};
void sieve()
{
      lpf[2] = 2;
      prim.pb(2);
      for(ll i = 2; i < maxn; i+=2)
      {
            lpf[i] = 2;
      }  
      for(ll i = 3; i*i < maxn; i+=2)
      {
            if(lpf[i] == 0)
            {
                  lpf[i] = i;
                  for(ll j = 2*i; j < maxn; j+=i)
                        lpf[j] = i;
                  prim.pb(i);
 
            }
      }
      for(ll i = sqrt(maxn); i <= maxn; i++)
      {
            if(lpf[i])
                  continue;
            else 
            {
                  lpf[i] = i;
                  prim.pb(i);
            }
      }
}

ll factorial[200001];

void factoriall(){
    for(ll i =0;i<200001;i++){
        if(i==0){
            factorial[i]=1;
        }
        else{
            factorial[i]=(factorial[i-1]*i)%M;
        }
    }
}

ll power(ll a, ll b, ll mod){ 
    ll x = 1, y = a; 
    while (b > 0){ 
        if (b%2){ 
            x = (x*y)%mod; 
        } 
        y = (y*y)%mod; 
        b /= 2; 
    } 
    return x%mod; 
}    
 
ll modular_inverse(ll n, ll mod){ 
    return power(n, mod-2, mod); 
} 
 
ll nCr(ll n, ll k, ll mod){ 
    return factorial[n]*((modular_inverse(factorial[k],mod)*modular_inverse(factorial[n-k],mod)%mod))%mod; 
} 

const ll N = 200001;
vector<pair<ll,ll>> adj[N];
bool visited[N];
ll siz[N];
ll parent[N];

// void dfs(ll vertex){
//     if(visited[vertex]){
//         return;
//     }
//     else{
//         //
//         visited[vertex]=true;
//         for(ll child : adj[vertex]){
//             //
//             dfs(child);
//             //
//         }
//         //
//     }
// }

void make(ll v){
    parent[v]=v;
    siz[v]=1;
}

ll find(ll v){
    if(parent[v]==v){
        return v;
    }
    return parent[v]=find(parent[v]);
}

void Union(ll a, ll b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(siz[a]<siz[b]){
            swap(a,b);
        }
        parent[b]=a;
        siz[a]=siz[a]+siz[b];
    }
}

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

void solve()
{
    ll n,q;
    cin>>n>>q;
    map<ll,ll> m;
    ll num=n;
    for(ll i=2;i<=num;i++){
        if(num%i==0){
            while(num%i==0){
                num=num/i;
                m[i]++;
            }
        }
    }
    ll number=n;
    map<ll,ll> mp=m;
    for(ll i=0;i<q;i++){
        ll a;
        cin>>a;
        if(a==1){
            ll x;
            cin>>x;
            num=x;
            for(ll j=2;j<=sqrt(num);j++){
                if(num%j==0){
                    while(num%j==0){
                    num=num/j;
                    m[j]++;
                    }
                }
            }
            if(num!=1){
                m[num]++;
                num=1;
            }
            //cout<<number<<" ";
            ll checker=1;
            for(auto j=m.begin();j!=m.end();j++){
                //cout<<(*j).first<<" "<<(*j).second<<endl;
                checker=checker*((*j).second+1);
            }
            map<ll,ll> mc;
            num=checker;
            for(ll j=2;j<=sqrt(num);j++){
                if(num%j==0){
                    while(num%j==0){
                    num=num/j;
                    mc[j]++;
                    }
                }
            }
            if(num!=1){
                mc[num]++;
                num=1;
            }
            ll p=0;
            for(auto j=mc.begin();j!=mc.end();j++){
                if(m[(*j).first]>=(*j).second){

                }
                else{
                    p=1;break;
                }
            }
            if(p==0){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            number=n;
            m=mp;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //sieve();
    factoriall();
    int tee=1;
    cin>>tee;
    while(tee--)
    {
        solve();
    }
}