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
#define rall(p) p.rbegin(), p.rend()
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)



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

map<ll,ll> primefacts(ll d){
    ll temp=d;
    map<ll,ll> mp;
        while(temp%2==0){
            mp[2]+=1;
            temp/=2;
        }
        for(ll x=3;x*x<=temp;x+=2){
            while(temp%x==0){
                mp[x]+=1;
                temp/=x;
            }
        }
        if(temp>2) mp[temp]+=1;
    return mp;
}

//======================================================

class solution
{
public:
    solution(){

    }
    void solve(){
        ll n,x;cin>>n>>x;
        vector<ll> v(n);
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            sum+=v[i];
        }
        vector<ll> deg;
        for(int i=0;i<n;i++){
            deg.push_back(sum-v[i]);
        }
        sort(rall(deg));

        while(1){
            ll small=deg.back();
            ll ct=0;
            for(int i=deg.size()-1;i>=0;i--){
                if(deg[i]==small){
                    ct+=1;
                    deg.pop_back();
                }
                else break;
            }
            if(ct%x){
                small=min(small,sum);
                cout<<power(x,small)<<nline;
                return;
            }
            else{
                ll lim=ct/x;
                while(lim--) deg.push_back(small+1);
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