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
#define N 200009
//#define mx 1100009
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define PII pair<long long,long long>
typedef tree<PII, null_type,
        less_equal<PII>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_multiset;
//priority_queue < pair< long long,  long long>, vector < pair <  long long,  long long >> , greater<pair< long long,  long long>> > qq;
*/
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
void solve()
{
    long long n,m;
    cin>>n>>m;
    if(n>m)swap(n,m);
    long long ans=0;
    if(n==1)ans=m;
    else if(n==2)
    {
        ans=(m/4)*4;
        if(m%4==1)ans+=2;
        else if(m%4==2||m%4==3)ans+=4;
    }
    else
    {
        if(n*m%2==1)
        {
            ans=(n*m+1)/2;
        }
        else ans=(n*m)/2;
    }
    cout<<ans<<endl;
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
  				  		      		      							