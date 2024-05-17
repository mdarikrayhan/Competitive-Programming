#pragma GCC optimize("Ofast")
//--------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ll = long long;
#define nline '\n'
#define ff first
#define ss second
#define all(p) p.begin(), p.end()
#define erasedups(arr) arr.erase(unique(all(arr)),arr.end())

//------------------------------------------------------
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define rev_ordered_set tree<ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define rev_ordered_multiset tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
// erasing only one instance => mst.erase(mst.find_by_order(mst.order_of_key(val)));
// *(o_set.find_by_order(1)) -> 2nd smallest num
//  o_set.order_of_key(4) -> idx of 4 or no. of elements less than 4
//  o_set.erase(o_set.find(2));
//  multi.erase(multi.upper_bound(val))
//======================================================================
#define BUG
#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define bug(...)
#endif

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

//======================================================================
// defining and initializing
ll M = 1e9 + 7;
const int MAXN = 5e6 + 10;

struct HASH
{
    size_t operator()(const pair<ll, ll> &x) const
    {
        return hash<long long>()(((long long)x.first) ^ (((long long)x.second) << 32));
    }
};

//=======================================================================
// functions

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll lcm(ll a, ll b)
{
    return (a * b) / (gcd(a, b));
}

ll power(ll base, ll idx, ll M=1e9+7)
{
    ll res = 1;
    base = base % M;
    if (base == 0)
        return 0;
    while (idx > 0)
    {
        if (idx & 1)
            res = (res * base) % M;
        idx >>= 1;
        base = (base * base) % M;
    }
    return res;
}

class DSU{
    int n;
    vector<int> par, rank;

public:
    DSU(int n){
        this->n = n;
        par.resize(n, -1);
        rank.resize(n, 1);
    }
    int find(int i){
        if (par[i] == -1)
            return i;
        return par[i] = find(par[i]);
    }
    bool add(int x, int y){
        int a = find(x), b = find(y);
        if (a == b)
            return true;
        if (rank[a] > rank[b])
        {
            par[b] = a;
            rank[a] += rank[b];
        }
        else
        {
            par[a] = b;
            rank[b] += rank[a];
        }
        return false;
    }
    int components(int node){
        int p = find(node);
        return rank[p];
    }
};

//======================================================



class solution
{
public:
    solution(){

    }
    void solve(){
       ll n;cin>>n;
       vector<ll> primes(1e5,true);
       primes[0]=primes[1]=false;
       for(ll i=2;i<1e5;i++){
        if(primes[i]){
            for(ll j=i*i;j<1e5;j+=i){
                primes[j]=false;
            }
        }  
       }
       auto check=[&](ll n){
            for(ll i=2;i*i<=n;i++){
                if(n%i==0) return false;
            }
            return true;
       };

       if(n==3){
        cout<<1<<endl;
        cout<<3<<endl;
       }
       else if(n==5){
        cout<<2<<endl;
        cout<<2<<" "<<3<<endl;
       }
       else{
        for(int i=2;i<1e5;i++){
            if(n>=1e5){
                if(primes[i] && check(n-3-i)){
                    cout<<3<<endl;
                    cout<<3<<" "<<i<<" "<<n-3-i<<endl;
                    return;
                }
            }
            else{
                if(primes[i] && primes[n-3-i]){
                    cout<<3<<endl;
                    cout<<3<<" "<<i<<" "<<n-3-i<<endl;
                    return;
                }
            }
        }
       }
       
    }
};

int32_t main(){

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solution test;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    t = 1;
    //cin >> t;

    cout << fixed << setprecision(9);

    while (t-- > 0)
    {
        test.solve();
    }
    return 0;
}