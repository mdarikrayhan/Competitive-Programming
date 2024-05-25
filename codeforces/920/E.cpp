// Radhe Radhe
// Author :  AryRDW
// Date   :  24-05-2024
// Time   :  01:06:25
#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long             ll;
typedef long double           ld;
typedef pair<int,int>         pii;
typedef pair<ll,ll>           pll;
typedef pair<double,double>   pdd;
typedef vector<ll>            vl;
typedef vector<pll>           vpl;
typedef vector<pii>           vpi;
typedef vector<int>           vi;
typedef vector<vector<int>>   vvi;
typedef vector<vector<ll>>    vvl;
#define lb                    lower_bound;
#define ub                    upper_bound;
#define yeah                  cout<<"Yes"<<endl
#define nope                  cout<<"No"<<endl
#define forn(i,e)             for(ll i = 0; i < e; i++)
#define forsn(i,s,e)          for(ll i = s; i < e; i++)
#define rforn(i,s)            for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e)         for(ll i = s; i >= e; i--)
#define ln                    "\n"
#define mp                    make_pair
#define pb                    push_back
#define fi                    first
#define se                    second
#define INF                   2e18
#define all(x)                (x).begin(), (x).end()
#define sz(x)                 (ll)(x).size()

#ifndef ONLINE_JUDGE  
#define dbg(x)                cerr<<#x<<"  ";_print(x);cerr<<endl;
#else
#define dbg(x);
#endif
#ifndef ONLINE_JUDGE  
#define dbg2(x,n);            cerr<<#x<<" ";_print(x,n);cerr<<endl;
#else
#define dbg2(x,n);
#endif
template<class T,class V> void _print(pair<T,V> p);
template<class T>void _print(set<T> v);
template<class T>void _print(multiset<T> v) ;
template<class T,class V>void _print(map<T, V> v);
template<class T>void _print(vector<T> v);
void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;} 
template<class T,class V> void _print(pair<T,V> p) {cerr<<"{"; _print(p.first);cerr<<","; _print(p.second);cerr<<"}";}
template<class T>void _print(vector<T> v) {cerr<<" [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(vector<T> v,int n) {cerr<<" [ "; int j=0; for (T i:v){ if(j>=n)break;j++; _print(i);cerr<<" ";}cerr<<"]";}
template<class T>void _print(set<T> v) {cerr<<" [ "; for (T i:v){_print(i); cerr<<" ";}cerr<<"]";}
template<class T>void _print(multiset<T> v) {cerr<< " [ "; for (T i:v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T,class V>void _print(map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";} 
template<class T,class V>void _print(unordered_map<T, V> v) {cerr<<" [ "; for(auto i:v) {_print(i);cerr<<" ";} cerr<<"]";}
template<class T,class V>void _print(queue<T, V> v) {cerr<<" [ "; while(!v.empty()) {_print(v.front());cerr<<" ";v.pop();} cerr<<"]";}
template<class T,class V>void _print(stack<T, V> v) {cerr<<" [ "; while(!v.empty()) {_print(v.top());cerr<<" ";v.pop();} cerr<<"]";}
template<class T,class V>void _print(priority_queue<T, V> v) {cerr<<" [ "; while(!v.empty()) {_print(v.front());cerr<<" ";v.pop();} cerr<<"]";}

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll binpow(ll a, ll b, ll MOD) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;
    if (M == 1)return 0;
    while(a>1) {
        ll q = a/ M;
        ll t = M;M = a % M, a= t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)x += m0;
    return x;
}

ll gcd(ll a, ll b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}

void ord_erase(ordered_set<int> &s, int v){
    auto rank = s.order_of_key(v);
    auto it = s.find_by_order(rank);
    s.erase(it);
}
void ord_erase(ordered_multiset<int> &s, int v){
    auto rank = s.order_of_key(v);
    auto it = s.find_by_order(rank);
    s.erase(it);
}


ll MOD = 998244353;
//const ll N=1e5+5;
//ll dp[N];
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};
bool comp(vi &a,vi &b){
    return sz(a)<sz(b);
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<set<int>> adj(n+1);
    forn(i,m){
        int u,v;cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    set<int> avl;
    forn(i,n)avl.insert(i+1);
    dsu dsu(n+1);
    vi vis(n+1,0);
    auto dfs=[&](auto dfs,int u)->void{
        vis[u]=1;
        auto it=avl.begin();
        while(it!=avl.end()){
            int val=*it;
            if(!adj[u].count(*it)){
                dsu.merge(u,*it);
                avl.erase(it);
                dfs(dfs,val);
            }
            it=avl.upper_bound(val);
        }
    };
    forsn(i,1,n+1){
        if(!vis[i]){
            dfs(dfs,i);
        }
    }
    auto groups=dsu.groups();
    sort(all(groups),comp);
    cout<<sz(groups)-1<<ln;
    int f=0;
    for(auto &k:groups){
        if(!f && sz(k)==1){
            f=1;continue;
        }
            cout<<sz(k)<<" ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cout<<fixed<<setprecision(0);
    ll t=1;
    // cin >> t;
    forn(i,t)
    {
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}