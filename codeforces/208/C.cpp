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
#define N 109
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
long long dis[N][N];
long long cnt[N][N];
bool f[N][N]= {false};
void solve()
{
    long long n,m;
    cin>>n>>m;
    for(long long i=0; i<=n; i++)
    {
        for(long long j=0; j<=n; j++)dis[i][j]=1e8;
    }
    for(long long i=1; i<=m; i++)
    {
        long long u,v;
        cin>>u>>v;
        f[u][v]=f[v][u]=true;
        dis[u][v]=dis[v][u]=1;
        cnt[u][v]=cnt[v][u]=1;
    }
    if(n==2)
    {
        cout<<1.00000000<<endl;
        return;
    }
    for(long long i=1; i<=n; i++)
    {
        for(long long j=1; j<=n; j++)
        {
            if(i==j)continue;
            for(long long k=1; k<=n; k++)
            {
                if(i==k||j==k)continue;
                if(dis[j][k]>dis[j][i]+dis[i][k])
                {
                    dis[j][k]=dis[j][i]+dis[i][k];
                    cnt[j][k]=cnt[j][i]*cnt[i][k];
                }
                else if(dis[j][k]==dis[j][i]+dis[i][k])
                {
                    cnt[j][k]+=(cnt[j][i]*cnt[i][k]);
                }
            }
        }
    }
    double mx=1.00000000;
    for(long long i=2; i<=n; i++)
    {
        if(dis[1][n]==dis[1][i]+dis[i][n])
        {
          //  cout<<i<<" pok "<<cnt[1][i]<<" "<<cnt[i][n]<<" "<<cnt[1][n]<<endl;
            mx=max(mx,((2.00000000*cnt[1][i]*cnt[i][n])/cnt[1][n]));
        }
    }
    cout<<setprecision(8)<<fixed;
    cout<<mx<<endl;
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

 	 			   			 		  	    	 			   	