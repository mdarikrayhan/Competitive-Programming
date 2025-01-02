#include<bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define f(i,s,e) for (int (i)=(s);(i)<(e);++(i))
#define rep(i,n) f(i,0,n)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
// typedef pair<int, int> node;
// typedef tree<node, null_type, less<node>,rb_tree_tag, tree_order_statistics_node_update> pbds;


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
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll ans =0;

ll helper(ll indx, ll k, ll trans, vector<ll>&v, vector<vector<ll>>&dp){

    if(trans==0){
        return 0;
    }

    if(indx>=sz(v)){
        return 0;
    }

    if(dp[indx][trans]!=-1){
        return dp[indx][trans];
    }


    ll ni = upper_bound(all(v),v[indx]+k)-v.begin();
    ll take = ni-indx+helper(ni,k,trans-1,v,dp);
    ll not_take = helper(indx+1,k,trans,v,dp);

    return dp[indx][trans]= max(take,not_take);

}

void solve(){

     ans=0;

    ll n,k;
    cin>>n>>k;

    vector<ll>v(n);

    rep(i,n){
        cin>>v[i];
    }

    rep(i,n){
        ll a; cin>>a;
    }



    sort(all(v));
    debug(v)
    vector<vector<ll>>dp(n+1,vector<ll>(3,-1));
    ans=helper(0,k,2,v,dp);

    cout<<ans <<endl;

}   


int main() {
    
    ios_base::sync_with_stdio(false),
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

}