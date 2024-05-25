#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x...) { cout << "(" << #x << ")" << " = ( "; PRINT(x); } 
template <typename T1> void PRINT(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void PRINT(T1 t1, T2... t2) { cout << t1 << " , "; PRINT(t2...); }
#define all(v) (v).begin(), (v).end()
//(data type to be stored (pair,long long,string,vector),"null_type"(specifically used for set),comparator,underlying tree,class denoting the policy for updating node invaralong longs)
typedef tree < pair<long long,long long>, null_type,less<pair<long long,long long>>,rb_tree_tag,tree_order_statistics_node_update > pbds;
void solve();
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(10);
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
    long long n;
    cin>>n;
    long long arr[n];

    for(long long i=0;i<n;i++)
    cin>>arr[i];

    const long long mod=998244353;
    vector<vector<long long>>dp(4,vector<long long>(n+5,1));
    for(long long i = n - 1; i >= 0; i--){
    long long x = arr[i];
    map<pair<long long, long long>, long long> changes;
    // when x = mex - 1
    if(changes.find({0,x+1})==changes.end())
    changes[{0,x+1}]=0;

    changes[{0, x + 1}] = (changes[{0,x+1}]%mod+ dp[0][x + 1]%mod)%mod;

    if(changes.find({1,x+1})==changes.end())
    changes[{1,x+1}]=0;

    changes[{1, x + 1}] = (changes[{1,x+1}]%mod+dp[1][x + 1]%mod)%mod;


    // when x = mex

    if(changes.find({0,x})==changes.end())
    changes[{0,x}]=0;
    changes[{0, x}] = (changes[{0,x}]%mod + dp[0][x + 1]%mod)%mod;
    // when x = mex + 1
    if(x > 0){
        if(changes.find({0,x-1})==changes.end())
        changes[{0,x-1}]=0;
        changes[{0, x - 1}] =(changes[{0,x-1}]%mod+ dp[1][x - 1]%mod)%mod;

        if(changes.find({1,x-1})==changes.end())
        changes[{1,x-1}]=0;
        changes[{1, x - 1}] = (changes[{1,x-1}] %mod + dp[1][x - 1]%mod)%mod;
    }
    for(auto it : changes){
        auto ind=it.first;
        auto delta=it.second;
        dp[ind.first][ind.second] =(dp[ind.first][ind.second]%mod + delta%mod)%mod;
    }
}
long long x = (dp[0][0]%mod+mod-1)%mod;
cout<<x <<endl;
}