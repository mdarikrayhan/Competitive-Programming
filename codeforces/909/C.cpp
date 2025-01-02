#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifdef ONLINE_JUDGE

#else
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#endif
 
#define ff              first
#define ss              second
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define mod1            998244353
#define inf             1e18
#define nline           "\n"
#define PI              3.141592653589793238462
#define sz(x)           ((int)(x).size())
#define all(x)          (x).begin(), (x).end()
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

void _print(long long t) {cerr << t;}
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

#define int long long
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

// static bool comp(pii &a,pii&b){
//     return (a.first<b.first);
// }

int32_t main()
{
    c_p_c();

    int n;cin>>n;
    vector<char> v(n+1);
    v[0]='c';
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<vi> dp(n+1,vi(n+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=0;
        }
    }
    //dp[i][j]-> no of ways to indent the code from first statement till (ith statement ending at jth indent).

    dp[1][0]=1;
    vi pref(n+1);
    pref[n]=dp[1][n];
    for(int i=n-1;i>=0;i--){
        pref[i]=(pref[i+1]+dp[1][i])%mod;
    }
    for(int i=2;i<=n;i++){
        for(int j=n;j>=0;j--){
            if(v[i-1]=='f'){
                dp[i][j]=(j==0) ? 0 : dp[i-1][j-1];
            }
            else{
                dp[i][j]=pref[j];
            }
        }  
        pref[n]=dp[i][n];
        for(int j=n-1;j>=0;j--){
            pref[j]=(pref[j+1]+dp[i][j])%mod;
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        ans=(ans+dp[n][i])%mod;
    }
    cout<<ans;
    return 0;
}

