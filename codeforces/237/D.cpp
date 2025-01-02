#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define hi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define xx first
#define yy second
#define mem(a,d) memset(a,d,sizeof a)
#define memc(a,d) memcpy(a,d,sizeof a)
#define Maxn 1e18
#define PI 2*acos(0.0)
#define endl "\n"
#define test cout<<" mike_testing "
#define N 100009
//#define mx 1100009
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define PII pair<long long\,long long\>
typedef tree<PII, null_type,
        less<PII>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/
//priority_queue < pair< long long\,  long long\>, vector < pair <  long long\,  long long\ >> , greater<pair< long long\,  long long\>> > qq;
long long mod=1e9+7;
long long bigmod( long long l,  long long r)
{
    if(r == 0)
        return 1LL;
    long long res = bigmod(l, r / 2)% mod;
    res = (res * res) % mod;
    if(r & 1)
        res = (res * l)% mod;
    return res% mod;
}
map<pair<int,int>,bool>mp;
vector<int>v[N];
void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>>g;
    for(int i=1; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        g.pb({a,b});
        v[a].pb(g.size());
        v[b].pb(g.size());
    }
    cout<<g.size()<<endl;
    for(auto [x,y]:g)cout<<2<<" "<<x<<" "<<y<<endl;
    vector<pair<int,int>>ans;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<v[i].size(); j++)
        {
            int a=v[i][j-1],b=v[i][j];
            if(a>b)swap(a,b);
            if(mp[ {a,b}])continue;
            ans.pb({a,b});
        }
    }
    for(auto [x,y]:ans)cout<<x<<" "<<y<<endl;
}
signed main()
{
    hi;
    long long t,i;
    t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
/*
*/

  	 		    		 	  	 	 	 	  			