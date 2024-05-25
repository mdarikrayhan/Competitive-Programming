#include<bits/stdc++.h>
using namespace std;
#define int long long


// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// // order_of_key(k) : no. of elements < k
// // *find_by_order(i) : value at index i (0-based)

//typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef map<char,int> mc;
#define py cout<<"Yes\n";
#define pn cout<<"No\n";
#define endl "\n";
#define all int i=0;i<n;i++
#define allj int j=0;j<n;j++
#define all1 int i=1;i<=n;i++
#define all1j int j=1;j<=n;j++
#define allm int i=0;i<m;i++
#define sorti(v) sort(v.begin(),v.end());
#define sortig(v) sort(v.begin(),v.end(),greater<int>());
#define take int n;cin>>n;int a[n]; for(all){cin>>a[i];}
#define show(v) for(auto x:v){cout<<x<<" ";}cout<<endl;
#define mnv(v) *min_element(v.begin(), v.end());
#define mxv(v) *max_element(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
#define set_bits __builtin_popcountll
#define debug(x) cerr<<#x<<" is "; _print(x); cerr<<endl;

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 

const int N=1e9+7; //largeprime
//int N=998244353;
const int inf=1e18;
const int NN=1e5+10;
const int sis=2e5+7;


struct DSU{
    vector<int> par,siz;
    void init(int n){
        par.resize(n+1);
        siz.resize(n+1);
        for(int i = 1; i <= n; i++){
            par[i] = i;
            siz[i] = 1;
        }
    }
    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(siz[x] < siz[y]) swap(x,y);
        par[y] = x;
        siz[x] += siz[y];
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};

int binpow(int a,int b,int mod=1e9+7){
    int res=1;
    a%=mod;
    while(b){
        if(b&1){
            res*=a;
            res%=mod;
        }
        b>>=1;
        a*=a;
        a%=mod;
    }

    return res;
}
int modInverse(int n){
    return binpow(n,N-2);
}


void solve(){
    int n,m; cin>>n>>m;

    DSU dsu;

    vi ans;

    dsu.init(m + 1);
    for(all){
        int s; cin>>s;
        if(s == 1){
            int x; cin>>x;
            if(dsu.find(x) != dsu.find(0)){
                dsu.unite(x,0);
                ans.push_back(i + 1);
            }
        }
        else{
            int x,y; cin>>x>>y;
            if(dsu.find(x) != dsu.find(y)){
                dsu.unite(x,y);
                ans.push_back(i + 1);
            }
        }
    }

    cout<<binpow(2, ans.size())<<" "<<ans.size()<<endl;
    show(ans);
    
}

int t=1;

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int t; cin>>t;
    while(t--){
        solve();
    }
}

