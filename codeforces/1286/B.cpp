#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
                            // comparator 
template<typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;// find_by_order, order_of_key
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef vector<int> vi;
// typedef pair<int,int> pi;
#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int> ((a).size())
#define pqg priority_queue<ll,vector<ll>>
#define pql priority_queue<ll, vector<ll>, greater<ll>>
// #define pb push_back
// #define pk pop_back
#define ff first
#define ss second
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x) 
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T,unsigned size> void _print(array <T,size> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
const ll mod1 = 1e9+7, mod2 = 998244353;
const ll INF = INT_MAX, INF2 = INT64_MAX;
const int mx = 2e3+10;
#define int long long
vector<int> g[mx],sb(mx,0),endd(mx,0);
int timer=0;
void dfs(int src,int par)
{
    sb[src]=1;
    for(auto child : g[src])
    {
        if(child!=par)
        {
            dfs(child,src);
            sb[src] += sb[child];
        }
    }
    endd[src] = timer++;
}
void solve()
{
    int n;
    cin >> n;
    int root =0;
    vector<int> val(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        int p,c;
        cin >> p >> c;
        if(p!=0) g[p].push_back(i);
        else root = i;
        val[i] = c;
    }
    dfs(root,0);
    for (int i = 1; i <= n; i++)
    {
        // cout << sb[i] << endl;
        if(sb[i]<=val[i])
        {
            cout << "NO\n";
            return;
        }
    }
    vector<int> perm(n+1);
    iota(all(perm),0);
    sort(perm.begin()+1,perm.end(),[&](int x,int y){
        return endd[x]<endd[y];
    });
    debug(perm);
    pbds<int> st;
    vector<int> ans(n+1,0);
    for (int i = 0; i < n; i++)
    {
        st.insert(i+1);
    }
    for (int i = n+1 - 1; i >= 1; i--)
    {
        int node = perm[i];
        ans[node] = *st.find_by_order(val[node]);
        st.erase(ans[node]);
    }
    cout << "YES\n";
    for (int i = 1; i < n+1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
} 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}